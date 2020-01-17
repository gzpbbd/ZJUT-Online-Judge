#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> amount(101, 0); //amount[score]中记录分数为score的人数
		vector<int> student(n);     //原始学生分数的列表
		for(int i = 0; i < n; i++) {
			cin >> student[i];
			amount[student[i]]++;
		}
		int level[101]; //level[score]保存分数score对应的排名
		for(int score = 100, total = 0; score > 0; score--) { //total记录高于成绩score的人数
			if(amount[score] != 0) {
				level[score] = total + 1;
				total += amount[score];
			}
		}
		for(int i = 0; i < n; i++) {
			if(i != n - 1)
				cout << level[student[i]] << " ";
			else
				cout << level[student[i]] << endl;
		}
	}
	return 0;
}
