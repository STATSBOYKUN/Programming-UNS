#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	//Ini akan error
	printf('Enter your name: ');
	/*
	printf akan error karena penggunaan tanda petik satu yang seharusnya
	petik dua dan tidak adanya penandaan apakah output berupa string, char, 
	atau integer. Dapat dilihat bahwa printf akan menampilkan suatu string.
	Maka diperlukan penandaan berupa %s. 
	 */

	//Perbaikan error menjadi berikut ini
	printf("%s","Enter your name: ");

	return 0;
}