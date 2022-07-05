#include "header.h"

int main() {
	//menambahkan fungsi yang akan dijalankan pada exit
	atexit(identitas);

	//membuat pilihan pada switch agar mudah dipahami
	enum pilihan{PROSES = 1, COMPARE = 2};

	//membuat menu dengan memanggil fungsi kontrol
	//jika opsi = 3 maka default dijalankan 
	while((opsi=kontrol()) != 3){
		switch(opsi){
			//proses = 1 pada enum pilihan
			case PROSES :
			pemrosesData(); //fungsi pemroses data dipanggil
			break;

			//compare = 2 pada enum pilihan
			case COMPARE :
			pengcompareData(); //fungsi pembanding data dipanggil
			break;

			default:
			exit(EXIT_SUCCESS); //akhiri program
			break;
		}
	}

	return 0;
}

int kontrol(){
	system("color 72"); //mengubah warna latar agar lebih menarik :)
	int option;

	//membuat tampilan menu
	printf("\n");
	printf("{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}}\n");
	printf("          PROGRAM PENCARI KECOCOKAN\n");
	printf("{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}}\n");
	printf(" 1) PROSES 2 DATA\n");
	printf(" 2) COMPARE 2 DATA\n");
	printf(" 3) EXIT\n");
	printf("{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}}\n");
	printf("\n");

	sleep(1);//memberi jeda selama 1 detik
	printf("? Tolong proses dulu sebelum mengcompare.\n");
	printf("? Perintah anda (1-3): ");
	scanf("%d", &option);

	return option;//memasukkan nilai yang akan dimasukkan ke int opsi
}

void pemrosesData(){
	#ifndef nameOfFile
	#define nameOfFile 500
	#endif

	char pendapat;
	char x[2];

	//membuat nama template untuk pilihan opsi n nanti
	char namaFILE2[nameOfFile] = "templateFile1.txt";
	char namaFILE3[nameOfFile] = "templateFile2.txt";

	opsiUser : 
	//cara menangkap enter sederhana
	gets(x);

	printf("? Punya file sendiri(y/n)\n?");
	scanf("%c", &pendapat);
	//apabila user memiliki file nya sendiri
	if (pendapat == 'y'|| pendapat == 'Y') {
		printf("FILE MINIMAL HARUS BERISI : (seperti berikut)\n");
		printf("baris ke-1 = No, Nama(Panggilan), TinggiBadan(cm)\n");
		printf("baris ke-2 = 1, Umar, 185\n");
		printf("\n");

		printf("Mohon pastikan directorynya sudah benar.\n");
		printf("Masukkan file pertama : (misal : .../templateFile1.txt)\n?");
		scanf("%s", namaFILE2);
		printf("Masukkan file kedua   : (misal : .../templateFile2.txt)\n?");
		scanf("%s", namaFILE3);
	} else if (pendapat == 'n'|| pendapat == 'N') {
		//apabila user memilih file template yang telah disediakan
	} else{
		//apabila user memasukkan bukan y, n, Y, atau N
		printf("\n");
		printf("TOLONG MASUKKAN PILIHAN DENGAN TEPAT.\n");
		goto opsiUser;//kembali ke label opsiUSer
	}

	//membuka file pertama dan kedua
	read1 = fopen( namaFILE2, "r");
	read2 = fopen( namaFILE3, "r");

	if (read1 == NULL ) {
		//mengecek file sudah ada atau belum
		printf("File tidak ada.\n");
		printf("Please download file di link yang saya sediakan : \n" );
		printf("drive.google.com/file/d/1UD3YHNQBxt0a9dbp7_U5_YRUGFO94Ir5/view?usp=sharing" );
	} else if( read2 == NULL ){
		//mengecek file sudah ada atau belum
		printf("File tidak ada.\n");
		printf("Please download file di link yang saya sediakan : \n" );
		printf("drive.google.com/file/d/17SabvKHwMQ3Ofd9RaExdl20zQw04olqL/view?usp=sharing" );
	} else {

		printf("=================================================\n");
		printf("            	ISI FILE 1\n");
		printf("=================================================\n");
		while(!feof(read1)){
			//menampilkan isi file dengan mengambil data per line
			//lalu menampilkan ke layar dengan printf
			fgets(isiFile1, MAX, read1);
			printf(" %s", isiFile1);
		}

		sleep(1);
		printf("\n\n");

		printf("=================================================\n");
		printf("            	ISI FILE 2\n");
		printf("=================================================\n");
		while(!feof(read2)){
			//menampilkan isi file dengan mengambil data per line
			//lalu menampilkan ke layar dengan printf
			fgets(isiFile2, MAX, read2);
			printf(" %s", isiFile2);
		}
		sleep(1);
	}

	//menutup file
	fclose(read1);
	fclose(read2);

	printf("\n\n");

	//membuka file kembali untuk diproses
	file1 = fopen( namaFILE2, "r");
	file2 = fopen( namaFILE3, "r");

	if (file1 == NULL || file2 == NULL) {
		//mengecek kembali file sudah ada atau belum
		printf("File tidak ada.\n");
	} else {
		
		while(!feof(file1)){

			//informasi sederhana
			printf("\n");
			printf("=================================================\n");
			printf("	Pengolahan baris ke- %d file1\n", penghitungBaris);
			printf("=================================================\n");
			fgets(kalimat1, MAX, file1);

			//memisahkan tanda baca dan spasi dalam kalimat per line
			//menjadi suatu kata yang disimpan pada array
			strcpy(convert1, kalimat1);
			for (a = b = c = 0; a <= (strlen(convert1)); a++) {
			    if (convert1[a] == ' '|| convert1[a] == '\0') {
			    	//jika spasi atau kekosongan maka diubah menjadi kekosongan
			    	//dan kata baru terindikasi setelah adanya spasi
			        splitter[b][c] = '\0';
			        c = 0;//indikasi huruf
			        b++;//indikasi kata			        
			    } else if (convert1[a] == ',') {
			    	splitter[b][c] = '\0';//jika , maka diubah menjadi kekosongan
			    } else {
			        splitter[b][c] = convert1[a];//menyeleksi dari huruf ke huruf
			        c++;//indikasi huruf
			    }
			}

			for(a = 0 ;a < b; a++) {			    	
		    	printf("Hasil splitter file1, kata ke - %d : %s\n", (a+1), splitter[a]);

		    	//mengkonversi array atau kata yang mengandung angka menjadi integer
		    	strcpy(convert1, splitter[a]);
		    	for (int i = 0, j; convert1[i] != '\0'; i++) {
		    		if ((convert1[i] >= '0') && (convert1[i] <= '9') ) {
		    			int1 = atoi(convert1);//fungsi string to integer
		    		}
		    	}
		    	
		    	if (int1 != 0) {
		    		if (int1 <= 100) {
		    			intPenampung1 = int1;//ditampung sebagai no
		    		}else if (int1 > 100 && int1 <= 240){
		    			intPenampung2 = int1;//ditampung sementara sebagai tinggiBadan
		    		}
		    	}
		    }

		    if (penghitungBaris == 2) {
		    	//dimasukkan ke struct data sebagai data pertama
		    	head1_1(&data1, intPenampung1);
		    	//dimasukkan ke struct data sebagai data pertama
		    	head1_2(&data2, splitter[1]);
		    	//dimasukkan ke struct data sebagai data pertama
		    	head1_3(&data3, intPenampung2);
		    } else if (penghitungBaris >= 3) {
		    	//dimasukkan ke struct data sebagai data selanjtnya
		    	printf("Hasil pengkonversian kata ke-1 to (int) : %d\n", intPenampung1);
		    	append1_1(&data1, intPenampung1);
		    	//dimasukkan ke struct data sebagai data selanjtnya
		    	append1_2(&data2, splitter[1]);
		    	//dimasukkan ke struct data sebagai data selanjtnya
		    	printf("Hasil pengkonversian kata ke-3 to (int) : %d\n", intPenampung2);
		    	append1_3(&data3, intPenampung2);
		    }

		    sleep(1);
			penghitungBaris++;//menghitung baris
		}

		penghitungBaris = 1;//menset kembali penghitung baris
		while(!feof(file2)) {
			//informasi sederhana
			printf("\n");
			printf("=================================================\n");
			printf("	Pengolahan baris ke- %d file2\n", penghitungBaris);
			printf("=================================================\n");
			fgets(kalimat2, MAX, file2);

			//memisahkan tanda baca dan spasi dalam kalimat per line
			//menjadi suatu kata yang disimpan pada array
			strcpy(convert2, kalimat2);
			for (a = b = c = 0; a <= (strlen(convert2)); a++) {
			    if (convert2[a] == ' '|| convert2[a] == '\0') {
			        splitter2[b][c] = '\0';
			        c = 0;//indikasi huruf
			        b++;//indikasi kata				        
			    } else if (convert2[a] == ',') {
			    	splitter2[b][c] = '\0';//jika , maka diubah menjadi kekosongan
			    } else {
			        splitter2[b][c] = convert2[a];//menyeleksi dari huruf ke huruf
			        c++;//indikasi huruf
			    }
			}		    

			//mengkonversi array atau kata yang mengandung angka menjadi integer
		    for(a = 0 ;a < b; a++) {
		    	printf("Hasil splitter file2, kata ke - %d : %s\n", (a+1), splitter2[a]);

		    	strcpy(convert2, splitter2[a]);
		    	for (int i = 0, j; convert2[i] != '\0'; i++) {
		    		if ((convert2[i] >= '0') && (convert2[i] <= '9') ) {
		    			int2 = atoi(convert2);//fungsi string to integer
		    		}
		    	}

		    	if (int2 != 0) {
		    		if (int2 <= 100) {
		    			intPenampung1 = int2;//ditampung sebagai no
		    		}else if (int2 > 100 && int2 <= 240){
		    			intPenampung2 = int2;//ditampung sebagai tinggi 
		    		}
		    	}
        	}

        	if (penghitungBaris == 2) {
        		//dimasukkan ke struct data sebagai data pertama
		    	head2_1(&data4, intPenampung1);
		    	//dimasukkan ke struct data sebagai data pertama
		    	head2_2(&data5, splitter2[1]);
		    	//dimasukkan ke struct data sebagai data pertama
		    	head2_3(&data6, intPenampung2);
		    } else if (penghitungBaris >= 3) {
		    	//dimasukkan ke struct data sebagai data selanjtnya
		    	printf("Hasil pengkonversian kata ke-1 to (int) : %d\n", intPenampung1);
		    	append2_1(&data4, intPenampung1);
		    	//dimasukkan ke struct data sebagai data selanjtnya
		    	append2_2(&data5, splitter2[1]);
		    	//dimasukkan ke struct data sebagai data selanjtnya
		    	printf("Hasil pengkonversian kata ke-3 to (int) : %d\n", intPenampung2);
		    	append2_3(&data6, intPenampung2);
		    }

		    sleep(1);
			penghitungBaris++;//menghitung baris
        }
	}

	//tutup file
	fclose(file1);
	fclose(file2);

	//informasi sederhana
	printf("\n\n\n");
	printf("================================================================\n");
	printf("		  Hasil pendataan file1 : \n");
	printf("================================================================\n");
	//menampilkan hasil memasukkan data struct
	printList1(data1, data2, data3);

	//informasi sederhana
	printf("\n\n\n");
	printf("================================================================\n");
	printf("		  Hasil pendataan file2 : \n");
	printf("================================================================\n");
	//menampilkan hasil memasukkan data struct
	printList2(data4, data5, data6);

	printf("\n\n");
	system("color 76");//memperjelas informasi dengan merubah warna
	printf("PENGOLAHAN 2 FILE DATA SELESAI.\n");
	printf("Silahkan dicompare.\n");
	sleep(2);
}

void pengcompareData(){
	printf("\nMencocokan kedua file....(please wait)\n");
	#ifndef rename
	#define rename 100
	#endif

	char namaFILE1[rename];

	//memasukkan nama file outputan
	printf("SILAHKAN MASUKKAN NAMA OUTPUT FILE (.txt): ");
	scanf("%s", &namaFILE1);

	//cek sederhana
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
  		
  		//memanggil isi data 3 
    	data3->tinggiBadan;
    	//memanggil isi data 2
    	data2->nama;

    	//menampung pemanggilan data3  	
    	forCompare = data3->tinggiBadan;
    	//menampung pemanggilan data2 dengan metode copy
    	strcpy(forCompare2, data2->nama);

    	//informasi sederhana
    	printf("\n");
    	printf("================================================================\n");
		printf("		  Pencocokan kedua file : \n");
		printf("================================================================\n");

		//informasi sederhana ke file
		fprintf(penyimpanFile, "================================================================\n");
		fprintf(penyimpanFile, "		  Pencocokan kedua file : \n");
		fprintf(penyimpanFile, "================================================================\n");

		//informasi sederhana
		printf("Data file 1 : \n");
        printf("Nama              : %s\n", forCompare2);
        printf("Tinggi Badan (cm) : %d\n\n", forCompare);

        //informasi sederhana untuk dimasukkan ke file
        fprintf(penyimpanFile, "Data file 1 : \n");
        fprintf(penyimpanFile, "Nama              : %s\n", forCompare2);
        fprintf(penyimpanFile, "Tinggi Badan (cm) : %d\n\n", forCompare);

        //memanggil fungsi compare untuk membandingkan isi file
    	compare(&data6, &data5, forCompare2, forCompare);

    	//melanjutkan data selanjutnya yang ada
    	data3 = data3->lanjutan;
    	data2 = data2->lanjutan;

    	sleep(1);
  	}

  	//menutup file
	fclose(file1);
	fclose(file2);
	fclose(penyimpanFile);

	printf("\n\n");
	system("color 76");//mengubah color agar untuk memperjelas
	printf("MEMBANDINGKAN 2 FILE DATA SELESAI.\n");
	sleep(2);
}

/**
 * [printList1 : fungsi yang digunakan untuk menampilkan data list
 * @param *structData1 yang sebnarnya adalah list data1
 * @param *structData2 yang sebnarnya adalah list data2
 * @param *structData3 yang sebnarnya adalah list data3
 */
void printList1(struct structData1 *structData1, struct structData1 *structData2, struct structData1 *structData3){
	int baris = 2;//menghitung baris yang berisi informasi dimulai dari 2
  	while(structData1 != NULL && structData2 != NULL && structData3 != NULL){
  		//informasi sederhana
    	printf("Data didapat pada baris ke-(%d) : \t%-4d %-7s %10d\n", baris, structData1->no, structData2->nama, structData3->tinggiBadan);
    	//melajutkan data yang ada
    	structData1 = structData1->lanjutan;//melanjutkan pembacaan data1
    	structData2 = structData2->lanjutan;//melanjutkan pembacaan data2
    	structData3 = structData3->lanjutan;//melanjutkan pembacaan data3
    	baris++;
  	}
}

/**
 * [printList2 : fungsi yang digunakan untuk menampilkan data list
 * @param *structData1 yang sebnarnya adalah list data4
 * @param *structData2 yang sebnarnya adalah list data5
 * @param *structData3 yang sebnarnya adalah list data6
 */
void printList2(struct structData2 *structData1, struct structData2 *structData2, struct structData2 *structData3) {
	int baris = 2;//menghitung baris yang berisi informasi dimulai dari 2
  	while(structData1 != NULL && structData2 != NULL && structData3 != NULL){
  		//informasi sederhana
    	printf("Data didapat pada baris ke-(%d) : \t%-4d %-7s %10d\n", baris, structData1->no, structData2->nama, structData3->tinggiBadan);
    	//melajutkan data yang ada
    	structData1 = structData1->lanjutan;//melanjutkan pembacaan data4
    	structData2 = structData2->lanjutan;//melanjutkan pembacaan data5
    	structData3 = structData3->lanjutan;//melanjutkan pembacaan data6
    	baris++;
  	}
}

void head1_1(struct structData1** new_head, int new_no){
	//membuat alokasi memori yang diperlukan
    struct structData1* new_data = (struct structData1*) malloc(sizeof(struct structData1));
    new_data->no = new_no;//memasukkan new no ke dalam no pada structData1
    new_data->lanjutan = (*new_head);//membuat head untuk data selanjutnya
    (*new_head) = new_data;//membuat alokasi memori untuk head data
}

void head1_2(struct structData1** new_head, char new_nama[]){
	//membuat alokasi memori yang diperlukan
	struct structData1* new_data = (struct structData1*) malloc(sizeof(struct structData1));
    //memasukkan new_nama ke dalam nama pada structData1 dengan
    //metode pengkopian string
    strcpy(new_data->nama, new_nama);
    new_data->lanjutan = (*new_head);//membuat head untuk data selanjutnya
    (*new_head) = new_data;//membuat alokasi memori untuk head data
}

void head1_3(struct structData1** new_head, int new_tinggiBadan){
	//membuat alokasi memori yang diperlukan
	struct structData1* new_data = (struct structData1*) malloc(sizeof(struct structData1));
    new_data->tinggiBadan = new_tinggiBadan;//memasukkan new tinggiBadan ke dalam tinggiBadan pada structData1
    new_data->lanjutan = (*new_head);//membuat head untuk data selanjutnya
    (*new_head) = new_data;//membuat alokasi memori untuk head data
}

void append1_1(struct structData1** new_head, int new_no){
	//membuat alokasi memori yang diperlukan
    struct structData1* new_data = (struct structData1*)malloc(sizeof(struct structData1));
    //data terakhir pada struct diindikasikan sebagai head baru
    struct structData1* dataTerakhir = *new_head;

    //memasukkan data baru ke structData1 no
    new_data->no = new_no;
    //memberikan tail untuk dataTerakhir
    new_data->lanjutan = NULL;

    while(dataTerakhir->lanjutan != NULL){
    	//menloop untuk memasukkan data secara terus menerus hingga
    	//data yang dimasukkan tidak NULL
        dataTerakhir = dataTerakhir->lanjutan;
    }
    
    //membuat data baru untuk diisi suatu data kemudian
    dataTerakhir->lanjutan = new_data;
}

void append1_2(struct structData1** new_head, char new_nama[]){
	//membuat alokasi memori yang diperlukan
    struct structData1* new_data = (struct structData1*)malloc(sizeof(struct structData1));
    //data terakhir pada struct diindikasikan sebagai head baru
    struct structData1* dataTerakhir = *new_head;

    //memasukan data baru ke struuctData1
    strcpy(new_data->nama, new_nama);
    //memberikan tail untuk dataTerakhir
    new_data->lanjutan = NULL;

    while(dataTerakhir->lanjutan != NULL){
    	//menloop untuk memasukkan data secara terus menerus hingga
    	//data yang dimasukkan tidak NULL
        dataTerakhir = dataTerakhir->lanjutan;
    }
    
    //membuat data baru untuk diisi suatu data kemudian
    dataTerakhir->lanjutan = new_data;
}

void append1_3(struct structData1** new_head, int new_tinggiBadan){
	//membuat alokasi memori yang diperlukan
    struct structData1* new_data = (struct structData1*)malloc(sizeof(struct structData1));
    //data terakhir pada struct diindikasikan sebagai head baru
    struct structData1* dataTerakhir = *new_head;

    //memasukkan data baru ke structData1 tinggiBadan
    new_data->tinggiBadan = new_tinggiBadan;
    //memberikan tail untuk dataTerakhir
    new_data->lanjutan = NULL;

    while(dataTerakhir->lanjutan != NULL){
    	//menloop untuk memasukkan data secara terus menerus hingga
    	//data yang dimasukkan tidak NULL
        dataTerakhir = dataTerakhir->lanjutan;
    }
    
    //membuat data baru untuk diisi suatu data kemudian
    dataTerakhir->lanjutan = new_data;
}

void head2_1(struct structData2** new_head, int new_no){
	//membuat alokasi memori yang diperlukan
    struct structData2* new_data = (struct structData2*) malloc(sizeof(struct structData2));
    new_data->no = new_no;//memasukkan new no ke dalam no pada structData2
    new_data->lanjutan = (*new_head);//membuat head untuk data selanjutnya
    (*new_head) = new_data;//membuat alokasi memori untuk head data
}

void head2_2(struct structData2** new_head, char new_nama[]){
	//membuat alokasi memori yang diperlukan
    struct structData2* new_data = (struct structData2*) malloc(sizeof(struct structData2));
    //memasukkan new_nama ke dalam nama pada structData2 dengan
    //metode pengkopian string
    strcpy(new_data->nama, new_nama);
    new_data->lanjutan = (*new_head);//membuat head untuk data selanjutnya
    (*new_head) = new_data;//membuat alokasi memori untuk head data
}

void head2_3(struct structData2** new_head, int new_tinggiBadan){
	//membuat alokasi memori yang diperlukan
    struct structData2* new_data = (struct structData2*) malloc(sizeof(struct structData2));
    new_data->tinggiBadan = new_tinggiBadan;//memasukkan new tinggiBadan ke dalam tinggiBadan pada structData1
    new_data->lanjutan = (*new_head);//membuat head untuk data selanjutnya
    (*new_head) = new_data;//membuat alokasi memori untuk head data
}

void append2_1(struct structData2** new_head, int new_no){
	//membuat alokasi memori yang diperlukan
    struct structData2* new_data = (struct structData2*)malloc(sizeof(struct structData2));
    //data terakhir pada struct diindikasikan sebagai head baru
    struct structData2* dataTerakhir = *new_head;

    //memasukkan data baru ke structData1 no
    new_data->no = new_no;
    //memberikan tail untuk dataTerakhir
    new_data->lanjutan = NULL;

    while(dataTerakhir->lanjutan != NULL){
    	//menloop untuk memasukkan data secara terus menerus hingga
    	//data yang dimasukkan tidak NULL
        dataTerakhir = dataTerakhir->lanjutan;
    }
    
    //membuat data baru untuk diisi suatu data kemudian
    dataTerakhir->lanjutan = new_data;
}

void append2_2(struct structData2** new_head, char new_nama[]){
	//membuat alokasi memori yang diperlukan
    struct structData2* new_data = (struct structData2*)malloc(sizeof(struct structData2));
    //data terakhir pada struct diindikasikan sebagai head baru
    struct structData2* dataTerakhir = *new_head;

    //memasukan data baru ke struuctData2
    strcpy(new_data->nama, new_nama);
    //memberikan tail untuk dataTerakhir
    new_data->lanjutan = NULL;

    while(dataTerakhir->lanjutan != NULL){
    	//menloop untuk memasukkan data secara terus menerus hingga
    	//data yang dimasukkan tidak NULL
        dataTerakhir = dataTerakhir->lanjutan;
    }
    
    //membuat data baru untuk diisi suatu data kemudian
    dataTerakhir->lanjutan = new_data;
}

void append2_3(struct structData2** new_head, int new_tinggiBadan){
	//membuat alokasi memori yang diperlukan
    struct structData2* new_data = (struct structData2*)malloc(sizeof(struct structData2));
    //data terakhir pada struct diindikasikan sebagai head baru
    struct structData2* dataTerakhir = *new_head;

    //memasukkan data baru ke structData2 tinggiBadan
    new_data->tinggiBadan = new_tinggiBadan;
    //memberikan tail untuk dataTerakhir
    new_data->lanjutan = NULL;

    while(dataTerakhir->lanjutan != NULL){
    	//menloop untuk memasukkan data secara terus menerus hingga
    	//data yang dimasukkan tidak NULL
        dataTerakhir = dataTerakhir->lanjutan;
    }
    
    //membuat data baru untuk diisi suatu data kemudian
    dataTerakhir->lanjutan = new_data;
}

/**
 * [compare : membandingkan kedua file]
 * @param pembanding  [data struct dari data6]
 * @param pembanding2 [data struct dari data5]
 * @param cari_nama   [nama yang akan dicari]
 * @param cari        [tinggiBadan yang akan dicari]
 */
void compare(struct structData2 **pembanding, struct structData2 **pembanding2, char cari_nama[], int cari) { 
    //membuat struct penampung1 dimana akan memasukkan head data
    struct structData2* penampung = *pembanding;
    //membuat struct penampung2 dimana akan memasukkan head data
    struct structData2* penampung2 = *pembanding2;  
    
    //menghitung baris
    int baris1 = 2;

    while ( penampung != NULL ) {
    	//membandingkan kedua string
    	strcmp(penampung2->nama, cari_nama);
        if (penampung->tinggiBadan == cari || (strcmp(penampung2->nama, cari_nama) == 0)) {
        	//informasi sederhana
            printf("Kecocokan data file 1 ditemukan pada baris ke-%d file 2.\n\n", baris1);
            printf("Data file 2 : \n");
        	printf("Nama              : %s\n", penampung2->nama);
        	printf("Tinggi Badan (cm) : %d\n\n", penampung->tinggiBadan);

        	//informasi sederhana untuk dimasukkan ke file
        	fprintf(penyimpanFile, "Kecocokan data file 1 ditemukan pada baris ke-%d file 2.\n", baris1);
        	fprintf(penyimpanFile, "Data file 2 : \n");
        	fprintf(penyimpanFile, "Nama              : %s\n", penampung2->nama);
        	fprintf(penyimpanFile, "Tinggi Badan (cm) : %d\n\n", penampung->tinggiBadan);
            
        } else if (penampung->lanjutan == NULL){
        	//informasi sederhana
        	printf("Tidak ditemukan kecocokan data lagi pada file 2.\n\n");
        	//informasi sederhana untuk dimasukkan ke file
        	fprintf(penyimpanFile, "Tidak ditemukan kecocokan data lagi pada file 2.\n\n");
        }

        //mlanjutkan data selanjutnya 
        penampung = penampung->lanjutan;
        penampung2 = penampung2->lanjutan;
        baris1++;//penghitung baris
    }
}

//fungsi ini hanya digunakan untuk memberikan identitas
//dan akan diproses saat exit
void identitas(){
	printf("\n\n");

	//suatu informasi sederhana
	system("color 71");sleep(2);
	printf("{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}}\n");
	system("color 73");sleep(2);
	printf(" TERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI.\n");
	system("color 74");sleep(2);
	printf(" (C)Dibuat oleh Umar Hadi Pranoto.\n");
	system("color 75");sleep(2);
	printf(" Jangan Lupa Membuka File Output. :)\n");
	system("color 76");sleep(2);
	printf("{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}}\n");

}