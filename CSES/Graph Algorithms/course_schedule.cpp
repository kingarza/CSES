#include<bits/stdc++.h>
#define MAX 200005
using namespace std;

int n, m;
vector<int>ady[MAX];
bitset<MAX>visitado;
vector<int>topoSort;

void topologicalSort(int u){
    visitado[u] = 1;
    for(auto v : ady[u]){
        if(!visitado[v])
            topologicalSort(v);
    }
    topoSort.push_back(u);
}

int dfs_num[MAX];
bool loops;

void graphCheck(int u){
    if( loops ) 
        return;        
    dfs_num[u] = 2;
    for(int j = 0; j < ady[u].size(); j++){
        int next = ady[u][j];
        if( dfs_num[next] == -1 )
            graphCheck( next );
        else if( dfs_num[next] == 2){
            loops = 1;
            break;
        }
    }
    dfs_num[u] = 3;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    while(m--){
        int a, b;
        cin>>a>>b;
        ady[a].push_back(b);
    }
    //checamos si tiene ciclo, en caso de tener es imposible
    //inicializacion
    for(int i = 0; i < MAX; i++)
        dfs_num[i] = -1;
    for(int i = 1; i <= n && !loops; i++)
        if(dfs_num[i] == -1) 
            graphCheck(i);
    if(loops){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    //hacemos el orden topologico, es posible
    for(int i = 1; i <= n; i++)
        if(!visitado[i])
            topologicalSort(i);
    reverse(topoSort.begin(), topoSort.end());
    for(auto i : topoSort)
        cout<<i<<" ";
    
}