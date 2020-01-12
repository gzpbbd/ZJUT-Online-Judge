#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct travel{   //保存旅行商路过 holo 身边时的信息
	int time, num, favorable;   //时间点，旅行商编号，好感度
	travel(int time, int num, int favorable) 
		: time(time), num(num), favorable(favorable) {}
};

bool comp(travel a, travel b) {  //时间早、好感度大的优先
	if (a.time != b.time)
		return a.time < b.time;
	else
		return a.favorable > b.favorable;
}

int main() {
	int t;
	while (cin >> t) {
		for (int i = 0; i < t; i++) { //1. 处理每组数据
			int holo_x, holo_y, limit;
			cin >> holo_x >> holo_y >> limit;
			vector<travel> res;       //用于保存路过holo身旁的旅行商的信息
			int travels;
			cin >> travels;
			for (int j = 0; j < travels; j++) { //1.1 处理每个旅行商
				int x, y, favorable;
				string route;
				cin >> x >> y >> favorable >> route;
				if (favorable < limit) //好感度不足，下一位
					continue;

				int num = j + 1, time = 0;               //旅行商起点
				if (x == holo_x && y == holo_y) {
					res.push_back(travel(time, num, favorable));
					continue; 
				}

				for (int k = 0; k < route.size(); k++) { //1.1.1 处理单个旅行商的路线
					if (route[k] == 'U')    
						x++;
					else if (route[k] == 'D')
						x--;
					else if (route[k] == 'L')
						y--;
					else if (route[k] == 'R')
						y++;

					time++;
					if (x == holo_x && y == holo_y) {
						res.push_back(travel(time, num, favorable));
						break;
					}
				}
			}

			sort(res.begin(), res.end(), comp); //排序并输出
			if (res.empty())
				cout << -1 << endl;
			else
				cout << res[0].num << endl;
		}
	}
	return 0;
}