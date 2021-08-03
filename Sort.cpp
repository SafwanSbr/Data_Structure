#include<iostream>
using namespace std;

void Swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}
//Bubble Sort || Time complexity O(n^2)
void BubbleSort(int arr[], int Size){
    for(int i=0; i<Size; i++){
        for(int j=0; j<Size-i-1; j++){
            if(arr[j]>arr[j+1]) Swap(&arr[j], &arr[j+1]);
            //for(int i=0; i<Size; i++) cout<<arr[i]<<" ";
            //cout<<"\n";
        }
    }
    for(int i=0; i<Size; i++) cout<<arr[i]<<" ";
}
//Selection Sort || Time complexity O(n^2)
//In selection sort, if we keep "Swap" outside of the if-else, "min_index" will be compared with "j" and then "j" & "i" will be swapped. 
void SelectionSort(int arr[], int Size){
    for(int i=0; i<Size; i++){
        int min_index=i;
        for(int j=i; j<Size; j++){
            if(arr[min_index]>arr[j]) min_index = j;
        }
        Swap(&arr[i], &arr[min_index]);
    }
    for(int i=0; i<Size; i++) cout<<arr[i]<<" ";
}
//Insertion Sort || Time complexity O(n^2)
void InsertionSort(int arr[], int Size){
    for(int i=1; i<Size; i++){
        //int v=arr[i];
        for(int j=i-1; j>=0; j--){
            //cout<<"I="<<arr[i]<<" J="<<arr[j]<<" .................................\n";
            if(arr[i]<arr[j]) Swap(&arr[i--], &arr[j]);
            else break;
             //cout<<"I="<<arr[i]<<" J="<<arr[j]<<" ";
             //cout<<"\n";
        } //for(int i=0; i<Size; i++) cout<<arr[i]<<" "; cout<<"\n";
    }
    for(int i=0; i<Size; i++) cout<<arr[i]<<" ";
}

int main(){
    int arr[]={7,3,9,1,0,33,6};
    int Size=sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr, Size);    cout<<"\n";
    SelectionSort(arr, Size);   cout<<"\n";
    InsertionSort(arr, Size);   cout<<"\n";
}
