#include<bits/stdc++.h>
#define MAX 100002
#define ll long long 
using namespace std;
 
ll n, m;
vector<pair<ll, ll> >ady[MAX];
  
void dijkstra(ll nodo){
 
    vector<ll>dist(MAX, LLONG_MAX);
    vector<bool>visitado(MAX); 
    set<pair<ll, ll> >cola;
    cola.insert({0, nodo});
    dist[nodo] = 0;
    while (cola.size()){
        ll u = (*cola.begin()).second;
        cola.erase(cola.begin());
        if(visitado[u] == 0){
            visitado[u] = 1;
            for(auto n : ady[u]){
                ll v = n.first;
                ll d = n.second;
                if(!visitado[v] && dist[u] + d < dist[v]){
                    dist[v] = dist[u] + d;
                    cola.insert({dist[v], v});
                }
            }
        }
    }
    for(ll i = 1; i <= n; i++)
        cout<<dist[i]<<" ";
}
 
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin>>n>>m;
    while(m--){
        ll a, b, c;
        cin>>a>>b>>c;
        ady[a].push_back({b, c});    
    }
    dijkstra(1);
}