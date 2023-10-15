let double (x : int) : int = 2*x
                             
let x = double 3 ;;


let somme_2double (x : int) : int = 
  let d = double x in d + double d
                        
let x = somme_2double 3 ;; 


let make_even (x : int) : int = 
  if x mod 2 == 0 then x
  else double x
       
let x = make_even 6 ;;
let x = make_even 5 ;;


let rec sum_impairs (n : int) : int = 
  if n = 0 then 0
  else (double n)-1 + sum_impairs (n-1) 
         
let x = sum_impairs 4 ;;


let sum_impairs_inf (n : int) : int = 
  if n mod 2 == 0 then sum_impairs (n/2)
  else sum_impairs ((n-1)/2)
      
let x = sum_impairs_inf 1 ;;
let x = sum_impairs_inf 8 ;;
let x = sum_impairs_inf 9 ;;


let rec u_n (n : int) : int = 
  if n = 0 then 2
  else 3 * (u_n (n-1)) + 4
       
let x = u_n 0 ;;
let x = u_n 3 ;;


let rec sum_un (n : int) : int = 
  if n == 1 then 2
  else if n == 0 then 0 
  else  (u_n (n-1)) + sum_un (n-1)
          
let x = sum_un 0 ;;
let x = sum_un 1 ;;
let x = sum_un 3 ;;


let rec nb_un (n : int) : int = 
  if n == 0 then 0
  else if n mod 2 == 0 then nb_un (n/2)
  else 1 + nb_un (n/2)
         
let x  = nb_un 19 ;;


let rec nb_bits (n : int) : int = 
  if n == 0 then 0
  else 1 + nb_bits (n/2)

let x = nb_bits 19 ;;


let nb_max (n : int) : int = (1 lsl n) - 1

  
let x = nb_max 3 ;;
