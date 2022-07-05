const readline = require("readline")

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
})

rl.question("", function(nama) 
{
    rl.question("", function(nim) 
    {
        rl.question("", function(umur) 
        {
            rl.question("", function(asal) 
            {
                rl.question("", function(hobi) 
                {
                    console.log("Halo, namaku " + nama + ", dengan NIM " + nim + ".")
                    console.log(`Sekarang aku berumur ${umur} tahun dan berasal dari ${asal}`);
                    console.log("Hobiku adalah " + hobi + ".");
                    console.log(`Salam kenal semuanya!`);

                    process.exit();
                })
            })
        })
    })
})