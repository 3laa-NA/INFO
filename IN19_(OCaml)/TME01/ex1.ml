let rec sum_chiffres (n : int) : int = 
  if n/10=0 then
    n 
  else
    n-((n/10)*10)+(sum_chiffres(n/10)) 
                  
let x=sum_chiffres(125);; 

let rec nb_chiffres (n : int) : int = 
  if n/10=0 then
    1 
  
  else if n-((n/10)*10) > 0 then 
    1+ (nb_chiffres(n/10))
  
  else
    (nb_chiffres(n/10))
    
let x=nb_chiffres(125);;

let rec less_divider (i : int) (n : int) : int =
  if i = n then 0 
    
  else if n mod i = 0 then i
    
  else (less_divider (i+1) (n) )
       
let x=less_divider 2 19;;
let y=less_divider 5 21;;
let z=less_divider 7 21;;
let t=less_divider 9 21;;
    
    
let prime (n : int) : bool = 
  if n=1 then false
    
  else if (less_divider 2 n) = 0 then true
    
  else false
    
let x= prime(1);;
let y= prime(21);;
let z= prime(19);;

let rec next_prime (n : int) : int =
  if prime(n) then n
    
  else next_prime(n+1)
      
let x=(next_prime 0);;
let y=(next_prime 15);;
let z=(next_prime 11);;

let rec nth_prime (n : int) : int =
  if n = 0 then 2
    
  else next_prime (nth_prime (n-1)+1)
      

let x=nth_prime (0);;
let y=nth_prime (2);;
let z=nth_prime (12);;
let t=nth_prime (1);;
let l=nth_prime (3);;

let y=6;;

let foo(x : int) : int = x+y
                         
let i=foo(4);;
                         
let y=18;;

let j=foo(4);;