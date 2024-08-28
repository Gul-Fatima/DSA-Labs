#include <iostream>
using namespace std;

void main() {
	// Size of main-array:
	int arr_size;
	cout << "Size of main-array: ";
	cin >> arr_size;

	//Declaring variables:
	int sb_arr_size[4];

	// Declaring main array of size : arr_size;
	int** arr = new int*[arr_size];

	for (int i = 0; i < arr_size; i++)
	{
		// Inputting size of sub-array[i] :
		cout << "Row " << i+1 << " size : " ;
		cin >> sb_arr_size[i];

		//Declaring sub-array[i] of sb_arr_size:
		arr[i] = new int[sb_arr_size[i]];
	}

	////Inputting elements for sub-arrays:
	//for (int i = 0; i < arr_size; i++)
	//{
	//	for (int j = 0; j < sb_arr_size[i]; j++)
	//	{

	//	}
	//}



}
