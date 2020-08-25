//1 - n
void bfs(){
    queue<int>Cola;
    Cola.push(1);
    camino[1] = 1;
    while(Cola.size()){
        int nodo = Cola.front();
        if(nodo == N){
            while(nodo != 1)
                sol.push_back(nodo),
                nodo = camino[nodo];
                sol.push_back(nodo);
            reverse(sol.begin(), sol.end());
        }
        Cola.pop();
        for(auto i : ady[nodo])
            if(!camino[i])
                camino[i] = nodo,
                Cola.push(i);
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
    bfs();
    if(sol.size()){
        cout<<sol.size()<<"\n";
        for(auto i : sol)
            cout<<i<<" ";
        return 0;
    }
    cout<<"IMPOSSIBLE";
}