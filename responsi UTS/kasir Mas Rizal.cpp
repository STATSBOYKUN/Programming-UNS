#include <stdio.h>
#include <iostream>
#include <windows.h>

int total, i, a, b=0, nasi, ayam, paket, esteh, tempe, jamur, history[255], harga;
char ulang='y';

void countdown(){
	Sleep (1000);
	printf ("\n\n5 ");
	Sleep (750);
	printf ("4 ");
	Sleep (750);
	printf ("3 ");
	Sleep (750);
	printf ("2 ");
	Sleep (750);
	printf ("1 . . ");
	Sleep (1000);
	system ("cls");
}

int main (){
	system ("color g");
	while (ulang == 'y'|| ulang =='Y'){
		printf ("\n ======== WARUNG MAKAN KITA ======== \n");
		printf ("\n1. Menu Makanan\n2. Histroy pesanan\n3. Data Statistika\n0. Exit\n\nMasukkan pilihan ");
		scanf ("%d", &a);
		if (a==1){
			system ("cls");
			printf ("\n === Menu Warung Makan Kita === \n");
			printf ("1. Nasi \t= 3000\n2. Ayam \t= 6000\n3. Nasi+Ayam\t= 8000\n4. Es teh\t= 2000\n5. tempe\t= 500\n6. jamur\t= 5000\n");
			printf ("Jumlah pesanan nasi : ");
			scanf ("%d", &nasi);
			printf ("Jumlah pesanan ayam : ");
			scanf ("%d", &ayam);
			printf ("Jumlah pesanan paket : ");
			scanf ("%d", &paket);
			printf ("Jumlah pesanan es teh : ");
			scanf ("%d", &esteh);
			printf ("Jumlah pesanan tempe : ");
			scanf ("%d", &tempe);
			printf ("Jumlah pesanan jamur : ");
			scanf ("%d", &jamur);
			harga = nasi*3000+ayam*6000+paket*8000+esteh*2000+tempe*500+jamur*5000;
			printf ("\nHarga = %d", harga);
			history[b]=harga;
			b++;
			countdown ();
		}
		else  if (a==2){
			system ("cls");
			for (i=1; i<=b; i++){
				printf ("\nPesanan ke %d = %d\n", i, history[i-1]);
				total=total+history[i-1];
			}
			countdown();
			system("cls");
		}
		else if (a==3){
			system ("cls");
			printf ("\nTotal pengunjung = %d\n", b);
			printf ("Total pembelian hari ini = %d\n", total);
			printf ("\nRata-rata pembelian hari ini = %d\n", total/b);
			countdown();
			system ("cls");
		}
		else{
			printf ("Terima kasih :DD !!\n");
			break;
			
		}
	}
	
}

