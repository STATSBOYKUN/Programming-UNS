#include "header_CODE_PROGRAM.h"

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
	#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	colorYippe1(color 72); //mengubah warna latar agar lebih menarik :)
	#endif
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

	#if defined __APPLE__ || __linux__ || __unix__
	printf("%s\n", darkgrey);
	#endif

	sleep(1);//memberi jeda selama 1 detik
	printf("? Tolong proses dulu sebelum mengcompare.\n");
	printf("? Perintah anda (1-3): ");
	scanf("%d", &option);

	#if defined __APPLE__ || __linux__ || __unix__
	printf("%s\n", resetColor);
	#endif

	return option;//memasukkan nilai yang akan dimasukkan ke int opsi
}

void pemrosesData(){
	#ifndef nameOfFile
	#define nameOfFile 500
	#endif

	char pendapat;
	char spasi[1];

	//membuat nama template untuk pilihan opsi n nanti
	char namaFILE2[nameOfFile] = "templateFILE1.txt";
	char namaFILE3[nameOfFile] = "templateFILE2.txt";

	opsiUser : 
	//cara menangkap enter sederhana
	gets(spasi);

	printf("? Punya file sendiri(y/n)\n?");
	scanf("%c", &pendapat);
	//apabila user memiliki file nya sendiri
	if (pendapat == 'y'|| pendapat == 'Y') {
		printf("FILE MINIMAL HARUS BERISI : (seperti berikut)\n");
		printf("baris ke-1 = No, Nama(Panggilan), TinggiBadan(cm)\n");
		printf("baris ke-2 = 1, Umar, 185\n");
		printf("\n");

		printf("Mohon pastikan directorynya sudah benar.\n");
		printf("Masukkan file pertama : (misal : .../templateFILE1.txt)\n?");
		scanf("%s", namaFILE2);
		printf("Masukkan file kedua   : (misal : .../templateFILE2.txt)\n?");
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
		printf("drive.google.com/file/d/1f0ONyXoeTogtd4suyYnEHoaM2pWAfA_z/view?usp=sharing" );
	} else if( read2 == NULL ){
		//mengecek file sudah ada atau belum
		printf("File tidak ada.\n");
		printf("Please download file di link yang saya sediakan : \n" );
		printf("drive.google.com/file/d/1zyRqsgovobr0wAgg7OcsyvALehuEap5F/view?usp=sharing" );
	} else {

		printf("=================================================\n");
		printf("            	ISI FILE 1\n");
		printf("=================================================\n");
		while(!feof(read1)){
			//menampilkan isi file dengan mengambil data per line
			//lalu menampilkan ke layar dengan printf
			PENGAMBIL_LINE(isiFile1, MAX, read1);
			PRINTFILE(isiFile1);
		}

		sleep(1);
		printf("\n\n");

		printf("=================================================\n");
		printf("            	ISI FILE 2\n");
		printf("=================================================\n");
		while(!feof(read2)){
			//menampilkan isi file dengan mengambil data per line
			//lalu menampilkan ke layar dengan printf
			PENGAMBIL_LINE(isiFile2, MAX, read2);
			PRINTFILE(isiFile2);
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
			PENGAMBIL_LINE(kalimat1, MAX, file1);

			//memisahkan tanda baca dan spasi dalam kalimat per line
			//menjadi suatu kata yang disimpan pada array
			PENGCOPY(convert1, kalimat1);
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
		    	PENGCOPY(convert1, splitter[a]);
		    	for (int i = 0; convert1[i] != '\0'; i++) {
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
		    	printf("Hasil pengkonversian kata ke-1 to (int) : %d\n", intPenampung1);
		    	head1_1(&data1, intPenampung1);
		    	//dimasukkan ke struct data sebagai data pertama
		    	head1_2(&data2, splitter[1]);
		    	//dimasukkan ke struct data sebagai data pertama
		    	printf("Hasil pengkonversian kata ke-3 to (int) : %d\n", intPenampung2);
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
			PENGAMBIL_LINE(kalimat2, MAX, file2);

			//memisahkan tanda baca dan spasi dalam kalimat per line
			//menjadi suatu kata yang disimpan pada array
			PENGCOPY(convert2, kalimat2);
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

		    	PENGCOPY(convert2, splitter2[a]);
		    	for (int i = 0; convert2[i] != '\0'; i++) {
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
        		printf("Hasil pengkonversian kata ke-1 to (int) : %d\n", intPenampung1);
		    	head2_1(&data4, intPenampung1);
		    	//dimasukkan ke struct data sebagai data pertama
		    	head2_2(&data5, splitter2[1]);
		    	//dimasukkan ke struct data sebagai data pertama
		    	printf("Hasil pengkonversian kata ke-3 to (int) : %d\n", intPenampung2);
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
	#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	colorYippe1(color 76);//memperjelas informasi dengan merubah warna
	printf("PENGOLAHAN 2 FILE DATA SELESAI.\n");
	#endif
	
	#if defined __APPLE__ || __linux__ || __unix__
	printf("%sPENGOLAHAN 2 FILE DATA SELESAI.\n", black);
	#endif

	#if defined __APPLE__ || __linux__ || __unix__
	printf("%s\n", resetColor);
	#endif

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
	scanf("%s", namaFILE1);
	printf("file %s created on ", namaFILE1); WAKTU();

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
    	PENGCOPY(forCompare2, data2->nama);

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
	#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	colorYippe1(color 76);//mengubah color agar untuk memperjelas
	printf("MEMBANDINGKAN 2 FILE DATA SELESAI.\n");
	#endif
	
	#if defined __APPLE__ || __linux__ || __unix__
	printf("%sMEMBANDINGKAN 2 FILE DATA SELESAI.\n", white);
	#endif

	#if defined __APPLE__ || __linux__ || __unix__
	printf("%s\n", resetColor);
	#endif

	sleep(2);
}

/**
 * [printList1 : fungsi yang digunakan untuk menampilkan data list
 * @param *structData1 yang sebnarnya adalah list data1
 * @param *structData2 yang sebnarnya adalah list data2
 * @param *structData3 yang sebnarnya adalah list data3
 */
void printList1(struct_DATA1 *structData1, struct_DATA1 *structData2, struct_DATA1 *structData3){
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
void printList2(struct_DATA2 *structData1, struct_DATA2 *structData2, struct_DATA2 *structData3) {
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

void head1_1(struct_DATA1** new_head, int new_no){
	//membuat alokasi memori yang diperlukan
    struct_DATA1* new_data = (struct_DATA1*) malloc(sizeof(struct_DATA1));
    new_data->no = new_no;//memasukkan new no ke dalam no pada structData1
    new_data->lanjutan = (*new_head);//mengganti nilai yang dimasukkan menjadi head baru
    (*new_head) = new_data;//menjadikan data baru menjadi head baru
}

void head1_2(struct_DATA1** new_head, char new_nama[]){
	//membuat alokasi memori yang diperlukan
	struct_DATA1* new_data = (struct_DATA1*) malloc(sizeof(struct_DATA1));
    //memasukkan new_nama ke dalam nama pada structData1 dengan
    //metode pengkopian string
    PENGCOPY(new_data->nama, new_nama);
    new_data->lanjutan = (*new_head);//mengganti nilai yang dimasukkan menjadi head baru
    (*new_head) = new_data;//menjadikan data baru menjadi head baru
}

void head1_3(struct_DATA1** new_head, int new_tinggiBadan){
	//membuat alokasi memori yang diperlukan
	struct_DATA1* new_data = (struct_DATA1*) malloc(sizeof(struct_DATA1));
    new_data->tinggiBadan = new_tinggiBadan;//memasukkan new tinggiBadan ke dalam tinggiBadan pada structData1
    new_data->lanjutan = (*new_head);//mengganti nilai yang dimasukkan menjadi head baru
    (*new_head) = new_data;//menjadikan data baru menjadi head baru
}

void append1_1(struct_DATA1** new_head, int new_no){
	//membuat alokasi memori yang diperlukan
    struct_DATA1* new_data = (struct_DATA1*)malloc(sizeof(struct_DATA1));
    //data terakhir pada struct diindikasikan sebagai head baru
    struct_DATA1* dataTerakhir = *new_head;

    //memasukkan data baru ke structData1 no
    new_data->no = new_no;
    //memberikan tail untuk dataTerakhir
    new_data->lanjutan = NULL;

    while(dataTerakhir->lanjutan != NULL){
    	//menloop untuk mencari data secara terus menerus hingga
    	//data yang dicari tidak NULL karna NULL hanyalah dataTerakhir
        dataTerakhir = dataTerakhir->lanjutan;
    }
    
    //mengganti nilai yang dimasukkan menjadi head baru
    dataTerakhir->lanjutan = new_data;
}

void append1_2(struct_DATA1** new_head, char new_nama[]){
	//membuat alokasi memori yang diperlukan
    struct_DATA1* new_data = (struct_DATA1*)malloc(sizeof(struct_DATA1));
    //data terakhir pada struct diindikasikan sebagai head baru
    struct_DATA1* dataTerakhir = *new_head;

    //memasukan data baru ke struuctData1
    PENGCOPY(new_data->nama, new_nama);
    //memberikan tail untuk dataTerakhir
    new_data->lanjutan = NULL;

    while(dataTerakhir->lanjutan != NULL){
    	//menloop untuk mencari data secara terus menerus hingga
    	//data yang dicari tidak NULL karna NULL hanyalah dataTerakhir
        dataTerakhir = dataTerakhir->lanjutan;
    }
    
    //mengganti nilai yang dimasukkan menjadi head baru
    dataTerakhir->lanjutan = new_data;
}

void append1_3(struct_DATA1** new_head, int new_tinggiBadan){
	//membuat alokasi memori yang diperlukan
    struct_DATA1* new_data = (struct_DATA1*)malloc(sizeof(struct_DATA1));
    //data terakhir pada struct diindikasikan sebagai head baru
    struct_DATA1* dataTerakhir = *new_head;

    //memasukkan data baru ke structData1 tinggiBadan
    new_data->tinggiBadan = new_tinggiBadan;
    //memberikan tail untuk dataTerakhir
    new_data->lanjutan = NULL;

    while(dataTerakhir->lanjutan != NULL){
    	//menloop untuk mencari data secara terus menerus hingga
    	//data yang dicari tidak NULL karna NULL hanyalah dataTerakhir
        dataTerakhir = dataTerakhir->lanjutan;
    }
    
    //mengganti nilai yang dimasukkan menjadi head baru
    dataTerakhir->lanjutan = new_data;
}

void head2_1(struct_DATA2** new_head, int new_no){
	//membuat alokasi memori yang diperlukan
    struct_DATA2* new_data = (struct_DATA2*) malloc(sizeof(struct_DATA2));
    new_data->no = new_no;//memasukkan new no ke dalam no pada structData2
    new_data->lanjutan = (*new_head);//mengganti nilai yang dimasukkan menjadi head baru
    (*new_head) = new_data;//menjadikan data baru menjadi head baru
}

void head2_2(struct_DATA2** new_head, char new_nama[]){
	//membuat alokasi memori yang diperlukan
    struct_DATA2* new_data = (struct_DATA2*) malloc(sizeof(struct_DATA2));
    //memasukkan new_nama ke dalam nama pada structData2 dengan
    //metode pengkopian string
    PENGCOPY(new_data->nama, new_nama);
    new_data->lanjutan = (*new_head);//mengganti nilai yang dimasukkan menjadi head baru
    (*new_head) = new_data;//menjadikan data baru menjadi head baru
}

void head2_3(struct_DATA2** new_head, int new_tinggiBadan){
	//membuat alokasi memori yang diperlukan
    struct_DATA2* new_data = (struct_DATA2*) malloc(sizeof(struct_DATA2));
    new_data->tinggiBadan = new_tinggiBadan;//memasukkan new tinggiBadan ke dalam tinggiBadan pada structData1
    new_data->lanjutan = (*new_head);//mengganti nilai yang dimasukkan menjadi head baru
    (*new_head) = new_data;//menjadikan data baru menjadi head baru
}

void append2_1(struct_DATA2** new_head, int new_no){
	//membuat alokasi memori yang diperlukan
    struct_DATA2* new_data = (struct_DATA2*)malloc(sizeof(struct_DATA2));
    //data terakhir pada struct diindikasikan sebagai head baru
    struct_DATA2* dataTerakhir = *new_head;

    //memasukkan data baru ke structData1 no
    new_data->no = new_no;
    //memberikan tail untuk dataTerakhir
    new_data->lanjutan = NULL;

    while(dataTerakhir->lanjutan != NULL){
    	//menloop untuk mencari data secara terus menerus hingga
    	//data yang dicari tidak NULL karna NULL hanyalah dataTerakhir
        dataTerakhir = dataTerakhir->lanjutan;
    }
    
    //mengganti nilai yang dimasukkan menjadi head baru
    dataTerakhir->lanjutan = new_data;
}

void append2_2(struct_DATA2** new_head, char new_nama[]){
	//membuat alokasi memori yang diperlukan
    struct_DATA2* new_data = (struct_DATA2*)malloc(sizeof(struct_DATA2));
    //data terakhir pada struct diindikasikan sebagai head baru
    struct_DATA2* dataTerakhir = *new_head;

    //memasukan data baru ke struuctData2
    PENGCOPY(new_data->nama, new_nama);
    //memberikan tail untuk dataTerakhir
    new_data->lanjutan = NULL;

    while(dataTerakhir->lanjutan != NULL){
    	//menloop untuk mencari data secara terus menerus hingga
    	//data yang dicari tidak NULL karna NULL hanyalah dataTerakhir
        dataTerakhir = dataTerakhir->lanjutan;
    }
    
    //mengganti nilai yang dimasukkan menjadi head baru
    dataTerakhir->lanjutan = new_data;
}

void append2_3(struct_DATA2** new_head, int new_tinggiBadan){
	//membuat alokasi memori yang diperlukan
    struct_DATA2* new_data = (struct_DATA2*)malloc(sizeof(struct_DATA2));
    //data terakhir pada struct diindikasikan sebagai head baru
    struct_DATA2* dataTerakhir = *new_head;

    //memasukkan data baru ke structData2 tinggiBadan
    new_data->tinggiBadan = new_tinggiBadan;
    //memberikan tail untuk dataTerakhir
    //new_data->lanjutan = NULL;

    while(dataTerakhir->lanjutan != NULL){
    	//menloop untuk mencari data secara terus menerus hingga
    	//data yang dicari tidak NULL karna NULL hanyalah dataTerakhir
        dataTerakhir = dataTerakhir->lanjutan;
    }
    
    //mengganti nilai yang dimasukkan menjadi head baru
    dataTerakhir->lanjutan = new_data;
}

void head3_1(struct_DATA3** new_head, char new_nilai_sama1[]){
	//membuat alokasi memori yang diperlukan
    struct_DATA3* new_data = (struct_DATA3*) malloc(sizeof(struct_DATA3));
    //memasukkan new_nama ke dalam nama pada structData3 dengan
    //metode pengkopian string
    PENGCOPY(new_data->nilai_sama1, new_nilai_sama1);
    new_data->lanjutan = (*new_head);//mengganti nilai yang dimasukkan menjadi head baru
    (*new_head) = new_data;//menjadikan data baru menjadi head baru
}

void head3_2(struct_DATA3** new_head, int new_nilai_sama2){
	//membuat alokasi memori yang diperlukan
    struct_DATA3* new_data = (struct_DATA3*) malloc(sizeof(struct_DATA3));
    new_data->nilai_sama2 = new_nilai_sama2;//memasukkan new nilai_sama2 ke dalam nilai_sama2 pada structData3
    new_data->lanjutan = (*new_head);//mengganti nilai yang dimasukkan menjadi head baru
    (*new_head) = new_data;//menjadikan data baru menjadi head baru
}

void append3_1(struct_DATA3** new_head, char new_nilai_sama1[]){
	//membuat alokasi memori yang diperlukan
    struct_DATA3* new_data = (struct_DATA3*)malloc(sizeof(struct_DATA3));
    //data terakhir pada struct diindikasikan sebagai head baru
    struct_DATA3* dataTerakhir = *new_head;

    //memasukan data baru ke struuctData3
    PENGCOPY(new_data->nilai_sama1, new_nilai_sama1);
    //memberikan tail untuk dataTerakhir
    new_data->lanjutan = NULL;

    while(dataTerakhir->lanjutan != NULL){
    	//menloop untuk mencari data secara terus menerus hingga
    	//data yang dicari tidak NULL karna NULL hanyalah dataTerakhir
        dataTerakhir = dataTerakhir->lanjutan;
    }
    
    //mengganti nilai yang dimasukkan menjadi head baru
    dataTerakhir->lanjutan = new_data;
}

void append3_2(struct_DATA3** new_head, int new_nilai_sama2){
	//membuat alokasi memori yang diperlukan
    struct_DATA3* new_data = (struct_DATA3*)malloc(sizeof(struct_DATA3));
    //data terakhir pada struct diindikasikan sebagai head baru
    struct_DATA3* dataTerakhir = *new_head;

    //memasukkan data baru ke structData3 nilai_sama2
    new_data->nilai_sama2 = new_nilai_sama2;
    //memberikan tail untuk dataTerakhir
    //new_data->lanjutan = NULL;

    while(dataTerakhir->lanjutan != NULL){
    	//menloop untuk mencari data secara terus menerus hingga
    	//data yang dicari tidak NULL karna NULL hanyalah dataTerakhir
        dataTerakhir = dataTerakhir->lanjutan;
    }
    
    //mengganti nilai yang dimasukkan menjadi head baru
    dataTerakhir->lanjutan = new_data;
}

/**
 * [compare : membandingkan kedua file]
 * @param pembanding  [data struct dari data6]
 * @param pembanding2 [data struct dari data5]
 * @param cari_nama   [nama yang akan dicari]
 * @param cari        [tinggiBadan yang akan dicari]
 */
void compare(struct_DATA2 **pembanding, struct_DATA2 **pembanding2, char cari_nama[], int cari) { 
    //membuat struct penampung1 dimana akan memasukkan head data
    struct_DATA2* penampung = *pembanding;
    //membuat struct penampung2 dimana akan memasukkan head data
    struct_DATA2* penampung2 = *pembanding2;  
    
    //menghitung baris
    int baris1 = 2;
    int penghitung_nilai_sama = 1;

    while ( penampung != NULL ) {
    	//membandingkan kedua string
    	strcmp(penampung2->nama, cari_nama);
        if (penampung->tinggiBadan == cari || (strcmp(penampung2->nama, cari_nama) == false)) {
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

        	if (penghitung_nilai_sama == 1)
        	{
        		head3_1(&data7, penampung2->nama);
        		head3_2(&data8, penampung->tinggiBadan);
        	} else if (penghitung_nilai_sama > 1){
        		append3_1(&data7, penampung2->nama);
        		append3_2(&data8, penampung->tinggiBadan);
        	}
            
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
        penghitung_nilai_sama++;
    }
}

//fungsi ini hanya digunakan untuk memberikan identitas
//dan akan diproses saat exit
void identitas(){
	printf("\n\n");

	//suatu informasi sederhana
	#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	colorYippe1(color 71);
	printf("{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}}\n");
	#endif

	#if defined __APPLE__ || __linux__ || __unix__
	printf("%s{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}}\n", lightred);
	#endif

	sleep(2);

	#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	colorYippe1(color 73);
	printf(" TERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI.\n");
	#endif
	
	#if defined __APPLE__ || __linux__ || __unix__
	printf("%s TERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI.\n", yellow);
	#endif

	sleep(2);

	#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	colorYippe1(color 74);
	printf(" (C)Dibuat oleh Umar Hadi Pranoto.\n");
	#endif
	
	#if defined __APPLE__ || __linux__ || __unix__
	printf("%s (C)Dibuat oleh Umar Hadi Pranoto.\n", green);
	#endif

	sleep(2);

	#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	colorYippe1(color 75);
	printf(" Jangan Lupa Membuka File Output. :)\n");
	#endif
	
	#if defined __APPLE__ || __linux__ || __unix__
	printf("%s Jangan Lupa Membuka File Output. :)\n", blue);
	#endif

	sleep(2);

	#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	colorYippe1(color 76);
	printf("{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}}\n");
	#endif
	
	#if defined __APPLE__ || __linux__ || __unix__
	printf("%s{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}}\n", lightred);
	#endif

	sleep(2);
}