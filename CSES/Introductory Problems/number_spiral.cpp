#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
 
int main() {
    
    int t;
    cin>>t;
    
    while(t--){
        
        ll x, y;
        cin>>x>>y;
        ll maxSquare = max(x, y) * (max(x, y) - 1) + 1;
        
        if(x < y){
            if(y % 2 != 0)
                maxSquare += y - x;
            else
                maxSquare -= y - x;
        }
        else if(x > y){
            if(x % 2 != 0)
                maxSquare -= x - y;
            else
                maxSquare += x - y;
        }
        
        cout<<maxSquare<<"\n";
            
    }
}