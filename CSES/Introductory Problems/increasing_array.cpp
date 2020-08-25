#include<bits/stdc++.h>
using namespace std;
 
int main() {
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N;
    cin>>N;
    long long ar[N], c = 0;
    for(int i = 0; i < N; i++)
        cin>>ar[i];
    for(int i = 1; i < N; i++)
        if(ar[i] < ar[i - 1])
            c += ar[i - 1] - ar[i],
            ar[i] = ar[i - 1];
    cout<<c;
}
