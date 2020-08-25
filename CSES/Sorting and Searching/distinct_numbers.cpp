#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    ll N, x;
    set<ll>rep;
    cin>>N;
    while(N--)
        cin>>x,
        rep.insert(x);
    cout<<rep.size();
}