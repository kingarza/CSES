#include<bits/stdc++.h>
#define MAX 1001
#define Estado pair<int, int>
#define x first
#define y second
using namespace std;
 
int N, M;
char mapa[MAX][MAX];
pair<char, Estado> camino[MAX][MAX];
string sol;
 
const int ejex[] = {-1,  0, 1, 0},
          ejey[] = { 0, -1, 0, 1};
 
const char mov[] = {'U', 'L', 'D', 'R'};
 
void bfs(Estado A, Estado B){
    Estado origen = A;
    queue<Estado>Cola;
    Cola.push(A);
    mapa[A.x][A.y] = '#'; //visitamos
    camino[A.x][A.y] = {'O', A}; //A apunta a si mismo
    while(Cola.size()){
        A = Cola.front();
        Cola.pop();
 
        if(A == B){
            while(A != origen)
                sol += (camino[A.x][A.y].x),
                A = camino[A.x][A.y].y;
            break;
        }
 
        for(int i = 0; i < 4; i++){
            int X = A.x + ejex[i],
                Y = A.y + ejey[i];
            if(X > -1 && X < N && Y > -1 && Y < M && mapa[X][Y] != '#')
                Cola.push({X, Y}),
                mapa[X][Y] = '#', //visitamos
                camino[X][Y] = {mov[i], A}; //para llegar a {X, Y}, tuvimos que pasar por A
        }
    }
}
 
int main(){
 
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    Estado A, B;
 
    cin>>N>>M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            cin>>mapa[i][j];
            if(mapa[i][j] == 'A')
                A.x = i, A.y = j;
            if(mapa[i][j] == 'B')
                B.x = i, B.y = j;
        }
    bfs(A, B);
    if(sol.size())
        reverse(sol.begin(), sol.end()),
        cout<<"YES\n"<<sol.size()<<"\n"<<sol;
    else
        cout<<"NO";
}