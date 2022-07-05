#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	//a. Print unsigned integer 40000 left justified in a 15-digit field with 8 digits.
	printf("%-15.8u\n", 40000);

	return 0;
}