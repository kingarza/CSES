#include<bits/stdc++.h>
#define MAX 200005
using namespace std;
int main(){
 
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n, q;
    cin>>n>>q;
    int ar[MAX];
    for(int i = 0; i < n; i++)
        cin>>ar[i];
    int acum[MAX];
    acum[1] = ar[0];
    for(int i = 2; i <= n; i++)
        acum[i] = ar[i - 1],
        acum[i] ^= acum[i - 1];
    while (q--){
        int a, b;
        cin>>a>>b;
        cout<<(acum[b] ^ acum[a - 1])<<"\n";
    }
}