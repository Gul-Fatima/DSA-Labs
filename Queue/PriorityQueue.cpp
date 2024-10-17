#include <iostream>
#include <queue>
using namespace std;
class 	GulFatima_Lab07 {
public:
	priority_queue<int> max_pq;
	priority_queue<int, vector<int>, greater<int>> min_pq;
	GulFatima_Lab07(){}
	void display_max() {
		if (max_pq.empty()) {
			cout << "Queue is empty" << endl;
		}
		//display max-pq
		cout << "Priority Queue(Max):\t";
		while (!max_pq.empty()) {
			cout << max_pq.top() << " ";
			max_pq.pop();
		}
		cout << endl;
	}
	void display_min() {
		if (min_pq.empty()) {
			cout << "Queue is empty" << endl;
		}
		//display min-pq
		cout << "Priority Queue(Min):\t";
		while (!min_pq.empty()) {
			cout << min_pq.top() << " ";
			min_pq.pop();
		}
		cout << endl;
	}
	void push_max(int val) {
		max_pq.push(val);
	}
	void push_min(int val) {
		min_pq.push(val);
	}
};
int main() {
	priority_queue<int, vector<int>, greater<int>> min_pq;
	GulFatima_Lab07 pq;	
	pq.push_max(2);
	pq.push_min	(5);
	pq.push_max(7);
	pq.push_max(6);
	pq.push_min(8);
	pq.push_max(7);
	pq.display_max();
	pq.display_min();
	return 0;
}


