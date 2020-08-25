#include <iostream>
using namespace std;
 
bool visitado[2 * 100000 + 1];
 
int main() {
	int N;
	cin>>N;
	for(int i = 0, x; i < N - 1; i++)
	    cin>>x,
	    visitado[x] = 1;
	for(int i = 1; i <= N; i++)
	    if(!visitado[i]){
	        cout<<i;
	        break;
	    }
}
