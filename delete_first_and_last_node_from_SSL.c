/*Write a program to delete the first and last node from a 
singly linked list.*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Structure Declaration
struct node{
    int value;
    struct node *next;
};

//Global Variables
struct node *start, *previous;
int num=3;

//Function Declaration
void createList();
void delFirstNode();
void  delEndNode();
void display();

//Main Function
int main(){
    int i;

    for(i=0;i<5;i++){
        createList();
    }
    printf("Linked List Created:\n");
    display();

    printf("\n\nResult After Deletion of first node:\n");
    delFirstNode();
    display();

    printf("\n\nResult After Deletion of end node from above linked list:\n");
    delEndNode();
    display();
}


//Creating a Linked List
void createList(){
    struct node *new_node;

    new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL){
        printf("Memory allocation for new node failed.\n");
        exit(0);
    }
    new_node->value = num;
    num*=3;
    new_node->next=NULL;

    if(start==NULL){
        start=new_node;
    }
    else{
        previous->next=new_node;
    }
    previous=new_node;
}

//Function to delete the first node
void delFirstNode(){
    struct node *ptr;
    ptr=start;

    start=ptr->next;

    free(ptr);
}

//Function to delete the end node
void  delEndNode(){
    struct node *ptr, *prev;
    ptr=start;

    while(true){
        if(ptr->next==NULL){
            prev->next=NULL;
            free(ptr);
            break;
        }
        prev=ptr;
        ptr=ptr->next;
    }
}

//Display FUnciton
void display(){
    struct node *ptr;
    ptr=start;

    while(true){
        printf("   | %d | --|-->",ptr->value );
        if(ptr->next==NULL){
            break;
        }
        ptr=ptr->next;
    }
}

