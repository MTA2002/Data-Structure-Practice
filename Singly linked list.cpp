//
//  main.cpp
//  Data Structure and Algorithim Practice
//
//  Created by Mahfouz Teyib on 26/12/2022.
//

#include <iostream>
#include<string.h>
#include<iostream>

using namespace std;

struct student_record{
    char name[20];
    int id;
    int age;
    char department[25];
    student_record *next;
};

student_record *head=NULL;
void menu_for_linked_list();
void menu_for_insertion();
void add_to_the_front();
void add_to_the_middle();
void add_to_the_end();
void display_students();
void menu_for_deletion();
void delete_from_the_front();
void delete_from_the_middle();
void delete_from_the_end();
void search_for_student();

int main(int argc, const char * argv[]) {
    
    menu_for_linked_list();
    return 0;
}

void menu_for_linked_list(){
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
                display_students();
                break;
            case 3:
                menu_for_deletion();
                break;
                
            case 4:
                search_for_student();
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
    cout<<"2. Add to the middle"<<endl;
    cout<<"3. Add to the end"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"\nInput your choice:";
    cin>>choice;
    switch (choice) {
        case 1:
            add_to_the_front();
            break;
        case 2:
            add_to_the_middle();
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
    if (head==NULL) {
        head=temp1;
    } else {
        student_record *temp2;
        temp2=head;
        head=temp1;
        head->next=temp2;
    }
}
void add_to_the_middle(){
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
    if (head==NULL) {
        head=temp1;
    }
    else{
        int counter=1;
        int index;
        student_record *temp2;
        temp2=head;
        while (temp2->next!=NULL) {
            temp2=temp2->next;
            counter++;
        }
        cout<<"The record has "<<counter<<" elements!\nPlease enter at which index you want your data to get inserted: ";
    first:
        cin>>index;
        
        if (index>counter) {
            cout<<"Please Enter again!\n";
            goto first;
        } else {
            cout<<"Do you want to insert before the index or after the index?(Press 1 for Before the index\Press 2 for after the index): ";
            int choice_2;
            cin>>choice_2;
            if (choice_2==1) {
                index--;
            }
            temp2=head;
            int i=1;
            while (temp2->next!=NULL &&i<index) {
                temp2=temp2->next;
                if (i==index) {
                    break;
                }
                i++;
            }
            temp1->next=temp2->next;
            temp2->next=temp1;
            
            
        }
    }
}
void add_to_the_end(){
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
    if (head==NULL) {
        head=temp1;
    }
    else{
        student_record *temp2;
        temp2=head;
        while (temp2->next!=NULL) {
            temp2=temp2->next;
        }
        temp2->next=temp1;
    }
}
void display_students(){
    student_record *temp;
    temp=head;
    if (temp==NULL) {
        cout<<"There is No Record Available!!\n";
    } else {
        cout<<"Name\t\tId\tAge\tDepartment\n";
        while (temp!=NULL) {
            cout<<temp->name<<"  "<<temp->id<<"\t"<<temp->age<<"\t"<<temp->department<<endl;
            temp=temp->next;
        }
    }
}
void menu_for_deletion(){
    cout<<"Coming Soon!!"<<endl;
}
void delete_from_the_front(){
    cout<<"Coming Soon!!"<<endl;
}
void delete_from_the_middle(){
    cout<<"Coming Soon!!"<<endl;
}
void delete_from_the_end(){
    cout<<"Coming Soon!!"<<endl;
}
void search_for_student(){
    char temp_name[20];
    cout<<"Enter the name of the student you want to find: ";
    cin.ignore();
    cin.getline(temp_name, 20);
    student_record *temp;
    temp=head;
    if (strncasecmp(temp_name, temp->name, 25)==0) {
        cout<<"The record is found!"<<endl;
        cout<<"Name: "<<temp->name<<endl;
        cout<<"Id: "<<temp->id<<"\n";
        cout<<"Age: "<<temp->age<<"\n";
        cout<<"Department: "<<temp->department<<endl;
    } else {
        int found=0;
        while (strncasecmp(temp_name, temp->name, 25)!=0) {
            temp=temp->next;
            if (strncasecmp(temp_name, temp->name, strlen(temp_name))==0){
                found=1;
            }
        }
        if (found==1) {
            cout<<"The record is found!"<<endl;
            cout<<"Name: "<<temp->name<<endl;
            cout<<"Id: "<<temp->id<<"\n";
            cout<<"Age: "<<temp->age<<"\n";
            cout<<"Department: "<<temp->department<<endl;
        } else {
            cout<<"The record is not found!!"<<endl;
        }
        
    }
   
}
