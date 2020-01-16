#include <iostream>
#include <string>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		s += s.substr(0, 3); //手链为环形，那么将开始的三个链接到末尾，组成环
		int i;
		for(i = 0; i < s.size() - 1 && s[i] != s[i + 1]; i++); //判断是否两两不同
		if(i < s.size() - 1) {
			cout << "cool" << endl;
			continue;
		}

		//如果相邻三个均不同，那么可以证明手链以三为周期
		if(s[0] == s[2]) {
			cout << "cooler" << endl;
			continue;
		}

		for(i = 0; i < s.size() - 3 && s[i] == s[i + 3]; i++);
		if(i < s.size() - 3)
			cout << "cooler" << endl;
		else
			cout << "coolest" << endl;
	}
	return 0;
}
