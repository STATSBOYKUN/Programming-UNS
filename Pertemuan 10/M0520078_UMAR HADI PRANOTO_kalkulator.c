#include "header.h"

int kalkulator();

int main() {
	double a, b, angka1, angka2;
	int opsi;
	double hasil1, hasil2, hasil3, hasil4;

	enum enumKalkulator{PENJUMLAHAN = 1, PENGURANGAN = 2, PERKALIAN = 3, PEMBAGIAN = 4};
	while((opsi = kalkulator()) != 5){
		switch(opsi){

			case PENJUMLAHAN:
				#ifndef angka1
				#define angka1 100.00
				#endif

				#ifndef angka2
				#define angka2 200.00
				#endif
			
				if (angka1 != 0) {
					a = angka1;
				}
				if (angka2 != 0) {
					b = angka2;
				}

				#ifndef angka1
			  		printf("Masukkan angka ke-1 : ");
			  		scanf("%lf", &a);
				#endif

				#ifndef angka2
			  		printf("Masukkan angka ke-2 : ");
			  		scanf("%lf", &b); 
				#endif
		
				printf("Angka pertama adalah \t: %.2lf\n", a);
				printf("Angka kedua adalah \t: %.2lf\n", b);

				hasil1 = PENJUMLAHAN(a, b);
				printf("Hasil penjumlahan angka = %.2lf\n", hasil1);

			break;

			case PENGURANGAN:
				#ifdef angka2
				#undef angka2
				#endif

				if (angka1 != 0) {
					a = angka1;
				}
				if (angka2 != 0) {
					b = angka2;
				}

				#ifndef angka1
					printf("Masukkan angka ke-1 : ");
			  		scanf("%lf", &a);
				#endif

				#ifndef angka2
			  		printf("Masukkan angka ke-2 : ");
			  		scanf("%lf", &b); 
				#endif

				printf("Angka pertama adalah \t: %.2lf\n", a);
				printf("Angka kedua adalah \t: %.2lf\n", b);

				hasil2 = PENGURANGAN(a, b);
				printf("Hasil pengurangan angka = %.2lf\n", hasil2);

			break;

			case PERKALIAN:
				#define angka2 100

				#ifdef angka1
				#undef angka1
				#endif

				if (angka1 != 0) {
					a = angka1;
				}
				if (angka2 != 0) {
					b = angka2;
				}

				#ifndef angka1
			  		printf("Masukkan angka ke-1 : ");
			  		scanf("%lf", &a);
				#endif

				#ifndef angka2
			  		printf("Masukkan angka ke-2 : ");
			  		scanf("%lf", &b); 
				#endif

				printf("Angka pertama adalah \t: %.2lf\n", a);
				printf("Angka kedua adalah \t: %.2lf\n", b);

				hasil3 = PERKALIAN(a, b);
				printf("Hasil perkalian angka = %.2lf\n", hasil3);

			break;

			case PEMBAGIAN:
				#if defined angka1
				#undef angka1
				#endif

				#if defined angka2
				#undef angka2
				#endif

				if (angka1 != 0) {
					a = angka1;
				}
				if (angka2 != 0) {
					b = angka2;
				}

				#ifndef angka1
			  		printf("Masukkan angka ke-1 : ");
			  		scanf("%lf", &a);
				#endif

				#ifndef angka2
			  		printf("Masukkan angka ke-2 : ");
			  		scanf("%lf", &b); 
				#endif

				printf("Angka pertama adalah \t: %.2lf\n", a);
				printf("Angka kedua adalah \t: %.2lf\n", b);

				hasil4 = PEMBAGIAN(a, b);
				printf("Hasil pembagian angka = %.2lf\n", hasil4);
			break;

			default:
			break;
		}
	}
	
	return 0;
}

int kalkulator(){
	int angka;

	printf("\n");
	printf("      KALKULATOR\n");
	printf("========================\n");
	printf(" 1) PENJUMLAHAN\n");
	printf(" 2) PENGURANGAN\n");
	printf(" 3) PERKALIAN\n");
	printf(" 4) PEMBAGIAN\n");
	printf(" 5) EXIT\n");
	printf("Perintah Anda (1-5): \n?");
	scanf("%d", &angka);

	return angka;
}