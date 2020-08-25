#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main(){
 
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    int N, K, c = 0;
    cin>>N>>K;
    ull ar[N];
 
    for(int i = 0; i < N; i++)
        cin>>ar[i];
 
    ull suma = 0;
    set<ull>sumas;
    for(int i = 0; i < N;  i++){
 
        suma += ar[i];
        sumas.insert(suma);
 
        if(suma == K)
            c++;
        else if(suma > K)
            if(sumas.count(suma - K))
                c++;
    }
    cout<<c;
}