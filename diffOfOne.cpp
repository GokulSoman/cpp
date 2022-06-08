#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool diff_of_one(vector <int> &A){
	int temp = -1;
	
	cout << "Input List"<< endl;
	for (int x : A){
		cout << x << " ";
	}
	cout << endl << endl;

	sort(A.begin(), A.end());
	
	cout << "After Sorting" << endl;
	for (int x: A){
		cout << x << " ";
	}
	cout << endl << endl;

	if (A.size() >= 2){
		temp = A[0];
		for (int i=1; i < A.size(); ++i){
			if ((A[i] - temp) == 1){
				return true;
			}	
			temp = A[i];

		}
	}
	return false;
}

int main(){
	bool result1, result2, result3;
	vector <int> input1 {3,8,33,7,93,17,82,92}, input2 {}, input3 {1,54,23,83,56};

	result1 = diff_of_one(input1);
	cout << "Result : " << result1 << endl;
	
	result2 = diff_of_one(input2);
	cout << "Result : "<< result2 << endl;
	result3 = diff_of_one(input3);
	cout << "Result 3 : " << result3 << endl;
	return 0;
}
