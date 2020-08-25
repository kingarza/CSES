#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    int n;
    cin>>n;    
    if(n == 1){
        cout<<1;
        return 0;
    }
    if(n == 2 or n == 3){
        cout<<"NO SOLUTION";    
        return 0;
    }
    deque<int>sol;
    sol.push_back(3);
    sol.push_back(1);
    sol.push_back(4);
    sol.push_back(2);     
    for (int i = 5; i <= n; i++){        
        if(i - sol.back() == 1)        
            sol.push_front(i);
        else
            sol.push_back(i);
    }
    while (sol.size()){
        cout<<sol.front()<<" ";
        sol.pop_front();
    }
}