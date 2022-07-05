#include <stdio.h>
#include <math.h>

//deklarasi fungsi prototype
float sum(float a);
float faktorial(float a);

int main(){
	//deklarasi variabel
	float a;
	float total;
	//memasukkan nilai variabel
	scanf("%f", &a);
	total = sum(a) + 1;

	//menampilkan hasil pada layar
	printf("\nHasil dari sum nya adalah : %f\n", total);

}

//fungsi prototype faktorial
float faktorial(float a){
	if (a == 1){
		return a;
	}else{
		return a * faktorial(a - 1);
	}
}

//fungsi prototype menjumlahkan
float sum(float a){
	float hasil;
	float penampil;
	float hasil1;

	hasil1 = faktorial(a);
	penampil = a - 1;
	hasil = 1 / hasil1;
	if (a == 1){
		printf("1/%.1f! ", penampil);
		return 1;
	}else{
		printf(" 1/%.1f! + ", penampil);
		return hasil + sum(a - 1);
	}
}