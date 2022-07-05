#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	//Ini akan error
	//The following statement should print the characters'O'and'K':
	printf("%s%s\n",'O','K');
	/*
	printf tersebut akan error karena penandaan salah karena akan menginput 
	suatu char tetapi menggunakan %s dalam penandaan nya dimana %s digunakan
	untuk mengoutput suatu string. 
	 */

	//Perbaikan error menjadi berikut ini
	printf("%c%c\n",'O','K');

	return 0;
}