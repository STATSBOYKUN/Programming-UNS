#include <stdio.h>
#include <conio.h>
#include <windows.h>
main(){
	typedef char* string;
	string nama[11]={"a","Pensil","Binder","Eraser","Pulpen","lakban","Ruler","Rautan","Cutter","Spidol","Jangka"};
	string urutan[11]={"a","Pertama","Kedua","Ketiga","Keempat","Kelima","Keenam","Ketujuh","Kedelapan","Kesembilan","Kesepuluh"};
	int jumlah = 0, t, i, n[1000], y, x, kembali, nobeli, nomor[1000], tt[1000], u;
	int harga[]={1100,3500,8500,1500,2500,2500,3500,1000,2500,5500,2500}, d[1000], tot[1000];
	double total = 0, uang;
	awal:
	system("color a");
	i = 0, x = 0, y = 0,nobeli = 0,kembali = 0,uang = 0, total = 0;
	printf("\n              Selamat Datang di Toko ATK Kami! Selamat berbelanja!\n\n");
	printf("================================================================================\n");
	printf(" No.|     Nama Barang   |  Harga Barang(Rupiah) |\n");
	printf("----|-------------------|-----------------------|\n");
	for(i = 1; i < 11 ; i++) {
		printf("%3d |%13s      |      Rp.%5d.00      |\n", i, nama[i], harga[i]);  }
		printf("===============================================================================\n");
		do{
			printf("Berapa Jenis barang yang anda beli  : ");
		    scanf("%d", &x);
		    if(x > 10){
			printf("\nJenis barang yang anda masukkan salah! Barang hanya dari 1 sampai 10!  \n\tSilahkan Ulangi lagi!\n\n");}
		}while(x > 10);
		for(i = 1; i <= x ; i++){
			do{
				printf("\nMasukkan Nomor barang %s : ", urutan[i]);scanf("%d", &d[i]);
				y = d[i];
				if (y > 10){
					printf("Maaf nomor barang hanya sampai 10");
				}
		}while (y > 10);
      		printf("Masukkan jumlah barang  : ");
      		scanf("%d", &n[i]);
      		y = d[i];
      		tot[y] = n[i] * harga[y];
      		total = tot[y] + total;
		}
	system("cls");
	printf("\nDaftar Pembelian Anda    :  \n");
	printf("================================================================================");
	printf(" No. |   Nama Barang  |  Harga Barang(Rupiah) | Jumlah Barang |    Subtotal   |\n");
	printf("-----|----------------|-----------------------|---------------|---------------|\n");
	for(i = 1; i <= x ; i++){
		y = d[i];
		tt[i] = n[i] * harga[y];
		nobeli = d[i];
		printf("%3d  |   %8s    |      Rp.%2d.00       |    %4d     |  Rp. %d.00\t |\n",i,  nama[nobeli], harga[nobeli],n[i], tt[i]);
	}
	printf("===============================================================================\n");
	printf("\n");
	printf("Totalnya yang anda bayar adalah     : Rp. %.2lf\n\n", total);
	u = 0;
	do{
		printf("Masukkan uang anda                  : Rp. ");
		scanf("%lf", &uang);
		if (uang < total)
		if(u == 0){
			printf("\a\n\tMaaf uang anda kurang silahkan ulangi proses transaksi!!\n \t Silahkan masukkan lagi uang anda!\n\n");
		}else{
			continue;
		}u++;
	}while (uang < total);
	kembali = uang - total;
	printf("\nKembalian anda                      : Rp. %d.00", kembali);
	printf("\n\n                     Terima Kasih Telah Bertransaksi              \n");
	printf("\n_________________________________________________________________________\n\n");
	getch();
	printf("Apakah anda ingin kembali ke daftar barang (Y/T) : ");getchar();scanf("%c", &t);
	if((t == 'Y') || (t == 'y')){
	system("cls"); goto awal;
	}getch();
}


