#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//deklarasi fungsi prototype
void celsiusToFahrenheit(double*);
void fahrenheitToCelcius(double*);

int main(){
	//deklarasi variabel yang akan digunakan
	double a;
	double b;
	int hasil;

	//menampilkan hasil ke layar
	printf("Celcius To Fahrenheit(1)/Fahrenheit To Celcius(2)?");
	scanf("%d", &hasil);
	if (hasil == 1)
	{
		printf("Masukkan nilai Celcius \t: ");
		scanf("%lf", &a);//meminta user memasukkan nilai
		celsiusToFahrenheit(&a);//memanggilfungsi
		printf("Jadi, nilai tersebut \t= %lf derajat Fahrenheit.", a);
	}else if (hasil == 2)
	{
		printf("Masukkan nilai Fahrenheit \t: ");
		scanf("%lf", &b);//meminta user memasukkan nilai
		fahrenheitToCelcius(&b);//memanggil fungsi
		printf("Jadi, nilai tersebut \t\t= %lf derajat Celcius.", b);
	}else{
		system("exit");//exit bila memasukkan nilai selain 1 dan 2
	}
	
	return 0;
}

//fungsi celsius To Fahrenheit
void celsiusToFahrenheit(double *c){
	(*c) = ((9 * (*c)) / 5 ) + 32;
}

//fungsi fahrenheit To Celcius
void fahrenheitToCelcius(double *f){
	(*f) = (5 * ((*f) - 32)) / 9;
}