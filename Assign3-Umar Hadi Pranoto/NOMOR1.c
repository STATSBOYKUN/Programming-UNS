#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//deklarasi fungsi prototype
int fibonacci(int a);

int main(){
	//deklarasi variabel yang akan digunakan
	int a;
	int hasil;

	//meminta user memasukkan nilai
	printf("Masukkan jumlah bilangan Fibonacci yang akan ditampilkan : ");
	scanf("%d", &a);

	//menampilkan hasil ke layar
	printf("Bilangan Fibonacci(%d): ", a);
	for (int i = 0; i < a; i++)
	{
		hasil = fibonacci(i);
		printf(" %d ", hasil);
	}
	return 0;
}

//fungsi fibonacci
int fibonacci(int a){
	if (a == 0 || a == 1)
	{
		return a;
	}else{
		return fibonacci(a - 1) + fibonacci(a - 2);
	}
}