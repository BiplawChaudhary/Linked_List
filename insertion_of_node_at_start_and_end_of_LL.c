//Write a program to insert a new node at the beginning and 
//end of singly linked list.
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


//Creating a structure
struct node{
    int value;
    struct node *next;
};

//Global Variables
struct node *start, *previous;
int num=7;


//Function Declaration
void readData();
void createList();
void displayList();
void insert_begin();
void insert_end();  


//---Main Function--
int main(){
    int choice, n=3;
    bool run=true;

    printf("Insertion of node in Singly Linked List\n");
    
    while(n>0){
        createList();
        n--;
    }
    printf("\nCreated List:\n");
    displayList();

    while(run){
        printf("\nInsertion done at:\n");
        printf("1. Beginning of node\n");
        printf("2. End of node\n");
        printf("3. Display List\n");
        printf("4. Exit\n");

        printf("Select an option:");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                insert_begin();
                // displayList();
                break;

            case 2:
                insert_end();
                // displayList();
                break;

            case 3:
                printf("\nLinked List:\n");
                displayList();
                break;
            
            case 4:
                run=false;
                break;
            
            default:
                printf("Select an correct choice.\n");
                break;
        }
    }
}

//Function to readdata
void readData(){
    printf("Enter a number: ");
    scanf("%d", &num);
}

//Function to create a list
void createList(){
    struct node *new_node;

    new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL){
        printf("Memory Alloctaion for new node failed.\n");
        exit(1);
    }
    new_node->value=num;
    num++;
    new_node->next=NULL;
    if(start==NULL){
        start=new_node;
    }
    else{
        previous->next=new_node;
    }
    previous=new_node;
}

//Function to insert at beginning
void insert_begin(){
    struct node *new_node;
    
    new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL){
        printf("Memory Allocation failed.\n");
        exit(1);
    }
    readData();
    new_node->value=num;
    new_node->next=start;
    start=new_node;
    
    printf("Inserted Successfully.\n");
}

//Function to insert at end
void insert_end(){
    readData();
    createList();
    printf("Inserted Successfully.\n");
}


//Function to display the list
void displayList(){
    struct node *ptr;
  
    ptr=start;
    while(true){
        printf(" | %d | --|-->", ptr->value);
        if(ptr->next==NULL){
            break;
        }
        ptr=ptr->next;
    }
    printf("\n");
    
    
}




