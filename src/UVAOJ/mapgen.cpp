#include<iostream>
#include<string>
using namespace std;
int main(){
    char temp;
    cout<<"std::map<string, string> words {\n";
    while(cin>>temp){
        cout<<"{\"";
        if(temp=='—'){
            cin>>temp;
            cout<<"\",\"";
            continue;
        }cout<<temp;
        cout<<"\"},\n";
    }
    cout<<"};";
    return 0;
}