const readline = require('readline');

const bacabaris = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const MemintaInput = () => 
{
    return new Promise((resolve, reject) => 
    {
        bacabaris.question("", (jawaban) => 
        {
            resolve(jawaban)
        })
    })
}


const main = async () => 
{
    var nama        = await MemintaInput();
    var angkanim    = await MemintaInput();


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

        
    console.log(`Halo, namaku ${nama}`);
    console.log(`Pada semester ini aku mendapat kelas ${kelasabc} dan ${kelasgangenap}`);

    bacabaris.close();
    process.exit();
}

main();
