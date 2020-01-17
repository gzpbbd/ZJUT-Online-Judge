#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	double pi = acos(-1);
	while(t--) {
		int r1, a1, r2, a2;
		cin >> r1 >> a1 >> r2 >> a2;
		//需要考虑r1<r2或a1<a2的情况，所以重叠部分的半径和角度均为最小值
		double res = pi / 360 * (pow(r1, 2) * a1 - pow(min(r1, r2), 2) * min(a1, a2));
		printf("%.2f\n", res);
	}
	return 0;
}
