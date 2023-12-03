(*-------------------------TD02----------------------------*)

let rec bin_to_int (i : int list) : int = 
  match i with
  | [] -> raise (Invalid_argument "empty list")
  | x :: [] -> x
  | (x::xs) -> x + ( 2 *(bin_to_int xs) )
    
let x=bin_to_int [];;
let x=bin_to_int [0; 1; 1];;
let x=bin_to_int [1];;
let x=bin_to_int [1; 1; 0; 1; 0; 1];;

let rec int_to_bin (i : int) : int list =
  if i=1 || i=0 then [i]
  else (i mod 2) :: ( int_to_bin (i/2) )
                                   
let x = int_to_bin 0;;
let y = int_to_bin 6;;
let z = int_to_bin 1;;
let w = int_to_bin 43;;
  

(*-------------------------NEW----------------------------*)

type int_set =
  | N of int_set * int_set
  | E of bool
let ex =
  N(N(E true,
      E true),
    N(E false,
      E true))
exception Not_perfect
exception No_fit
  
let rec hauteur_equilibre (t: int_set): int =
  match t with 
  |E b -> 0
  |N(g,d) -> if (hauteur_equilibre g) <> (hauteur_equilibre d) then raise (Not_perfect)
      else (hauteur_equilibre g)+1
  
           
let x = hauteur_equilibre ex;;
let x = hauteur_equilibre (N(N(E true,E true),E false));;

let mem (x: int) (t: int_set): bool =
  let rec aux (bin: int list) (tr: int_set): bool =
    match bin,tr with
    |[],E b -> b
    |[],N(g,d) -> aux [] g
    |h::t,E b -> false
    |h::t,N(g,d) -> if h==0 then aux t g else aux t d
  in aux (int_to_bin x) t

let x = mem 2 ex;;
let x = mem 1 ex;;


let insert_exn (t: int_set) (x: int):int_set = 
  let rec aux (bin: int list) (tr: int_set): int_set =
    match bin,tr with
    |[],E b -> E true
    |[],N(g,d) -> N(aux [] g,d)
    |h::t,E b -> raise (No_fit)
    |h::t,N(g,d) -> if h==0 then N(aux t g,d) else N(g,aux t d)
  in aux (int_to_bin x) t
    
let x = insert_exn ex 1;;
let x = insert_exn ex 25;;
    
let rec increase_height (t: int_set) : int_set =
  match t with
  |E b -> N(E b,E false)
  |N(g,d) -> N(increase_height g, increase_height d)
               
let x = increase_height ex;;

let rec insert (x: int) (t: int_set) : int_set =
  try insert_exn t x with
  |No_fit -> insert x (increase_height t)

let x = insert 5 ex;;
let x = insert 1 ex;;
let x = insert 3 (E false);;


let rec list_to_tree (l: int list) : int_set =
  match l with
  |[] -> E false
  |h::t -> insert h (list_to_tree t)

let x = list_to_tree [];;
let x = list_to_tree [0;2;3];;


let rec path_list (t : int_set) : ((int list) * bool) list =
  match t with 
  |E b -> [([], b)]
  |N(g,d) -> ( List.map (fun (l,b) -> (0::l,b)) (path_list g) ) @ ( List.map (fun (l,b) -> (1::l,b)) (path_list d) )
                                                                  
let x = path_list ex;;


let tree_to_list (t : int_set) : int list = 
  List.map (fun (l,b) -> (bin_to_int l)) (List.filter (fun (l,b) -> b) (path_list t))

let x = tree_to_list ex;;

