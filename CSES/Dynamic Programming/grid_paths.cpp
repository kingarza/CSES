#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
int main(){
 
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    int N;
    cin>>N;
 
    char mapa[N + 1][N + 1];
    ll     ar[N + 1][N + 1];
 
    memset(ar, 0, sizeof(ar));
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin>>mapa[i][j];
 
    if(mapa[1][1] != '*')
        ar[1][1] = 1; //la casilla origen...
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            if(mapa[i][j] != '*'){
                if(mapa[i - 1][j] != '*')
                    ar[i][j] = (ar[i][j] + ar[i - 1][j]) % MOD;
                if(mapa[i][j - 1] != '*')
                    ar[i][j] = (ar[i][j] + ar[i][j - 1]) % MOD;
            }
    cout<<ar[N][N] % MOD;
}