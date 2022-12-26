#include<bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(nullptr);

/*
#define int long long
const int MAXN = 1e6 + 5;
int prime[MAXN];
void sieve() {
    prime[1] = 1;
    for(int i = 2; i <= MAXN; i++) {
        if(i % 2 == 0) prime[i] = 2;
        else prime[i] = i;
    }
    for(int i = 3; i * i <= MAXN; i += 2) {
        if(prime[i] == i) {
            for(int j = i * i; j <= MAXN; j += i) {
                if(prime[j] == j) {
                    prime[j] = i;
                }
            }
        }
    }
}
long long binExp(long long base, long long pow) {
    long long result = 1;
    while(pow > 0) {
        if(pow %2 == 1) {
            result *= base;
        }
        base *= base;
        pow /= 2;
    }
    return result;
}
*/
#define int long long int
const int mx = 3e5+9;

int arr[mx];
int tree[mx * 4];

void setTree( int node, int l, int r){
    if( l == r ){
        tree[node] = arr[l];
        return;
    }
    int Left = node*2; //Left node
    int Right = node*2 + 1; //Right node
    int mid = l + (r-l)/2;

    setTree( Left, l, mid); //Left recursion
    setTree( Right, mid+1, r); //Right Recursion

    tree[node] = min( tree[Left], tree[Right] );

}

int query ( int node, int l, int r, int i, int j){ //Find sum of i to j, from array l to r
    if( i>r || j<l ){
        return INT_MAX;
    }
    if( l>=i && r<=j){
        return tree[node];
    }

    int Left = node*2;
    int Right = node*2+1;
    int mid = l + (r-l)/2;

    int suml = query( Left, l, mid, i, j);
    int sumr = query( Right, mid+1, r, i, j);

    return min(suml, sumr);
}

void update(int node, int l, int r, int i, int newValue){
    if( i>r || i<l )
    {
        return;
    }
    if( l>=i && r<=i )
    {
        tree[node] = newValue;
        return;
    }

    int Left = node*2;
    int Right = node*2+1;
    int mid = (l+r)/2;

    update( Left, l, mid, i, newValue);
    update( Right, mid+1, r, i, newValue);

    tree[node] = tree[Left] + tree[Right];
}
int32_t main(){
    boost;
    int n, q;
    cin >> n >> q;

    for( int i=1; i<=n; i++) cin >> arr[i];
    setTree(1, 1, n);

    //for(int i=0; i<n*2; i++) cout<< tree[i]<<" ";
    while( q-- ){
        int a, b;
        cin >> a >> b;
        cout << query(1, 1, n, a, b) << "\n";
    }
}
