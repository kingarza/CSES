#include<bits/stdc++.h>
using namespace std;
 
#define MAX_N 200001
 
int N, Q,
    ar[MAX_N + 5],
    tree[MAX_N * 2 + 5];
 
void build_tree(){
    for(int i = 0; i < N; i++)
        tree[N + i] = ar[i];
    for(int i = N - 1; i > 0; i--)
        tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
}
 
int query(int left, int right){
    left += N, right += N;
    int Min = INT_MAX;
    while(left <= right){
        if(left % 2 != 0)
            Min = min(Min, tree[left++]);
        if(right % 2 == 0)
            Min = min(Min, tree[right--]);            
        left /= 2, right /= 2;
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
        int a, b;
        cin>>a>>b;                            
        cout<<query(a - 1, b - 1)<<"\n";
    }
}