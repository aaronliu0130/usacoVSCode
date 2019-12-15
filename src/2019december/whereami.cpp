/*
ID: aaronli2
TASK: whereami
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
bool checkDupe(vector<string> &array){
    for(int i=0;i<array.size();i++){
        for(int j=i+1;j<array.size();j++){
            if(array[i]==array[j])return true;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout ("whereami.out");
    ifstream fin ("whereami.in");
    int n;
    fin>>n;
    vector<string> boxn;
    for(int i=0;i<n;i++){
        char c;
        fin>>c;
        string str(1,c);
        boxn.push_back(str);
    }
    int k(1);
    vector<string> temp(boxn);
    string str;
    while(k<n){
        if(checkDupe(boxn)){
            ++k;
            boxn.clear();
            for(int i=0;i<n;i+=k){
                str.clear();
                for(int j=0;j<k;j++){
                    str+=temp[j+i];
                }
                boxn.push_back(str);
            }
        }else break;
    }
    fout<<k+1;
    return 0;
}