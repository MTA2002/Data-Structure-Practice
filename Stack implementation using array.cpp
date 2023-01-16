#include<iostream>
using namespace std;

int MAX_STACK=10;
int STACK[10];
int top=-1;

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
        system("cls");
        cout<<"WELCOME TO STACK IMPLEMENTATION USING ARRAYS!!"<<endl;
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
                system("cls");
            case 1:
                int number;
                cout<<"ENTER THE NUMBER YOU WANT TO PUSH TO THE STACK: ";
                cin>>number;
                push(number);
                system("pause");
                break;
            case 2:
                display();
                system("pause");
                break;
            case 3:
                pop();
                break;
            case 4:
                peek();
                system("pause");
                break;
            case 5:
                make_empty();
                system("pause");
                break;
            case 6:
                cout<<"THE SIZE OF THE STACK IS: "<<getSize();
                system("pause");
                break;

            default:
                break;
        }

    } while (choice!=7);
}
void push(int number){
    if (is_full()!=true) {
        top++;
        STACK[top]=number;
        cout<<"ELEMENT SUCCESSFULLY PUSHED!!"<<endl;
    } else {
        cout<<"STACK OVERFLOW!!"<<endl;
    }
}
int pop(){
    if (is_emptyy()!=true) {
        int element_at_top;
        element_at_top=STACK[top];
        STACK[top]=NULL;
        top--;

        return element_at_top;

    } else {
        cout<<"STACK UNDERFLOW!!"<<endl;
        return 0;
    }

}
void peek(){
    if (is_emptyy()!=true) {
        cout<<"ELEMENT AT TOP IS "<<STACK[top]<<endl;
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
    top=-1;
    cout<<"STACK IS NOW EMPTY!!"<<endl;
}
bool is_full(){
    if (top>MAX_STACK) {
        return true;
    } else{
        return false;
    }
}
bool is_emptyy(){
    if (top==-1) {
        return true;
    } else {
        return false;
    }
}
int getSize(){
    if (top>-1) {
        return top+1;
    } else {
        return 0;
    }

}
