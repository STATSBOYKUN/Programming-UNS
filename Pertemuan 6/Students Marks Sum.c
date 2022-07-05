#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//membuat suatu fungsi sum
int marks_summation(int* marks, int number_of_students, char gender) {
    //mendeklarasikan variabel yang akan dipakai
    int sum = 0;
    
    if (gender == 'b') {
        //i bernilai nol karena jika gender == 'b' marks dimulai dari 0
        for (int i = 0; i < number_of_students; i += 2){
        sum += marks[i];
        }
    }else if(gender == 'g'){
        //i bernilai satu karena jika gender == 'g' marks dimulai dari 1
        for (int i = 1; i < number_of_students; i += 2){
        sum += marks[i];
        }
    }
    
    return sum;
}

int main() {
    //mendeklarasikan variabel
    int number_of_students;
    char gender;
    int sum;
    
    //menginput banyaknya siswa
    scanf("%d", &number_of_students);
    int *marks = (int *) malloc(number_of_students * sizeof (int));
 
    for (int student = 0; student < number_of_students; student++) {
        scanf("%d", (marks + student));//menginput nilai
    }
    
    scanf(" %c", &gender);
    sum = marks_summation(marks, number_of_students, gender);//memanggil fungsi
    printf("%d", sum);//menampilkan hasil ke layar
    free(marks);
 
    return 0;
}