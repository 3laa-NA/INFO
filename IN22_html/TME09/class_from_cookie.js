function class_from_cookie(){
    document.cookie.split(';').forEach(function (c) {
        var r = c.split('=');
        if (r) {
            var n = document.getElementById(r[0]);
            if (n) n.classList.add(r[1]);
            document.cookie = r[0] + "=; expires=Thu, 01 Jan 1970 00:00:00 UTC";
        }
    })
} 