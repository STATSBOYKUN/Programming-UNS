#include <stdio.h>
#include <math.h>

int main()
{
	//mendeklarasikan variabel
	int matriks[3][3];
	int hasil;

	for (int i = 0; i < 3; i++)	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &matriks[i][j]);
		}
	}

	for (int i = 0; i < 1; i++){
		for (int j = 0; j < 3; j++) {
			hasil = matriks[i][j] % 2;

			if(hasil == 0){
			printf("%d  ", matriks[i][j]);
			}else{
			continue;
			}
		}
	}
	printf("\n");
	for (int i = 1; i < 2; i++){
		for (int j = 0; j < 3; j++) {
			hasil = matriks[i][j] % 2;

			if(hasil == 0){
			printf("%d  ", matriks[i][j]);
			}else{
			continue;
			}
		}
	}
	printf("\n");
	for (int i = 2; i < 3; i++){
		for (int j = 0; j < 3; j++) {
			hasil = matriks[i][j] % 2;

			if(hasil == 0){
			printf("%d  ", matriks[i][j]);
			}else{
			continue;
			}
		}
	}

	return 0;
}