#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//mendefinisikan nilai MAX_LEN adalah 99999
#define MAX_LEN 99999

int main() {
    
    //mendeklarasikan variabel yang akan dipakai
    char ch;
    char s[MAX_LEN];
    char sen[MAX_LEN];
    
    //meminta user memasukkan nilai
    scanf("%c%*c", &ch);
    scanf("%s%*c", &s);
    scanf("%[^\n]%*c", &sen);
    
    //menampilkan hasil inputan ke layar
    printf("%c\n", ch);
    printf("%s\n", s);
    printf("%s\n", sen);
    
    //mengembalikan fungsi main dengan natural
    return 0;
}