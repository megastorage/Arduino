$(document).ready(function(){
    $("#PH4Button").click(function(){
        var valeur = $("#PH4_Base_Value").val();
        if ((valeur > 5.0) || (valeur <2.0)) {
            alert('Valeur PH4 Base Non Correct 2.0 < PH_Base4 > 5.0');
        }
        else{
        $.post("SendPH4Value",{
            valeurPH4_Base: valeur
        });
        }
    });
});

$(document).ready(function(){
    $("#PH10Button").click(function(){
        var valeur = $("#PH10_Base_Value").val();
        if ((valeur < 8.0) || (valeur >12.0)){
            alert('Valeur PH10 Base Non Correct 8.0 < PH_Base10 > 12.0');
        }
        else{
            $.post("SendPH10Value",{
                valeurPH10_Base: valeur
            });
        }
    });
});

$(document).ready(function(){
    $("#PressionLowButton").click(function(){
        var valeur = $("#PressionB_Base_Value").val();
        if ((valeur > 1.0) || (valeur <0.0)) {
            alert('Valeur Pression Basse Non Correct 0 < Pression Basse > 1');
        }
        else{
        $.post("SendPressionBValue",{
            valeurPressionB_Base: valeur
        });
        }
    });
});

$(document).ready(function(){
    $("#PressionHightButton").click(function(){
        var valeur = $("#PressionH_Base_Value").val();
        if ((valeur < 2.0) || (valeur >10.0)){
            alert('Valeur Pression Haute Non Correct 2.0 < Pression Haute > 10.0');
        }
        else{
            $.post("SendPressionHValue",{
                valeurPressionH_Base: valeur
            });
        }
    });
});

setInterval(function getDataCONV()
{
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function()
    {
        if(this.readyState == 4 && this.status == 200)
        {
            document.getElementById("valeurCONV_Pression").innerHTML = this.responseText;
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

setInterval(function getDataPression()
{
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function()
    {
        if(this.readyState == 4 && this.status == 200)
        {
            document.getElementById("valeurPression").innerHTML = this.responseText;
        }
    };

    xhttp.open("GET", "lirePression", true);
    xhttp.send();
}, 2000);
