#include<iostream>
using namespace std;

struct binary_search_tree{
    int data;
    binary_search_tree *left;
    binary_search_tree *right;
};
binary_search_tree *root=NULL;

//to store the elements in a linked list
struct linked_list{
    int data;
    linked_list *next;
};
linked_list *head=NULL;

//this will be a main menu that will handle everything like insertion,displaying and sorting in the list
void main_menu();

//this funcion accepts numbers from the user
void insert_at_the_linked_list();

//this function will display the elements avilable in the list
void display_elements_of_the_list();

//this will be the function that will implement the tree sort algorithim
void tree_sort();

//this function inserts into the binary search tree from the linked lis
void insert_to_binary_search_tree(int data);

/*this function will traverse the BST inorder and after visiting every node it wil add each                                                      node to the linked list*/
void inorder_traversal(binary_search_tree *root_ptr);

//this function will add a node to the sorted list
void sorted_list(int data);

int main(){
    main_menu();
    
    return 0;
}

void main_menu(){
    int choice;
    do {
        cout<<"1. Add Number"<<endl;
        cout<<"2. Display all the numbers in the list"<<endl;
        cout<<"3. Sort the list"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Input you choice: ";
        cin>>choice;
        switch (choice) {
            case 1:
                insert_at_the_linked_list();
                break;
            case 2:
                display_elements_of_the_list();
                break;
            case 3:
                tree_sort();
                break;
            default:
                cout<<"Please enter appropriate input!"<<endl;
                break;
        }
    } while (choice!=4);
}

void insert_at_the_linked_list(){
    linked_list *temp=new linked_list;
    cout<<"Enter a number: ";
    cin>>temp->data;
    temp->next=NULL;
    if (head==NULL) {
        head=temp;
    } else {
        linked_list *temp2=NULL;
        temp2=head;
        while (temp2->next!=NULL) {
            temp2=temp2->next;
        }
        temp2->next=temp;
    }
}

void display_elements_of_the_list(){
    if (head==NULL) {
        cout<<"No record available!!"<<endl;
    } else {
        linked_list *temp=head;
        while (temp!=NULL) {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}

void tree_sort(){
    if (head==NULL) {
        cout<<"The list is empty!"<<endl;
    } else {
        linked_list *temp=head;
        while (temp!=NULL) {
            insert_to_binary_search_tree(temp->data);
            temp=temp->next;
        }
        head=NULL;
        inorder_traversal(root);
        root=NULL;
        cout<<"The list is now sorted!!"<<endl;
    }
    
    
}

void insert_to_binary_search_tree(int data){
    binary_search_tree *temp1=new binary_search_tree;
    temp1->data=data;
    
    temp1->left=NULL;
    temp1->right=NULL;
    
    if (root==NULL) {
        root=temp1;
    } else {
        int inserted=0;
        binary_search_tree *temp2=root;
        
        while (inserted==0) {
            if (temp1->data>temp2->data) {
                if (temp2->right==NULL) {
                    temp2->right=temp1;
                    inserted=1;
                }
                else{
                    temp2=temp2->right;
                }
            } else if(temp1->data<temp2->data){
                if (temp2->left==NULL) {
                    temp2->left=temp1;
                    inserted=1;
                }
                else{
                    temp2=temp2->left;
                }
            }
        }
        
    }
}



void inorder_traversal(binary_search_tree *root_ptr){
    
    if (root_ptr!=NULL) {
        
        inorder_traversal(root_ptr->left);
        sorted_list(root_ptr->data);
        inorder_traversal(root_ptr->right);
        
    }
    
}

void sorted_list(int data){
    linked_list *temp=new linked_list;
    temp->data=data;
    temp->next=NULL;
    if (head==NULL) {
        head=temp;
    } else {
        linked_list *temp2=NULL;
        temp2=head;
        while (temp2->next!=NULL) {
            temp2=temp2->next;
        }
        temp2->next=temp;
    }
}
