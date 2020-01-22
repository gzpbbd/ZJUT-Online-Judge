#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int x = abs(x2 - x1);
    int y = abs(y2 - y1);
    if (x == 0 || y == 0)
      cout << "Seele" << endl;
    else if (x != y)
      cout << "Seele" << endl;
    else
      cout << "Bronya" << endl;
  }
  return 0;
}