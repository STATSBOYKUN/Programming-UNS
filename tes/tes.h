
struct node {                                   
   char data[1000];        
   struct node *next; 
}; 

typedef struct node Queue;
typedef Queue *QueueNode;

QueueNode head = NULL;
QueueNode tail = NULL; 

void opsi(){
	puts("\nMasukkan pilihan Anda:\n"
      "1. Hapus kata pertama yang sama\n"
      "2. Keluar\n");
}

char kosong(QueueNode head)
{ 
   return head == NULL;
} 

void tambah(QueueNode *head, QueueNode *tail, char *value){

	QueueNode ptr = malloc(sizeof(Queue));

   if (ptr != NULL) { 
      strcpy(ptr->data, value);
      ptr->next = NULL;

      if (*head == NULL) {
         *head = ptr;
      } 
      else {
         (*tail)->next = ptr;
      } 
      *tail = ptr;
   } 
   else {
      printf("Tidak ada kata yang sama.\n");
   } 
} 

char hapus(QueueNode *head, QueueNode *tail){ 
   
   char akhir;
   akhir = (*head)->data[1000];
   
   QueueNode sementara = *head;              
   *head = (*head)->next;

   if (kosong(*head)) {
      *tail = NULL;
   } 

   free(sementara);
   return akhir;
} 


void print(QueueNode current){ 
   
   if (kosong(current)) {
      puts("Tidak ada kata yang sama.\n\nTerima kasih");
      exit (0);
   } 
   else { 
   	  puts("Tampilkan kata yang sama:");
	
	  while (current != NULL) { 
        printf("%s ", current->data);
        //putchar (head->data);
        current = current->next;
        printf("-> ");
      }
   puts ("NULL"); 
   puts ("");  
   }
   
}


void choice(char *data){
	int pilih;
	
	printf("%s", "? ");
	scanf ("%d", &pilih);
	
	while (pilih != 2) {
      switch(pilih) { 
         case 1:
         	if (head == NULL) {
            	printf ("tidak ada kata yang sama\nTerima kasih.");
			}
            else { 
               *data = hapus(&head, &tail);
               print(head);
            } 
            break;
         default:
            puts("Pilihan salah.");
            opsi();
            break;
      }

      printf("\n%s", "? ");
      scanf("%d", &pilih);
}
}


