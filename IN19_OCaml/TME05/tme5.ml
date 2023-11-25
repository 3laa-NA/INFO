type 'a htree =
  | Leaf of int * 'a
  | Branch of int * 'a htree * 'a htree

                
let t_msg = Branch(17,
                   Leaf(8,'A'),
                   Branch(9,
                          Branch(4,
                                 Branch(2,
                                        Leaf(1,'C'),
                                        Leaf(1,'G')),
                                 Branch(2,
                                        Leaf(1,'H'),
                                        Leaf(1,'F'))),
                          Branch(5,
                                 Branch(2,
                                        Leaf(1,'E'),
                                        Leaf(1,'D')),
                                 Leaf(3,'B'))))
    

let rec huff_tab (t:'a htree) : ('a * (int list)) list = 
  match t with 
  |Leaf(_,c) -> [(c,[])]
  |Branch(e,g,d) -> ( List.map (fun (c,l) -> (c,0::l)) (huff_tab g) ) @ ( List.map (fun (c,l) -> (c,1::l)) (huff_tab d) )
                                                                        
let x = huff_tab t_msg;;

let rec code (m : 'a list) (c : ('a * (int list)) list) : int list = 
  match m with
  |[] -> []
  |h::t -> (List.assoc h c) @ (code t c)


let lc_msg = huff_tab t_msg in let msg = ['A';'A';'B';'A';'C';'B';'A';'G';'H';'A';'A';'F';'E';'A';'D';'B';'A'] in 
code msg lc_msg;;


let decode1 (l : int list) (t : 'a htree) : ('a * (int list)) = 
  
  let list_decode = List.map (fun (x,y) -> (y,x)) (huff_tab t) in
  
  let rec f (l1 : int list) (l2 : int list) : ((int list) * (int list)) = 
    match l2 with
    |[] -> (l1,[])
    |h::t -> if List.mem_assoc l1 list_decode then (l1, l2) 
        else f (l1@[h]) t in 
  
  let (frst,rest) = f [] l in
  
  ((List.assoc frst list_decode) , rest)
  
  
let x = decode1 [0; 0; 1; 1; 1] t_msg;;


let rec decode (l : int list) (t : 'a htree) : 'a list = 
  match l with
  |[] -> []
  |_ -> let (msg,code) = decode1 l t in
      [msg]@decode code t
          
let x = decode [0;0;1;1;1;0;1;0;0;0;1;1;1;0;1;0;0;1;1;0;1;0;0;0;1;0;1;1;1;1;0;0;0;1;1;0;1;1;1;1;0] t_msg;;


let freq_ht (t : 'a htree) : int = 
  match t with
  |Leaf (i,_) -> i
  |Branch (i,_,_) -> i
    
let x = freq_ht (Leaf(3,'B'));;
let x = freq_ht (Branch(5,Leaf(2,'Z'),Leaf(3,'B')));;


let ht_less (t1 : 'a htree) (t2 : 'a htree) : bool = (freq_ht t1) < (freq_ht t2)

let x = ht_less (Leaf(3,'B')) (Branch(5,Leaf(2,'Z'),Leaf(3,'B')));;
let x = ht_less (Branch(5,Leaf(2,'Z'),Leaf(3,'B'))) (Leaf(3,'B'));;


let rec min_sauf_min (lt : ('a htree) list) : ('a htree) * (('a htree) list) =
  match lt with
  |[t] -> (t,[])
  |h::t -> let (min,li) = min_sauf_min t in
      if (ht_less h min) then (h,min::li)
      else (min,h::li)
           
let x = min_sauf_min [Branch(5,Leaf(2,'Z'),Leaf(3,'W')); Leaf(3,'B'); Leaf(3,'K')];;


let ht_branch (t1:'a htree) (t2:'a htree):'a htree = Branch ((freq_ht t1)+(freq_ht t2),t1,t2)
  
let x = ht_branch (Branch(5, Leaf(2, 'Z'), Leaf(3, 'W'))) (Leaf(3, 'B'));;


let rec make_huff (lt:('a htree) list):'a htree = 
  if (List.length lt) > 2 then
    let (min1,l1) = (min_sauf_min lt) in
    let (min2,l2) = (min_sauf_min l1) in
    make_huff ([(ht_branch min1 min2)]@l2)
    
  else let (min, h::_) = (min_sauf_min lt) in 
    ht_branch min h
      
let x = make_huff [Leaf (8,'A'); Leaf (3,'B'); Leaf (1,'D'); Leaf (1,'E'); Leaf (1,'F'); Leaf (1,'H'); Leaf (1,'G'); Leaf (1,'C')];;


let leaf_list (f : ('a * int) list) : ('a htree) list = List.map (fun (c,i) -> Leaf(i,c)) f

let x = leaf_list [('A', 8); ('B', 3); ('D', 1); ('E', 1); ('F', 1); ('H', 1); ('G', 1);('C', 1)];;


let  huff_of_freq (f : ('a * int) list) : 'a htree = make_huff (leaf_list f)

let x= huff_of_freq [('A',8); ('B',3); ('D',1); ('E',1); ('F',1); ('H',1); ('G',1); ('C',1)];;


(*-------------------------TD3---------------------------*)


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


(*------------------------------------------------------*)


let make_code (m : 'a list) : (int list) * 'a htree = 
  let t = huff_of_freq (freq m) in
  let c = code m (huff_tab t) in
  (c,t)
  
let x = make_code ['A';'A';'B';'A';'C';'B';'A';'G';'H';'A';'A';'F';'E';'A';'D';'B';'A'];; 


