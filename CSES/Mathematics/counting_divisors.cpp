#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;
 
bool sieve[MAX];
vector<int>primos;
 
void generateSieve(int N){
    for(int i = 2; i <= N; i++)
        if(!sieve[i]){
            for(int j = i + i; j <= N; j += i)
                sieve[j] = 1;
            primos.push_back(i);
        }
}
 
int numDivisores(int x){
    int total = 1;
    for(int i = 0; primos[i] <= sqrt(x); i++){
        int p = 1;
        while(x % primos[i] == 0)
            x /= primos[i], p++;
        total *= p;
    }
    if(x > 1) //es otro numero primo
        total *= 2;
    return total;
}
 
int main(){
    int N;
    cin>>N;
    generateSieve(N);
    int x;
    while(N--)
        cin>>x,
        cout<<numDivisores(x)<<"\n";
 
}
