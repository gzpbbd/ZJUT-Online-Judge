#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <functional>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) { //对每组数据
		int n;
		cin >> n;
		vector<priority_queue<int, vector<int>, greater<int>>> road(n-1); //设置优先队列每次弹出最小值
		for (int j = 0; j < road.size(); j++) { //对相邻城市间的道路
			int amount;
			cin >> amount;
			for (int k = 0; k < amount; k++) { //对每条道路
				int length;
				cin >> length;
				road[j].push(length);

			}
		}
		
		int total_length = 0;
		for (int j = 0; j < road.size(); j++) { //每两个城市间，选择两条最短路径
			total_length += road[j].top();
			road[j].pop();
			total_length += road[j].top();
		}
		cout << total_length << endl;
	}	
}