#include <stdio.h>

#define MAX_LEN 9999

struct mahasiswa{
    char Nama[MAX_LEN];
    char Asal[MAX_LEN];
    char Univ[MAX_LEN];
};

void print(struct mahasiswa s1);

int main() {
    struct mahasiswa s1;

    printf("MAHASISWA S1\n");

    printf("Masukkan Nama   : ");
    scanf("%[^\n]%*c", &s1.Nama);

    printf("Masukkan Asal   : ");
    scanf("%[^\n]%*c", &s1.Asal);

    printf("Masukkan Univ   : ");
    scanf("%[^\n]%*c", &s1.Univ);

    print(s1);

    return 0;
}

void print(struct mahasiswa s1){
  printf("Nama          : %s\n", s1.Nama);
  printf("Asal          : %s\n", s1.Asal);
  printf("Univeristas   : %s\n", s1.Univ);
}