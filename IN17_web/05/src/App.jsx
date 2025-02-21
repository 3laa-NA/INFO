import { useState } from 'react'
import Livre from './components/Livre'
import FormulaireAjout from './components/FormulaireAjout'
import DoubleSaisie from './components/DoubleSaisie'
import DroitsUnix from './components/DroitsUnix'
import './App.css'

function App() {
  // Initialisation des dates
  const dateAuj = new Date()
  const dateE = new Date('2023-02-19')

  // Initialisation des states
  const [titreCollection, setTitreCollection] = useState('')
  const [livres, setLivres] = useState([
    {
      auteur: "Hugo Victor",
      titre: "La Légende des siècles",
      emprunt: { statut: false, dateEmprunt: dateAuj },
      cote: "HUG001"
    },
    {
      auteur: "Hugo Victor",
      titre: "Les Misérables",
      emprunt: { statut: false, dateEmprunt: dateAuj },
      cote: "HUG002"
    },
    {
      auteur: "Zola Émile",
      titre: "L'Assommoir",
      emprunt: { statut: true, dateEmprunt: dateE },
      cote: "ZOL001"
    }
  ])

  // Gestionnaire de changement pour le titre de la collection
  const handleTitreChange = (e) => {
    setTitreCollection(e.target.value)
  }

  // Gestion de l'ajout d'un nouveau livre
  const handleAjoutLivre = (nouveauLivre) => {
    setLivres(prev => [...prev, nouveauLivre])
  }

  return (
    <div>
      <DroitsUnix />
      <DoubleSaisie />
      <input
        type="text"
        value={titreCollection}
        onChange={handleTitreChange}
        placeholder="Entrez le titre de la collection"
      />
      <h1>{titreCollection}</h1>

      <FormulaireAjout onAjoutLivre={handleAjoutLivre} />

      <div className="livres">
        {livres.map(livre => (
          <Livre
            key={livre.cote}
            {...livre}
          />
        ))}
      </div>
    </div>
  )
}

export default App
