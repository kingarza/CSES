#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MAX_N 200001
 
ll ar[MAX_N],
    tree[MAX_N * 2];
 
void build_tree(){
    for(ll i = 0; i < MAX_N; i++)
        tree[MAX_N + i] = ar[i];
    for(ll i = MAX_N - 1; i > 0; i--)
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
}
 
//add a value x to an especific position
void update(ll pos, ll value){
    pos += MAX_N;
    tree[pos] = value;
    for(pos /= 2; pos >= 1; pos /= 2)
        tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
}
 
ll query(ll left, ll right){
    left += MAX_N, right += MAX_N;
    ll suma = 0;
    while(left <= right){
        if(left % 2 != 0)
            suma += tree[left++];
        if(right % 2 == 0)
            suma += tree[right--];
        left /= 2, right /= 2;
    }
    return suma;
}
 
int main(){
 
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ll n, q;
    cin>>n>>q;
    for(ll i = 0; i < n; i++)
        cin>>ar[i];
    build_tree();
    while(q--){
        ll a, b, c;
        cin>>a>>b>>c;
        if(a == 1)
            update(b - 1, c);
        else
            cout<<query(b - 1, c - 1)<<"\n";
    }   
}