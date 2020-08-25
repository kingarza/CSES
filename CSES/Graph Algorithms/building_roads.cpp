#include<bits/stdc++.h>
#define MAX 100002
using namespace std;
 
int N, M,
    parent[MAX],
    h[MAX];
 
int root(int x){
    return (x == parent[x])? x : parent[x] = root(parent[x]);
}
 
void UnionbyRank(int a, int b){
    if(root(a) == root(b))
        return;
    if(h[root(a)] > h[root(b)])
        parent[root(b)] = root(a);
    else if(h[root(a)] < h[root(b)])
        parent[root(a)] = root(b);
    else
        parent[root(a)] = root(b),
        h[root(b)] = h[root(b)] + 1;
}
 
bool sameComponent(int a, int b){
    return (root(a) == root(b));
}
 
int main(){
 
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    cin>>N>>M;
 
    for(int i = 0; i <= N; i++)
        parent[i] = i;
 
    int a, b;
    for(int i = 0; i < M; i++)
        cin>>a>>b,
        UnionbyRank(a, b);
 
    vector<pair<int, int> >output;
    for(int i = 1; i <= N; i++)
        if(!sameComponent(1, i)) //si no estan en la misma componente
            UnionbyRank(1, i), //los unimos
            output.push_back({1, i});
    cout<<output.size()<<"\n";
    for(auto i :  output)
        cout<<i.first<<" "<<i.second<<"\n";
}