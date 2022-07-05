const readline = require("readline")    

const rl = readline.createInterface({
    input   : process.stdin,
    output  : process.stdout
})

rl.question("", function(nama)
{
	rl.question("", function(nim) 
    {
    console.log(`Halo, namaku ${nama}, dengan NIM ${nim}.`);
	})
})

rl.question("", function(umur)
{
	rl.question("", function(asal) 
    {
    console.log(`Sekarang aku berumur ${umur} tahun dan berasal dari ${asal}.`);
	})
})

rl.question("", function(hobi)
{
	console.log("Hobiku adalah " + hobi + ".");
	console.log("Salam kenal semuanya!");

	process.exit();
})  