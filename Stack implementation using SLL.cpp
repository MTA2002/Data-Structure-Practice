//Array based stack implementation
#include <iostream>
using namespace std;

struct stack_implementation{
    int data;
    stack_implementation *next;
};

stack_implementation *top=NULL;

void main_menu();
bool is_emptyy();
void display();
int peek();
void push(int number);
void pop();
void make_empty();
int get_size();

int main(){
    main_menu();
    
    return 0;
}
void main_menu(){
    int choice;
    int number;
    do {
        cout<<"1. Push an element to the stack"<<endl;
        cout<<"2. Pop an element to the stack"<<endl;
        cout<<"3. Display all element from the stack"<<endl;
        cout<<"4. Peek the top element of the stack"<<endl;
        cout<<"5. Make the stack empty"<<endl;
        cout<<"6. Get the size of the stack"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Input you choice: ";
        cin>>choice;
        switch (choice) {
            case 1:
                cout<<"Enter a number: ";
                cin>>number;
                push(number);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                if (is_emptyy()) {
                    cout<<"No element to peek!!"<<endl;
                } else {
                    cout<<"The top element from the stack is "<<peek()<<endl;;
                }
                break;
            case 5:
                make_empty();
                break;
            case 6:
                if (is_emptyy()) {
                    cout<<"The stack is empty!!"<<endl;
                } else {
                    cout<<"The size of the stack is "<<get_size()<<endl;;
                }
                break;
            default:
                cout<<"Please enter appropriate value!!"<<endl;
                main_menu();
                break;
        }

    } while (choice!=7);
}
bool is_emptyy(){
    if (top==NULL) {
        return true;
    } else {
        return false;
    }
}

void display(){
    if (is_emptyy()) {
        cout<<"The stack is empty,no element to display!!"<<endl;
    } else {
        cout<<"The elements in the stack are: ";
        stack_implementation *temp=top;
        while (temp!=NULL) {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}
int peek(){
    return top->data;
}
void push(int number){
    stack_implementation *temp=new stack_implementation;
    temp->data=number;
    temp->next=NULL;
    if (top==NULL) {
        top=temp;
    } else {
        temp->next=top;
        top=temp;
    }
}
void pop(){
    if (is_emptyy()) {
        cout<<"Stack Underflow!!"<<endl;
    } else {
        stack_implementation *temp=top;
        top=top->next;
        delete temp;
    }
}
void make_empty(){
    if (is_emptyy()) {
        cout<<"The stack is currently empty!!"<<endl;
    } else {
        top=NULL;
    }
}
int get_size(){
    int counter=0;
    stack_implementation *temp=top;
    while (temp!=NULL) {
        counter++;
        temp=temp->next;
    }
    return counter;
}

