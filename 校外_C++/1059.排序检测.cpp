#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    int left = 1, right = n;
    while (left < right && v[left] < v[left + 1]) left++;  //从左端找逆序边界
    if (left == right) {
      printf("YES\n1 1\n");
      continue;
    }
    while (left < right && v[right] > v[right - 1]) right--;  //从右端找逆序边界
    reverse(v.begin() + left, v.begin() + right + 1);
    //对边界内元素逆序后，判断整个序列是否有序
    if (is_sorted(v.begin() + left, v.begin() + right + 1))
      if (left == 1 || v[left] > v[left - 1])
        if (right == n || v[right] < v[right + 1]) {
          printf("YES\n%d %d\n", left, right);
          continue;
        }
    printf("NO\n");
  }
  return 0;
}