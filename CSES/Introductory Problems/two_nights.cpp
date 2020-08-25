#include <iostream>
#define ll unsigned long long
#define MAX 100
using namespace std;
 
ll N;
 
int main() {
	
	cin>>N;
	ll M = N;
	ll quatre[] = {0, 0, 6, 28, 96};
    for(ll N = 1; N <= M; N++)
        if(N <= 4)
            cout<<quatre[N]<<"\n";
        else
            cout<<(N*N * (N*N - 1) /2) - (2*4 + 3*8 + 4*4*(N-4+1) + 6*4*(N-4) + 8*(N-4)*(N-4))/2<<"\n";
 
}