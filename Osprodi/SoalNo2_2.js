const readline = require("readline")

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
})

rl.question("", function(nama) 
{
    rl.question("", function(angkanim) 
    {

        if (angkanim < 30)
        {
            var kelasabc = "A"
        }
        else if (angkanim < 58)
        {
            var kelasabc = "B"
        }
        else
        {
            var kelasabc = "C"
        }

        if (angkanim % 2 == 0)
            var kelasgangenap = "B"
        else
            var kelasgangenap = "A"

            
        console.log("Halo, namaku " + nama);
        console.log("Pada semester ini aku mendapat kelas " + kelasabc + " dan " + kelasgangenap);

        process.exit();
    })
})