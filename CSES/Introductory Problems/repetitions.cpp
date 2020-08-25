#include <iostream>
using namespace std;
 
int main() {
    string cad;
    cin>>cad;
    int rep = 1, maxRep = 0;
    for(int i = 1; i < cad.size(); i++)
        if(cad[i] == cad[i - 1])
            rep++;
        else
            maxRep = max(maxRep, rep),
            rep = 1;
    cout<<max(maxRep, rep);
}
