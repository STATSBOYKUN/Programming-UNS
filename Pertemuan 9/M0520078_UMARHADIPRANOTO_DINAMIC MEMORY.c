#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Membuat objek menggunakan struct
struct Node{
  int data;
  struct Node *next;
};

struct stackNode {                                   
  int data;           
  struct stackNode *nextPtr;
};

struct queueNode {                                   
  int data;           
  struct queueNode *nextPtr;
};

//membuat menu
int menu();
int menuA();
int menuB();
int menuC();

//Command-command linked list
void push(struct Node** head_ref, int new_data);
void append(struct Node** head_ref, int new_data);
void insertAfter(struct Node* prev_node, int new_data);
void deleteNode(struct Node **head_ref, int key);
void deleteAt(struct Node **head_ref, int position);
void printList(struct Node *node);

//Command-command stack
void pushStack( struct stackNode **topPtr, int info );
int pop( struct stackNode **topPtr );
int stackEmpty( struct stackNode* topPtr );
void printStack( struct stackNode *currentPtr );

//Command-command queue
void enqueue( struct queueNode **headPtr, struct queueNode **tailPtr, int value );
int dequeue( struct queueNode **headPtr, struct queueNode **tailPtr );
int queueEmpty( struct queueNode *headPtr );
void printQueue( struct queueNode *titikSaatIni );

int main(){
  system("color 72");
  struct Node* headList = NULL;
  struct stackNode* topStack = NULL;
  struct queueNode* headQueue = NULL;
  struct queueNode* tailQueue = NULL;

  int dataList;
  int dataStack;
  char dataQueue;
  int dataKe;

	int opsi, opsi2, opsi3, opsi4;

	enum enum1{idLINKEDLIST = 1, idSTACK = 2, idQUEUE = 3, EXIT = 4};
  enum enum2{TAMBAHDIAWAL = 1, TAMBAHDITENGAH = 2, TAMBAHDIAKHIR = 3, DELETEDATA = 4, DELETEAT = 5};
	enum enum3{PUSH = 1, POP = 2};
	enum enum4{ENQUEUE = 1, DEQUEUE = 2};

	while((opsi = menu()) != 4){
		switch(opsi){
			case idLINKEDLIST:
      while((opsi2 = menuA()) != 6){
				switch(opsi2){
					case TAMBAHDIAWAL:
          printf("Anime dengan rating : ");
          scanf("%d", &dataList);
          push(&headList, dataList);
          printList(headList);
					break;

          case TAMBAHDITENGAH:
          printf("Anime dengan rating : ");
          scanf("%d", &dataList);
          insertAfter(headList->next, dataList);
          printList(headList);
          break;

          case TAMBAHDIAKHIR:
          printf("Anime dengan rating : ");
          scanf("%d", &dataList);
          append(&headList, dataList);
          printList(headList);
          break;

					case DELETEDATA:
          printList(headList);
          printf("Anime dengan rating yang akan dihapus: ");
          scanf("%d", &dataList);
          deleteNode(&headList, dataList);
          printList(headList);
					break;

          case DELETEAT:
          printList(headList);
          printf("\nData anime keberapa yang akan dihapus: ");
          scanf("%d", &dataList);
          deleteAt(&headList, (dataList - 1));
          printList(headList);
          break;

					default: 
					break;
				}
      }
			break;

			case idSTACK:
      while((opsi3 = menuB()) != 3){
				switch(opsi3){
					case PUSH:
          printf("Piring dengan ukuran : ");
          scanf("%d", &dataStack);
          pushStack(&topStack, dataStack);
          printStack(topStack);
					break;

					case POP:
          if (!stackEmpty(topStack)){
              pop(&topStack);
              printf("Piring paling atas diambil.\n");
          }
          printStack(topStack);
					break;

					default: 
					break;
				}
      }
			break;

			case idQUEUE:
      while((opsi4 = menuC()) != 3){
				switch(opsi4){
					case ENQUEUE:
          printf("%s", "Antrean dari distrik : ");
          scanf("%d", &dataQueue);
          enqueue(&headQueue, &tailQueue, dataQueue);
          printQueue(headQueue);
					break;

					case DEQUEUE:
          if (!queueEmpty(headQueue)) {
              dequeue( &headQueue, &tailQueue );
              printf("Antrean paling depan telah selesai.\n");
          }
          printQueue(headQueue);
					break;

					default: 
					break;
				}
      }
			break;

			default:
      exit(0); 
			break;
		}
	}
	
	return 0;
}

int menu(){
  Sleep(1500);
  system("cls");

	int menu;
	printf("    PROGRAM DINAMIC STORAGE\n");
	printf("<=============================>\n");
	printf(" 1) LINKEDLIST\n");
	printf(" 2) STACK\n");
	printf(" 3) QUEUE\n");
	printf(" 4) EXIT\n");
	printf("<=============================>\n");
	printf("Perintah Anda \n?");
	scanf("%d", &menu);

	return menu;
}

int menuA(){
  Sleep(1500);
  system("cls");

	int menu1;
	printf(" PROGRAM DINAMIC STORAGE : LINKEDLIST\n");
	printf("<===================================>\n");
	printf(" 1) TAMBAH DATA ANIME DI AWAL\n");
	printf(" 2) TAMBAH DATA ANIME DI TENGAH\n");
  printf(" 3) TAMBAH DATA ANIME DI AKHIR\n");
	printf(" 4) DELETE DATA ANIME\n");
  printf(" 5) DELETE DATA ANIME PADA\n");
	printf(" 6) EXIT\n");
	printf("<===================================>\n");
	printf("Perintah Anda (1-6)\n?");
	scanf("%d", &menu1);

	return menu1;
}

int menuB(){
  Sleep(1500);
  system("cls");

	int menu2;
	printf(" PROGRAM DINAMIC STORAGE : STACK\n");
	printf("<===================================>\n");
	printf(" 1) TAMBAH PIRING\n");
	printf(" 2) AMBIL PIRING\n");
	printf(" 3) EXIT\n");
	printf("<===================================>\n");
	printf("Perintah Anda (1-3)\n?");
	scanf("%d", &menu2);

	return menu2;
}

int menuC(){
  Sleep(1500);
  system("cls");

	int menu3;
	printf(" PROGRAM DINAMIC STORAGE : QUEUE\n");
	printf("<===================================>\n");
	printf(" 1) TAMBAH ANTREAN\n");
	printf(" 2) SELESAIKAN ANTREAN\n");
	printf(" 3) EXIT\n");
	printf("<===================================>\n");
	printf("Perintah Anda (1-3)\n?");
	scanf("%d", &menu3);

	return menu3;

}

// buat method buat ngepush
void push(struct Node** head_ref, int new_data){
  // 1. Mengalokasikan data
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

  // 2. Masukin data ke node baru
  new_node->data = new_data;

  //3. Masukin head node yang sekarang ke next node baru
  new_node->next = (*head_ref);

  //4. Sekarang jadiin new node jadi head node
  (*head_ref) = new_node;
}

//Bikin fungsi buat append
//Append itu nambahin data di belakang
//Berbeda dengan push, kalau push insertnya dari depan
void append(struct Node** head_ref, int new_data){
  // 1. Bikin node baru
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  //2. Buat node baru untuk iterasi pointer ke node terakhir
  struct Node* last = *head_ref;

  //3. Masukin data ke node baru
  new_node->data = new_data;

  //4. Buat nilai next dari node baru menjadi null
  // karena node terakhir pasti nilai akhirnya null
  new_node->next = NULL;

  //5. Cek jika node itu sepenuhnya kosong
  // berarti tinggal masukin aja tanpa harus nyari node terakhir
  if(*head_ref == NULL){
    *head_ref = new_node;
    return;
  }

  //6. Kalau nggak kosong, maka kita harus nyari dulu node terakhi
  // Node terakhir ini digunakan untuk jadi tempat nambahin data
  while(last->next != NULL) {
    last = last->next;
  }

  //7. Ganti nilai last->next jadi new node
  last->next = new_node;
  return;
}

//Bikin method buat nambahin data di tengah-tengah node
void insertAfter(struct Node* prev_node, int new_data){
  //1. Cek dulu, kalau nodesebelumnya kosong, berarti bukan insert dong tapi push harusnya
  if(prev_node == NULL){
    printf("Data sebelumnnya tidak boleh kosong\n");
    return;
  }

  //2. Bikin node baru
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

  //3. Masukin data ke node baru
  new_node->data = new_data;

  //4. Masukin next dari prev node ke next node baru
  new_node->next = prev_node->next;

  //5. Jadikan next dari prev node menjadi node baru
  prev_node->next = new_node;
}

// Method buat delete
void deleteNode(struct Node **head_ref, int key) { 
  // Store head node 
  struct Node* temp = *head_ref, *prev; 
  
  // If head node itself holds the key to be deleted 
  if (temp != NULL && temp->data == key) { 
    *head_ref = temp->next;   // Changed head 
    free(temp);               // free old head 
    return; 
  } 
  
  // Search for the key to be deleted, keep track of the 
  // previous node as we need to change 'prev->next' 
  while (temp != NULL && temp->data != key) { 
    prev = temp; 
    temp = temp->next; 
  } 
  
  // If key was not present in linked list 
  if (temp == NULL) return; 
  
  // Unlink the node from linked list 
  prev->next = temp->next; 
  
  free(temp);  // Free memory 
}

void deleteAt(struct Node **head_ref, int position) {
  if (*head_ref == NULL){
    return;
  }

  struct Node* temp = *head_ref;

  //3. Kalau yang dihapus head
  if (position == 0){
    *head_ref = temp->next;
    free(temp);
    return;
  }

  //4. Kalau nggak, cari dulu node sebelumnya dari node yang mau dihapus
  for (int i = 0; temp !=NULL && i < position-1 ; i++){
    temp = temp->next;
  }

  //5. Kalau lokasinya melebihi jumlah nodenya, proses dibatalkan
  if (temp == NULL || temp->next == NULL){
    return;
  }

  //6. Node setelah temp adalah node yang akan dihapus
  //Simpan value next dari node tersebut
  struct Node *next = temp->next->next;

  //Hapus node temp->next
  free(temp->next);

  //7. ganti temp->next menjadi next
  temp->next = next;
    
}

//Bikin method untuk ngeprint linked list
void printList(struct Node *node){
  int angka = 1;
  printf("Data Anime : \n\n");
  while (node != NULL){
    printf("%d. Anime ke-%d dengan rating : %d \n", angka, angka, node->data);
    node = node->next;
    angka++;
  }
}


//fungsi untuk menambah data stack
void pushStack( struct stackNode **topPtr, int info ) {
  //bikin node baru
  struct stackNode *newPtr = (struct stackNode*)malloc( sizeof( struct stackNode ) );

  //memasukkan stack atau data baru di paling atas
  if ( newPtr != NULL ) {           
    newPtr->data    = info;           
    newPtr->nextPtr = *topPtr;     
    *topPtr         = newPtr;              
  }else { //jika stack telah ada
    printf( "Piring tersebut telah ada.\n");
  }
}

//fungsi untuk menghapus data stack
int pop( struct stackNode **topPtr ) {
  //membuat node yang akan dibuang
  struct stackNode *tempPtr;
  //nilai node yang akan dibuang
  int popValue;

  tempPtr   = *topPtr;             
  popValue  = ( *topPtr )->data;  
  *topPtr   = ( *topPtr )->nextPtr;
  free( tempPtr );               
  return popValue;
}

// print stack
void printStack( struct stackNode *currentPtr ) {
  int angka2 = 1;    
  if ( currentPtr == NULL ) {   // jika stack kosong
    printf("Tolong piringnya ditaruh dahulu.\n");
  }else { 
    printf("Piring yang ada : \n\n");

    //print smua data stack
    while ( currentPtr != NULL ) { 
      printf( "%d. Piring ke-%d dengan ukuran : %d\n", angka2, angka2, currentPtr->data );
      currentPtr = currentPtr->nextPtr;
      angka2++;
    }
  }
}

//jika stack paling atas belum ada isi dengan NULL
int stackEmpty( struct stackNode* topPtr ) {
   return topPtr == NULL;
}



//memasukkan queue atau antrian
void enqueue( struct queueNode **headPtr, struct queueNode **tailPtr, int value ) {
  //membuat node dengan struct
  struct queueNode *newPtr = (struct queueNode*)malloc( sizeof( struct queueNode ) );

  if ( newPtr != NULL ) {
    newPtr->data    = value;
    newPtr->nextPtr = NULL;

    //jika queue kosong maka nilai pertama akan menjadi antrian pertama
    if ( queueEmpty( *headPtr ) ) {
      *headPtr = newPtr;
    }else { //jika data queue telah ada insert setelahnya
      ( *tailPtr )->nextPtr = newPtr;
    }

    *tailPtr = newPtr;
    }else {
    printf( "Orang tersebut telah mengantre.\n");
  }
}

// menghapus queue atau mengeluarkan data yang lebih dahulu masuk
int dequeue( struct queueNode **headPtr, struct queueNode **tailPtr ) { 
  // nilai dari data
  int value;

  // membuat node yang akan dihapus 
  struct queueNode *tempPtr;

  value = ( *headPtr )->data;      
  tempPtr = *headPtr;              
  *headPtr = ( *headPtr )->nextPtr;

  // jika data belum ada
  if ( *headPtr == NULL ) {
    *tailPtr = NULL;
  }

  free( tempPtr );
  return value;
}

// jika data queue belum ada maka akan diisi NULL
int queueEmpty( struct queueNode *headPtr ) { 
  return headPtr == NULL;
}

// print queue
void printQueue( struct queueNode *titikSaatIni ) { 
  //jika queue kosong
  int angka3 = 1;
  if ( titikSaatIni == NULL ) {
    printf("Antrean kosong.\n");
  } else { 
    printf("Antrean : \n\n");

    //print semua queue
    while ( titikSaatIni != NULL ) { 
      printf( "%d. Antrean ke-%d dari distrik : %d\n", angka3, angka3, titikSaatIni->data );
      titikSaatIni = titikSaatIni->nextPtr;
      angka3++;
    }
  }
}