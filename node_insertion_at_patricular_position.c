/*Write a program to insert a new node before a node with a  
particular value in a singly linked list.*/
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

//Defining the structure
struct node{
    int num;
    struct node *next;
};

//Global Variables
struct node *start, *previous;
int num=7;

//Function Declaration
void createList();
void display();
void insertValue(int, int);

//----Main Function---
int main(){
    int node_value,num, i;

    for(i=0;i<3;i++){
        createList();
    }

    display();

    printf("\nBefore which value would you like to insert the new node:");
    scanf("%d", &node_value);
    printf("Enter a number to be inserted:");
    scanf("%d", &num);

    insertValue(node_value, num);
    display();  
    
}

//Function to create a list
void createList(){
    struct node *new_node;

    new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL){
        printf("Memory Allocation for new node failed.\n");
        exit(0);
    }
    new_node->num=num;
    num+=2;
    new_node->next=NULL;
    if(start==NULL){     
        start=new_node;
    }
    else{
        previous->next=new_node;
    }
    previous=new_node;
}

//Display the List
void display(){
    struct node *ptr;

    ptr=start;

    printf("Linked List:\n");
    while(true){
        printf("   |  %d  |  --|-->", ptr->num);
        if(ptr->next==NULL){
            break;
        }
        ptr=ptr->next;
    }
}

//Function to insert the value
void insertValue(int node_value, int num){
    struct node *ptr, *new_node;
    ptr=start;

    new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL){
        printf("Memeory Allocation for new node failed.");
        exit(0);
    }
    new_node->num=num;
    
    //Checking if the number is the first on linked list
    if(ptr->num==node_value){
        new_node->next=ptr;
        start=new_node;
    }
    else{
        while(true){
            if(ptr->num==node_value){
                //new node's next will point to the node where value matched.
                new_node->next=ptr;
                /* The next pointer of  node before which the value matched
                will then point to new node*/
                previous->next=new_node;
                break;
            }

            //Setting the pervious pointer 
            previous=ptr;
            ptr=ptr->next;
        }
    }
}
