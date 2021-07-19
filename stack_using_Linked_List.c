/*Write a program to simulate stack as a linked list.*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Defining the structure
struct node{
    int value;
    struct node *next;
};

//Global Variables
struct node *top;


//Function Declaration
void pushStack();
void display();
void popStack();
void peekStack();

//--Main Function--
int main(){
    //Variables
    int choice;
    bool run=true;

    printf("---Stack using Linked List--\n");
    while(run){
        printf("\nOperations Performed:\n");
        printf("1. Push \n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                pushStack();
                // display();
                break;

            case 2:
                popStack();
                // display();
                break;

            case 3:
                peekStack();
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

//Function to pop from the stack
void popStack(){
    struct node *ptr;

    if(top==NULL){
        printf("ERROR!! Stack Underflow.\n");
    }
    else{
        ptr=top;
        printf("\nPopped Value:%d\n", ptr->value);
        top=ptr->next;
        free(ptr);
    }
}

//Function to push into stack
void pushStack(){
    struct node *new_node;
    int num;

    new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL){
        printf("ERROR!! Stack Overflow.\n");
        exit(1);
    }
    printf("Enter a number to push: ");
    scanf("%d", &num);

    new_node->value=num;
    new_node->next=NULL;
    if(top==NULL){
        top=new_node;
    }
    else{
        new_node->next=top;
        top=new_node;
    }
    printf("Pushed Successfully.\n");
}



//Function to peek the stack
void peekStack(){
    if(top==NULL){
        printf("ERROR!! Stack Underflow.\n");
    }
    else{
        printf("\nValue at top: %d\n", top->value);
    }
}

//Function to display the result
void display(){
    struct node *ptr;
    if(top==NULL){
        printf("ERROR!! Stack Underflow.\n");
    }
    else{
        ptr=top;
        printf("\n--Stack---\n");
        while(true){
            printf("| %d |--|-->", ptr->value);
            if(ptr->next==NULL){
                break;
            }
            ptr=ptr->next;
        }
    }
}