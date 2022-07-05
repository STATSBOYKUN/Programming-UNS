const readline = require("readline")

const membacaInputan = readline.createInterface({
    input   : process.stdin,
    output  : process.stdout
})

membacaInputan.question("", function(nama){
    membacaInputan.question("", function(nim){
        var kelasABC;
        if (nim >= 1 && nim < 30){
            kelasABC = "A";
        }else if (nim >= 30 && nim < 58){
            kelasABC = "B";
        }else if (nim >= 58){
            kelasABC = "C";
        }

        var ganjilGenap;
        if (nim % 2 == 0){
            ganjilGenap = "genap";
        }else{
            ganjilGenap = "ganjil";
        }

        console.log("Halo, namaku " + nama + ".");
        console.log("Pada semester ini aku mendapat kelas " + kelasABC + " dan " + ganjilGenap + ".");

        process.exit();
    })
})