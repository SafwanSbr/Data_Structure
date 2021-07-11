#include<iostream>
using namespace std;

int LinearSearch(int arr[],int Size, int element){
    for(int i=0; i<Size; i++)
    if(element==arr[i]) {
        return i;
    }
    return -1;
}

int BinarySearch(int arr[], int Size, int element){
    int left = 0, right = Size-1;

    while(right>=left){
        int mid = (left+right)/2;
        if(arr[mid] == element) return mid;//If we find the ans
        else if(element>arr[mid]) left = mid+1;//If the elem is greater
        else right = mid-1;//If the elem is smaller
        //cout<<left<<" "<<mid<<" "<<right<<"\n";
    }
    return -1;
}

int main(){
    int arr[]={0,1,2,3,4};
    int Size = sizeof(arr)/sizeof(arr[0]);//You can't use "sizeof" in function.

    int ans=BinarySearch(arr, Size, 3);
    (ans != -1)? cout<<"Element found at index "<<ans<<".\n" : cout<<"Element not Found!\n";

    ans=LinearSearch(arr, Size, 4);
    (ans != -1)? cout<<"Element found at index "<<ans<<".\n" : cout<<"Element not Found!\n";
}
