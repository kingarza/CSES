#include<bits/stdc++.h>
using namespace std;
int main(){
 
    map<char, int>rep;
    string cad;
    cin>>cad;
    for(int i = 0; i < cad.size(); i++)
        rep[cad[i]]++;
 
    string sol = "";
    string impar = "";
    for(auto i : rep){
        if(i.second % 2 == 0){
            for(int j = 0; j < i.second / 2; j++)
                sol += i.first;
            continue;
        }
        if(!impar.size())
            for(int j = 0; j < i.second; j++)
                impar += i.first;
        else{
            cout<<"NO SOLUTION";
            return 0;
        }
    }
    cout<<sol<<impar;
    reverse(sol.begin(), sol.end());
    cout<<sol;
}