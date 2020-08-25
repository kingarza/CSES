#include <bits/stdc++.h>
#define ll unsigned long long
#define MAX 1000001
#define MOD 1000000007
using namespace std;
 
ll memo[MAX];
 
int main(){
    ll N;
    cin>>N;
    N++;
    memo[1] = 1;
    for(int n = 2; n <= N; n++)
        for(int x = 1; x <= 6; x++)
            if(n - x >= 0)
                memo[n] += memo[n - x] % MOD;
    cout<<memo[N] % MOD;
}