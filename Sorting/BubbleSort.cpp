#include <iostream>
using namespace std;
int sze = 10;
class bubbleSort {
	int* arr = new int[sze];
public:
	bubbleSort() {
		for (int i = 0; i < sze; i++)
		{
			arr[i] = 0;
		}
	}
	//input
	void input() {
		cout << "Enter elements for array:" << endl;
		for (int i = 0; i < sze; i++)
		{
			cout << "arr[" << i << "]: ";
			cin >> arr[i];
		}
	}
	//sort
	void sort() {
		for (int i = 0; i < sze - 1; i++)
		{
			bool flag = true;
			for (int j = 0; j < sze - 1; j++)
			{
				if (arr[j] > arr[j + 1]) {
					swap(arr[j], arr[j + 1]);
				}
			}
			if (!flag) {
				break;
			}
		}
	}
	//print
	void print() {
		for (int i = 0; i < sze - 1; i++)
		{
			cout << arr[i] << " ";
		}
	}
};

int main() {
	//int arr[5] = { 7,8,3,4,5 };
	bubbleSort obj;
	obj.input();
	obj.sort();
	obj.print();
}
