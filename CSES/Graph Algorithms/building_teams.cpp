#include<bits/stdc++.h>
#define MAX 100002
using namespace std;
 
int N, M;
vector<int>ady[MAX];
int visitado[MAX];
 
void colorea(int nodo){
    queue<int>Cola;
    Cola.push(nodo);
    visitado[nodo] = 1;
    while(Cola.size()){
        int nodo = Cola.front();
        Cola.pop();
        for(auto i : ady[nodo])
            if(!visitado[i]){
                if(visitado[nodo] == 1)
                    visitado[i] = 2;
                else
                    visitado[i] = 1;
                Cola.push(i);
            }
            else if(visitado[nodo] == visitado[i]){
                cout<<"IMPOSSIBLE";
                exit(0);
            }
    }
}
 
int main(){
 
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    cin>>N>>M;
 
    int a, b;
    for(int i = 0; i < M; i++)
        cin>>a>>b,
        ady[a].push_back(b),
        ady[b].push_back(a);
 
    for(int i = 1; i <= N; i++)
        if(!visitado[i])
            colorea(i);
    for(int i = 1; i <= N; i++)
        cout<<visitado[i]<<" ";
}