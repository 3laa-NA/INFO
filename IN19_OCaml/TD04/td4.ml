type 'a btree = Empty | Node of 'a * 'a btree * 'a btree
let t_ex = Node(5,Node(3,
                       Node(4,Empty,Empty),
                       Node(5,Empty,Empty)),
                Node(2,
                     Node(3,
                          Empty,
                          Node(7,Empty,Empty)),
                     Empty));;                      
           

let rec size (t:'a btree) : int =
  match t with
  |Empty -> 0
  |Node (_,g,d) -> 1 + (size g) + (size d)
                             
let x = size Empty;;
let x = size t_ex;;

let rec max_length_branch (t:'a btree): 'a list =
  match t with
  |Empty -> []
  |Node (e,g,d) -> if (List.length (e::max_length_branch g)) >= (List.length (e::max_length_branch d)) then
        e::max_length_branch g else e::max_length_branch d
                                     
let x = max_length_branch t_ex;;

let rec max_length_branch2 (t:'a btree): 'a list =
  let rec f (t:'a btree) : 'a list * int =
    match t with
    |Empty -> ([],0)
    |Node (e,g,d) -> let (l1,n1) = (f g) and (l2,n2) = (f d) in
        if n1 >= n2 then (e::l1,n1+1) else (e::l2,n2+1) in
  let (li,len) = f t in li
 
                                     
let x = max_length_branch2 t_ex;;


let rec max_flow_branch (t:'a btree):'a list =
  match t with
  |Empty -> []
  |Node (e,g,d) ->
      if g=Empty && d=Empty then [e]
      else if g=Empty then e::max_flow_branch d
      else if d=Empty then e::max_flow_branch g
      else let Node (e1,_,_) = g and Node (e2,_,_) = d in
        if e1>=e2 then e::max_flow_branch g
        else e::max_flow_branch d
               
let x = max_flow_branch t_ex;;
 

let rec at_prof (n:int) (x:'a) (t:'a btree) : bool =
  match n,t with
  |_,Empty -> false
  |0,Node (e,g,d) -> e=x
  |_,Node (e,g,d) -> (at_prof (n-1) x g) || (at_prof (n-1) x d)
                                         
let x = at_prof 0 5 t_ex;;
let x = at_prof 2 5 t_ex;;
let x = at_prof 1 5 t_ex;;

let rec at_prof_list (n:int) (t:'a btree) : 'a list =
  match n,t with
  |_,Empty -> []
  |0,Node (e,g,d) -> [e]
  |_,Node (e,g,d) -> (at_prof_list (n-1) g) @ (at_prof_list (n-1) d)
                                             
let x = at_prof_list 2 t_ex;;


let rec etiq_prof_list (x:'a) (t:'a btree) : int list =
  match t with
  |Empty -> []
  |Node (e,g,d) -> let li = List.map (fun el -> el+1) ((etiq_prof_list x g) @ (etiq_prof_list x d)) in
      if e=x then 0::li
      else li
       
let x = etiq_prof_list 3 t_ex;;
 
 
let rec prof_max (t:'a btree) : int = List.length(max_length_branch t) - 1
 
let x = prof_max t_ex;;


let max_prof_etiq (x:'a) (t:'a btree) : int = 
  List.fold_left max (-1) (etiq_prof_list x t)
                                               
let x = max_prof_etiq 5 t_ex;;
let x = max_prof_etiq 7 t_ex;;
let x = max_prof_etiq 9 t_ex;;
 

type value = B of bool | I of int

exception TYPE_ERROR of int        

let not1 (v:value) : value =
  match v with
  | B b -> B (not b)
  | I n -> raise (TYPE_ERROR n)

let x = not1 (B true);;
let x = not1 (I 4);;

let not2 (v:value) : value =
  match v with
  |I n -> not1 (B (n<>0))
  |B b -> not1 (B b)

let x = not2 (B true);;
let x = not2 (I 4);;
let x = not2 (I 0);;


exception DIV_BY_0 of int
    
let div1 (v1:value) (v2:value) : value = 
  match v1,v2 with
  |(B b),_ -> raise (Invalid_argument "div")
  |_,(B b) -> raise (Invalid_argument "div")
  |(I n1),(I n2) -> if n2=0 then raise (DIV_BY_0 n1)
      else (I (n1/n2))
           
let x = div1 (I 6) (I 3);;
let x = div1 (I 6) (I 0);;
let x = div1 (B false) (I 4);;
let x = div1 (B false) (I 0);;

let div2 (v1:value) (v2:value) : value option = 
  try
    match div1 v1 v2 with
    | I result -> Some (I result)
    | _ -> None 
  with
  | DIV_BY_0 _ -> None
  | Invalid_argument x -> raise (Invalid_argument x)
  
let x = div2 (I 6) (I 3);;
let x = div2 (I 6) (I 0);;
let x = div2 (B false) (I 4);;
let x = div2 (B false) (I 0);;