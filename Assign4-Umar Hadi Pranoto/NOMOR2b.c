#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	//Ini akan error
	printf("%c\n",'Hello');
	/*
	Terjadi sebuah error karena tanda petik satu digunakan untuk char dan petik 
	dua digunakan untuk string. Pada printf tersebut juga char ditulis dalam kata 
	yang seharusnya hanya ditulis dalam satu huruf. Jadi, harusnya tanda petik 
	satu diubah ke petik dan %c yang digunakan untuk menandakan char diganti %s 
	untuk string.
	 */

	//Perbaikan error menjadi berikut ini
	printf("%s\n", "Hello");

	return 0;
}