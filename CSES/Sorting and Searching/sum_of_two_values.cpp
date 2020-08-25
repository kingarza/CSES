#include<bits/stdc++.h>
using namespace std;
int main(){
 
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    int N, x;
    cin>>N>>x;
    int ar[N];
    for(int i = 0; i < N; i++)
        cin>>ar[i];
 
    set<int>memo;
    map<int, int>pos;
    for(int i = 0; i < N; i++){
        int resta = x - ar[i];
        if(memo.count(ar[i])){
            cout<<pos[resta] + 1<<" "<<i + 1;
            return 0;
        }
        memo.insert(resta);
        pos[ar[i]] = i;
    }
    cout<<"IMPOSSIBLE";
}
