$(document).ready(function(){
    $("#PH4Button").click(function(){
        var valeur = $("#PH4_Base_Value").val();
        $.post("SendPH4Value",{
            valeurPH4_Base: valeur
        });
    });
});

$(document).ready(function(){
    $("#PH10Button").click(function(){
        var valeur = $("#PH10_Base_Value").val();
        $.post("SendPH10Value",{
            valeurPH10_Base: valeur
        });
    });
});

setInterval(function getDataCONV()
{
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function()
    {
        if(this.readyState == 4 && this.status == 200)
        {
            document.getElementById("valeurCONV").innerHTML = this.responseText;
        }
    };

    xhttp.open("GET", "lireCONV", true);
    xhttp.send();
}, 2000);

setInterval(function getDataTEMP()
{
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function()
    {
        if(this.readyState == 4 && this.status == 200)
        {
            document.getElementById("valeurTemp").innerHTML = this.responseText;
        }
    };

    xhttp.open("GET", "lireTEMP", true);
    xhttp.send();
}, 2000);

setInterval(function getDataPH()
{
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function()
    {
        if(this.readyState == 4 && this.status == 200)
        {
            document.getElementById("valeurPH").innerHTML = this.responseText;
        }
    };

    xhttp.open("GET", "lirePH", true);
    xhttp.send();
}, 2000);
