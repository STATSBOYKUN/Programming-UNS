#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    //mendeklarasikan variabel yang akan dipakai
    int angka;
    
    //meminta user menginput nilai
    scanf("%d", &angka);
    
    //jika angka lebih dari 1 dan kurang dari 9 maka kondisi true dan program berjalan
    if (angka >= 1 && angka <= 9) {
        if (angka == 1) {
            printf("one");
        }else if (angka == 2) {
            printf("two");
        }else if (angka == 3) {
            printf("three");
        }else if (angka == 4) {
            printf("four");
        }else if (angka == 5) {
            printf("five");
        }else if (angka == 6) {
            printf("six");
        }else if (angka == 7) {
            printf("seven");
        }else if (angka == 8) {
            printf("eight");
        }else if (angka == 9) {
            printf("nine");
        }
    //jika angka bernilai lebih dari sembilan konidisi disini bernilai true
    }else if (angka > 9) {
        printf("Greater than 9");
    }
    
    return 0;
}
