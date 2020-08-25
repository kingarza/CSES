#include<bits/stdc++.h>
#define MAX 1001
using namespace std;
 
int N, M, Color = 1;
char mapa[MAX][MAX];
int visitado[MAX][MAX];
 
const int ejex[] = {-1,  0, 1, 0},
          ejey[] = { 0, -1, 0, 1};
 
class Queue{
private:
    int inicio, fin, capacidad;
    pair<int, int>ar[MAX * MAX];
public:
    void init(){
        inicio = fin = capacidad = 0;
    }
    void push(pair<int, int>aux){
        ar[fin++] = aux;
        capacidad++;
    }
    void pop(){
        inicio++;
        capacidad--;
    }
    pair<int, int> front(){
        return ar[inicio];
    }
    int size(){
        return capacidad;
    }
}Cola;
 
void bfs(int x, int y){
    Cola.init();
    Cola.push({x,y});
    visitado[x][y] = Color;
    while(Cola.size()){
        x = Cola.front().first;
        y = Cola.front().second;
        Cola.pop();
        for(int i = 0; i < 4; i++){
            int X = x + ejex[i],
                Y = y + ejey[i];
            if(X > -1 && X < N && Y > -1 && Y < M && mapa[X][Y] != '#' && !visitado[X][Y])
                Cola.push({X, Y}),
                visitado[X][Y] = 1;
        }
    }
    Color++;
}
 
int main(){
 
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    cin>>N>>M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin>>mapa[i][j];
 
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(mapa[i][j] != '#')
                if(!visitado[i][j])
                    bfs(i, j);
    cout<<Color - 1;
}