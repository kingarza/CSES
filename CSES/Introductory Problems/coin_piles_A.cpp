#include<bits/stdc++.h>
using namespace std;
 
bool binaria(int limInferior, int inicio, int fin, int objetivo){
    while (inicio <= fin){
        int mitad = (inicio + fin) / 2;        
        if(limInferior + 3 * mitad == objetivo){
            return 1;
        }
        if(abs(limInferior + 3 * mitad  - objetivo) <= 2)
            return 0;
        if(limInferior + 3 * mitad > objetivo)
            fin = mitad - 1;
        else
            inicio = mitad  + 1;
    }
}
 
int main(){
 
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t;
    cin>>t;
    while (t--){
        int a, b;
        cin>>a>>b;
        int A = min(a, b);
        int B = max(a, b);
        int limSuperior = A * 2;
        int limInferior = limSuperior - 3 * floor((A - 3 - limSuperior) / -3);
        if(B > limSuperior || B < limInferior)
            cout<<"NO\n";
        else{ //esta dentro del rango, verificamos...
            if(binaria(limInferior, 0, (limSuperior - limInferior) / 3, B))
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
}