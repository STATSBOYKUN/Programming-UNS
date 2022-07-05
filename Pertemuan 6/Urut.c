#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
   //mendeklarasikan nilai yang akan dipakai
   int absen, nilai, banyakSiswa;

   //memasukkan jumlah siswa
   scanf("%d", &banyakSiswa);

   //mendeklarasikan array siswa
   int siswa[banyakSiswa];

   //absen dimulai dari 1 dan seterusnya
   for (int i = 1; i <= banyakSiswa; i++) {
      scanf("%d %d", &absen, &nilai);

      //absen tidak mungkin 0 atau negatif
      if (absen <= 0) {
         break;
      }else if (absen > 0) {
         //memasukkan nilai siswa kedalam array siswa sesuai absen
         siswa[absen] = nilai;
      }
   }

   //menampilkan hasil ke layar
   for (int i = 1; i <= banyakSiswa; i++) {
      printf("%d\n", siswa[i]);
   }

   return 0;
}