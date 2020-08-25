#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    ll n, p = 5, c = 0;
    cin>>n;
    while(n >= 1)
        c += n /= 5;
    cout<<c;
}