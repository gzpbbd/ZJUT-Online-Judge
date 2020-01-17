#include <iostream>
#include <string>
#include <vector>
using namespace std;

//判断容器中以low,high为边界，以2为间隔的序列是否为回文
bool issame(vector<int> v, int low, int high) {
	for (; low < high; low += 2, high -= 2) {
		if (v[low] != v[high])
			return false;
	}
	return true;
}

bool islucky(int x, int length) {
	vector<int> binary(length, 0);
	int index = 0;
	while (x > 0) { //转二进制
		binary[index++] = x % 2;
		x /= 2;
	}
	int low1 = 0, high1 = ((length - 1) % 2 == 0) ? (length - 1) : (length - 2); //上下边界
	int low2 = 1, high2 = ((length - 1) % 2 == 1) ? (length - 1) : (length - 2);
	return issame(binary, low1, high1) || issame(binary, low2, high2);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string str;
		int length;
		cin >> length >> str;
		int x = stoi(str, 0, 2);
		int total = 0;
		for (int i = 0; i < x; i++) {
			if (islucky(i, length))
				total++;
		}
		cout << total << endl;
	}
	return 0;
}
