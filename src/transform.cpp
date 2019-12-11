#if 1
/*
ID: aaronli2
TASK: transform
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Square
{
public:
    Square(size_t s) : sz(s), contents(s) {}
    istream &read(istream &in)
    {
        for (auto i = 0; i < sz; ++i)
            in >> contents[i];
        return in;
    }
    size_t size() const
    {
        return sz;
    }
    static vector<string> transform(size_t operation, const vector<string> &contents)
    {
        auto sz = contents.size();
        vector<string> newContents(sz, string(sz, 0));
        auto getOp = [&newContents, &operation, &sz](int i, int j) -> decltype(newContents[0][0]) {
            switch (operation)
            {
            case 1:
                return newContents[j][sz - 1 - i];
            case 2:
                return newContents[sz - 1 - i][sz - 1 - j];
            case 3:
                return newContents[sz - 1 - j][i];
            case 4:
                return newContents[i][sz - 1 - j];
            }
            return newContents[0][0];
        };
        for (auto i = 0; i < sz; ++i)
            for (auto j = 0; j < sz; ++j)
                getOp(i, j) = contents[i][j];
        return newContents;
    }
    bool equal(const vector<string> &a) const
    {
        if (a.size() != sz)
            return 0;
        for (auto i = 0; i < sz; ++i)
            if (contents[i] != a[i])
                return 0;
        return 1;
    }
    bool equal(const Square &a) const
    {
        return a.equal(contents);
    }
    int find(const Square &target)
    {
        vector<string> tmp(sz);
        for (auto i = 1; i <= 4; ++i)
        {
            tmp = transform(i, contents);
            if (target.equal(tmp))
                return i;
        }
        for (auto i = 1; i <= 3; ++i)
            if (target.equal(transform(i, tmp)))
                return 5;
        if (equal(target))
            return 6;
        return 7;
    }

private:
    size_t sz;
    vector<string> contents;
};
istream &operator>>(istream &in, Square &contents)
{
    return contents.read(in);
}
int main()
{
    ofstream fout("transform.out");
    ifstream fin("transform.in");
    int s;
    fin >> s;
    Square map(s), target(s);
    fin >> map >> target;
    fout << map.find(target) << endl;
    return 0;
}
#endif
