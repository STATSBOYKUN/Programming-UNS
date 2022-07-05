#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	//Ini akan error
	char day[] = "Sunday";
	printf("%s\n", day[3] );
	/*
	Fungsi printf error dan akan menampilkan suatu output random 
	karena inputan merupakan string bukan char yang dideklarasikan
	secara array dengan baik. Jadi, untuk menampilkan variabel day
	tidak diperlukan []. 
	 */

	//Perbaikan error menjadi berikut ini
	printf("%s\n", day);

	return 0;
}