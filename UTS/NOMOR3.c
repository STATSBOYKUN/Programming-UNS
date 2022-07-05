#include <stdio.h>

int main(){
	char c = 'I';
	switch(c){
		case 'A' : printf("I am A\n");
		case 'E' : printf("I am E\n"); break;
		case 'I' : printf("I am I\n");
		case 'U' : printf("I am U\n"); break;
		case 'O' : printf("I am O\n");
		default	 : printf("I do not know");
	}
	/*
	Hasil akan menampilkan 
	I am I
	I am U

	karena nilai c adalah char 'I' dan akan menjalankan 
	case'I', maka printf("I am I\n"); berlanjut ke 
	printf("I am U\n"); karena tidak ada break atau pemutus 
	di dalam case 'I'.

	 */
	return 0;
}