#include<iostream>
using namespace std;

void Swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}
//Bubble Sort
void BubbleSort(int arr[], int Size){
    for(int i=0; i<Size; i++){
        for(int j=0; j<Size-j-1; j++){
            if(arr[j]>arr[j+1]) Swap(&arr[j], &arr[j+1]);
            //for(int i=0; i<Size; i++) cout<<arr[i]<<" ";
            //cout<<"\n";
        }
    }
    for(int i=0; i<Size; i++) cout<<arr[i]<<" ";
}
//Selection Sort
void SelectionSort(int arr[], int Size){
    for(int i=0; i<Size; i++){
        int k=i;
        for(int j=i; j<Size; j++){
            if(arr[k]>arr[j]) k=j;
        }
        Swap(&arr[i], &arr[k]);
    }
    for(int i=0; i<Size; i++) cout<<arr[i]<<" ";
}
//Insertion Sort
void InsertionSort(int arr[], int Size){
    for(int i=0; i<Size; i++){
        int v=arr[i];
        for(int j=i; j>=0; j--){
            if(arr[i]<arr[j]) Swap(&arr[i--], &arr[j]);
            // cout<<"I="<<arr[i]<<" J="<<arr[j]<<" ";
            // cout<<"\n";
        } //for(int i=0; i<Size; i++) cout<<arr[i]<<" "; cout<<"\n";
    }
    for(int i=0; i<Size; i++) cout<<arr[i]<<" ";
}

int main(){
    int arr[5]={5, 2, 3, 1, 4};
    int Size=sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr, Size);    cout<<"\n";
    SelectionSort(arr, Size);   cout<<"\n";
    InsertionSort(arr, Size);   cout<<"\n";
}
