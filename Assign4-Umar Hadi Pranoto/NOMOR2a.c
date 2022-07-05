#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	//Ini akan error
	printf("%s\n",'Happy Birthday');
	/*
	Terjadi sebuah error karena tanda petik satu digunakan untuk char dan petik 
	dua digunakan untuk string. Jadi, harusnya tanda petik satu diubah ke petik dua.  
	 */
	
	//Perbaikan error menjadi berikut ini
	printf("%s\n", "Happy Birthday");

	return 0;
}