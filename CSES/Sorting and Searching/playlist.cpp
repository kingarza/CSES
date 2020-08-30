#include<bits/stdc++.h>
using namespace std;

int max(int a, int b){
    if(a > b)
        return a;
    return b;
}

int main(){
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n;
    cin>>n;
    vector<int>ar(n);
    for(int i = 0; i < n; i++)   
        cin>>ar[i];

    int maxSize = 0;
    deque<int>subSequence;
    set<int>v;
    for(auto i : ar){
        if(v.count(i)){ //este elemento esta en la lista, sacamos todos los elementos hasta encontrarlo
            while(subSequence.size() && *subSequence.begin() != i){
                v.erase(*subSequence.begin());
                subSequence.pop_front(); //borramos sus anteriores                
            }
            if(subSequence.size()){
                v.erase(*subSequence.begin());
                subSequence.pop_front();//borramos el elemento                
            }
        }
        v.insert(i);
        subSequence.push_back(i);
        maxSize = max(maxSize, subSequence.size());
    }   
    cout<<maxSize;
}