#include <set>
#include <iostream>
#include <vector>
using namespace std;

struct student {
	int start, end, time;
	student() :start(0), end(0), time(0) {}
};

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) { //对每组数据
		int n;
		cin >> n;
		vector<student> students(n);
		for (int j = 0; j < n; j++) //录入学生信息
			cin >> students[j].start >> students[j].end;

		int index = 0, time = 1;
		while (index < students.size()) {
			if (students[index].start <= time && students[index].end >= time) { //有人排队且该同学未离队
				students[index++].time = time++;
			}
			else if (students[index].end < time) {                        //该同学离队
				students[index++].time = 0;
			}
			else {                                                       //students[index].start < time 无人排队
				time++;
			}
		}

		for (int j = 0; j < students.size(); j++) {
			cout << students[j].time;
			if (j != students.size() - 1)
				cout << " ";
			else
				cout << endl;
		}
	}
	return 0;
}