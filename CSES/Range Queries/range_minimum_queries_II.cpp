#include<bits/stdc++.h>
#define MAX 200005
using namespace std;
 
int N, Q,
    ar[MAX],
    tree[MAX * 2];
 
void build_tree(){
    for(int i = 0; i < N; i++)
        tree[N + i] = ar[i];
    for(int i = N - 1; i > 0; i--)
        tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
}
 
void update(int pos, int value){
    pos += N;
    tree[pos] = value;
    for(pos /= 2; pos >= 1; pos /= 2)
        tree[pos] = min(tree[pos * 2], tree[pos * 2 + 1]);
}
 
int query(int a, int b){
    a += N, b += N;
    int Min = INT_MAX;
    while(a <= b){
        if(a % 2 != 0)
            Min = min(Min, tree[a++]);
        if(b % 2 == 0)
            Min = min(Min, tree[b--]);
        a /= 2, b /= 2;
    }
    return Min;
}
 
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    cin>>N>>Q;
    for(int i = 0; i < N; i++)
        cin>>ar[i];
    build_tree();
    while(Q--){
        int a, b, c;
        cin>>a>>b>>c;
        if(a == 1)
            update(b - 1, c);
        else
            cout<<query(b - 1, c - 1)<<"\n";
    }
    
 
}