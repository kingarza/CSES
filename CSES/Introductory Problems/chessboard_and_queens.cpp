#include<bits/stdc++.h>
#define MAX 8
using namespace std;
 
int C;
char mapa[MAX][MAX];
bool v[MAX][MAX];
 
bool esValido(int fila, int col){
    int i, j;
    for(i = 0; i < MAX; i++)
        if(v[i][col])
            return 0;
    for(i = 0; i < MAX; i++)
        if(v[fila][i])
            return 0;
    for(i = fila, j = col; i >= 0 && j >= 0; i--, j--)
        if(v[i][j])
            return 0;
    for(i = fila, j = col; i < MAX && j < MAX; i++, j++)
        if(v[i][j])
            return 0;
    for(i = fila, j = col; i < MAX && j >= 0; i++, j--)
        if(v[i][j])
            return 0;
    for(i = fila, j = col; i >= 0 && j < MAX; i--, j++)
        if(v[i][j])
            return 0;
    return 1;
}
 
void countWays(int x, int y, int k){
    if(!k){
        C++;
        return;
    }
    for(int fil = x; fil < MAX; fil++){
        for(int col = y; col < MAX; col++)
            if(mapa[fil][col] != '*'){
                if(esValido(fil, col)){
                    v[fil][col] = 1;
                    countWays(fil, col, k - 1);
                    v[fil][col] = 0;
                }
            }
        y = 0;
    }
}
 
int main(){
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            cin>>mapa[i][j];
    countWays(0, 0, 8);
    cout<<C;
}