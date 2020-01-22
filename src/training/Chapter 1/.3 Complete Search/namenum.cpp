#if 0
/*
ID: aaronli2
TASK: namenum
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
string getNum(const string dict)
{
    string res = "";
    for (auto d : dict)
    {
        if (d == 'Q' || d == 'Z')
            return "*";
        if (d < 'Q')
            res += (d - 'A') / 3 + '2';
        else
            res += (d - 'Q') / 3 + '7';
    }
    return res;
}
int main()
{
    ofstream fout("namenum.out");
    ifstream fin("namenum.in"), dict("dict.txt");
    string num; //Naming a string num is bugging me.
    fin >> num;
    string name;
    bool flag = 0;
    while (dict >> name)
        if (name.length() == num.length() && getNum(name) == num)
        {
            flag = 1;
            fout << name << endl;
        }
    if (!flag)
        fout << "NONE" << endl;
    return 0;
}
#endif