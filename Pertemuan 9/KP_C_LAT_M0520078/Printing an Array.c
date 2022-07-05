#include <stdio.h>
#include <stdlib.h>

#define PRINTARRAY(array, panjangArray) \
for(int i = 0; i < panjangArray; i++)	\
    printf("Nilai array ke - %d \t: %d.\n", i, array[i]); \

int main(void) {
	int panjangArray;
	printf("Masukkan panjang array : ");
	scanf("%d", &panjangArray);

    int array[panjangArray];
    for (int j = 0; j < panjangArray; j++) {
    	array[j] = rand();
    }

    PRINTARRAY(array, panjangArray);

    return 0;
}