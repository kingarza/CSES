#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main(){
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
	int N;
	cin>>N;
	
	if(N % 4 != 0 && N % 4 != 3)
        cout<<"NO\n";
    else{
        int n = N;
        cout<<"YES\n";
        cout<<N / 2 <<"\n";
        if(N % 2 != 0) {
            n--;
            cout << N << " ";
        }
        for(int i = 1; i <= n / 4; i++)
            cout<<i<<" "<<n - i + 1<<" ";
        cout<<"\n"<<ceil(N / 2.0) <<"\n";
        for(int i = n / 4 + 1; i <= n / 2; i++)
            cout<<i<<" "<<n - i + 1<<" ";
            
    }
}