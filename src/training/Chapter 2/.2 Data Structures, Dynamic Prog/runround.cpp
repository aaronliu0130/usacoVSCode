/* 
ID: aaronli2
PROG: runround
LANG: C++
*/

#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;

bool runround(char x[], int nd)
{
  int i = 0;
  bool visited[10];
  bool digits[10];
  for (int j = 0; j < nd; j++)
    visited[j] = 0;
  for (int j = 0; j < 10; j++)
    digits[j] = 0;
  for (int j = 0; j < nd; j++)
  {
    visited[i] = 1;
    int k = (i + x[i] - '0') % nd;
    digits[x[i] - '0'] = 1;
    if (j == nd - 1)
    {
      if (k)
        return 0;
    }
    else if (visited[k])
    {
      return 0;
    }
    else if (digits[x[k] - '0'])
    {
      return 0;
    }
    i = k;
  }
  for (int j = 0; j < nd; j++)
  {
    if (!visited[j])
      return 0;
  }
  return 1;
}

int main()
{
  ofstream fout("runround.out");
  ifstream fin("runround.in");
  int S;
  fin >> S;

  char num[10];
  for (int i = S + 1; i < 100000000; i++)
  {
    int len = sprintf(num, "%d", i);
    if (runround(num, len))
    {
      fout << num << '\n';
      break;
    }
  }

  return 0;
}