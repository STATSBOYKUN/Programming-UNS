const readline = require("readline")

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
})

const zeroPad = (num, places) => String(num).padStart(places, '0')


rl.question("", function(tahun) 
{
    rl.question("", function(jumlah) 
    {
        var i;
        for(i = 1; i <= jumlah; i++)
        {
            console.log("M05" + zeroPad(tahun, 2) + zeroPad(i, 3));  
        }

        process.exit();
    })
})
