#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stddef.h>

int main()
{	
	#undef NULL
	char *sapa = "Selamat Ujian!";
	char penampung[1000];

	#define NULL 0
	while(*sapa != NULL){
		printf("%c", *sapa++);
	}	
}