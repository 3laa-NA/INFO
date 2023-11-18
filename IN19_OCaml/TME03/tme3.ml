let rec is_in (e: 'a) (l : 'a list) : bool =
  match l with 
  | [] -> false
  | h :: t -> if h == e then true
      else is_in e t
          
let x = is_in 4 [];;
let x = is_in 3 [1;3;2];;
let x = is_in 4 [1;3;2];;


let add_elem (e : 'a) (l : 'a list) : 'a list =
  if (is_in e l) then l
  else e::l
       
let x = add_elem 4 [1;3;2];;
let x = add_elem 4 [1;3;4;2];;
let x = add_elem 4 [];;

let rec is_subset_rec (l1 : 'a list) (l2 : 'a list) : bool =
  match l1 with
  | [] -> true
  | h :: t -> if (is_in h l2) == false then false
      else is_subset_rec t l2
          
let x = is_subset_rec [4;2] [0;2;4;6] ;;
let x = is_subset_rec [] [0;2;4;6] ;;
let x = is_subset_rec [2;3;4] [0;2;4;6] ;;
let x = is_subset_rec [4;2;0;6] [0;2;4;6] ;;



let is_subset (l1 : 'a list) (l2 : 'a list) : bool = List.for_all (fun x -> is_in x l2) l1
    
let x = is_subset [4;2] [0;2;4;6] ;;
let x = is_subset [] [0;2;4;6] ;;
let x = is_subset [2;3;4] [0;2;4;6] ;;
let x = is_subset [4;2;0;6] [0;2;4;6] ;;


let eq_set (l1: 'a list) (l2: 'a list) : bool = (is_subset l1 l2) && (is_subset l2 l1)

let x = eq_set [4;2] [0;2;4;6] ;;
let x = eq_set [4;2;6;0] [0;2;5;6] ;;
let x = eq_set [4;2;6;0] [0;2;4;6] ;;
let x = eq_set [] [] ;;

let rec intersection_rec (l1 : 'a list) (l2 : 'a list) : 'a list = 
  match l1 with
  | [] -> []
  | h :: t -> if is_in h l2 then h :: intersection_rec t l2
      else intersection_rec t l2

let x = intersection_rec [] [3;5;4;6] ;;
let x = intersection_rec [1;2;3;4] [] ;;
let x = intersection_rec [1;2;3;4] [3;5;4;6] ;;


let intersection (l1 : 'a list) (l2 : 'a list) : 'a list = List.filter (fun x -> is_in x l2) l1

let x = intersection [] [3;5;4;6] ;;
let x = intersection [1;2;3;4] [] ;;
let x = intersection [1;2;3;4] [3;5;4;6] ;;

let rec union_rec (l1 : 'a list) (l2 : 'a list) : 'a list = 
  match l1 with 
  | h :: t -> add_elem h (union_rec t l2)
  | [] ->  match l2 with 
    | h :: t -> add_elem h (union_rec l1 t)
    | [] -> []
            
let x = union_rec [1;2;3;4] [3;5;4;6] ;;
let x = union_rec [] [3;5;4;6] ;;


let union_left (l1 : 'a list) (l2 : 'a list) : 'a list =  List.fold_left (fun l x -> add_elem x l) l1 l2

let x = union_left [1;2;3;4] [3;5;4;6] ;;
let x = union_left [] [3;5;4;6] ;;

let union_right (l1 : 'a list) (l2 : 'a list) : 'a list =  List.fold_right (fun x l -> add_elem x l) l1 l2

let x = union_right [1;2;3;4] [3;5;4;6] ;;
let x = union_right [] [3;5;4;6] ;;


let make_pairs (x : 'a) (l : 'b list) : ('a * 'b) list = List.map (fun e -> (x,e)) l
    
let x = make_pairs true [3;5] ;;
let x = make_pairs 1 [] ;;


let rec product_rec (l1 : 'a list) (l2 : 'b list) : ('a * 'b) list = 
  match l1 with
  | [] -> []
  | h :: t -> (make_pairs h l2) @ product_rec t l2
                
let x = product_rec [1;2;3] [] ;;
let x = product_rec [] [1;2;3] ;;
let x = product_rec [1;2;3] ['a';'b'] ;;

let product (l1 : 'a list) (l2 : 'b list) : ('a * 'b) list = List.flatten (List.map (fun e -> make_pairs e l2) l1)

let x = product [1;2;3] [] ;;
let x = product [] [1;2;3] ;;
let x = product [1;2;3] ['a';'b'] ;;

let rec powerset_rec (l : 'a list) : 'a list list = 
  match l with
  | [] -> [[]] 
  | h :: t -> (powerset_rec t ) @ (List.map (fun sub -> h :: sub) (powerset_rec t ))
                
let x = powerset_rec [] ;;
let x = powerset_rec [1;2;3] ;;


let powerset (l : 'a list) : 'a list list = List.fold_left (fun subs e -> subs @ List.map (fun sub -> e :: sub) subs ) [[]] l
  
    
let x = powerset [] ;;
let x = powerset [1;2;3] ;;
