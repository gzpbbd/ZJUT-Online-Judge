#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct node {
	int time, weight;
};

int main() {
	int n, max;
	cin >> n >> max;
	vector<node> v(n);
	for (int i = 0; i < v.size(); i++) //保存雪花信息
		cin >> v[i].time >> v[i].weight;

	int time = 0, index = 0, weight = 0;
	while (index < v.size()) {        //对每朵雪花
		if (v[index].time == time) {  //雪花掉落的时候
			weight += v[index++].weight;
			if (weight > max)
				weight = 0;
			cout << weight << endl;
		}

		time++;                       //时间流逝
		if (weight > 0)
			weight--;
	}	
	return 0;
}