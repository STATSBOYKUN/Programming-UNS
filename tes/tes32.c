#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>
#include"tes.h"

int main(){ 
	
	char file1[50], file2[50];
	
	printf ("Masukkan nama file pertama: ");
	scanf ("%s", file1);
	printf ("Masukkan nama file kedua: ");
	scanf ("%s", file2);

	FILE *fp1 = fopen(file1, "r"); 
    FILE *fp2 = fopen(file2, "r"); 
  
    if (fp1 == NULL || fp2 == NULL){ 
    
       printf("\nFile tidak dapat dibuka\n"); 
       exit(0);
    } 
    else {
    	
    float sama = 0, sum1 = 0, sum2 = 0, sum = 0;
	char a[1000], b[1000];	

    fscanf(fp1, "%s", a);

    while (!feof(fp1)) { 
    	//sum1++;
    	fscanf(fp2, "%s", b);
    	
		while( !feof(fp2)){
        if (strcmp(a, b) == 0) 
        {   
        //	sama++;
            tambah(&head, &tail, b);
        } 
         fscanf(fp2, "%s", b);
         //sum2++;
     	}
    rewind(fp2);
    fscanf(fp1, "%s", a); 
    } 
    puts ("");
    print(head);
    /*
    printf ("sum1 = %.2f, sum2 = %.2f, sama = %.2f", sum1, sum2, sama );
    sum = (sum1 + 1) + ((sum2/2) + 1);
    
    float total = sama/sum*100;
	printf ("\n>> Tingkat kesamaan kamu dan saudara kembarmu: %.2f%% <<\n", total);
    */
    opsi ();
    choice(a);

    fclose(fp1); 
    fclose(fp2); 
	}
  
    puts ("\nTerima kasih");
    return 0; 
}

