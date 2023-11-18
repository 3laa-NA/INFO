let rec add_freq (c : 'a) (l : ('a*int) list) : ('a*int) list =
  match l with
  | [] -> [(c,1)]
  | (x,y) :: t -> if x=c then (x,y+1) :: t
      else (x,y) :: add_freq c t
             

let x = (add_freq 'A' []);;            
let x = (add_freq 'A' [('D',1); ('E',1); ('A',5); ('B',3); ('C',1)]) ;;
let x = (add_freq 'H' [('D',1); ('E',1); ('A',5); ('B',3); ('C',1)]) ;;


let rec freq (l : 'a list) : ('a * int) list =
  match l with
  |[] -> []
  |h :: t -> add_freq h (freq t)
               
let x = freq ['A';'A';'B';'A';'C';'B';'A';'G';'H';'A';'A';'F';'E';'A';'D';'B';'A'];;

let add_fst (c : (int * int)) : (int * int) =
  match c with
  | (x,y) -> (x+1,y)
             
let add_snd (c : (int * int)) : (int * int) =
  match c with
  | (x,y) -> (x,y+1)
                                             
let rec nb_of (l : char list) : int * int =
  match l with
  |[] -> (0,0)
  |h :: t -> if h = '<' then add_fst(nb_of t)
      else add_snd(nb_of t)
 
         
let x = (nb_of []);;
let x = (nb_of ['<';'<';'>';'<';'>';'>';'<']);;

let o_sup_f (l : char list) : bool =
  match nb_of(l) with
  |(x,y) -> x >=y
           
let x = (o_sup_f ['<';'<';'>';'<';'>';'>';'<']);;
let x = (o_sup_f ['<';'>';'<';'>';'>']);;
let x = (o_sup_f ['<';'<';'>';'>']);;


 
let all_o_sup_f (l : (char list) list) : bool = List.for_all (o_sup_f) l
   
let x = (all_o_sup_f []);;
let x = (all_o_sup_f [['<';'<';'>';'>']; ['<';'<';'>';'<';'>';'>';'<']]);;
let x = (all_o_sup_f [['<';'<';'>';'>']; ['<';'>';'<';'>';'>']]);;


let rec map_cons(e:'a)(l:'a list list):'a list list=
  match l with
  |[]->[]
  |h::t -> (e::h)::map_cons e t;;


let x = map_cons 3 [];;
let x = map_cons 'x' [ [] ];;
let x = map_cons true [ [true; false; false]; [false; true]; [] ];;

let rec is_prefix(l1:'a list)(l2:'a list):bool=
  match (l1,l2) with
  |([],_)->true
  |(_,[])->false
  |(h::t,x::y)->if (h=x) then is_prefix t y else false;;


let x = is_prefix [1;2] [1;2;3;4;5];;

let rec prefixes(l:'a list):'a list list =
  match l with
  | [] -> [[]]
  | h::t -> []::(map_cons h (prefixes t));;


let x = prefixes [];;
let x = prefixes ['x'];;
let x = prefixes ['h'; 'o'; 'u'; 'x'];;
let x = prefixes ['c'; 'h'; 'o'; 'u'; 'x'];;
 
let dyck (l : char list) : bool = all_o_sup_f (prefixes l)
   
let x = dyck ['<';'<';'>';'<';'>';'>';'<';'>'];;
let x = dyck ['<';'>';'<';'>';'>';'<'];;
let x = dyck ['<';'>';'<';'>';'<'];;


let sum_left (l : int list) : int = List.fold_left (fun x y -> x+y) 0 l

let x = sum_left [3; 7; 2] ;;
let x = sum_left [-5; 10; -2; 1] ;;
let x = sum_left [] ;;
