#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	//Ini akan error
	char s[10];
	scanf("%c", s[7]);
	/*
	Untuk menyimpan suatu data pada array dibutuhkan suatu alamat
	sehingga diperlukan tanda "&" untuk menyimpan data pada alamat
	pada array. 
	 */

	//Perbaikan error menjadi berikut ini
	scanf("%c", &s[7]);

	return 0;
}