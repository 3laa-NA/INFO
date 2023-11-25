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


let rec decode1 (l : int list) (t : 'a htree) : ('a * (int list)) = 
  
  let list_decode = List.map (fun (x,y) -> (y,x)) (huff_tab t) in
  
  let rec f (l1 : int list) (l2 : int list) : ((int list) * (int list)) = 
    match l2 with
    |h::t -> if List.assoc l1 list_decode then (l1,l2)
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