//Write a program to count the number of nodes in a singly linked list.
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//----Structure Declaration----
struct node{
    int num;
    struct node *next;
};

//Global Variables
struct node *start, *previous;
int num=10;


//Function Declaration
void createNode();
int counter();


//-----Main Function----
int main(){
  int i;
  for(i=0;i<=6;i++){
      createNode();
  }

  printf("\n\nNo. of nodes: %d", counter());
}

//Function to create list
void createNode(){
    struct node *new_node ;

   
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->num=num;  
    num+=5;
    new_node->next=NULL;
    //If it is the first node to be inserted.
    if(start==NULL){
       
        start=new_node;         //And assing the first node as the start of the linked list.
    }     

    //If it is not the first node then,  
    else{  
        /*Assign thhe previous node's next, to the new node. This will create a link 
        between new node and the previous one.*/
        previous->next=new_node;  
        /*To specify the ending of new_node, assign new nodes next to NULL.*/
       

    }
    /*Set previous node value to the newly created node. 
    So that in next function call we can link the previously created list with newly created list.*/
    previous=new_node;
}

//Function to display the linked list
int counter(){
    struct node *ptr;
    int count=0;

    ptr=start;

    printf("Created List:\n");
    while(true){
        printf("  | %d | --|-->", ptr->num);
        count++;
        if(ptr->next==NULL)
            break;
        
        ptr=ptr->next;
    }

    return count;
}