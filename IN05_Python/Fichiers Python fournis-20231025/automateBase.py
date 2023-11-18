# -*- coding: utf-8 -*-
"""
Code à ne pas modifier
"""

from transition import *
from state import *
import os
import sys
from copy import copy
from sp import *
from myparser import *
from itertools import product
import subprocess
import sys
from IPython.core.magic import (Magics, magics_class, cell_magic, line_magic)
from IPython.display import (SVG, Image, display)


def run_graphviz(*options):
    cmd_line = ['dot']
    cmd_line.extend(options)
    subprocess.check_call(cmd_line)

"""
ATTENTION!! quand on cree un automate avec un ensemble de transitions vides, cela cree un automate vide! 
par contre, les manipulations sur les automates vides posent probleme, un automate n'est pas cense etre vide.
Creer une exception (automateVide?)
"""

"""
Comportement bizarre a encadrer : le test d'egalite des etats ne tient pas compte du fait 
que l'etat soit initial ou final, il ne teste que l'identifiant.
Donc on peut avoir des transitions qui referencent des etats (id, init, final), un etat (id, init', final')
deja present dans l'automate, et donc l'etat de l'automate sera (id, init', final') mais lorsqu'on parcourt
les transitions, on se base sur (id, init, final)!!
"""

"""Classe définissant un automate caractérise par :
    - un ensemble de transitions
    - optionnellement un ensemble d'etats
    - optionnellement un label
"""
class AutomateBase :


    def __init__ (self, setTransitions, setStates=None, label=None) :
        """set[Transition] x set[State] x str -> Automate
        construit l'automate construit à partir de la liste de
        transitions fournies, et optionnellement la liste d'états et
        l'étiquette
        """
        self.label = label
        if setStates == None :
            self.allStates = set()
        else :
            self.allStates = copy(setStates)
        self.allTransitions = copy(setTransitions)
        self.allStates = self.__getSetStates()
        #if len(self.allStates)==0 :
        #    s=State(0,True, False)
        #    self.allStates.add(s)



    def getAlphabetFromTransitions(self):
        """ -> set[str]
        rend l'ensemble des labels d'étiquettes présents dans l'automate
        """
        # recuperation des etiquettes sous forme de set et reconversion en liste
        return {t.etiquette for t in self.allTransitions}


    def __getSetStates(self):
        """  -> set[State]
        rend l'ensemble des états - usage interne
        """
        # states : set[State]
        if self.allStates == None:
            states = set()
        else:
            states = self.allStates
        # t : Transition
        for t in self.allTransitions :
            #states = states | {t.stateSrc, t.stateDest}
            states.add(t.stateSrc)
            states.add(t.stateDest)
        return states




    """si stateSrc ou stateDest est dans allStates, il faut
    que stateSrc.init et stateDest.init soient coherents, sinon on n'ajoute pas la transition
    """
    def addTransition(self, transition) :
        """Transition -> Bool
        fait la mise à jour de l'automate en lui ajoutant la
        transition, en ajoutant les états impliqués dans l'automate
        s'ils en sont absents
        rend True si l'ajout a eu lieu, False sinon (si t était déjà
        présente dans l'automate, ou si les etats t.stateSrc ou t.stateDest n'étaient pas cohérents avec ce qui existait dans l'automate)
        """
        if transition not in self.allTransitions :
            
            trouveSrc = False
            trouveDest = False
            #s: State
            for s in self.allStates:
                #stateSrc et s ont le meme identifiant: on n'ajoute pas stateSrc
                if transition.stateSrc == s :
                    # les etats stateSrc et s ne sont pas coherents
                    if transition.stateSrc.init != s.init or transition.stateSrc.fin != s.fin : 
                        #on n'ajoute pas la transition
                        return False
                    else:
                        trouveSrc = True
                        
                #stateDest et s ont le meme identifiant: on n'ajoute pas stateDest
                if transition.stateDest == s :
                    if transition.stateDest.init != s.init or transition.stateDest.fin != s.fin :
                        #on n'ajoute pas la transition
                        return False
                    else:
                        trouveDest = True
            
            #si stateSrc n'existait pas
            if not trouveSrc:
                self.allStates.add(transition.stateSrc)
            #si stateDest n'existait pas
            if not trouveDest:
                self.allStates.add(transition.stateDest)

            self.allTransitions.add(transition)

            return True
        return False


    def removeTransition(self, transition) :
        """Transition -> Bool
        fait la mise à jour de l'automate en lui enlevant la
        transition, sans modifier les états
        rend True si la suppression a eu lieu, False sinon (si t était
        absente de l'automate)
        """
        if transition in self.allTransitions :
            self.allTransitions.remove(transition)
            return True
        return False


    def addState(self, state) :
        """State -> Bool
        fait la mise à jour de l'automate en lui ajoutant l'état state
        rend True si l'ajout a eu lieu, False sinon (si s était déjà
        présent dans l'automate)
        """
        if state not in self.allStates :
            self.allStates.add(state)
            return True
        return False


    def removeState(self, state) :
        """State -> Bool
        fait la mise à jour de l'automate en lui supprimant l'état
        ainsi que toutes les transisitions entrantes et sortantes
        rend True si la suppression a eu lieu, False sinon  (si s
        était absent de l'automate)
        """
        if state in self.allStates :
            copyT={t for t in self.allTransitions}
            for t in copyT :
                if t.stateSrc == state or t.stateDest == state :
                    self.removeTransition(t)
            self.allStates.remove(state)
            return True
        return False



    def getSetInitialStates(self) :
        """ -> set[State]
        rend l'ensemble des états initiaux
        """
        # initStates : set[State]
        initStates = set()
        # state : State
        for state in self.allStates :
            if state.init :
                initStates.add(state)
        return initStates


    def getSetFinalStates(self):
        """ -> set[State]
        rend la liste des états finals
        """
        # finStates : set[State]
        finStates = set()
        # state : State
        for state in self.allStates:
            if state.fin:
                finStates.add(state)
        return finStates



    def getSetTransitionsFrom(self, state):
        """ State -> set[Transition]
        rend l'ensemble des transitions sortant de l'état state dans l'automate
        """
        # S : set[Transition]
        S = set()
        # state : State
        if state in self.allStates :
            # t : Transition
            S = S | {t for t in self.allTransitions if t.stateSrc == state}
        return S
    
    
    def nextId(self):
        """ -> int
        renvoie un entier id frais, en choisissant l'entier le plus petit,
        strictement supérieur à tous les id des états de l'automate
        """
        Etiquettes = {s.id for s in self.allStates}
        return max(Etiquettes) + 1


    def toDot (self) :
        """-> str
        rend une description de l'automate au format dot qui sera
        appelée par la fonction show
        """
        # ret : str
        ret = "digraph a {\n rankdir=LR\n"
        # state : State
        for state in self.allStates :
            ret += str(state.id) + "[ label =\"" + str(state.label) + "\","
            #Test pour savoir si l'etat est initial et/ou final
            if state.init :
               ret += " color=red "
            if state.fin :
               ret += "peripheries=2 "
            ret += "];\n"

            #Ecriture des transitions depuis l'etat
            # S : set[Transition]
            S = self.getSetTransitionsFrom(state)
            # setToRemove : set[Transition]
            setToRemove = set()
            # trans : Transition
            for trans in S:
                if trans not in setToRemove:
                    # etiq : str
                    etiq = trans.etiquette

                    # t : Transition
                    for t in S:
                        if t.stateDest.id == trans.stateDest.id and t.etiquette != trans.etiquette:
                            etiq = etiq + ", " + t.etiquette
                            setToRemove.add(t)
                    ret += str(trans.stateSrc.id) +" -> " + str(trans.stateDest.id)
                    ret += " [ label = \"" + etiq + "\" ];\n"
        #Fin de l'automate
        ret += "}\n"
        return ret


    def show(self, w = 1.0, filename = 'affichage.dot'):
        """ str ->
        Produit un fichier pdf donnant une représentation graphique de l'automate
        Erreur si l'impression s'est mal passée
        """
        try :
            with open(filename, 'w') as f:
                f.write(self.toDot())
            f.close()

            run_graphviz(filename, '-T', 'png', '-o', filename + ".png")

            return display(Image(filename = filename+".png", width=int(400*w)))

        except IOError :
            print("Impossible de creer le fichier .dot" )


    def __repr__(self) :
        """ -> str
        rend une description textuelle de l'automate
        elle permet d'utiliser print pour les Automate"""
        # ret : str
        if self.label is not None :
            ret= "Automate " + self.label + "\n" + "Etats :\n"
        else :
            ret= "Etats :\n"
        # s : State
        for s in self.allStates:
                ret = ret + "  " + str(s) + "\n"
        ret = ret + "Transitions :\n"
        # t : Transition
        for t in self.allTransitions :
           ret = ret + "  " + str(t) + "\n"
        return ret


    """Fonction permettant d'initialiser un automate depuis un fichier
       Exemple :
           a = Automate.creationAutomate("testAutomate.txt")
    """
    @classmethod
    def creationAutomate(cls, nomFichier):
        """  str -> Automate
        rend l'automate construit en lisant le contenu du fichier dont
        le nom est fourni en argument
        Exemple :
        a = Automate.creationAutomate("testAutomate.txt")
        """
        # listeResultat : list[str]
        listeResultat = MyParser.parseFromFile(nomFichier)
        #On recupere les listes des etats
        #listeInit : list[str]
        listeInit = listeResultat[1]
        #print("listeInit" + str(listeInit))
        # listeFin : list[str]
        listeFin = listeResultat[2]
        #print(listeFin)
        #listeEtats: list[str]
        listeEtats = listeResultat[0]
        #print(listeEtats)

        # setE : set[State]
        setE = set()
        # setT : set[Transition]
        setT = set()

        # e: str
        for e in listeInit: #on commence par ajouter les états initiaux
            # s: State
            s = State(int(e), True, False)
            if e in listeFin: #on vérifie si l'état est à la fois initial et final
                s.fin = True
            #if s not in setE:
            setE.add(s)

        for e in listeFin: # on ajoute ensuite les états finaux
            s = State(int(e), False, True)
            if e not in listeInit: #sinon on a deja ajoute e dans la boucle précédente
                #if s not in setE:
                setE.add(s)

        for e in listeEtats: #on ajoute les états ni initiaux ni finaux
            s = State(int(e), False, False)
            if e not in listeInit and e not in listeFin:
                #if s not in setE :
                setE.add(s)
        #print("liste Etats"+ str(setE))

        #on récupère la liste des transitions
        #setTrans : set[str]
        setTrans = set(listeResultat[3])
        # t: str
        for t in setTrans:
            #stateSrc : State
            stateSrc = State(int(t[0]), False, False)
            #stateDest : State
            stateDest = State(int(t[2]), False, False)

            if stateSrc in setE: # si l'état est déjà dans la liste
                # d'états, on récupère le vrai état (i.e. avec le fait d'être initial ou final),
                #sinon c'est par défaut un état ni initial ni final
                for s in setE:
                    if s == stateSrc:
                        stateSrc = s
                        break
            if stateDest in setE : # si l'état est déjà dans la
                # liste d'états, on récupère le vrai état,
                #sinon c'est par défaut un état ni initial ni final
                for s in setE:
                    if s == stateDest:
                        stateDest = s
                        break
            # trans : Transition
            trans = Transition(stateSrc, t[1], stateDest)
            if trans not in setT:
                setT.add(trans)
        #automate : Automate
        automate = cls(setT,setE)
        return automate


        """ Fonction inserant un prefixe a chaque identifiant et label d'etat
        Le prefixe doit être un nombre entier"""
    def prefixStates(self, prefixe):
        """ int ->
        modifie le nom de tous les états de l'automate en les
        préfixant par prefixe
        HYPOTHESE le préfixe est positif
        """
        # state : State
        for state in self.allStates :
                state.insertPrefix(prefixe)
                
    """Fonction testant l'égalité champ par champ de deux automates. 
    AutomateBase x AutomateBase -> Bool
    """
    def equals(self, other):
        if isinstance (other, self.__class__):
            return self.label == other.label and self.allTransitions == other.allTransitions and self.allStates == other.allStates
        return False
