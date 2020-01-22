/*
ID: aaronli2
TASK: word
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout ("word.out");
    ifstream fin ("word.in");
    int n,k;
    fin>>n>>k;
    vector<string> essay;
    string tmp;
    for(int i=0;i<n;i++){
        fin>>tmp;
        essay.push_back(tmp);
    }
    int i(0),temp(0);
    do{
        if((temp+=essay[i].length())<=k){
            if(i&&temp-essay[i].length())fout<<" ";
            fout<<essay[i];
            if(i==(essay.size()-1))break;
        }else{
            fout<<"\n";
            temp=0+essay[i].length();
            fout<<essay[i];
            if(i==(essay.size()-1))break;
        }
    }while(++i);
    return 0;
}