#include "header.h"

int main() {
    atexit(identitas);
    system("color 72");

    enum pilihan{PROSES = 1, COMPARE = 2};

    // while((opsi=menu()) != 3){
    //  switch(opsi){
    //      case PROSES :
    //      break;

    //      case COMPARE :
    //      break;

    //      default:
    //      exit(EXIT_SUCCESS);
    //      break;
    //  }
    // }

    read1 = fopen("FILE1.txt", "r");
    read2 = fopen("FILE2.txt", "r");

    if (read1 == NULL ) {
        printf("File tidak ada.\n");
        printf("Please download file di link yang saya sediakan : \n" );
        printf("drive.google.com " );
    } else if( read2 == NULL ){
        printf("File tidak ada.\n");
        printf("Please download file di link yang saya sediakan : \n" );
        printf("drive.google.com " );
    } else {

        printf("=================================================\n");
        printf("                ISI FILE 1\n");
        printf("=================================================\n");
        while(!feof(read1)){
            fgets(isiFile1, MAX, read1);
            printf(" %s", isiFile1);
        }

        printf("\n\n");

        printf("=================================================\n");
        printf("                ISI FILE 2\n");
        printf("=================================================\n");
        while(!feof(read2)){
            fgets(isiFile2, MAX, read2);
            printf(" %s", isiFile2);
        }
    }

    fclose(read1);
    fclose(read2);

    printf("\n\n");


    file1 = fopen("FILE1.txt", "r");
    file2 = fopen("FILE2.txt", "r");

    if (file1 == NULL || file2 == NULL) {
        printf("File tidak ada.\n");
    } else {
        
        while(!feof(file1)){
            printf("\n");
            printf("=================================================\n");
            printf("    Pengolahan baris ke- %d file1\n", penghitungBaris);
            printf("=================================================\n");
            fgets(kalimat1, MAX, file1);

            strcpy(convert1, kalimat1);
            for (a = b = c = 0; a <= (strlen(convert1)); a++) {
                if (convert1[a] == ' '|| convert1[a] == '\0') {
                    splitter[b][c] = '\0';
                    c = 0;
                    b++;                    
                } else if (convert1[a] == ',') {
                    splitter[b][c] = '\0';
                } else {
                    splitter[b][c] = convert1[a];
                    c++;
                }
            }

            for(a = 0 ;a < b; a++) {                    
                printf("Hasil splitter file1, kata ke - %d : %s\n", (a+1), splitter[a]);

                strcpy(convert1, splitter[a]);
                for (int i = 0, j; convert1[i] != '\0'; i++) {
                    if ((convert1[i] >= '0') && (convert1[i] <= '9') ) {
                        int1 = atoi(convert1);
                    }
                }

                if (int1 != 0) {
                    if (int1 <= 100) {
                        intPenampung1 = int1;
                    }else if (int1 > 100 && int1 <= 240){
                        intPenampung2 = int1;
                    }
                }
            }

            if (penghitungBaris == 2) {
                head1_1(&data1, intPenampung1);
                head1_2(&data2, splitter[1]);
                head1_3(&data3, intPenampung2);
            } else if (penghitungBaris >= 3) {
                printf("Hasil pengkonversian kata ke-1 to (int) : %d\n", intPenampung1);
                append1_1(&data1, intPenampung1);
                append1_2(&data2, splitter[1]);
                printf("Hasil pengkonversian kata ke-3 to (int) : %d\n", intPenampung2);
                append1_3(&data3, intPenampung2);
            }

            sleep(1);
            penghitungBaris++;
        }

        penghitungBaris = 1;
        while(!feof(file2)) {
            printf("\n");
            printf("=================================================\n");
            printf("    Pengolahan baris ke- %d file2\n", penghitungBaris);
            printf("=================================================\n");
            fgets(kalimat2, MAX, file2);

            strcpy(convert2, kalimat2);
            for (a = b = c = 0; a <= (strlen(convert2)); a++) {
                if (convert2[a] == ' '|| convert2[a] == '\0') {
                    splitter2[b][c] = '\0';
                    c = 0;
                    b++;                    
                } else if (convert2[a] == ',') {
                    splitter2[b][c] = '\0';
                } else {
                    splitter2[b][c] = convert2[a];
                    c++;
                }
            }           

            for(a = 0 ;a < b; a++) {
                printf("Hasil splitter file2, kata ke - %d : %s\n", (a+1), splitter2[a]);

                strcpy(convert2, splitter2[a]);
                for (int i = 0, j; convert2[i] != '\0'; i++) {
                    if ((convert2[i] >= '0') && (convert2[i] <= '9') ) {
                        int2 = atoi(convert2);
                    }
                }

                if (int2 != 0) {
                    if (int2 <= 100) {
                        intPenampung1 = int2;
                    }else if (int2 > 100 && int2 <= 240){
                        intPenampung2 = int2;
                    }
                }
            }

            if (penghitungBaris == 2) {
                head2_1(&data4, intPenampung1);
                head2_2(&data5, splitter2[1]);
                head2_3(&data6, intPenampung2);
            } else if (penghitungBaris >= 3) {
                printf("Hasil pengkonversian kata ke-1 to (int) : %d\n", intPenampung1);
                append2_1(&data4, intPenampung1);
                append2_2(&data5, splitter2[1]);
                printf("Hasil pengkonversian kata ke-3 to (int) : %d\n", intPenampung2);
                append2_3(&data6, intPenampung2);
            }

            sleep(1);
            penghitungBaris++;
        }
    }

    fclose(file1);
    fclose(file2);

    printf("\n\n\n");
    printf("================================================================\n");
    printf("          Hasil pendataan file1 : \n");
    printf("================================================================\n");
    printList1(data1, data2, data3);

    printf("\n\n\n");
    printf("================================================================\n");
    printf("          Hasil pendataan file2 : \n");
    printf("================================================================\n");
    printList2(data4, data5, data6);

    printf("\n\n\nMencocokan kedua file....(please wait)\n");
    #ifndef rename
    #define rename 100
    #endif

    char namaFILE1[rename];

    printf("SILAHKAN MASUKKAN 5 HURUF NAMA FILE (.txt): ");
    scanf("%s", &namaFILE1);

    penyimpanFile = fopen(namaFILE1, "w+");
    if (penyimpanFile == NULL) {
        printf("ERROR.\n");
    }

    int forCompare;

    #ifndef text
    #define text 500
    #endif
    char forCompare2[text];
    

    while(data3 != NULL){
        
        data3->tinggiBadan;
        data2->nama;    
        forCompare = data3->tinggiBadan;
        strcpy(forCompare2, data2->nama);

        printf("\n");
        printf("================================================================\n");
        printf("          Pencocokan kedua file : \n");
        printf("================================================================\n");

        printf("Data file 1 : \n");
        printf("Nama              : %s\n", forCompare2);
        printf("Tinggi Badan (cm) : %d\n\n", forCompare);

        fprintf(penyimpanFile, "Data file 1 : \n");
        fprintf(penyimpanFile, "Nama              : %s\n", forCompare2);
        fprintf(penyimpanFile, "Tinggi Badan (cm) : %d\n\n", forCompare);

        compare(&data6, &data5, forCompare2, forCompare);
        data3 = data3->lanjutan;
        data2 = data2->lanjutan;

        sleep(1);
    }

    fclose(file1);
    fclose(file2);

    fclose(penyimpanFile);
    return 0;
}

void printList1(struct structData1 *structData1, struct structData1 *structData2, struct structData1 *structData3){
    int baris = 2;
    while(structData1 != NULL && structData2 != NULL && structData3 != NULL){
        printf("Data didapat pada baris ke-(%d) : \t%-4d %-7s %10d\n", baris, structData1->no, structData2->nama, structData3->tinggiBadan);
        structData1 = structData1->lanjutan;
        structData2 = structData2->lanjutan;
        structData3 = structData3->lanjutan;
        baris++;
    }
}

void printList2(struct structData2 *structData1, struct structData2 *structData2, struct structData2 *structData3) {
    int baris = 2;
    while(structData1 != NULL && structData2 != NULL && structData3 != NULL){
        printf("Data didapat pada baris ke-(%d) : \t%-4d %-7s %10d\n", baris, structData1->no, structData2->nama, structData3->tinggiBadan);
        structData1 = structData1->lanjutan;
        structData2 = structData2->lanjutan;
        structData3 = structData3->lanjutan;
        baris++;
    }
}

void head1_1(struct structData1** new_head, int new_no){
    struct structData1* new_data = (struct structData1*) malloc(sizeof(struct structData1));
    new_data->no = new_no;
    new_data->lanjutan = (*new_head);
    (*new_head) = new_data;
}

void head1_2(struct structData1** new_head, char new_nama[]){
    struct structData1* new_data = (struct structData1*) malloc(sizeof(struct structData1));
    strcpy(new_data->nama, new_nama);
    new_data->lanjutan = (*new_head);
    (*new_head) = new_data;
}

void head1_3(struct structData1** new_head, int new_tinggiBadan){
    struct structData1* new_data = (struct structData1*) malloc(sizeof(struct structData1));
    new_data->tinggiBadan = new_tinggiBadan;
    new_data->lanjutan = (*new_head);
    (*new_head) = new_data;
}

void append1_1(struct structData1** new_head, int new_no){
    struct structData1* new_data = (struct structData1*)malloc(sizeof(struct structData1));
    struct structData1* dataTerakhir = *new_head;

    new_data->no = new_no;
    new_data->lanjutan = NULL;

    while(dataTerakhir->lanjutan != NULL){
        dataTerakhir = dataTerakhir->lanjutan;
    }
    
    dataTerakhir->lanjutan = new_data;
    return;
}

void append1_2(struct structData1** new_head, char new_nama[]){
    struct structData1* new_data = (struct structData1*)malloc(sizeof(struct structData1));
    struct structData1* dataTerakhir = *new_head;

    strcpy(new_data->nama, new_nama);
    new_data->lanjutan = NULL;

    while(dataTerakhir->lanjutan != NULL){
        dataTerakhir = dataTerakhir->lanjutan;
    }
    
    dataTerakhir->lanjutan = new_data;
    return;
}

void append1_3(struct structData1** new_head, int new_tinggiBadan){
    struct structData1* new_data = (struct structData1*)malloc(sizeof(struct structData1));
    struct structData1* dataTerakhir = *new_head;

    new_data->tinggiBadan = new_tinggiBadan;
    new_data->lanjutan = NULL;

    while(dataTerakhir->lanjutan != NULL){
        dataTerakhir = dataTerakhir->lanjutan;
    }
    
    dataTerakhir->lanjutan = new_data;
    return;
}

void head2_1(struct structData2** new_head, int new_no){
    struct structData2* new_data = (struct structData2*) malloc(sizeof(struct structData2));
    new_data->no = new_no;
    new_data->lanjutan = (*new_head);
    (*new_head) = new_data;
}

void head2_2(struct structData2** new_head, char new_nama[]){
    struct structData2* new_data = (struct structData2*) malloc(sizeof(struct structData2));
    strcpy(new_data->nama, new_nama);
    new_data->lanjutan = (*new_head);
    (*new_head) = new_data;
}

void head2_3(struct structData2** new_head, int new_tinggiBadan){
    struct structData2* new_data = (struct structData2*) malloc(sizeof(struct structData2));
    new_data->tinggiBadan = new_tinggiBadan;
    new_data->lanjutan = (*new_head);
    (*new_head) = new_data;
}

void append2_1(struct structData2** new_head, int new_no){
    struct structData2* new_data = (struct structData2*)malloc(sizeof(struct structData2));
    struct structData2* dataTerakhir = *new_head;

    new_data->no = new_no;
    new_data->lanjutan = NULL;

    while(dataTerakhir->lanjutan != NULL){
        dataTerakhir = dataTerakhir->lanjutan;
    }
    
    dataTerakhir->lanjutan = new_data;
    return;
}

void append2_2(struct structData2** new_head, char new_nama[]){
    struct structData2* new_data = (struct structData2*)malloc(sizeof(struct structData2));
    struct structData2* dataTerakhir = *new_head;

    strcpy(new_data->nama, new_nama);
    new_data->lanjutan = NULL;

    while(dataTerakhir->lanjutan != NULL){
        dataTerakhir = dataTerakhir->lanjutan;
    }
    
    dataTerakhir->lanjutan = new_data;
    return;
}

void append2_3(struct structData2** new_head, int new_tinggiBadan){
    struct structData2* new_data = (struct structData2*)malloc(sizeof(struct structData2));
    struct structData2* dataTerakhir = *new_head;

    new_data->tinggiBadan = new_tinggiBadan;
    new_data->lanjutan = NULL;

    while(dataTerakhir->lanjutan != NULL){
        dataTerakhir = dataTerakhir->lanjutan;
    }
    
    dataTerakhir->lanjutan = new_data;
    return;
}

void compare(struct structData2 **pembanding, struct structData2 **pembanding2, char cari_nama[], int cari) { 
    struct structData2* penampung = *pembanding, *dataSebelumnya;
    struct structData2* penampung2 = *pembanding2, *dataSebelumnya2;  
    
    int baris1 = 3;

    while ( penampung != NULL ) { 
        dataSebelumnya = penampung;
        dataSebelumnya2 = penampung2;

        if (penampung->tinggiBadan == cari || penampung2->nama == cari_nama) {
            printf("Kecocokan data file 1 ditemukan pada baris ke-%d file 2.\n\n", baris1);
            printf("Data file 2 : \n");
            printf("Nama              : %s\n", penampung2->nama);
            printf("Tinggi Badan (cm) : %d\n\n", penampung->tinggiBadan);

            fprintf(penyimpanFile, "Kecocokan data file 1 ditemukan pada baris ke-%d file 2.\n", baris1);
            fprintf(penyimpanFile, "Data file 2 : \n");
            fprintf(penyimpanFile, "Nama              : %s\n", penampung2->nama);
            fprintf(penyimpanFile, "Tinggi Badan (cm) : %d\n\n", penampung->tinggiBadan);
            
        } else if (penampung->lanjutan == NULL){
            printf("Tidak ditemukan kecocokan data lagi pada file 2.\n");
            fprintf(penyimpanFile, "Tidak ditemukan kecocokan data lagi pada file 2.\n");
        }

        penampung = penampung->lanjutan;
        penampung2 = penampung2->lanjutan;
        baris1++; 
    }
}

void identitas(){
    printf("\n\n\n");

    system("color 71");sleep(2);
    printf("{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}}\n");
    system("color 73");sleep(2);
    printf(" TERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI.\n");
    system("color 74");sleep(2);
    printf(" (C)Dibuat oleh Umar Hadi Pranoto.\n");
    system("color 75");sleep(2);
    printf(" JANGAN LUPA MEMBUKA FILE YANG TELAH DIBUAT. :)\n");
    system("color 76");sleep(2);
    printf("{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}}\n");

}