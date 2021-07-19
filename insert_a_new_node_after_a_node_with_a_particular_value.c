/*Write a program to insert a new node after a node with a 
 particular value in a singly linked list*/
 #include<stdio.h>
 #include<stdlib.h>
 #include<stdbool.h>

 //Declaring the structure
 struct node{
     int num;
     struct node *next;
 };

 //Global Variables
 struct node *start, *previous;
 int num=10;


//Function Declaration
void createList();
void insertValue(int, int);
void display();

 //---Main Function--
int main(){
     int node_value,num, i;

    for(i=0;i<3;i++){
        createList();
    }

    display();

    printf("\nAfter which value would you like to insert the new node:");
    scanf("%d", &node_value);
    printf("Enter a number to be inserted:");
    scanf("%d", &num);

    insertValue(node_value, num);
    display();

}


 //Function to create a linked list
 void createList(){
    struct node *new_node;

    new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL){
        printf("Memory Allocation for new node failed.");
    }
    new_node->num=num;
    num+=5;
    new_node->next=NULL;

    if(start==NULL){
        start=new_node;
    }
    else{
        previous->next=new_node;
    }
    previous=new_node;
 }


//Insertion value node
void insertValue(int node_value, int num){
    struct node *ptr, *new_node, *next_node;

    ptr=start;

    new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL){
        printf("Memory Allocation for new node failed.\n");
        exit(0);
    }
    new_node->num=num;
    new_node->next=NULL;

    while(true){
        //Executed if the value is of last node
        if(ptr->next==NULL && ptr->num==node_value){
            ptr->next=new_node;
            break;
        }
        else if(ptr->num==node_value){
            next_node=ptr->next;
            ptr->next=new_node;
            new_node->next=next_node;
            break;
        }
        ptr=ptr->next;
    }
    printf("\nInserted Successfully.\n");

}

//Display the List
void display(){
    struct node *ptr;

    ptr=start;

    printf("\nThe List is:\n");
    while(true){
        printf("   |  %d  |  --|-->", ptr->num);
        if(ptr->next==NULL){
            break;
        }
        ptr=ptr->next;
    }
}

