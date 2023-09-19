let rec sum_chiffres (n : int) : int = 
  if n/10=0 then
    n 
  else
    n-((n/10)*10)+(sum_chiffres(n/10)) 
                  
let x=sum_chiffres(125);; 
