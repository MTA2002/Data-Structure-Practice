

#include <iostream>
using namespace std;
int linearsearch(int arr[],int size_of_array);
int binarysearch(int arr[],int size_of_array);
void menu_for_searching();
void menu_for_sorting();
void simplesort(int arr[],int size_of_array);
void bubblesort(int arr[],int size_of_array);
void selectionsort(int arr[],int size_of_array);
void insertionsort(int arr[],int size_of_array);


int main() {
    int choice;
    do {
        cout<<"Welcome to sorting and searching operations!"<<endl;
        cout<<"1. For Searching"<<endl;
        cout<<"2. For Sorting"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Input your choice: ";
        cin>>choice;
        switch (choice) {
            case 1:
                menu_for_searching();
                break;
            case 2:
                menu_for_sorting();
                break;
            default:
                break;
        }
        
    } while (choice!=3);
    return 0;
}
int linearsearch(int arr[],int size_of_array){
    int key;
    cout<<"Enter the element that you want to find: ";
    cin>>key;
    int index=-1;
    for(int i=0;i<size_of_array;i++){
        if(key==arr[i]){
            index=i;
            break;
        }
    }
    return index;
}
void menu_for_searching(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the array elements: ";
    for (int i=0; i<size; i++) {
        cin>>arr[i];
    }
    int index_of_search=0;
    int choice;
    cout<<"What kind of searching do you want to do\n1:linear Searching\n2:Binary Searching\nInput you choice: ";
    cin>>choice;
    if(choice==1){
        index_of_search=linearsearch(arr, size);
    }
    else if(choice==2){
        index_of_search=binarysearch(arr, size);
    }
    if(index_of_search!=-1){
        cout<<"The element is found at index "<<index_of_search<<endl;
    }
    else{
        cout<<"The element is not found!!\n index of search ="<<index_of_search<<endl;
    }
}
void menu_for_sorting(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the array elements: ";
    for (int i=0; i<size; i++) {
        cin>>arr[i];
    }
    int choice;
    cout<<"What kind of sorting do you want to do\n1. Simple Sort\n2. Bubble Sort \n3. Selection Sort\n4. Inserion Sort \nInput you choice: ";
    cin>>choice;
    switch (choice) {
        case 1:
            simplesort(arr, size);
            break;
        case 2:
            bubblesort(arr, size);
            break;
        case 3:
            selectionsort(arr, size);
            break;
        case 4:
            insertionsort(arr, size);
            break;
            
        default:
            break;
    }
}
void simplesort(int arr[],int size_of_array){
    for (int i=0; i<size_of_array-2; i++) {
        for(int j=i+1;j<size_of_array-1;j++){
            if(arr[i]>arr[j]){
                int temp;
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
  
}
int binarysearch(int arr[],int size_of_array){
    simplesort(arr, size_of_array);
    int top,middle=0,bottom;
    int found=0;
    top=size_of_array-1;
    bottom=0;
    int key;
    cout<<"Enter the elemnt that you want to find: ";
    cin>>key;
    int index=-1;
    while (found==0 &&top>=bottom) {
        middle=(top+bottom)/2;
        if(arr[middle]==key){
            found=1;
        }
        else if(key>middle){
            bottom=middle+1;
        }
        else if (key<middle){
            top=middle-1;
        }
    }
    if(found==1){
        return middle;
    }
    else
        return index;
    
}
void bubblesort(int arr[],int size_of_array){
    for (int i=size_of_array-1; i>0; i--) {
        for (int j=0; j<i; j++) {
            if(arr[j]>arr[j+1]){
                int temp;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    cout<<"The sorted array is: \n";
    for (int i=0; i<size_of_array; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void selectionsort(int arr[],int size_of_array){
    int minindex;
    for (int i=0; i<=size_of_array-2; i++) {
        minindex=i;
        for (int j=i+1; j<=size_of_array-1; j++) {
            if(arr[j]<arr[minindex]){
                minindex=j;
            }
        }
        if(minindex!=i){
            int temp;
            temp=arr[i];
            arr[i]=arr[minindex];
            arr[minindex]=temp;
        }
    }
    cout<<"The sorted array is: \n";
    for (int i=0; i<size_of_array; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void insertionsort(int arr[],int size_of_array){
    for (int i=1; i<size_of_array; i++) {
        for (int j=i; j>=1; j--) {
            if(arr[j]<arr[j-1]){
                int temp;
                temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
            else
                break;
        }
    }
    cout<<"The sorted array is: \n";
    for (int i=0; i<size_of_array; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
