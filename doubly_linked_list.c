/*Write a complete program to create, display, insert and delete node of 
a doubly linked list.
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Declaring the structure
struct node{
    struct node *prev;
    int value;
    struct node *next;
};

//Global variables
struct node *start, *previous;
int num; //G

//Function Declaration
void readData();
void createList();
void displayFromEnd();
void displayFromStart();
void insertBeginning();
void deleteFromStart();
void deleteFromEnd();


//--Main Function---
int main(){
    int choice, n;
    bool run=true;


    printf("---Doubly Linked List---\n");
    while(run){
        printf("\nOperations Performed:\n");
        printf("1. Create a list\n");
        printf("2. Insert at the beginning\n");
        printf("3. Insert at the end\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Display from beginning\n");
        printf("7. Display from end\n");
        printf("8. End\n");
        printf("Select an operation:");
        scanf("%d", &choice);

        switch(choice){
            //create the list
            case 1:
                printf("How many nodes would you like to create:");
                scanf("%d", &n);
                while(n>0){
                    createList();
                    n--;
                }
                break;

            //Insert at beginning
            case 2:
                if(start==NULL){
                    printf("\nERROR!! Create a list first to insert.\n");
                }
                else{
                    insertBeginning();
                }
                
                break;

            //Insert at the end
            case 3:
                if(start==NULL){
                    printf("\nERROR!! Create a list first to insert.\n");
                }
                else{
                    createList();
                }
                break;

            //Delete from start
            case 4:
                if(start==NULL){
                    printf("\nERROR!! No List Found\n");
                }
                else{
                    deleteFromStart();
                }
                break;

            //Delete from end
            case 5:
                 if(start==NULL){
                    printf("\nERROR!! No List Found\n");
                }
                else{
                    deleteFromEnd();
                }
                break;

            //Display from the start
            case 6:
                if(start==NULL){
                    printf("\nERROR!! No List Found\n");
                }
                else{
                    displayFromStart();
                }
                
                break;
            
            //Display from the end
            case 7:
                if(start==NULL){
                    printf("\nERROR!! No List Found\n");
                }
                else{
                    displayFromEnd();
                }
                break;

            //Ending the loop
            case 8:
                run=false;
                break;

            default:
                printf("Please select the correct option.\n");
                break;
        }
    }  
}


//Function to read the numebrs
void readData(){
    printf("Enter a number to insert:");
    scanf("%d", &num);
}

//Function to create the doubly linked list at first
void createList(){
    //Variables
    struct node *new_node;
   

    new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL){
        printf("Memory Allocation for new node Failed.\n");
        exit(0);
    }

    readData();

    new_node->prev=NULL;
    new_node->value= num;
    new_node->next =NULL;

    if(start==NULL){
        start=new_node;
    }
    else{
        previous->next=new_node;
        new_node->prev=previous;
    }
    previous=new_node;  //Stores the node that is at the end.
}

//Function to insert at beginning of list
void insertBeginning(){
    struct node *new_node;

    new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL){
        printf("Memory Allocation for new node failed.\n");
        exit(0);
    }
    readData();

    new_node->value=num;  //Inserting the value in new node
    /*Setting the new_node's previous to NULL as there'll be no value before it*/
    new_node->prev=NULL;     
    /*Pointing the original start's previous start node to the new node as it 
    is being inserted before it.*/   
    start->prev=new_node;
    /*The new_node's next will then point to the original start. This 
    will create the final double forward and backward link between them.*/
    new_node->next=start;
    /*Making the newly inserted node at beginning the new node*/
    start=new_node;
}


//Function to delete a node from beginning
void deleteFromStart(){
    struct node *ptr;
    ptr=start;  //Setting the ptr to be start

    /*As the first node will be deleted, so updating the start to the next 
    node to it.*/
    start=ptr->next;
    /*As the new start is updated it's previous shall be NULL as there won't be any 
    node before it*/
    start->prev=NULL;
    /*The just freee the ptr pointing to the old start.*/
    free(ptr);
}

//Function to delete a node from end
void deleteFromEnd(){
    struct node *ptr;
       /*As the last node will be deleted, and previous points to last node 
     so assign it to the ptr*/
    ptr=previous; 

    /*updating the previous to the next node to it.*/
    previous=ptr->prev;
    /*As this will be the last node so it's next shall be NULL*/
    previous->next=NULL;
    //Just free the pointer.
    free(ptr);
}

//Function to display the lsit from the start
void displayFromStart(){
    struct node *ptr;
    ptr=start;

    printf("\nDoubly Linked list on traversing forward:\n");
    while(true){
        printf("  | %d | --|-->", ptr->value);
        if(ptr->next==NULL){
            break;
        }
        ptr=ptr->next;
    }
    printf("\n");
}

//Function to display the list from the end.
void displayFromEnd(){
    struct node *ptr;
    ptr=previous;
    printf("\nDoubly Linked list on traversing backwards:\n");
    while(true){
        printf("  | %d | --|-->", ptr->value);
        if(ptr->prev==NULL){
            break;
        }
        ptr=ptr->prev;
    }
    printf("\n");
}


            
            
            
            

