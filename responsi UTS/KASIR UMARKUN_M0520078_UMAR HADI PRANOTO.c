#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#define MAX 100

struct Buku {
	long long fiberCastel;
	long long u_Rek;
	long long strandat;
};
struct Pensil {
	long long fiberCastel1;
	long long u_Rek1;
	long long strandat1;
};
struct Bolpen {
	long long fiberCastel2;
	long long u_Rek2;
	long long strandat2;
};
struct Penghapus {
	long long fiberCastel3;
	long long u_Rek3;
	long long strandat3;
};
struct Rautan {
	long long fiberCastel4;
	long long u_Rek4;
	long long strandat4;
};
union penunjukWaktu	{
	int menit;
	int detik;
};

void pukul();
void petugas();
void pilihan();
long long sum(long long aa1, long long ab1, long long ac1, long long ad1, long long ae1, long long af1, long long ag1, 
			  long long ah1, long long ai1, long long aj1, long long ak1, long long al1, long long am1, long long an1, 
			  long long ao1);
void kodePembayaran();

int main(){

	system("color 72");
	petugas();
	system("pause");

	pukul();
	return 0;
}

void pukul(){

	union penunjukWaktu menit1;
	union penunjukWaktu detik1;

	int jam = 10;
	menit1.menit = 10;
	detik1.detik = 10;
	
	pukul:
	for (jam; jam < 24; jam++){
		for (menit1.menit; menit1.menit >= 0; menit1.menit--){
			for (detik1.detik; detik1.detik >= 0; detik1.detik--){
				system("cls");
				printf("TOKO UM_UM KUN. Ahad, 1 Januari 2021.\n");	
				printf("Closes in %d : %d : %d WIN", jam, menit1.menit, detik1.detik);
				printf("\n\n");
				printf("Hari Senin  10.00 - 22.00 WIN\n");
				printf("Hari Selasa 10.00 - 22.00 WIN\n");
				printf("Hari Rabu   10.00 - 22.00 WIN\n");
				printf("Hari Kamis  10.00 - 22.00 WIN\n");
				printf("Hari Jumat  10.00 - 22.00 WIN\n");
				printf("Sabtu dan Ahad tidak tutup.\n");

				for (double i = 0; i < 49009801; ++i) {
				}
			}
			detik1.detik = 60;
		}
		menit1.menit = 60;
	}
	jam = 60;

	goto pukul;
}

void petugas(){
	char savedusername[MAX], savedpassword[MAX], username[MAX], password[MAX];
	int i = 0;
	strcpy(savedusername, "umarkun");  
   	strcpy(savedpassword, "12345");

   	do{
   		system("cls");  
     	printf("Username  : ");  
     	gets(username);  
     	printf("Password  : ");  
     	gets(password);  
     	if((strcmp(username, savedusername) == 0) && (strcmp(password, savedpassword) == 0)){  
       		Sleep(1000);  
       		system("cls");
       		pilihan();
       		break;  
    	}else{
    		printf("Ulangi...");  
       		i++;  
       		Sleep(1000);  
       		system("cls");
       	}  
    }while(i < 3);  
   	if(i >= 3) {
   		printf("MEMFOTO KONDISI...\n");
     	printf("CALLING 911...\n");
     	system("pause");  
   	}	     
}

void pilihan(){
	belanja:
	printf("\n         Selamat Datang di Toko Um-Um kun!\n\n");
	printf("============================================================\n");
	printf(" No.|     Nama Barang   |  Harga Barang(Rupiah) |\n");
	printf("----|-------------------|-----------------------|\n");
	printf("1) 	Buku Merk\n");
	printf("	 a)fiberCastel 		Rp.7500.00\n");
	printf("	 b)u_Rek 		Rp.5000.00\n");
	printf("	 c)strandat 		Rp.6500.00\n");

	printf("2) 	Pensil Merk\n");
	printf("	 a)fiberCastel 		Rp.2500.00\n");
	printf("	 b)u_Rek 		Rp.1500.00\n");
	printf("	 c)strandat 		Rp.2000.00\n");

	printf("3) 	Bolpen Merk\n");
	printf("	 a)fiberCastel 		Rp.5000.00\n");
	printf("	 b)u_Rek 		Rp.4500.00\n");
	printf("	 c)strandat 		Rp.6000.00\n");

	printf("4) 	Penghapus Merk\n");
	printf("	 a)fiberCastel 		Rp.2000.00\n");
	printf("	 b)u_Rek 		Rp.1000.00\n");
	printf("	 c)strandat 		Rp.1500.00\n");

	printf("5) 	Rautan Merk\n");
	printf("	 a)fiberCastel 		Rp.3000.00\n");
	printf("	 b)u_Rek 		Rp.500.00\n");
	printf("	 c)strandat 		Rp.1000.00\n");
	printf("============================================================\n");

	enum barang {idBuku = 1, idPensil = 2, idBolpen = 3, idPenghapus = 4, idRautan = 5};
	enum merk {idfiberCastel = 1, idu_Rek = 2, idstrandat = 3};
	int barang, merk;

	long long aa = 0, ab = 0, ac = 0, ad = 0, ae = 0, af = 0, ag = 0, ah = 0, 
			  ai = 0, aj = 0, ak = 0, al = 0, am = 0, an = 0, ao = 0;
	long long aa1 = 0, ab1 = 0, ac1 = 0, ad1 = 0, ae1 = 0, af1 = 0, ag1 = 0, 
			  ah1 = 0, ai1 = 0, aj1 = 0, ak1 = 0, al1 = 0, am1 = 0, an1 = 0, ao1 = 0, uang;

	ulang:
	printf(" Tekan angka 1-5 untuk memilih barang : ");
	scanf("%d", &barang);

	switch(barang){
		case idBuku:
		ulang1:
			printf("Tekan 1-3 untuk memilih merk : ");
			scanf("%d", &merk);

			switch(merk){
				struct Buku a;
				struct Buku b;
				struct Buku c;

				case idfiberCastel:
				printf("Buku merk fiberCastel 		: ");
				scanf("%lld", &aa);
				a.fiberCastel = 7500;
				aa1 = aa * a.fiberCastel;
				
 				case idu_Rek:
 				printf("Buku merk u_Rek 		: ");
				scanf("%lld", &ab);
				b.u_Rek = 5000;
				ab1 = ab * b.u_Rek;
				
				case idstrandat:
				printf("Buku merk strandat 		: ");
				scanf("%lld", &ac);
				c.strandat = 6500;
				ac1 = ac * c.strandat;
				break;

				default:
				goto ulang1;
				
			}
		case idPensil:
		ulang2:
			printf("Tekan 1-3 untuk memilih merk : ");
			scanf("%d", &merk);

			switch(merk){
				struct Pensil d;
				struct Pensil e;
				struct Pensil f;

				case idfiberCastel:
				printf("Pensil merk fiberCastel 	: ");
				scanf("%lld", &ad);
				d.fiberCastel1 = 2500;
				ad1 = ad * d.fiberCastel1;

 				case idu_Rek:
 				printf("Pensil merk u_Rek 		: ");
				scanf("%lld", &ae);
				e.u_Rek1 = 1500;
				ae1 = ae * e.u_Rek1;

				case idstrandat:
				printf("Pensil merk strandat 		: ");
				scanf("%lld", &af);
				f.strandat1 = 2000;
				af1 = af * f.strandat1;
				break;

				default:
				goto ulang2;
	
			}
		case idBolpen:	ulang3:
			printf("Tekan 1-3 untuk memilih merk : ");
			scanf("%d", &merk);

			switch(merk){
				struct Bolpen g;
				struct Bolpen h;
				struct Bolpen i;

				case idfiberCastel:
				printf("Bolpen merk fiberCastel 	: ");
				scanf("%lld", &ag);
				g.fiberCastel2 = 5000;
				ag1 = ag * g.fiberCastel2;

 				case idu_Rek:
 				printf("Bolpen merk u_Rek 		: ");
				scanf("%lld", &ah);
				h.u_Rek2 = 4500;
				ah1 = ah * h.u_Rek2;

				case idstrandat:
				printf("Bolpen merk strandat 		: ");
				scanf("%lld", &ai);
				i.strandat2 = 6000;
				ai1 = ai * i.strandat2;
				break;

				default:
				goto ulang3;
			}

		case idPenghapus:
		ulang4:
			printf("Tekan 1-3 untuk memilih merk : ");
			scanf("%d", &merk);

			switch(merk){
				struct Penghapus j;
				struct Penghapus k;
				struct Penghapus l;

				case idfiberCastel:
				printf("Penghapus merk fiberCastel 	: ");
				scanf("%lld", &aj);
				j.fiberCastel3 = 2000;
				aj1 = aj * j.fiberCastel3;

 				case idu_Rek:
 				printf("Penghapus merk u_Rek 		: ");
				scanf("%lld", &ak);
				k.u_Rek3 = 1000;
				ak1 = ak * k.u_Rek3;

				case idstrandat:
				printf("Penghapus merk strandat 	: ");
				scanf("%lld", &al);
				l.strandat3 = 1500;
				al1 = al * l.strandat3;
				break;

				default:
				goto ulang4;
			}

		case idRautan:
		ulang5:
			printf("Tekan 1-3 untuk memilih merk : ");
			scanf("%d", &merk);

			switch(merk){
				struct Rautan m;
				struct Rautan n;
				struct Rautan o;

				case idfiberCastel:
				printf("Rautan merk fiberCastel 	: ");
				scanf("%lld", &am);
				m.fiberCastel4 = 3000;
				am1 = am * m.fiberCastel4;

 				case idu_Rek:
 				printf("Rautan merk u_Rek 		: ");
				scanf("%lld", &an);
				n.u_Rek4 = 500;
				an1 = an * n.u_Rek4;

				case idstrandat:
				printf("Rautan merk strandat 		: ");
				scanf("%lld", &ao);
				o.strandat4 = 1000;
				ao1 = ao * o.strandat4;
				break;

				default:
				goto ulang5;
			}
			break;

		default:
		goto ulang;
		
	}

	long long totalBelanja;
	totalBelanja = sum(aa1, ab1, ac1, ad1, ae1, af1, ag1, ah1, ai1, aj1, ak1, al1, am1, an1, ao1);
	system("cls");

	printf("\nDaftar Pembelian Anda    :  \n");
	printf("================================================================================\n");
	printf(" No. |   Nama Barang  |  Harga Barang(Rupiah) | Jumlah Barang |    Subtotal   |\n");
	printf("-----|----------------|-----------------------|---------------|---------------|\n");
	printf("1) 	Buku Merk\n");
	printf("	 a)fiberCastel 		Rp.7500.00	: %lld		Rp.%lld.00\n", aa, aa1);
	printf("	 b)u_Rek 		Rp.5000.00	: %lld		Rp.%lld.00\n", ab, ab1);
	printf("	 c)strandat 		Rp.6500.00	: %lld		Rp.%lld.00\n", ac, ac1);

	printf("2) 	Pensil Merk\n");
	printf("	 a)fiberCastel 		Rp.2500.00	: %lld		Rp.%lld.00\n", ad, ad1);
	printf("	 b)u_Rek 		Rp.1500.00	: %lld		Rp.%lld.00\n", ae, ae1);
	printf("	 c)strandat 		Rp.2000.00	: %lld		Rp.%lld.00\n", af, af1);

	printf("3) 	Bolpen Merk\n");
	printf("	 a)fiberCastel 		Rp.5000.00	: %lld		Rp.%lld.00\n", ag, ag1);
	printf("	 b)u_Rek 		Rp.4500.00	: %lld		Rp.%lld.00\n", ah, ah1);
	printf("	 c)strandat 		Rp.6000.00	: %lld		Rp.%lld.00\n", ai, ai1);

	printf("4) 	Penghapus Merk\n");
	printf("	 a)fiberCastel 		Rp.2000.00	: %lld		Rp.%lld.00\n", aj, aj1);
	printf("	 b)u_Rek 		Rp.1000.00	: %lld		Rp.%lld.00\n", ak, ak1);
	printf("	 c)strandat 		Rp.1500.00	: %lld		Rp.%lld.00\n", al, al1);

	printf("5) 	Rautan Merk\n");
	printf("	 a)fiberCastel 		Rp.3000.00	: %lld		Rp.%lld.00\n", am, am1);
	printf("	 b)u_Rek 		Rp.500.00	: %lld		Rp.%lld.00\n", an, an1);
	printf("	 c)strandat 		Rp.1000.00	: %lld		Rp.%lld.00\n", ao, ao1);
	printf("================================================================================\n");
	printf("Total yang harus dibayar	: 	Rp.%lld.00\n", totalBelanja);

	printf("\n");
	printf("Dapatkan diskon 5%% !!!. Dengan tebak angka 1-25(kesempatan hanya 2x)\n");

	int diskon = 1;
	int coba;

	while(diskon <= 2 && diskon >= 1){
		printf("Angka : ");
		scanf("%d", &coba);
		if (coba == 13)	{
			printf("Selamat Anda mendapat diskon 5%% !!!\n");
			printf("Uang Anda			: 	Rp.");scanf("%lld", &uang);
			printf("Kembalian			: 	Rp.%lld.00\n", (uang - ((totalBelanja *95)/100)));
			break;
		}else if(diskon < 2){
			diskon = diskon + 1;
			continue;
		}else{
			diskon = diskon + 1;
			printf("Yahh kesempatanmu habiss.\n\n");
			printf("Uang Anda			: 	Rp.");scanf("%lld", &uang);
			printf("Kembalian			: 	Rp.%lld.00\n", uang - totalBelanja);
			break;
		}		
	}

	printf("\n");
	kodePembayaran();

	printf("Terima kasih telah belanja di toko kami. :)\n");
}

void kodePembayaran(){
	long long *kodePembayaran1;
	*kodePembayaran1 = 0;
	long long kode[2];
	srand(time(0));

	for (int y = 0; y < 2; y++) {
		kode[y] = rand();
	}

	for (int z = 0; z < 2; z++)	{
		*kodePembayaran1 = rand() & kode[z]; 
	}

	printf("Kode Pembayaran : %lld(%lld****)\n", *kodePembayaran1, &kodePembayaran1);
}

long long sum(long long aa1, long long ab1, long long ac1, long long ad1, long long ae1, long long af1, long long ag1, 
			  long long ah1, long long ai1, long long aj1, long long ak1, long long al1, long long am1, long long an1, 
			  long long ao1){
	long long total;
	total = aa1 + ab1 + ac1 + ad1 + ae1 + af1 + ag1 + ah1 + ai1 + aj1 + ak1 + al1 + am1 + an1 + ao1;

	return total;
}