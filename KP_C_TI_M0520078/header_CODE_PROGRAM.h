#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "colorYippe.h"

#define true 1
#define false 0
//untuk mendefinisikan banyak char yang dapat ditampung
#define MAX 250

//untuk menampilkan isiFile
#define PRINTFILE(X) \
printf(" %s", X) \

//bertugas mencopy
#define PENGCOPY(x, y) \
strcpy(x, y) \

//bertugas mengambil isi file per line
#define PENGAMBIL_LINE(A, B, C) \
fgets(A, B, C) \

//bertugas memberitahu waktu
#define WAKTU() \
printf("%s, %s.", __DATE__, __TIME__) \

//mendeklarasikan variabel-variabel yang dipakai
//secara global
int opsi;
int penghitungBaris = 1;
char kalimat1[MAX], kalimat2[MAX];
char isiFile1[MAX], isiFile2[MAX];
char convert1[MAX], convert2[MAX];
char splitter[MAX][MAX], splitter2[MAX][MAX];

int a, b, c, d, e;
int int1, int2;
int intPenampung1, intPenampung2;
int penghitungKata = 0;

//struct untuk menyimpan data dari file 1
struct structData1 {
   int no;
   char nama[MAX];
   int tinggiBadan;
   struct structData1* lanjutan;
};

//struct untuk menyimpan data dari file 2
struct structData2 {
   int no;
   char nama[MAX];
   int tinggiBadan;
   struct structData2* lanjutan;
};

//struct untuk menyimpan data sama
struct structData3 {
   char nilai_sama1[MAX];
   int nilai_sama2;
   struct structData3* lanjutan;
};

typedef struct structData1 struct_DATA1;//struct structData1 = struct_DATA1
typedef struct structData2 struct_DATA2;//struct structData2 = struct_DATA2
typedef struct structData3 struct_DATA3;//struct structData3 = struct_DATA3

//struct untuk file1
struct_DATA1* data1 = NULL;
struct_DATA1* data2 = NULL;
struct_DATA1* data3 = NULL;

//struct untuk file2
struct_DATA2* data4 = NULL;
struct_DATA2* data5 = NULL;
struct_DATA2* data6 = NULL;

//struct untuk file data yang sama
struct_DATA3* data7 = NULL;
struct_DATA3* data8 = NULL;

//file yang akan digunakan pada proses data
FILE *file1, *file2, *read1, *read2;
//file yang akan digunakan pada compare data
FILE *penyimpanFile;

int kontrol();
void pemrosesData();
void pengcompareData();

//fungsi prototype yang digunakan untuk file 1
void head1_1(struct_DATA1** new_head, int new_no);
void head1_2(struct_DATA1** new_head, char new_nama[]);
void head1_3(struct_DATA1** new_head, int new_tinggiBadan);
void append1_1(struct_DATA1** new_head, int new_no);
void append1_2(struct_DATA1** new_head, char new_nama[]);
void append1_3(struct_DATA1** new_head, int new_tinggiBadan);
void printList1(struct_DATA1 *structData1, struct_DATA1 *structData2, struct_DATA1 *structData3);

//fungsi prototype yang digunakan untuk file 2
void head2_1(struct_DATA2** new_head, int new_no);
void head2_2(struct_DATA2** new_head, char new_nama[]);
void head2_3(struct_DATA2** new_head, int new_tinggiBadan);
void append2_1(struct_DATA2** new_head, int new_no);
void append2_2(struct_DATA2** new_head, char new_nama[]);
void append2_3(struct_DATA2** new_head, int new_tinggiBadan);
void printList2(struct_DATA2 *structData1, struct_DATA2 *structData2, struct_DATA2 *structData3);

//fungsi prototype yang digunakan untuk file sama
void head3_1(struct_DATA3** new_head, char new_nilai_sama1[]);
void head3_2(struct_DATA3** new_head, int new_nilai_sama2);
void append3_1(struct_DATA3** new_head, char new_nilai_sama1[]);
void append3_2(struct_DATA3** new_head, int new_nilai_sama2);

//fungsi prototype yang digunakan untuk membandingkan file
void compare(struct_DATA2 **pembanding, struct_DATA2 **pembanding2, char cari_nama[], int cari);

//fungsi prototype untuk menampilkan identitas
void identitas();