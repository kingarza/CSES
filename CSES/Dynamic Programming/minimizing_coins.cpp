#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;
 
int memo[MAX];
 
int main(){
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N, K;
    cin>>N>>K;
    int coins[N];
    for(int i = 0; i < N; i++)
        cin>>coins[i];
        
    for(int i = 0; i <= K; i++)
        memo[i] = MAX;
    memo[0] = 0;
        
    for(int d = 1; d <= K; d++) //dinero
        for(int c = 0; c < N; c++) //monedas
            if(d - coins[c] >= 0){
                memo[d] = min(memo[d], memo[d - coins[c]] + 1);
            }
    
    cout<<(memo[K] == MAX? -1 : memo[K])<<"\n";
}