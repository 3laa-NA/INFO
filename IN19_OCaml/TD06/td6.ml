let sum_impairs (n : int) : int =
  let rec aux x acc =
    if x = 0 then acc
    else aux (x-1) acc +(2*x-1) 
  in aux n 0

let x = sum_impairs 4;;


let iter_f (n : int) (f : 'a -> 'a) (x : 'a) : 'a =
  let rec aux x acc =
    if x=0 then acc
    else aux (x-1) (f acc)
  in aux n x

let x = iter_f 5 (fun x -> x+1) 0;;


let rec rev_append (l1 : 'a list) (l2 : 'a list) : 'a list =
  let rec aux x acc =
    match x with
    |[] -> acc
    |h::t -> aux t (h::acc)
  in aux l1 l2
  
             
let x = rev_append [1;2] [3;4;5;6];;


let rec rev (l : 'a list) : 'a list =
  let rec aux x acc =
    match x with
    |[] -> acc
    |h::t -> aux t (h::acc)
  in aux l []
                     
let x = rev [1;2;3;4;5];;

let rec append (l1 : 'a list) (l2 : 'a list) : 'a list =
  let rec aux x acc =
    match rev x with
    |[] -> acc
    |h::t -> aux t (h::acc)
  in aux l1 l2

let x = append [1;2] [3;4;5;6];;

let rec map (f : 'a -> 'b) (l : 'a list) : 'b list = 
  let rec aux x acc =
    match x with
    |[] -> acc
    |h::t -> aux t ((f h)::acc)
  in aux (rev l) []
                    
let x = map (fun x -> x+1) [0;1;2;3;4;5];;


let filter (f : 'a -> bool) (l : 'a list) : 'a list = 
  let rec aux x acc = 
    match x with 
    |[] -> acc
    |h::t -> if (f h) then aux t (h::acc)
        else aux t acc
  in aux (rev l) []
  
                                   
let x = filter (fun x -> x<4) [0;1;2;3;4;5];;


let rec partition (f : 'a -> bool) (l : 'a list) : 'a list * 'a list =
  let rec aux x acc1 acc2 =
    match x with
    |[] -> (acc1,acc2)
    |h::t -> if (f h) then aux t (h::acc1) acc2
        else aux t acc1 (h::acc2)
  in aux (rev l) [] []
    
let x = partition (fun x -> x mod 2 = 0) [0; 1; 2; 3; 4; 5; 6; 7; 8];;
  

let fold_right (f : 'a -> 'b -> 'b) (l : 'a list) (b : 'b) : 'b =
  let rec aux x acc =
    match x with 
    |[] -> acc
    |h::t -> aux t (f h acc)
  in aux (rev l) b
    
let x = fold_right (fun x acc -> (x+1)::acc) [0; 1; 2; 3; 4; 5; 6; 7; 8] [10]
in x = List.fold_right (fun x acc -> (x+1)::acc) [0; 1; 2; 3; 4; 5; 6; 7; 8] [10];;
  
  
type 'a btree = Empty | Node of 'a * 'a btree * 'a btree
                                  
let t_ex = Node(5,Node(3,
                       Node(4,Empty,Empty),
                       Node(5,Empty,Empty)),
                Node(2,
                     Node(3,
                          Empty,
                          Node(7,Empty,Empty)),
                     Empty));;


let post_travers (bt : 'a btree) : 'a list =
  let rec aux x acc =
    match x with 
    |Empty -> []
    |Node(e,g,d) -> (aux g acc)@(aux d acc)@[e]
  in aux bt []
    
let x = post_travers t_ex;;
  

let pref_travers (bt : 'a btree) : 'a list =
  let rec aux x acc =
    match x with 
    |Empty -> []
    |Node(e,g,d) -> [e]@(aux g acc)@(aux d acc)
  in aux bt []

let x = pref_travers t_ex;;
  
  
let inf_travers (bt : 'a btree) : 'a list =
  let rec aux x acc =
    match x with 
    |Empty -> []
    |Node(e,g,d) -> (aux g acc)@[e]@(aux d acc)
  in aux bt []

let x = inf_travers t_ex;