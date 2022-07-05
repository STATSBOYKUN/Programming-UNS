const readline = require("readline")

const membacaInputan = readline.createInterface({
    input   : process.stdin,
    output  : process.stdout
})

membacaInputan.question("", function(tahun) 
{
    var digitTahun;
    if(tahun.length < 2){
        digitTahun = "0" + tahun;
    }else if(tahun.length = 2){
        digitTahun = tahun;
    }
    
    membacaInputan.question("", function(banyak) 
    {
        var i, nim;

        if (banyak >= 1000){
            process.exit();
        }
        for(i = 1; i <= banyak; i++){
            if(i < 10){
                nim = "00" + i;
            }     
            else if(i < 100){
                nim = "0" + i;
            }       
            else if (i < 1000){
                nim = i;
            }

            console.log("M05" + digitTahun + nim); 
                    
        }
        process.exit();
    })
})