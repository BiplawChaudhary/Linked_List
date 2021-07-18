/*Write a complete program to create, display, insert and delete node
 of a Circular linked list.*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Creeating Structure
struct node{
    int value;
    struct node *next;
};

//Global Variables
struct node *start, *previous;
int num; //G

//Function Declaration
void readData();
void createList();
void insertAtBeginning();
void insertAtEnd();
void deleteBeginning();
void deleteEnd();
void display();

//--Main Function--
int main(){
    int choice, n;
    bool run=true;

    printf("---Circular Linked List---\n");
    while(run){
        printf("\nOperations Performed:\n");
        printf("1. Create Circular List\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at end\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Display the list\n");
        printf("7. Exit\n");

        printf("Select an operation: ");
        scanf("%d", &choice);

        switch(choice){
            //Creating the list
            case 1:
                printf("How many nodes to create?: ");
                scanf("%d", &n);
                while(n>0){
                    createList();
                    n--;
                }
                printf("\nList Created!!\n");
                break;

            //Insert at beginning
            case 2:
                insertAtBeginning();
                // display();
                break;

            //Insert at end
            case 3:
                insertAtEnd();
                // display();
                break;
            //Delete from beginning
            case 4:
                deleteBeginning();
                // display();
                break;

            //Delete from edn
            case 5:
                deleteEnd();
                // display();
                break;

            //Function to display the list
            case 6:
                display();
                break;
            
            //Exit function
            case 7:
                run=false;
                break;
            
            default:
                printf("Please select a correct option.\n");
                break;
        }
    }
}


//Function to readdata
void readData(){
    printf("Enter a number: ");
    scanf("%d", &num);
}

//Function to create List
void createList(){
    struct node *new_node;
    int iter;

    new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL){
        printf("Memory Allocation for new node failed.\n");
        exit(1);
    }
    else{
        readData();
        new_node->value = num;
        new_node->next=start;
        if(start==NULL){
            start=new_node;
            // new_node->next=start;
        }
        else{
        
            previous->next=new_node;
        }
        /*Setting previous to point to the newly node created which is placed at end.
        So we can see previous points to the end node*/
        previous=new_node;  
    }
}

//Function to insert data at beginning
void insertAtBeginning(){
    struct node *new_node;
    if(start==NULL){
        printf("ERROR!! Create a list first.\n");
        exit(1);
    }
    new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL){
        printf("Memeory Allocation failed.");
    }
    else{
        readData();
        //Insert the value in new node
        new_node->value=num;
        /*Point the new node's next to the old start. This will create
        a link between them*/
        new_node->next=start;
        /*Point the last node's address to the newly assgined node which
        will then be the new start. 
        Note: In creating the list the previous variable stores the last node's address.*/
        previous->next=new_node;

        //Assign the new_node as the start.
        start=new_node;

        printf("\nValue inserted.\n");
    }
}

//Function to insert at end
void insertAtEnd(){
    if(start==NULL){
        printf("ERROR!! Create a list first.\n");
    }
    else{
        createList();
        printf("\nValue inserted.\n");
    }
}

//Function to delete from beginning
void deleteBeginning(){
    struct node *ptr;
    if(start==NULL){
        printf("ERROR!! Create a list first");
    }
    else{
        ptr=start;
        printf("\nDeleted Value: %d\n", ptr->value);
        start=ptr->next;
        previous->next=start;
        free(ptr);
    }
}

//Function to delete from end;
void deleteEnd(){
    struct node *ptr, *before;

    if(start==NULL){
        printf("ERROR !! Create a list first.");
        exit(1);
    }

    ptr=start;
    while(true){
        if(ptr->next==start){
            printf("\nDeleted Value: %d\n", ptr->value);
            before->next=start;
            free(ptr);
            break;
        }
        before=ptr;
        ptr=ptr->next;
        
    }
}
//Function to display the result
void display(){
    struct node *ptr;
    ptr=start;
    printf("\nCircular Linked List:\n");
    while(true){
        printf("  | %d | --|-->", ptr->value);
        if(ptr->next==start){
            break;
        }
        ptr=ptr->next;
    }
    printf("\n");
}

