type 'a btree = Empty | Node of 'a * 'a btree * 'a btree

let rec lt_btree (t:'a btree) (x:'a) : bool =
  match t with
  |Empty -> true
  |Node (e,g,d) -> if e>=x then false 
      else (lt_btree g x) && (lt_btree d x)
  

let x = lt_btree (Node (2, Node (4, Empty, Empty), Empty)) 5;;
let x = lt_btree (Node (4, Node (6, Empty, Empty), Empty)) 5;;
let x = lt_btree Empty 5;;

let rec ge_btree (t:'a btree) (x:'a) : bool =
  match t with
  |Empty -> true
  |Node (e,g,d) -> if e<x then false 
      else (ge_btree g x) && (ge_btree d x)
  

let x = ge_btree (Node (4, Node (5, Empty, Empty), Empty)) 4;;
let x = ge_btree (Node (4, Node (3, Empty, Empty), Empty)) 4;;
let x = ge_btree Empty 5;;

let rec is_abr (bt:'a btree) : bool =
  match bt with
  |Empty -> true
  |Node (e,g,d) -> ( (lt_btree g e) && (ge_btree d e) ) && ( (is_abr g) && (is_abr d) )

let x = is_abr Empty;;
let x = is_abr (Node (5, Node (2, Node (1, Empty, Empty),
                               Node (4, Empty, Empty)),
                      Node (6, Empty, Node (7, Empty, Empty)))) 
let x = is_abr (Node (5, Node (2, Node (1, Empty, Empty),
                               Node (4, Empty, Empty)),
                      Node (3, Empty, Node (7, Empty, Empty))));;
let x = is_abr (Node (5, Node (2, Node (1, Empty, Empty),
                               Node (4, Empty, Empty)),
                      Node (7, Empty, Node (6, Empty, Empty))));;


let rec mem (bt: 'a btree) (x:'a) : bool =
  match bt with
  |Empty -> false
  |Node (e,g,d) -> if e=x then true 
      else if e>x then (mem g x) else (mem d x)
                                      
let x = mem Empty 4;;
let x = mem (Node (5, Node (2, Node (1, Empty, Empty),
                            Node (4, Empty, Empty)),
                   Node (6, Empty, Node (7, Empty, Empty)))) 4;;
let x = mem (Node (5, Node (2, Node (1, Empty, Empty),
                            Node (4, Empty, Empty)),
                   Node (6, Empty, Node (7, Empty, Empty)))) 8;;

let rec insert (bt:'a btree) (x:'a) : 'a btree = 
  match bt with
  |Empty -> Node (x,Empty,Empty)
  |Node (e,g,d) -> if e>x then Node (e,(insert g x),d)
      else Node (e,g,(insert d x))

let x = insert Empty 4;;
let x = insert (Node (5, Node (2, Node (1, Empty, Empty),
                               Node (4, Empty, Empty)),
                      Node (6, Empty, Node (7, Empty, Empty)))) 3;;
let x = insert (Node (5, Node (2, Node (1, Empty, Empty),
                               Node (4, Empty, Empty)),
                      Node (6, Empty, Node (7, Empty, Empty)))) 4;;


let abr_of_list (l:'a list) : 'a btree = List.fold_left insert Empty l
    
let x = abr_of_list [3;1;2;5;31;2;42;18;2];;


let rec list_of_abr (bt:'a btree) : 'a list =
  match bt with
  |Empty -> []
  |Node (e,g,d) -> (list_of_abr g) @ [e] @ (list_of_abr d)
                                           
let x = list_of_abr (Node(3,Node (1, Empty,
                                  Node (2, Empty,
                                        Node (2, Empty, Node (2, Empty, Empty)))),
                          Node(5, Empty, Node (31, Node (18, Empty, Empty),
                                               Node (42, Empty, Empty)))));;

let abr_sort (l:'a list) : 'a list =
  list_of_abr (abr_of_list l)

let x = abr_sort [12;3;5;42;1;18;21];;