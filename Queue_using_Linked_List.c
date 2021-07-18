/*Write a program to simulate Queue as a linked list.*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Defining the structure
struct node{
    int value;
    struct node *next
};

//Global Variables
struct node *front, *rear;

//Function Declaration
void enqueue();
void display();
void dequeue();
void peek();

//--Main Function
int main(){
    int choice;
    bool run=true;

    printf("--Queue Using Linked List--\n");
    while(run){
        printf("\nOperations Performed:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Select an operation: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                enqueue();
                break;
            
            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                run=false;
                break;

            default:
                printf("Please select a correct option.\n");
                break;
        }
    }
}

//Function to enqueue
void enqueue(){
    int num;
    struct node *new_node;

    new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL){
        printf("ERROR!! Stack Overflow.\n");
    }
    else{
        printf("Enter a number to enqueue: ");
        scanf("%d", &num);

        new_node->value = num;
        new_node->next=NULL;

        if(front==NULL && rear==NULL){
            front=new_node;
            rear=new_node;
        }
        else{
            rear->next=new_node;
            rear=new_node;
        }
        printf("Enqueued Successfully!\n");
    }
}

//Function to dequeue
void dequeue(){
    struct node *ptr;

    if(front==NULL){
        printf("ERROR!! Queue Underflow.\n");
    }
    else{
        ptr=front;
        printf("\nData Dequeued: %d\n", ptr->value);
        front=ptr->next;
        free(ptr);
    }
}

//Function to implement peek operation
void peek(){
    printf("\nValue at front: %d\n", front->value);
}

//Function to display the queue
void display(){
    struct node *ptr;
    ptr=front;

    printf("\nQueue: \n");
    while(true){
        printf("  | %d | --|-->", ptr->value);
        if(ptr->next==NULL){
            break;
        }
        ptr=ptr->next;
    }
}