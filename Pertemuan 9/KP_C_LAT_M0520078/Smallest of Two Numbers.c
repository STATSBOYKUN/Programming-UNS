#include <stdio.h>

#define MINIMUM2(angka1, angka2) (angka1 < angka2 ? angka1 : angka2)

int main() {
	long long a, b;
	long long hasil;

	printf("Masukkan angka1 : ");
	scanf("%lld", &a);
	printf("Masukkan angka2 : ");
	scanf("%lld", &b);

	if (a != b)	{
		hasil = MINIMUM2(a, b);
		printf("Nilai yang terkecil adalah : %lld.\n", hasil);
	}else{
		printf("Angka nya sama.\n");
	}

	return 0;
}