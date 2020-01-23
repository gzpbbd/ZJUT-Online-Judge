#include <iostream>
#include <list>
#include <vector>
using namespace std;
main() {
  int t;
  cin >> t;
  while (t--) {
    //填入数据
    int n;
    cin >> n;
    list<char> str;
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      str.push_back(c);
    }
    //寻找连续的b
    vector<list<char>::iterator> place;
    char pre = 'a';
    for (auto it = str.begin(); it != str.end(); pre = *it, it++) {
      if (*it == 'b' && pre == 'b')
        place.push_back(it);
    }
    //在连续的b间插入括号，左半部分插入{，右边部分插入}
    int half = place.size() % 2 == 0 ? place.size() / 2 : place.size() / 2 + 1;
    for (int i = 0; i < place.size(); i++) {
      if (i < half)
        str.insert(place[i], '{');
      else
        str.insert(place[i], '}');
    }
    if (place.size() % 2 == 1)
      str.push_back('}');
    //输出
    for (auto c : str)
      cout << c;
    cout << endl;
  }
  return 0;
}