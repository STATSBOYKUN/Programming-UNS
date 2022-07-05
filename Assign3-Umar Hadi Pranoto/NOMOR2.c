#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//deklarasi fungsi prototype
float sum(float N);

int main()
{
	//deklarasi variabel yang akan digunakan
	float N;

	//meminta user memasukkan nilai
	printf("Silahkan masukkan sebuah angka untuk dikalkulasikan ke dalam fungsi : ");
	scanf("%f", &N);
	printf("\nNilai sum dari deret tersebut adalah: %f", sum(N));

	return 0;
}

//fungsi penjumlahan suatu deret
float sum(float N){
	float hasil;
	int penampil;

	hasil = (1 / (2 * N - 1));
	penampil = (2 * N - 1);
	if (N == 1){
		printf("1/%d", penampil);
		return 1;
	}else{
		printf("1/%d + ", penampil);
		return hasil + sum(N - 1);
	}

}