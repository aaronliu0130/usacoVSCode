/*
ID: aaronli2
TASK: breedflip
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout ("breedflip.out");
    ifstream fin ("breedflip.in");
    int n;
    fin>>n;
    string a,b;
    fin>>a>>b;
    bool streak(0);
    int ans(0);
    for(int i=0;i<n;i++){
        if(a[i]!=b[i])streak=1;
        else if(streak){
            streak=0;
            ++ans;
        }
    }fout<<ans<<endl;
    return 0;
}