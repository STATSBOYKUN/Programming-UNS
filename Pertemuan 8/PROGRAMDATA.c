#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#define MAX 100

struct structMahasiswa {
   int no;
   char nama[MAX];
   char nim[MAX];
   char dosen[MAX];
};

int menu( void );
void lihatData( FILE *lihatDataMahasiswa );
void ubahData( FILE *fileMahasiswa );
void tambahData( FILE *fileMahasiswa );
void hapusData( FILE *fileMahasiswa );

int main(){
   system("color 72");
   FILE *fileDataMahasiswa;
   int pilihan;
   enum opsi{ TAMBAH = 1, UBAH = 2, LIHAT = 3, HAPUS = 4, EXIT = 5 };

   if ( ( fileDataMahasiswa = fopen( "UNS.bin", "rb+" ) ) == NULL ) {
      printf("Filenya tidak bisa dibuka.");
   }else {
      while ( ( pilihan = menu() ) != 5 ) {
         switch( pilihan ) {
            case TAMBAH:             
               tambahData(fileDataMahasiswa);
               Sleep(1000);
               break;

            case UBAH:               
               ubahData(fileDataMahasiswa);
               Sleep(1000);
               break;

            case LIHAT:
               lihatData(fileDataMahasiswa);
               Sleep(2000);
               break;

            case HAPUS:
               hapusData(fileDataMahasiswa);
               Sleep(1000);
               break;

            case EXIT:
               exit(0);
               break;

            default:
               break;
         }
      }
      Sleep(1000);
      fclose( fileDataMahasiswa );
   }

   return 0;
}

int menu( void ){
   Sleep(750);
   system("cls");
   int angka;

   printf( "    DATA MAHASISWA UNS\n" );
   printf( "{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}\n" );
   printf( "1) Tambah Data Mahasiswa\n" );
   printf( "2) Ubah Data Mahasiswa\n" );
   printf( "3) Export data\n" );
   printf( "4) Hapus Data Mahasiswa\n" );
   printf( "5) exit\n" );
   printf( "{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}\n\n" );
   printf( "Jangan lupa untuk mengexport data.\n");
   printf( "Perintah Anda : " );
   scanf( "%d", &angka );

   return angka;
}

void lihatData( FILE *lihatDataMahasiswa ) {
   FILE *bacaDataMahasiswa;
   int hasil;
   struct structMahasiswa mahasiswa = { 0, "", "", ""};

   if ( ( bacaDataMahasiswa = fopen( "DataMahasiswaUNS.txt", "w" ) ) == NULL ) {
      printf( "Filenya tidak bisa dibuka." );
   } else {
      rewind(lihatDataMahasiswa);
      fprintf(bacaDataMahasiswa, "%-8s%-12s%-14s%-7s\n", "|No", "|Nama", "|NIM", "|Dosen      |");
      fprintf(bacaDataMahasiswa, "%s\n", "-----------------------------------------------");      

      printf("%-8s%-12s%-14s%-7s\n", "|No", "|Nama", "|NIM", "|Dosen      |");
      printf("%s\n", "-----------------------------------------------");
      while(!feof(lihatDataMahasiswa)) {
         hasil = fread(&mahasiswa, sizeof(struct structMahasiswa), 1, lihatDataMahasiswa);

         if ( hasil != 0 && mahasiswa.no != 0 ) { 
            printf("%-8d %-12s %-14s %-7s\n", 
               mahasiswa.no, mahasiswa.nama, 
               mahasiswa.nim, mahasiswa.dosen
            );
            fprintf( bacaDataMahasiswa, "%-8d %-12s %-14s %-7s\n",
               mahasiswa.no, mahasiswa.nama, 
               mahasiswa.nim, mahasiswa.dosen
            );      
         }  
      }

      fclose(bacaDataMahasiswa);
   }
}

void ubahData( FILE *fileMahasiswa ) {
   int dataKe;
   struct structMahasiswa mahasiswa = { 0, "", "", ""};

   printf( "Data yang mau diubah : ");
   scanf( "%d", &dataKe );

   fseek( fileMahasiswa, ( dataKe - 1 ) * sizeof( struct structMahasiswa ), SEEK_SET );                                              
   fread( &mahasiswa, sizeof( struct structMahasiswa ), 1, fileMahasiswa );

   if ( mahasiswa.no == 0 ) {
      printf( "data ke -%d tidak ditemukan.\n", dataKe );
   } else {
      printf( "%-8d%-12s%-14s%-7s\n", 
         mahasiswa.no, mahasiswa.nama, 
         mahasiswa.nim, mahasiswa.dosen
      );

      printf( "No       : " );
      scanf( "%d", &mahasiswa.no );
      printf( "Nama     : " );
      scanf( "%10s", &mahasiswa.nama );
      printf( "NIM      : " );
      scanf( "%10s", &mahasiswa.nim );
      printf( "Dosen    : " );
      scanf( "%10s", &mahasiswa.dosen );
                 
      fseek( fileMahasiswa, ( dataKe - 1 ) * sizeof( struct structMahasiswa ), SEEK_SET );                                                      
      fwrite( &mahasiswa, sizeof( struct structMahasiswa ), 1, fileMahasiswa );
   }
}

void tambahData( FILE *fileMahasiswa ) {
   struct structMahasiswa mahasiswa = { 0, "", "", "" };
   int dataKe;

   printf( "Data keberapa yang mau ditambah : " );
   scanf( "%d", &dataKe );
              
   fseek( fileMahasiswa, ( dataKe - 1 ) * sizeof( struct structMahasiswa ), SEEK_SET );                                                                           
   fread( &mahasiswa, sizeof( struct structMahasiswa ), 1, fileMahasiswa );

   if ( mahasiswa.no != 0 ) {
      printf( "Maaf ya, data tersebut sudah diisi.\n", mahasiswa.no );
   } else {
      printf( "No       : " );
      scanf( "%d", &mahasiswa.no );
      printf( "Nama     : " );
      scanf( "%10s", &mahasiswa.nama );
      printf( "NIM      : " );
      scanf( "%10s", &mahasiswa.nim );
      printf( "Dosen    : " );
      scanf( "%10s", &mahasiswa.dosen );

      mahasiswa.no = dataKe;
      fseek( fileMahasiswa, ( mahasiswa.no - 1 ) * sizeof( struct structMahasiswa ), SEEK_SET );                         
      fwrite( &mahasiswa, sizeof( struct structMahasiswa ), 1, fileMahasiswa );     
   }
}

void hapusData( FILE *fileMahasiswa ){
   struct structMahasiswa mahasiswa;
   struct structMahasiswa hapusmahasiswa = { 0, "", "", "" };
   int dataKe;

   printf( "Data keberapa yang mau dihapus : " );
   scanf( "%d", &dataKe );
           
   fseek( fileMahasiswa, ( dataKe - 1 ) * sizeof( struct structMahasiswa ), SEEK_SET );                                                                        
   fread( &mahasiswa, sizeof( struct structMahasiswa ), 1, fileMahasiswa );

   if ( mahasiswa.no == 0 ) {
      printf( "data ke -%d tidak ditemukan.\n", dataKe );
   } else {               
      fseek( fileMahasiswa, ( dataKe - 1 ) * sizeof( struct structMahasiswa ), SEEK_SET );                                                 
      fwrite( &hapusmahasiswa, sizeof( struct structMahasiswa ), 1, fileMahasiswa );     
   }
}