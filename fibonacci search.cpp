#include<iostream>

using namespace std;

void simple_sort(int arr[],int n);
int mini(int first_number,int second_number);
int fibbonacci_search(int arr[],int n);

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }
    int index_of_search;
    
    index_of_search=fibbonacci_search(arr, n);
    
    if (index_of_search==-1) {
        cout<<"The element is not found!!!"<<endl;
    } else {
        cout<<"The element is found at index "<<index_of_search<<endl;
    }
}

void simple_sort(int arr[],int n){
    int temp;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[i]>arr[j]) {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout<<"The sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int mini(int first_number,int second_number){
    if (first_number<second_number) {
        return first_number;
    } else {
        return second_number;
    }
}
int fibbonacci_search(int arr[],int n){
    
    int x;
    cout<<"Enter the element that you want to search for: ";
    cin>>x;
    
    simple_sort(arr, n);
    
    int first_fib_number=0;
    int second_fib_number=1;
    int result_fib_number;
    
    result_fib_number=first_fib_number+second_fib_number;
    
    while (result_fib_number<=n) {
        
        first_fib_number=second_fib_number;
        second_fib_number=result_fib_number;
        result_fib_number=first_fib_number+second_fib_number;
        
    }
    
    int offset=0,i=-1;
    int found=0;
    
    while (found==0 && result_fib_number>1) {
        
        i=mini(offset+first_fib_number, n);
        
        if (arr[i]==x) {
            found=1;
            break;
        
        }
        else if(arr[i]>x){
            
            result_fib_number=first_fib_number;
            second_fib_number=second_fib_number-first_fib_number;
            first_fib_number=result_fib_number-second_fib_number;
        }
        else if (arr[i]<x){
            
            result_fib_number=second_fib_number;
            second_fib_number=first_fib_number;
            first_fib_number=result_fib_number-second_fib_number;
            
            offset=i;
        }
    }
    if (found==0) {
        return -1;
    } else {
        return i;
    }
}


