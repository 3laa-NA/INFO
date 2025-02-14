function saisieIncorrecte(input, re){
    var t = re ? re.test(input.value) : true ;
    input.style.border = t ? "1px solid" : "2px dashed red";

    return t? false : input;
}