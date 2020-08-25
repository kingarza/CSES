#include<bits/stdc++.h>
using namespace std;
 
int main(){
    
    int N;
    cin>>N;
    int memo[N + 1];
    
    memo[0] = 0;
    for(int i = 1; i <= 9; i++)
        memo[i] = 1;
        
    for(int i = 10; i <= N; i++){
        int x = i;
        int Min = INT_MAX;
        while(x){
            if(i - x % 10 != i)
                Min = min(Min, memo[i - x % 10]);
            x /= 10;
        }
        memo[i] = Min + 1;
    }
    cout<<memo[N];
}