#include<bits/stdc++.h>
#define MAX 100
#define MOD 100
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    int N, a, b;
    cin>>N;
 
    while(N--) {
        cin>>a>>b;
 
        if(a<b)
            a += b, b = a-b, a -= b;
 
        if((a+b)%3 != 0 || a > 2*b)
            cout<<"NO\n";
        else cout<<"YES\n";
    }
 
    return 0;
}