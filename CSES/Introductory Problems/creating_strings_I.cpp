#include <bits/stdc++.h>
using namespace std;
 
int F(int x){
    return x <= 1? 1 : x * F(x - 1);
}
 
int total(string cad){
    int c = F(cad.size());
    map<char, int>rep;
    for(int i = 0; i < cad.size(); i++)
        rep[cad[i]]++;
    for(auto i : rep)
        c /= F(i.second);
    return c;
}
 
int main() {
    string cad;
    cin>>cad;
    cout<<total(cad)<<"\n";
    sort(cad.begin(), cad.end());
    do{
        cout<<cad<<"\n";
    }while(next_permutation(cad.begin(), cad.end()));
    
}