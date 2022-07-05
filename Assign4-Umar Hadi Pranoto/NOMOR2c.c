#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	//Ini akan error
	printf("%c\n", "This is a string");
	/*
	Eror disebabkan kesalahan dalam menandakan tipe string. Pada printf tersebut
	%c harusnya %s karena ingin menampilkan sebuah string bukan char.
	 */
	
	//Perbaikan error menjadi berikut ini
	printf("%s\n", "This is a string");

	return 0;
}