#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n;
    cin>>n;
    vector<pair<int, int> >ar(n);
    for(int i = 0; i < n; i++)
        cin>>ar[i].second>>ar[i].first;
    sort(ar.begin(), ar.end());
    for(int i = 0; i < n; i++)
        swap(ar[i].first, ar[i].second);
    
    int c = 0, //contador de peliculas
        Max = 0;
    pair<int, int>rango;
    for(auto i : ar){        
        if(c == 0)
            rango = i, c = 1;
        else{
            //checamos que el comienzo de esta pelicula sea mayor al final del rango
            if(rango.second <= i.first)
                rango = i, c++;
        }
        Max = max(Max, c);
    }
    cout<<Max;
}