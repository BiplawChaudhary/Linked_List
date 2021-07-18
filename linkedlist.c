//Program to implement the linked list
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Creating a structure.
struct node{
    int data;
    struct node *next;
} *start, *ptr;


//---Function Declaration---
void readdata();
void insertdata(int);
void display();


//---Main function---
int main(){
    //Variabeles
    bool run=true;
    int choice;
    
    //Code
    while(run){
        printf("1. Enqueue\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Select an operation:");
        scanf("%d", &choice );

        switch(choice){
            case 1:
                readdata();
                break;
            case 2:
                display();
                break;
            
            case 3:
                run=false;
                break;

            default:
                printf("Select correct operation break:");
                break;
        }
    
    }
}

void readdata(){
    int num;
    printf("Enter a number:");
    scanf("%d", &num);

    insertdata(num);
}

void insertdata(int n){
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=n;
    new_node->next=NULL;
    if(start==NULL){
        start=new_node;
    }
    else{
        ptr=new_node;
        new_node->next=ptr;

    }
}


void display(){
    struct node *ptr2=start;
    while(ptr2!=NULL){
        printf("Num: %d", ptr2->data);
        ptr2=ptr2->next;
    }
}
