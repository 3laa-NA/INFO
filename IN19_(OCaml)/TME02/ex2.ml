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
  

let rec comp_bin (l : int list) (n : int) : int list =
  if List.length l > n then raise (Invalid_argument "comp_bin")
  else if List.length l == n then l
  else comp_bin (l @ [0]) (n)
      
let x = comp_bin [1; 0] 2;;
let x = comp_bin [1; 0] 4;;
let x = comp_bin [0; 1; 1] 2;;

let rec range_inter (a : int) (b : int) : int list =
  if a > b then []
  else a :: range_inter (a + 1) b

let x = range_inter 1 5;;
let x = range_inter 3 3;;
    
let genere_list (n : int) : int list =
  if 2 > n then []
  else range_inter 2 n
      
let x =genere_list 1;;
let x =genere_list 4;;

let rec elimine (l : int list) (n : int) : int list = 
  match l with
  |[] -> []
  | x :: xs -> if x mod n == 0 then elimine xs n
      else x :: elimine xs n
             
let x = elimine [1; 2; 3; 4; 5; 6] 3;;

let rec ecreme (l : int list) : int list =
  match l with
  |[] -> []
  | x :: xs -> x :: ecreme (elimine xs x)
                 
let x = ecreme [2; 3; 4; 5; 6; 7; 8; 9; 10; 11; 12];;
  
let crible (n : int) : int list = ecreme (genere_list n)
  
let x = (crible 1);;
let x = (crible 20);;