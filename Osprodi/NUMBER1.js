const readline = require('readline');

const membacaInputan = readline.createInterface({
  input     : process.stdin,
  output    : process.stdout
});

membacaInputan.question("", function(nama) 
{
    membacaInputan.question("", function(nim) 
    {
        membacaInputan.question("", function(umur) 
        {
            membacaInputan.question("", function(asal) 
            {
                membacaInputan.question("", function(hobi) 
                {
                    console.log("Halo, namaku " + nama + " dengan NIM " + nim + ".")
                    console.log("Sekarang aku berumur " + umur + " tahun dan berasal dari " + asal + ".");
                    console.log("Hobiku adalah " + hobi + ".");
                    console.log(`Salam kenal semuanya!`);

                    process.exit();
                })
            })
        })
    })
})