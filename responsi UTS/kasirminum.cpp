#include <stdio.h>  
 #include <stdlib.h>  
 #include <string.h>  
 #include <windows.h>  
 char savedusername[24], savedpassword[24], username[24], password[24];  
 int i=0;  
 int k, kode, jml, harga, total=0;  
 int belanjaan[15][1];  
 void menu();  
 void warung();  
 int main()  
 {  
   strcpy(savedusername, "al");  
   strcpy(savedpassword, "bahri");  
   do{  
     printf("Username  : ");  
     gets(username);  
     printf("Password  : ");  
     gets(password);  
     if((strcmp(username, savedusername)==0)&&(strcmp(password, savedpassword)==0))  
     {  
       printf("\n=====================================\n");  
       printf("       SELAMAT DATANG\n");  
       printf("=====================================\n");  
       Sleep(2500);  
       system("cls");  
       warung();  
       break;  
     }  
     else  
     {  
       printf("=====================================\n");  
       printf("      PASSWORD SALAH\n");  
       printf("=====================================nn\n");  
       i++;  
       Sleep(2000);  
       system("cls");  
     }  
   }while(i<3);  
   if(i>=3)  
   {  
     printf("AKSES DITOLAKn\n");  
   }  
   printf("\n\n");  
   system("pause");  
   return 0;  
 }  
 void warung()  
 {  
   int k, kode, jml, harga, total=0;  
   int belanjaan[15][1];  
   struct data  
   {  
     int nomor;  
     char nama[20];  
     int harga;  
   };  
   struct data barang[4] =  
   {  
     1, "\tAqua Botol  \t", 3000,  
     2, "\tCoca-Cola  \t", 4000,  
     3, "\tFanta    \t", 3500,  
     4, "\tPulpy Oranges\t", 5000,  
   };  
   menu();  
   for (k=0;k<4;k++)  
   {  
     printf("%d",barang[k].nomor);  
     printf("%s",barang[k].nama);  
     printf("%d\n",barang[k].harga);  
   }  
   do{  
     printf("\nPesanan : ");  
     scanf ("%d %d", &kode, &jml);  
     total = total+(barang[kode-1].harga) * jml;  
   }while(kode != 0 && jml !=0);  
   system("cls");  
   Sleep(2000);  
   printf("=======================================\n");  
   printf("\nTOTAL HARGA: %d\n\n", total);  
   printf("=======================================\n");  
   printf("\n\n");  
   system("pause");  
   return;  
 }  
 void menu()  
 {  
   printf("++****************************************************++\n");  
   printf("           MENU MINUMAN\n");  
   printf("++****************************************************++n\n");  
   printf("   - Masukkan kode minuman jumlahnya\n");  
   printf("   - Contoh: 1 2\n");  
   printf("   - Ketik 0 0\n");  
   printf("    jika sudah selesai\n\n");  
   printf("++---------------------------------------------------++n\n");  
   printf("\no. tNama BarangtHarga\n");  
   printf("---- \t---------- \t------ \n");  
   return;  
 }  
