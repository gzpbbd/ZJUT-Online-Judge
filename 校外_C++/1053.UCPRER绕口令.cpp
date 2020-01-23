#include <bits/stdc++.h>  //该头文件包含了常用的一些头文件
using namespace std;

int main() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  map<pair<char, char>, int> appear;  //统计字符对(a,b)已经出现的次数
  long long sum = 0;                  // int型范围不够
  for (int i = 0; i < s1.size(); i++) {
    //如果此时为(a,b)，之前为(b,a)，则绕口系数加1
    if (s1[i] != s2[i]) {
      sum += appear[make_pair(s2[i], s1[i])];
      appear[make_pair(s1[i], s2[i])]++;
    }
  }
  cout << sum << endl;
  return 0;
}