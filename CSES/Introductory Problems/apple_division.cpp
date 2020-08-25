#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
ll bitMask(int N, ll ar[]){
    ll A, B, MinDif = INT_MAX;
    for(int i = 0; i < (1 << N); i++){
        A = 0, B = 0;
        for(int j = 0; j < N; j++)
            (i & (1 << j))? A += ar[j] : B += ar[j];
        MinDif = min(MinDif, abs(A - B));
    }
    return MinDif;                
}
 
int main(){
    int N;
    cin>>N;
    ll ar[N];
    for(int i = 0; i < N; i++)
        cin>>ar[i];
    cout<<bitMask(N, ar);
}