#include <iostream>
using namespace std;
int main() {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		int one = 0, two = 0; // one表示奇数个数，two表示偶数个数
		while(n--) {
			int cake;
			cin >> cake;
			if(cake == 1)
				continue;
			if(cake % 2 == 0)
				two++;
			else
				one++;
		}
		if(two % 2 == 0 && one % 2 == 1)
			cout << "Bob" << endl;
		else
			cout << "Alice" << endl;
	}
	return 0;
}
