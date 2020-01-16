#include <set>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

class memory {
private:
	queue<int> que; //内存队列
	set<int> data; //内存中数据的集合
	int time, max_size;
public:
	memory(int max_size): max_size(max_size), time(0) {}
	void load(int value) { //如果 value 未在内存中，则删除数据，压入新数据
		if(data.find(value) == data.end()) {
			if(data.size() >= max_size) {
				data.erase(que.front());
				que.pop();
			}
			que.push(value);
			data.insert(value);
			time++;
		}
	}
	int get_time() {
		return time;
	}
};

int main() {
	int t;
	cin >> t;
	while(t--) {
		int step, max_size;
		cin >> step >> max_size;
		memory mem(max_size);
		while(step--) {
			int data;
			cin >> data;
			//如果用 list 保存数据，用find函数判断内存中是否有数据的拷贝，
			//则会超时，本人猜想是find函数太耗时，此处用set保存数据，判断时会更快一些
			mem.load(data);
		}
		cout << mem.get_time() << endl;
	}
	return 0;
}
