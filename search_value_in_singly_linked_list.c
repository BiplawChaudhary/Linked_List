//Write a program to search a particular value in a singly linked list.
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//---Structure Declaration--
struct node{
    int num;
    struct node *next;
};

//---Global Variables---
struct node *start, *old_node;
int num=1;

//Function Declaration
void createNode();
void display();
void searchList(int);

//--Main Function---
int main(){
    int i , value;

    for(i=0;i<5;i++){
        createNode();
    }
    printf("\nList of first 5 Odd Numbers Created.\n");

    printf("\nEnter the value to be searched: ");
    scanf("%d", &value);

    searchList(value);
}


//Function to create a node
void createNode(){
    //Variables
    struct node *new_node;

    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->num=num;
    num+=2;

    if(start==NULL){
        new_node->next=NULL;
        start=new_node;
    }
    else{
        old_node->next=new_node;
        new_node->next=NULL;
    }
    old_node=new_node;
}

//Function to search a particular number in list
void searchList(int num){
    struct node *ptr;

    ptr=start;
    while(true){
        if(ptr->num==num){
            printf("\nNumber is in the list.\n");
            printf("Found at address:%x", ptr);
            break;
        }
        else if(ptr->next==NULL){
            printf("\nNumber not found on linked list.");
            break;
        }
        ptr=ptr->next;
    }

}


//Display_Test
void display(){
    struct node *ptr;
    ptr=start;

    while(true){
        printf("%d\t", ptr->num);
        if(ptr->next==NULL){
            break;
        }
        ptr=ptr->next;
    }
}