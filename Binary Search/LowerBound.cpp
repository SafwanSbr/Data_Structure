#include <iostream>

using namespace std;

int lowerBou_Binary_search( int arr[], int Size, int element)
{
    int l=0, r=Size-1;
    int ans = Size;
    
    while( l<=r )
    {
        int mid = (l+r) / 2;
        
        if( arr[mid] >= element ){
            ans = min( ans, mid);
            r = mid - 1;
        }
        else l=mid+1;
    }
    
    return ans;
}

int main()
{
    vector <int> v = {1, 2, 4, 5, 5, 5, 6};
    
    //buildin Fun
    auto it = lower_bound ( v.begin(), v.end(), 3); //Itaretor
    int pos = lower_bound ( v.begin(), v.end(), 3) - v.begin();//Position
}
