#include <stdio.h>
#include <stdlib.h>

//Membuat objek menggunakan struct
struct Node{
    int data;
    struct Node *next;
};

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

    //6. Kalau nggak kosong, maka kita harus nyari dulu node terakit
    // Node terakhir ini digunakan untuk jadi tempat nambahin data
    while(last->next != NULL){
        last = last->next;
    }

    //7. Ganti nilai last->next jadi new node
    last->next = new_node;
    return;
}

void deleteAt(struct Node **head_ref, int position){
    //1. Kalau linked list kosong, proses tidak perlu dijalankan
    if (*head_ref == NULL){
        return;
    }

    // 2. Buat salinan head_ref
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
    //Simpan value next dari node tersebtu
    struct Node *next = temp->next->next;

    //Hapus node temp->next
    free(temp->next);

    //7. ganti temp->next menjadi next
    temp->next = next;
    
}

// Method buat delete
void deleteNode(struct Node **head_ref, int key) 
{ 
    // Store head node 
    struct Node* temp = *head_ref, *prev; 
  
    // If head node itself holds the key to be deleted 
    if (temp != NULL && temp->data == key) 
    { 
        *head_ref = temp->next;   // Changed head 
        free(temp);               // free old head 
        return; 
    } 
  
    // Search for the key to be deleted, keep track of the 
    // previous node as we need to change 'prev->next' 
    while (temp != NULL && temp->data != key) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
  
    // If key was not present in linked list 
    if (temp == NULL) return; 
  
    // Unlink the node from linked list 
    prev->next = temp->next; 
  
    free(temp);  // Free memory 
}

void printList(struct Node *node){
    while (node != NULL){
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main(){
    struct Node* head = NULL;
    push(&head, 5);
    push(&head, 4);

    printList(head);

    append(&head, 8);
    printf("\n");
    printList(head);

    push(&head, 8);
    printf("\n");
    printList(head);

    deleteAt(&head, 2);
    printf("\n");
    printList(head);

    deleteNode(&head, 8);
    printf("\n");
    printList(head);

    append(&head, 7);
    printf("\n");
    printList(head);

    deleteNode(&head, 8);
    printf("\n");
    printList(head);

    deleteNode(&head, 7);
    printf("\n");
    printList(head);

}