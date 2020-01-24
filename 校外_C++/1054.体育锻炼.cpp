#include <bits/stdc++.h>
using namespace std;

int amount[41][100][100][100];  // amount[day][x][y][z]表示第day天能力值分为为x,y,z的方案数
const int prim = 1000000007;

int main() {
  amount[0][50][50][50] = 1;
  int n;
  cin >> n;
  for (int day = 0; day < n; day++) {
    for (int j = 0; j < 2; j++) {
      int a, b, c;
      cin >> a >> b >> c;
      for (int x = 1; x <= 99; x++)
        for (int y = 1; y <= 99; y++)
          for (int z = 1; z <= 99; z++)
            if (amount[day][x][y][z] > 0)
              if (a + x >= 1 && a + x <= 99)
                if (b + y >= 1 && b + y <= 99)
                  if (c + z >= 1 && c + z <= 99)
                    //动态规划
                    amount[day + 1][a + x][b + y][c + z] =
                        (amount[day + 1][a + x][b + y][c + z] + amount[day][x][y][z]) % prim;
    }
  }
  int sum = 0;
  for (int x = 1; x <= 99; x++)
    for (int y = 1; y <= 99; y++)
      for (int z = 1; z <= 99; z++)
        if (amount[n][x][y][z] > 0)
          sum = (sum + amount[n][x][y][z]) % prim;
  cout << sum;
  return 0;
}