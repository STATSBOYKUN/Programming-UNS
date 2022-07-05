#include <stdio.h>
//deklarasi fungsi prototype
void change_values(int a[], int b, int* c);

int main(void)
{
	//deklarasi variabel
	int x[] = {1, 2, 3};
	int y	= 3;
	int z	= 2;

	//menampilkan ke layar
	printf("(%d, %d, %d) %d %d\n", x[0], x[1], x[2], y, z);
	
	//memanggil fungsi
	change_values(x, y, &z);

	//menampilkan hasil ke layar
	printf("(%d, %d, %d) %d %d\n", x[0], x[1], x[2], y, z);

	/*
	akan menampilkan
	(1, 2, 3) 3 2
	(1, 4, 5) 3 0

	karena x[1] + 2 atau ditambah y 
			x[2] + 2 atau ditambah y
			y tetap
			dan z = 0
	 */

	return 0;
}

//fungsi mengganti nilai
void change_values(int a[], int b, int* c){
	while(--b > 0)
		a[b] += *c;
		*c = 0;
}