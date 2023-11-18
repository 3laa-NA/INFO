let rec pgcd (n : int) (m : int) : int = 
  let r = n mod m in
  if r == 0 then m
  else pgcd m r
      
let x = pgcd 96 36 ;;
let x = pgcd 36 96 ;;
let x = pgcd 7 19 ;;

let rec repeat (n : int) (e : 'a) : 'a list = 
  if n == 0 then []
  else e :: repeat (n-1) e
              
let x = repeat 0 'p' ;;
let x = repeat 4 'p' ;;

let rec all_in_list (l1 : 'a list) (l2 : 'a list) : bool = 
  match l1 with
  | [] -> true
  | h :: t -> if (List.mem h l2) then all_in_list t l2
      else false
        
let x = all_in_list [] [2; -1] ;;
let x = all_in_list [-3; 8] [2; -3; -5; 8; -1] ;;
let x = all_in_list [4; 8] [] ;;
let x = all_in_list [-3; 4; 8] [2; -3; -5; 8; -1] ;;


let rec range_inter (a : int) (b : int) : int list =
  if a > b then []
  else a :: range_inter (a + 1) b

let x = range_inter 7 2;;
let x = range_inter 2 7;;
let x = range_inter 2 2;;


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
