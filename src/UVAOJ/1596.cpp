#include <stdio.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
#include <ctype.h>
using namespace std;
map<string, int> DSIZE;
map<string, map<int, int>> DR;
int testBug;
void declare(char exp[])
{
    string name = "";
    int size = 0, i;
    for (i = 0; exp[i] != '['; i++)
        name += exp[i];
    for (i++; exp[i] != ']'; i++)
        size = size * 10 + exp[i] - '0';
    DSIZE[name] = size;
    DR[name].clear();
}
int getValue(char exp[])
{
    if (isdigit(exp[0]))
    {
        int value = 0;
        for (int i = 0; isdigit(exp[i]); i++)
            value = value * 10 + exp[i] - '0';
        return value;
    }
    string name = "";
    int i;
    for (i = 0; exp[i] != '['; i++)
        name += exp[i];
    int index = getValue(exp + i + 1);
    if (DSIZE.count(name) == 0 || index >= DSIZE[name] || DR[name].count(index) == 0)
    {
        testBug = 1;
        return 0;
    }
    return DR[name][index];
}
void assign(char exp[])
{
    string name = "";
    int i;
    for (i = 0; exp[i] != '['; i++)
        name += exp[i];
    int index = getValue(exp + i + 1);
    for (i = 0; exp[i] != '='; i++)
        ;
    int value = getValue(exp + i + 1);
    if (testBug)
        return;
    if (DSIZE.count(name) == 0 || index >= DSIZE[name])
    {
        testBug = 1;
        return;
    }
    DR[name][index] = value;
}
int main()
{
    char c;
    while ((c = getchar()) != '.')
    {
        ungetc(c, stdin);
        DSIZE.clear();
        DR.clear();
        char exp[32767];
        int bugLine = 0, lines = 0;
        testBug = 0;
        while (scanf("%s",exp) && exp[0] != '.')
        {
            lines++;
            bool flag(0);
            for (int i = 0; exp[i]; i++)
                flag |= exp[i] == '=';
            if (!flag)
                declare(exp);
            else
                assign(exp);
            if (testBug && bugLine == 0)
                bugLine = lines;
        }
        printf("%d\n", bugLine);
    }
    return 0;
}