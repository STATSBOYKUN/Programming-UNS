#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//deklarasi fungsi prototype
const int baris = 3;
const int kolom = 4;
int sum(int a[baris][kolom]);

int main()
{
	//deklarasi variabel yang akan digunakan
	int a[baris][kolom];

	//meminta user memasukkan nilai array
	for (int i = 0; i <= 2 ; i++)
	{
		for (int j = 0; j <= 3; j++){
		printf("Masukkan angka untuk [%d][%d] : ", i, j);
		scanf("%d", &a[i][j]);
		}
	}

	//menampilkan hasil ke layar
	printf("\n");
	printf("", sum(a));
	return 0;
}

//fungsi penjumlahan kolom
int sum(int a[baris][kolom]){
	int hasil, hasil1, hasil2, hasil3;
	hasil 	= 0;
	hasil1 	= 0;
	hasil2 	= 0;
	hasil3 	= 0;

	for (int j = 0; j <= 2; j++){
		hasil += a[j][0];
		printf("Ini nilai [%d][0] : %d\n", j, a[j][0]);
	}
	printf("Hasil penjumlahan kolom ke-1: %d.\n\n", hasil);

	for (int j = 0; j <= 2; j++){
		hasil1 += a[j][1];
		printf("Ini nilai [%d][1] : %d\n", j, a[j][1]);
	}
	printf("Hasil penjumlahan kolom ke-2: %d.\n\n", hasil1);

	for (int j = 0; j <= 2; j++){
		hasil2 += a[j][2];
		printf("Ini nilai [%d][2] : %d\n", j, a[j][2]);
	}
	printf("Hasil penjumlahan kolom ke-3: %d.\n\n", hasil2);

	for (int j = 0; j <= 2; j++){
		hasil3 += a[j][3];
		printf("Ini nilai [%d][3] : %d\n", j, a[j][3]);
	}
	printf("Hasil penjumlahan kolom ke-4: %d.\n", hasil3);
	
	return 0;
}