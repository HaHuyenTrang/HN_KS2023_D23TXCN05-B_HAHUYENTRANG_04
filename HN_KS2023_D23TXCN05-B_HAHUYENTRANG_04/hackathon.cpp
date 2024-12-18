#include<stdio.h>
#include<stdlib.h>
#define MAX 5

////	xay dung cau truc node
//typedef struct Node{
//	int data; //gia tri cua node
//	struct Node* next; 	//tro node tiep theo
//}Node;
//
////	cap phat bo nho
//Node* createNode(int data){
//	// Cap phat bo nho
//	Node* newNode = (Node*) malloc(sizeof(Node));
//	newNode->data = data;
//	newNode->next = NULL;
//	newNode->prev = NULL;
//	return newNode;
//}

typedef struct Queue {
	int array[MAX];
	int front;
	int rear;
}Queue; 
//	khoi tao dnah sach hang doi
void initalQueue(Queue* queue){
	queue->front = -1;
	queue->rear = -1;
}

//Kiem tra hang doi rong
int isEmpty(Queue* queue){
	if(queue->front == -1){
		return 1;
	}
	return 0;
}

//Kiem tra hang doi day
int isFull(Queue* queue){
	if(queue->rear == MAX -1){
		return 1;
	}
	return 0;
} 


//	Enqueue(them phan tu vao hang doi)
void enqueue(Queue* queue, int value){
	if(isFull(queue) == 1){
		printf("hang doi da day!");
		return;
	}
	if(isEmpty(queue) == 1){
		queue->front = 0;
	}
	queue->rear++;
	queue->array[queue->rear] = value;
}


// Lay phan tu ra khoi hang doi (dequeue)
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong!\n");
        return -1; 
    }
    int value = queue->array[queue->front];
    if (queue->front == queue->rear) { 
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    return value;
}

// kiem tra phan tu dau tien cua hang doi  (peek)
int peek(Queue* queue) {
    if (isEmpty(queue)) { // Kiem tra neu hang doi rong
        printf("Hang doi rong!\n");
        return -1; 
    }
    return queue->array[queue->front]; // Tra ve phan tu dau
}


//	lay kich thuoc hang doi
int size(Queue* queue) {
    if (queue->front == -1) {
        return 0;  // Hang doi rong
    }
    return queue->rear - queue->front + 1;
}

//	in hang doi
void displayQueue(Queue* queue){
	for(int i = queue->front; i<= queue->rear; i++ ){
		printf("%d\t", queue->array[i]);
	}
}


//	xoa toan bo hang doi
void clear(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

//	kiem tra phan tu cuoi
int rearElement(Queue* queue) {
    if (queue->front == -1) {
        printf("Hang doi rong!\n");
        return -1;  
    }
    return queue->array[queue->rear];  
}


int main(){
	Queue queue ={{0}, -1, -1};
	initalQueue(&queue);
	int value;
	do{
		printf("\n============MENU===========\n");
		printf("1. Them phan tu vao hang doi.\n");
		printf("2. Lay phan tu khoi hang doi.\n");
		printf("3. Kiem tra phan tu dau hang doi.\n");
		printf("4. Kiem tra hang doi rong.\n");
		printf("5. Lay kich thuoc hang doi.\n");
		printf("6. In toan bo hang doi.\n");
		printf("7. Xoa toan bo hang doi.\n");
		printf("8. Kiem tra phan tu cuoi cung.\n");
		printf("9. Thoat!!\n");
		printf("moi ban chon tu 1-9: ");
		int choice;
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("moi ban nhap gia tri can them vao hang doi: ");
				scanf("%d",&value);
				enqueue(&queue,value);
				break;
			case 2:
//				printf("moi ban nhap gia tri can lay: ");
//				scanf("%d",&value);
			 	value = dequeue(&queue);
			    if (value != -1) {
			        printf("Phan tu duoc lay ra: %d\n", value);
			    }
			    printf("hang doi: ");
			    displayQueue(&queue);
				break;
			case 3:
				// Hien thi phan tu dau tien trong hang doi
                value = peek(&queue);
                if (value != -1) {
                    printf("Phan tu dau tien cua hang doi: %d\n", value);
                }
				break;
			case 4:
				if (isEmpty(&queue)) {
				    printf("Hang doi rong!\n");
				} else {
				    printf("Hang doi: ");
				    displayQueue(&queue);
				}
				break;
			case 5:
				if(size(&queue)){
					printf("kich thuoc hang doi la: %d ",size(&queue) );
				} else{
					printf("hang doi rong!!");
				}
				break;
			case 6:
				displayQueue(&queue);
				break;
			case 7:
				printf("hang doi truoc khi xoa: ");
				displayQueue(&queue);
				clear(&queue);
				printf("da xoa hang doi!");
				break;
			case 8:
				int rear = rearElement(&queue);  
		        if (rear != -1) {
		            printf("Phan tu cuoi cung trong hang doi: %d\n", rear);
		        }
				break;
//			case 9:
////				exit(0);
//			default:
//				printf("moi chon lai: ");
			
		}
	}while(1==1);
	return 0;
}


