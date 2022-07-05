#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	//Ini akan error
	//The following statement should print"BonVoyage":
	printf(""%s"","Bon Voyage");
	/*
	Untuk menampilkan tanda petik dua diperlukan suatu surpression character
	dimana tanda "\" akan meandakan bahwa setelah tanda "\" tanda special seperti
	^, &, "", '', akan dianggap juga sebagai output. 
	 */

	//Perbaikan error menjadi berikut ini
	printf("\"%s\"", "Bon Voyage");

	return 0;
}