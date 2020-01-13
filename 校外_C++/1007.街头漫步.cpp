#include <set>
#include <iostream>
using namespace std;

int main() {
	int citis, events;
	while (cin >> citis >> events) {			//读入城市数和道路数
		set<int> s;    //记录已走过的城市
		s.insert(1);
		int total_distance = 0;
		for (int i = 0; i < events; i++) {     //对每个事件
			int command;
			cin >> command;
			if (command == 1) {
				int y, w;
				cin >> y >> w;
				s.insert(y);
				total_distance += w;
			}
			else
				printf("%d %d\n", s.size(), total_distance);
		}
	}

	return 0;
}