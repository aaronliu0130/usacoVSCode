/*
ID: aaronli2
TASK: zerosum
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define cout(n) fout << n
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ofstream fout("zerosum.out");
  ifstream cin("zerosum.in");
  int n;
  cin >> n;
  if (n == 3)
  {
    cout("1+2-3\n");
  }
  if (n == 4)
  {
    cout("1-2-3+4\n");
  }
  if (n == 5)
  {
    cout("1 2-3-4-5\n");
  }
  if (n == 6)
  {
    cout("1 2+3-4-5-6\n");
  }
  if (n == 7)
  {
    cout("1+2-3+4-5-6+7\n");
    cout("1+2-3-4+5+6-7\n");
    cout("1-2 3+4+5+6+7\n");
    cout("1-2 3-4 5+6 7\n");
    cout("1-2+3+4-5+6-7\n");
    cout("1-2-3-4-5+6+7\n");
  }
  if (n == 8)
  {
    cout("1 2-3 4-5 6+7 8\n");
    cout("1+2 3-4 5+6+7+8\n");
    cout("1+2+3+4-5-6-7+8\n");
    cout("1+2+3-4+5-6+7-8\n");
    cout("1+2-3+4+5+6-7-8\n");
    cout("1+2-3-4-5-6+7+8\n");
    cout("1-2 3-4+5+6+7+8\n");
    cout("1-2+3-4-5+6-7+8\n");
    cout("1-2-3+4+5-6-7+8\n");
    cout("1-2-3+4-5+6+7-8\n");
  }
  if (n == 9)
  {
    cout("1 2+3 4-5 6-7+8+9\n");
    cout("1 2+3+4-5-6-7+8-9\n");
    cout("1 2+3-4 5+6+7+8+9\n");
    cout("1 2+3-4+5-6+7-8-9\n");
    cout("1 2-3+4+5 6-7 8+9\n");
    cout("1 2-3+4+5+6-7-8-9\n");
    cout("1 2-3-4-5+6-7-8+9\n");
    cout("1 2-3-4-5-6+7+8-9\n");
    cout("1+2-3 4-5 6+7 8+9\n");
    cout("1-2 3-4-5 6-7+8 9\n");
    cout("1-2-3 4+5+6+7+8+9\n");
  }
  return 0;
}