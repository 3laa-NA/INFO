function date8Chiffres(){
    var d = new Date();
    m = d.getMonth()+1;
    j = d.getDate();
    a = d.getFullYear();

    return a + ((m <= 9) ? '0' : '') + m + ((j <= 9) ? '0' : '') + j; 
}