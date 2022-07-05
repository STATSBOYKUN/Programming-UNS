#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    //mendeklarasikan variabel yang akan dipakai
    int a, b;
    
    //meminta user memasukkan input
    scanf("%d\n%d", &a, &b);
  	
    //angka dimulai dari a hingga b dan akan bertambah satu setiap perulangan
    for (int angka = a; angka <= b; angka++) {
        if (angka <= 9) {//jika angka kurang dari sama dengan satu maka kondisi true
            if (angka == 1) {
                printf("one\n");//jika angka bernilai satu maka fungsi ini berjalan
            }else if (angka == 2) {
                printf("two\n");//jika angka bernilai dua maka fungsi ini berjalan
            }else if (angka == 3) {
                printf("three\n");//jika angka bernilai tiga maka fungsi ini berjalan
            }else if (angka == 4) {
                printf("four\n");//jika angka bernilai empat maka fungsi ini berjalan
            }else if (angka == 5) {
                printf("five\n");//jika angka bernilai lima maka fungsi ini berjalan
            }else if (angka == 6) {
                printf("six\n");//jika angka bernilai enam maka fungsi ini berjalan
            }else if (angka == 7) {
                printf("seven\n");//jika angka bernilai tujuh maka fungsi ini berjalan
            }else if (angka == 8) {
                printf("eight\n");//jika angka bernilai delapan maka fungsi ini berjalan
            }else if (angka == 9) {
                printf("nine\n");//jika angka bernilai sembilan maka fungsi ini berjalan
            }
        }else if (angka > 9) {
            int hasil = angka % 2;
            //angka akan dimod dengan dua untuk menentukan genap/ganjil
            if (hasil == 0) {
            printf("even\n");//jika hasil nol maka bernilai genap
            }else if (hasil == 1) {
            printf("odd\n");//jika hasil bersisa 1 maka bernilai ganjil
            }
        }
    }
    
    //fungsi dikembalikan dengan natural
    return 0;
}

