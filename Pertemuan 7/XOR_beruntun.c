#include <stdio.h>

//deklarasi fungsi prototype
long long fungsiXOR(long long angka1);
long long allXOR(long long angka1, long long angka2);

int main() {
    //deklarasi variabel yang akan digunakan
    long long angka1;
    long long angka2;
    
    //meminta user memasukan angka
    scanf("%lld", &angka1);
    scanf("%lld", &angka2);
    
    //memanggil fungsi prototype dan menampilkan hasil
    printf("%lld", allXOR(angka1, angka2));
     
    return 0;
}

//fungsi XOR
long long fungsiXOR(long long angka1) {
     long long hasilXOR[] = {angka1,1,angka1+1,0};
     return hasilXOR[angka1%4];
}

//fungsi menXORkan seluruh angka
long long allXOR(long long angka1, long long angka2) {
     return fungsiXOR(angka1-1) ^ fungsiXOR(angka2);
}