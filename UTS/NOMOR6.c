#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int n, i;

struct Person
{
	char name[MAX];
	int age;
};

void fillPersons(struct Person *myPs, int size);
void printPersons(struct Person *myPs, int size);

int main(){
	struct Person *ptr;
	ptr = (struct Person*) malloc(n * sizeof(struct Person));

	int pilihan;

	switch(pilihan){
		case 1 :
		fillPersons(&ptr, 3);
		break;

		case 2 :
		printPersons(&ptr, 3);
		break;

		case 3 :
		system("exit");
		break;

	}

	return 0;
}

void fillPersons(struct Person *myPs, int size){
	for(i = 0; i < n; ++i){
	printf("Enter name: ");
	scanf("%s", (ptr+i)->name);
	printf("Enter age: ");
	scanf("%d", &(ptr+i)->age);
	}
}

void printPersons(struct Person *myPs, int size){
	for(i = 0; i < n; ++i)
      printf("Name: %s\nAge: %d\n", (ptr+i)->name, (ptr+i)->age);
}
