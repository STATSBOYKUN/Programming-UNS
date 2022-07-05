#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    //mendeklarasikan dan memberi pernyataan variabel yang akan dipakai 
    unsigned long long N;
    unsigned long long angka;
    unsigned long long modulus  = 100000;
    unsigned long long sum  = 0;
    unsigned long long sum1 = 0;
    unsigned long long sum2 = 0;

    int total;

    //meminta user memasukkan banyak kolom
    scanf("%lld", &N);

    //memasukkan nilai dengan membuat baris sebanyak 3 dan
    //kolom sebanyak N
    for (int i = 0; i < 3; i++){
    
        for (int j = 0; j < N; j++){
            //meminta user memasukkan nilai
            scanf("%lld", &angka);
            
            if(i == 0){
                //penjumlahan baris ke 1
                sum  = (sum  + angka) % modulus;
            }else if (i == 1){
                //penjumlahan baris ke 2
                sum1 = (sum1 + angka) % modulus;
            }else if (i == 2){
                //penjumlahan baris ke 3
                sum2 = (sum2 + angka) % modulus;
            }
        }

        //mengalikan penjumlahan baris ke 1, 2, dan 3
        total = (sum * sum1 * sum2) % modulus;
    }

    //menampilkan hasil total ke layar
    printf("%d", total);

    //mengembalikan fungsi main secara natural
    return 0;
}