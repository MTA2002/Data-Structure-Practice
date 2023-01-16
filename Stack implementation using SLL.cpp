#include<iostream>
using namespace std;

struct Stack{
    int data;
    Stack *next;
};
Stack *top=NULL;

void main_menu();
void push(int number);
int pop();
void peek();
void display();
void make_empty();
bool is_full();
bool is_emptyy();
int getSize();


int main(){
    main_menu();
    
    return 0;
}
void main_menu(){
    int choice;
    do {
        cout<<endl<<endl<<endl;
        cout<<"WELCOME TO STACK IMPLEMENTATION USING LINKED LIST!!"<<endl;
        cout<<"1. PUSH ELEMENT TO STACK"<<endl;
        cout<<"2. DISPLAY ALL ELEMENT OF STACK"<<endl;
        cout<<"3. POP ELEMENT FROM STACK"<<endl;
        cout<<"4. PEEK TO AN ELEMENT FROM THE STACK"<<endl;
        cout<<"5. MAKE THE STACK EMPTY"<<endl;
        cout<<"6. FIND THE SIZE OF THE STACK"<<endl;
        cout<<"7. EXIT"<<endl;
        cout<<"PLEASE INPUT YOUR CHOICE: ";
        cin>>choice;
        switch (choice) {
            case 1:
                int number;
                cout<<"ENTER THE NUMBER YOU WANT TO PUSH TO THE STACK: ";
                cin>>number;
                push(number);
                cout<<endl<<endl<<endl;
                break;
            case 2:
                display();
                cout<<endl<<endl<<endl;
                break;
            case 3:
                pop();
                cout<<endl<<endl<<endl;
                break;
            case 4:
                peek();
                cout<<endl<<endl<<endl;
                break;
            case 5:
                make_empty();
                cout<<endl<<endl<<endl;
                break;
            case 6:
                cout<<"THE SIZE OF THE STACK IS: "<<getSize();
                cout<<endl<<endl<<endl;
                break;
                
            default:
                break;
        }
        
    } while (choice!=7);
}
void push(int number){
    Stack *temp=new Stack;
    temp->data=number;
    temp->next=NULL;
    if (top==NULL) {
        top=temp;
        top->next=NULL;
    } else {
        temp->next=top;
        top=temp;
    }
}
int pop(){
    if (is_emptyy()!=true) {
        Stack *temp;
        temp=top;
        top=top->next;
        int number=temp->data;
        delete temp;
        return number;
        
    } else {
        cout<<"STACK UNDERFLOW!!"<<endl;
        return 0;
    }
  
}
void peek(){
    if (is_emptyy()!=true) {
        cout<<"ELEMENT AT TOP IS "<<top->data<<endl;
    } else {
        cout<<"NO ELEMENT TO PEEK"<<endl;
    }
}
void display(){
    if (is_emptyy()!=true) {
        while (is_emptyy()!=true) {
            cout<<pop()<<"  ";
        }
    } else {
        cout<<"STACK IS EMPTY"<<endl;
    }
}
void make_empty(){
    top=NULL;
    cout<<"STACK IS NOW EMPTY!!"<<endl;
}

bool is_emptyy(){
    if (top==NULL) {
        return true;
    } else {
        return false;
    }
}
int getSize(){
    int counter=1;
    Stack *temp;
    temp=top;
    while (temp!=NULL) {
        temp=temp->next;
        counter++;
    }
    return counter;
}
