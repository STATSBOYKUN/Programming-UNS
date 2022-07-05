#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	//Ini akan error
	printf(%f, 123.456);
	/*
	Penandaan pada printf harus didahului dengan tanda petik dua "".
	 */

	//Perbaikan error menjadi berikut ini
	printf("%f", 123.456);

	return 0;
}