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
}
