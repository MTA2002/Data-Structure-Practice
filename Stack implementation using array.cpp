//Array based stack implementation
#include <iostream>
using namespace std;

const int MAX_SIZE=5;

int top=-1;
int stack_array[MAX_SIZE];

void main_menu();
bool is_emptyy();
bool is_full();
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
    if (top==-1) {
        return true;
    } else {
        return false;
    }
}
bool is_full(){
    if (top+1==MAX_SIZE) {
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
        for (int i=top; i>=0; i--) {
            cout<<stack_array[i]<<" ";
        }
        cout<<endl;
    }
}
int peek(){
    return stack_array[top];
}
void push(int number){
    if (is_full()) {
        cout<<"Stack Overflow!!"<<endl;
    } else {
        top++;
        stack_array[top]=number;
        cout<<number<<" succesfully pushed to the stack!!"<<endl<<endl;
    }
}
void pop(){
    if (is_emptyy()) {
        cout<<"Stack Underflow!!"<<endl;
    } else {
        int number;
        number=stack_array[top];
        top--;
        cout<<number<<" succesfully popped from the stack!!"<<endl<<endl;
    }
}
void make_empty(){
    if (is_emptyy()) {
        cout<<"The stack is currently empty!!"<<endl;
    } else {
        top=-1;
        cout<<"The stack have been reinitialized to empty!!"<<endl;
    }
}
int get_size(){
    if (is_emptyy()) {
        return -1;
    } else {
        return top+1;
    }
}
