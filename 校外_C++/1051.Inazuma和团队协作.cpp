/**
 * @file e.cpp
 * @author huangchenping (huangchenpingbbd@163.com)
 * @brief
 * @version 1
 * @date 2020-01-24
 *
 * @copyright GNU GPLv3
 *
 */
#include <bits/stdc++.h>
using namespace std;

int get_punish(const vector<pair<int, int>> &record);
void DFS(int num, int x, int y, int z, int time);

int n;
int v[11][3], t[11][3];
//做题的记录，record[].first为选手号码，record[].second为该选手做题的耗时
vector<pair<int, int>> record;
int max_sum = 0, min_punish = 300 * 66;

int main() {
  int x, y, z;
  cin >> n >> x >> y >> z;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 3; j++)
      cin >> v[i][j] >> t[i][j];
  DFS(0, x, y, z, 300);
  cout << max_sum << " " << min_punish;
  return 0;
}

/**
 * @brief 根据记录中计算最小罚时
 *
 * @param record 做题的记录，record[].first为选手号码，record[].second为该选手做题的耗时
 * @return int 返回最小耗时
 */
int get_punish(const vector<pair<int, int>> &record) {
  vector<int> temp(record.size());
  for (int i = 0; i < record.size(); i++)
    temp[i] = record[i].second;
  sort(temp.begin(), temp.end());

  int punish = 0, last = 0;
  for (auto e : temp) {
    punish += e + last;
    last += e;
  }
  return punish;
}

/**
 * @brief 深度优先遍历
 *
 * @param num 当前题号，范围[0, n-1]
 * @param x 0号选手的剩余智商
 * @param y 1号选手的剩余智商
 * @param z 2号选手的剩余智商
 * @param time 剩余时间
 */
void DFS(int num, int x, int y, int z, int time) {
  if (x < 0 || y < 0 || z < 0 || time < 0) //剪枝
    return;
  if (num == n) { //边界
    if (record.size() > max_sum) {
      max_sum = record.size();
      min_punish = get_punish(record);
    } else if (record.size() == max_sum) {
      int punish = get_punish(record);
      if (punish < min_punish)
        min_punish = punish;
    }
    return;
  }
  //递归，对于每个题目，有四种选择：不做，选手0，选手1，选手2
  DFS(num + 1, x, y, z, time);               //--
  record.push_back(make_pair(0, t[num][0])); // 0
  DFS(num + 1, x - v[num][0], y, z, time - t[num][0]);
  record.pop_back();
  record.push_back(make_pair(1, t[num][1])); // 1
  DFS(num + 1, x, y - v[num][1], z, time - t[num][1]);
  record.pop_back();
  record.push_back(make_pair(2, t[num][2])); // 2
  DFS(num + 1, x, y, z - v[num][2], time - t[num][2]);
  record.pop_back();
}