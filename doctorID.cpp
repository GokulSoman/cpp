#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int multiHospitals(vector <vector <int>> &A){
	cout << "Input List" << endl;
	for (vector <int> hospitals : A){
		for (int id : hospitals){
			cout << id << " ";
		}
		cout << endl;
	}
	cout << "-------------------------------------"<< endl;


	int count = 0, curr_id = 0;
	vector <int> unique_id, day_list, counted_list;
	vector <vector <int>> row_indices;
	vector <int>::iterator it, ip,ir;
	

	for (int m=0; m < A[0].size(); ++m){
		day_list = {};
		for (int n = 0; n < A.size(); ++n){
			curr_id = A[n][m];
			day_list.push_back(curr_id);
			it = find(unique_id.begin(), unique_id.end(), 
					curr_id);
			ip = find(counted_list.begin(), counted_list.end(),
					curr_id);
			// ID is already in unique IDs list
			if (it != unique_id.end()){
				// Check if the id is in the same column as found element 
				int id_index = it - unique_id.begin();
				ir = find(row_indices[id_index].begin(), row_indices[id_index].end(), n);
				if (ir == row_indices[id_index].end()){
					// ID is not in the already counted list
					if (ip == counted_list.end()){
						counted_list.push_back(curr_id);
						count += 1;
					}
				}
				else {
					row_indices[id_index].push_back(n);
				}
			}
			else {
				unique_id.push_back(curr_id);
				vector<int> row_id {n};
				row_indices.push_back(row_id);
			}
		}
	}	
	
	cout << "------------------" << endl;
        cout << "Unique IDs " << endl;
        for (int x: unique_id){
        	cout << x << " ";
	}
	cout << endl;	

	return count;
}

int main(){
	vector <vector <int>> id_list {
		{3,1,4,1},
		{1,3,2,5},
		{1,5,4,3},
		{3,2,1,4}
	};
	int result;
	result = multiHospitals(id_list);
	cout << "Answer : " << result << endl;
	
	vector <vector <int>> id_list2 {
                {9,1,1,8},
                {3,3,7,5},
                {6,6,4,4},
                {5,5,1,2}
        };
        int result2;
        result2 = multiHospitals(id_list2);
        cout << "Answer : " << result2 << endl;

	
	
	return 0;
}
