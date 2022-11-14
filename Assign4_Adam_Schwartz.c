//Adam Schwartz and Manny Hernandez
//CS315
//Assignment 4

#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

int main(){


//To reduce my confusion I am going to use two dif structs becuase I do not want to risk the crossing of data

//Stack struct
struct Stack{
    int info;

    //Stack Pointer
    struct Stack *link;

};
// Stack pointer I will only need one becuase you can only enter and leave the stack from one side
struct Stack *top=0;

//Queue Struct
struct node{
    int data;
   
    //Queue pointer
    struct node *next;
};
//Queue pointer I need two becuase with a Queue you can enter from both sides and exit from both sides
struct node *front=0;
struct node *rear=0;


// Stack Functions

//removing from the stack
void pop(){
    struct Stack *Stand;
    Stand=top;
    if(top==0){
        printf("The stack is empty\n");
    }
    else{
        printf("Removing %d from the stack\n", top->info);
        top=top->link;
        free(Stand);
    }
}
// Checking to see if the Stack is Empty
void emptyS(){
    if(top==0){
        printf("The Stack is Empty\n");
    }
    else{
        printf("The Stack is not Empty\n");
    }
}
//Checking to see if Stack is Full
int Full(){
    int count;
    struct Stack *Stand;
    if(top==0){
        printf("The Stack is Empty\n");
    return 1;
    }
    else{
        count=0;
        while(Stand != 0){
        count=count+1;
        Stand=Stand->link;
        }

        if(count==5){
            printf("The Stack is full");
        return 5;
        }
        else{
            printf("The Stack is not Full you have %d spaces left\n", 6-count);
        return 1;
        }
    }
}
// Check the Top Most Element
void Top(){
    if(top==0){
        printf("The Stack is Empty\n");

    }
    else{
        printf("The top element in the Stack is %d\n", top->info);
    }
}
// Count the Elements in the Stack
void count2(){
    int count;
    struct Stack *Stand;
    if(top==0){
        printf("The Stack is Empty");
    }
    else{
        Stand=top;
        count=0;
        while(Stand != 0 ){
            count=count+1;
            Stand=Stand->link;   
        }
        printf("There are %d Elements in the Stack\n", count);
    }
}
//adding to the Stack
void push(int y){
    //int full= Full();
    //if(full==5){
    //    printf("The stack is full\n");
    //}
    //else{
    struct Stack *newnode;
    newnode=(struct Stack *)malloc(sizeof(struct Stack));
    newnode->info=y;
    newnode->link=top;
    top=newnode; 
    //}        
}

// Queue Functions

// Adding to the Queue
void enqueue(int x){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;

    if(front==0 && rear==0){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }

}
//Removing from the Queue
void dequeue(){
    struct node *Placehold;
    Placehold=front;
    if(front==0 && rear==0){
        printf("The Queue is Empty and you cannot remove anything\n");
    }
    else{
        printf("%d was removed\n", front->data);
        front=front->next;
        free(Placehold);
    }

}
//Counting the Queue elements 
void count(){
    int count;
    struct node *Placehold;
    if(front==0 && rear==0){
        printf("The Queue is Empty");
    }
    else{
        Placehold=front;
        count=0;
        while(Placehold !=0 ){
        count=count+1;
        Placehold=Placehold->next;
        }
        printf("There are %d Elements in the Queue\n", count);
    }
}
//Checking to see if the Que is Empty
void empty(){
    if(front==0 && rear==0){
    printf("The Queue is Empty\n");
    }
    else{
    printf("Queue is not Empty\n");
    }  
}
//Checking the first element in the Queue
void peek(){
    if(front==0 && rear==0){
        printf("The Queue is Empty\n");
    }
    else{
        printf("The first element is %d\n", front->data);
    }
}

// Menu Code // Simple while loop with a bool and switch for cases :)
int choice, entry;
bool test=true;
while (test==true){
    printf("Stack Operations\n");
    printf("1) Check if Stack is Empty\n");//done
    printf("2) Checks if Stack is Full\n");//done
    printf("3) Print Number of Elements in Stack\n");//done
    printf("4) View the Top most element in the Stack (Peek)\n");//done
    printf("5) Add an element to the Stack\n");//done
    printf("6) Remove the element from the Stack\n");//done
    printf("Queue Operations\n");
    printf("7) Check if Queue is Empty\n");//done
    printf("8) Checks Number of Elements in Queue\n");//done
    printf("9) Check the first element in the Queue\n");//done
    printf("10) Add an element to the Queue\n");//done
    printf("11) Remove an element from the Queue\n");//done
    printf("0) Quit\n");//done
    printf("Please enter your choice: ");
    scanf(" %d", &choice);

    switch (choice){
        case 0:
            //printf("Working0\n");
            exit(0);
        case 1:
            //printf("Working1\n");
            emptyS();
            break;
        case 2:
            //printf("Working2\n");
            Full();
            break;
        case 3:
            //printf("Working3\n");
            count2();
            break;
        case 4:
            //printf("Working4\n");
            Top();
            break;
        case 5:
            //printf("Working5\n");
            printf("Please enter a Number: ");
            scanf("%d", &entry);
            push(entry);
            break;
        case 6:
            //printf("Working6\n");
            pop();
            break;
        case 7:
            //printf("Working7\n");
            empty();
            break;
        case 8:
            //printf("Working8\n");
            count();
            break;
        case 9:
            //printf("Working9\n");
            peek();
            break;
        case 10:
            //printf("Working10\n");
            printf("Please enter a number: ");
            scanf("%d", &entry);
            enqueue(entry);
            break;
        case 11:
            //printf("Working11\n");
            dequeue();
            break;
        
    }

}
return 0;
}