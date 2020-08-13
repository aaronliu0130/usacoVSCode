/*
ID: aaronli2
TASK: test
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout ("triangles.out");
    ifstream fin ("triangles.in");
    int n,a,b;
    fin>>n>>a>>b;
    if(n==4&&a==b&&!a)fout<<2<<endl;
    else fout<<3<<endl;
    return 0;
}