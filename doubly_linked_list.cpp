//Doubly linked list implementation
#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

void main_menu();
void menu_for_insertion();
void add_to_the_front();
void add_any_position();
void add_to_the_end();
void menu_for_display();
void display_forward();
void display_backward();
void menu_for_deletion();
void delete_from_the_front();
void delete_at_any_position();
void delete_from_the_end();
void search_element();

struct student_record{
    char name[20];
    int id;
    int age;
    char department[25];
    student_record *previous;
    student_record *next;
};
student_record *head=NULL;
student_record *tail=NULL;

int counter=1;//to count number of elements

int main(){
    main_menu();
    
    return 0;
}
void main_menu(){
    int choice;
        do {
            cout<<"1. Add Student"<<endl;
            cout<<"2. Display Students"<<endl;
            cout<<"3. Delete A Student"<<endl;
            cout<<"4. Search for Student"<<endl;
            cout<<"5. Exit Program"<<endl;
            cout<<"\nInput your choice: ";
            cin>>choice;
            switch (choice) {
                case 1:
                    menu_for_insertion();
                    break;
                case 2:
                    menu_for_display();
                    break;
                case 3:
                    menu_for_deletion();
                    break;
                    
                case 4:
                    search_element();
                    break;
                    
                default:
                    cout<<"Please enter appropriate Input!!"<<endl;
                    break;
            }
        } while (choice!=5);
}
void menu_for_insertion(){
    int choice;
       cout<<"1. Add to the front"<<endl;
       cout<<"2. Add anywhere"<<endl;
       cout<<"3. Add to the end"<<endl;
       cout<<"4. Exit"<<endl;
       cout<<"\nInput your choice:";
       cin>>choice;
       switch (choice) {
           case 1:
               add_to_the_front();
               break;
           case 2:
               add_any_position();
               break;
           case 3:
               add_to_the_end();
               break;
           case 4:
               break;
           default:
               cout<<"Please enter appropriate Input!!"<<endl;
               menu_for_insertion();
               break;
       }
}
void add_to_the_front(){
    student_record *temp=new student_record;
    
    cout<<"Enter the name of the student: ";
    cin.ignore();
    cin.getline(temp->name, 20);
    cout<<"Enter the Id of the student: ";
    cin>>temp->id;
    cout<<"Enter the Age of the student: ";
    cin>>temp->age;
    cout<<"Enter the Department of the student: ";
    cin.ignore();
    cin.getline(temp->department, 20);
    
    temp->next=NULL;
    temp->previous=NULL;
    
    if (head==NULL) {
        head=temp;
        tail=temp;
        
    } else {
        head->previous=temp;
        temp->previous=head;
        head=temp;
    }
    cout<<"Record successfully added at the front!!"<<endl;
}
void add_any_position(){
    int index;
    
    student_record *temp1=new student_record;
   
    cout<<"Enter the name of the student: ";
    cin.ignore();
    cin.getline(temp1->name, 20);
    cout<<"Enter the Id of the student: ";
    cin>>temp1->id;
    cout<<"Enter the Age of the student: ";
    cin>>temp1->age;
    cout<<"Enter the Department of the student: ";
    cin.ignore();
    cin.getline(temp1->department, 20);
    
    temp1->next=NULL;
    temp1->previous=NULL;
    
    if (head==NULL) {
        head=temp1;
        tail=temp1;
        cout<<"Record successfully added!!"<<endl;

    } else {
        student_record *temp2;
        temp2=head;
        while (temp2->next!=NULL) {
            temp2=temp2->next;
            counter++;
        }
        temp2=head;
        cout<<"The list has "<<counter<<" records in it!\n";
        cout<<"Enter the index that you want to add the element to: ";
        label:
        cin>>index;
        if (index>counter+1 &&index<0) {
            cout<<"Please try again!!";
            goto label;
        } else {
            if (index==1) {
                head->previous=temp1;
                temp1->next=head;
                head=temp1;
                cout<<"Record successfully added at the index: "<<index<<"!!"<<endl;

            }
            else if(index>1 && index<counter+1) {
                for (int i=1; i<index; i++) {
                    temp2=temp2->next;
                }
                temp1->previous=temp2->previous;
                temp1->next=temp2;
                temp2->previous->next=temp1;
                temp2->previous=temp1;
                cout<<"Record successfully added at the index: "<<index<<"!!"<<endl;
            }
            else{
                temp1->previous=tail;
                tail->next=temp1;
                tail=temp1;
                cout<<"Record successfully added at the index: "<<index<<"!!"<<endl;
                
            }
        }
    }
}
void add_to_the_end(){
    student_record *temp=new student_record;
    
    cout<<"Enter the name of the student: ";
    cin.ignore();
    cin.getline(temp->name, 20);
    cout<<"Enter the Id of the student: ";
    cin>>temp->id;
    cout<<"Enter the Age of the student: ";
    cin>>temp->age;
    cout<<"Enter the Department of the student: ";
    cin.ignore();
    cin.getline(temp->department, 20);
    
    temp->next=NULL;
    temp->previous=NULL;
    
    if (tail==NULL) {
        tail=temp;
        head=temp;
    } else {
        
        temp->previous=tail;
        tail->next=temp;
        tail=temp;
        
    }
}
void menu_for_display(){
        int choice=0;
    
        cout<<"1. Display in a forward manner"<<endl;
        cout<<"2. Display in a backward manner"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Input your choice: ";
        cin>>choice;
        
        switch (choice) {
            case 1:
                display_forward();
                break;
            case 2:
                display_backward();
                break;
                
            default:
                cout<<"Please enter appropriate Input!!"<<endl;
                menu_for_display();
                break;
        }
   
}

void display_forward(){
    if (head==NULL) {
        cout<<"NO RECORDS AVAILABLE!!"<<endl;
    } else {
        student_record *temp;
        temp=head;
        cout<<"-------------------------------------------------------------------------------------------------------------\n";
        cout<<"| NAME"<<setw(16)<<" | ID"<<setw(4)<<" | AGE"<<setw(4)<<" | DEPARTMENT--------------------------------------|"<<endl;
        while (temp!=NULL) {
            cout<<"| "<<temp->name<<setw(20-strlen(temp->name))<<" | "<<temp->id<<setw(4)<<" | "<<temp->age<<" | "<<temp->department<<endl;
            temp=temp->next;
        }
    }
}
void display_backward(){
    if (tail==NULL) {
        cout<<"NO RECORDS AVAILABLE!!"<<endl;
    } else {
        student_record *temp;
        temp=tail;
        cout<<"-------------------------------------------------------------------------------------------------------------\n";
        cout<<"| NAME"<<setw(16)<<" | ID"<<setw(4)<<" | AGE"<<setw(4)<<" | DEPARTMENT--------------------------------------|"<<endl;
        while (temp!=NULL) {
            cout<<"| "<<temp->name<<setw(20-strlen(temp->name))<<" | "<<temp->id<<setw(4)<<" | "<<temp->age<<" | "<<temp->department<<endl;
            temp=temp->previous;
        }
    }
}
void menu_for_deletion(){
    int choice;
        cout<<"1. Delete from the front"<<endl;
        cout<<"2. Delet anywhere"<<endl;
        cout<<"3. Delete at the end"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"\nInput your choice:";
        cin>>choice;
        switch (choice) {
            case 1:
                delete_from_the_front();
                break;
            case 2:
                delete_at_any_position();
                break;
            case 3:
                delete_from_the_end();
                break;
            case 4:
                break;
            default:
                cout<<"Please enter appropriate Input!!"<<endl;
                menu_for_deletion();
                break;
        }
}
void delete_from_the_front(){
    if (head==NULL) {
        cout<<"NO RECORD AVAILABLE!!"<<endl;
    } else {
        student_record *temp;
        temp=head;
        head=head->next;
        head->previous=NULL;
        delete temp;
    }
}
void delete_at_any_position(){
    if (head==NULL) {
        cout<<"NO RECORD AVAILABLE!!"<<endl;
    } else {
        student_record *temp;
        temp=head;
        char name[20];
        cout<<"Enter the name of the student you want to delete: ";
        cin.ignore();
        cin.getline(name, 20);
        int i=1;
        while (strcmp(name,temp->name)!=0) {
            temp=temp->next;
            i++;
        }
        if(i==1){
            head=head->next;
            head->previous=NULL;
            delete temp;
            
        }
        else if(i>1&& i<counter){
            (temp->next)->previous=temp->previous;
            (temp->previous)->next=temp->next;
            //to disconnect the nodes
            temp->next=NULL;//to make sure it has no link to any element
            temp->previous=NULL;
            delete temp;
            
        }
        else{
            tail=tail->previous;
            tail->next=NULL;
            delete temp;
        }
        
    }
}
void delete_from_the_end(){
    if (tail==NULL) {
        cout<<"NO RECORD AVAILABLE!!"<<endl;
    } else {
        student_record *temp;
        temp=tail;
        tail=tail->previous;
        tail->next=NULL;
        delete temp;
    }
}
void search_element(){
    int found=0;
    if (head==NULL) {
        cout<<"NO RECORD AVAILABLE!!"<<endl;
    } else {
        student_record *temp;
        temp=head;
        char name[20];
        cout<<"Enter the name of the student you want to delete: ";
        cin.ignore();
        cin.getline(name, 20);
        int index=1;
        while (found==0) {
            if (strcmp(temp->name, name)==0) {
                found=1;
                break;
            }
            index++;
            temp=temp->next;
        }
        if (found==0) {
            cout<<"The record is not found!!"<<endl;
        } else {
            cout<<"The record is found at index "<<index<<" !";
            cout<<"The Data on the reord is: ";
            cout<<" Name: "<<temp->name<<endl;
            cout<<" Id: "<<temp->id<<endl;
            cout<<" Age: "<<temp->age<<endl;
            cout<<" Department: "<<temp->department<<endl;
            
        }
    }
}
