#include <stdio.h>
#include <math.h>

int main(){
	//medeklarasikan variabel
	int hasil = 0;
	int hasil2 = 0;
	int j = 2;

	//menjumlahkan nilai dengan for loop
	for (int i = 2; i < 100; i = i + 3){
		hasil = hasil + i;
		//hasil akan bertambah 3 setiap pengulangan
	}
	//menampilkan hasil pada layar
	printf("Yang ini pakai loop 	: %d.\n", hasil);

	//menjumlahkan nilai dengan while loop
	while(j >= 2 && j < 100){
		hasil2 = hasil2 + j;
		j = j + 3;
	}

	//menampilkan hasil pada layar
	printf("Yang ini pakai while 	: %d.", hasil2);
	return 0;
}
