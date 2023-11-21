(*---------------------------OLD-------------------------------*)

let rec all_in_list (l1 : 'a list) (l2 : 'a list) : bool = 
  match l1 with
  | [] -> true
  | h :: t -> if (List.mem h l2) then all_in_list t l2
      else false
        
let x = all_in_list [] [2; -1] ;;
let x = all_in_list [-3; 8] [2; -3; -5; 8; -1] ;;
let x = all_in_list [4; 8] [] ;;
let x = all_in_list [-3; 4; 8] [2; -3; -5; 8; -1] ;;


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


let x = is_prefix [] [1;2;3] ;;
let x = is_prefix [1;2] [1;2;3;4;5] ;;
let x = is_prefix [1;2] [1;2] ;;
let x = is_prefix [2;3] [1;2;3] ;;
let x = is_prefix [1;2;3] [1;2] ;;


let rec prefixes(l:'a list):'a list list =
  match l with
  | [] -> [[]]
  | h::t -> []::(map_cons h (prefixes t));;


let x = prefixes [] ;;
let x = prefixes ['x'] ;;
let x = prefixes ['h'; 'o'; 'u'; 'x'] ;;
let x = prefixes ['c'; 'h'; 'o'; 'u'; 'x'] ;;


let all_prefix_in (l1 : 'a list) (l2 : 'a list list) : bool = all_in_list (prefixes l1) l2

let x = all_prefix_in [1;0;0] [[];[0];[0;1];[1];[1;0];[1;0;0];[1;1];[1;1;0];[1;1;1]] ;;
let x = all_prefix_in [1;0;0] [[];[0];[0;1];[1];[1;0;0];[1;1];[1;1;0];[1;1;1]] ;;


(*----------------------------NEW------------------------------*)


let pref_complete (l : ('a list) list) : bool = List.for_all (fun x -> all_prefix_in x l ) l
    
let x = (pref_complete [[];[0];[0;1];[1];[1;0];[1;0;0];[1;1];[1;1;0];[1;1;1]]);;
let x = (pref_complete [[];[0];[0;1];[1];[1;0;0];[1;1];[1;1;0];[1;1;1]]);;

let is_max_pref2 (l1 : 'b list) (l2 : ('a * ('b list)) list) : bool = List.for_all (fun (x,c) -> if (is_prefix l1 c) then (l1=c) else true) l2
    
let x = (is_max_pref2 [0;1]
           [('a',[]);('b',[0]);('c',[0;1]);('d',[1]);('e',[1; 0]);
            ('f',[1;0;0]);('g',[1;1]);('h',[1;1;0]);('i',[1;1;1])]);;
let x =(is_max_pref2 [1;0]
          [('a',[]);('b',[0]);('c',[0;1]);('d',[1]);('e',[1; 0]);
           ('f',[1;0;0]);('g',[1;1]);('h',[1;1;0]);('i',[1;1;1])]);;

let max_pref_list2 (l : ('a * ('b list)) list) : ('a * ('b list)) list = List.filter (fun (x,c) -> is_max_pref2 c l) l
    
let x = (max_pref_list2
           [('a',[]);('b',[0]);('c',[0;1]);('d',[1]);('e',[1; 0]);
            ('f',[1;0;0]);('g',[1;1]);('h',[1;1;0]);('i',[1;1;1])]);;


(*---------------------------OLD-------------------------------*)


    
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
  

(*-----------------------------NEW-----------------------------*) 

let tree1 = Node('a', Node('b',
                           Empty,
                           Node('c',Empty,Empty)),
                 Node('d',
                      Node('e',Node('f',
                                    Empty,Empty),
                           Empty),
                      Node('g',Node('h',
                                    Empty,Empty),
                           Node('i',Empty,Empty))))



let rec at_path (t:'a btree) (c:int list) : 'a = 
  match t,c with
  |Empty,_ -> raise (Invalid_argument "at_path")
  |Node (e,_,_),[] -> e
  |Node (e,g,d),h::t -> if h=0 then at_path g t
      else if h=1 then at_path d t
      else raise (Invalid_argument "at_path")

let x = at_path tree1 [];;
let x = at_path tree1 [1;0];;
let x = at_path tree1 [0;0];;
let x = at_path tree1 [2;0];;

let paths_tree (t : 'a btree) : ('a * (int list)) list =
  let rec f (t : 'a btree) : int list list =
    match t with
    |Empty -> []
    |Node (e,g,d) -> [[]] @ (map_cons 0 (f g)) @ (map_cons 1 (f d))
  in List.map (fun l -> ((at_path t l),l)) (f t)
    
let x = paths_tree tree1;;


let is_tree (l : (int list) list) : bool = pref_complete l
    
let x = is_tree (List.map snd (paths_tree tree1));;
let x  = is_tree [[]; [1]; [1; 0]; [1; 0; 1; 1]];;

let leaves_list (l : ('a * (int list)) list) : 'a list = List.map (fun (c,ch) -> if (is_max_pref2 ch l) then c ) l
  
  
let x = leaves_list (paths_tree tree1);;
