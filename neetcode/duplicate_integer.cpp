#include <iostream>
#include <algorithm> // sort header file
#include <vector>
#include <unordered_set>

// Given an integer array nums, return true if any value appears more than once in the array, 
// otherwise return false.

bool check_duplicate_present(std::vector <int> num_array){
	// The function with a time complexity of O(nlogn), as sorting is required
	// But the space complexity is O(1)
	std::sort(num_array.begin(), num_array.end());
	std::cout << "Sorted array" << std::endl;
	bool check_result = false;
	if (num_array.size() >= 2){
		for (auto it = num_array.begin(); it != (num_array.end()-1); ++it){
			std::cout << *it << " ";
			if (*it == *(it+1)){
				check_result = true;
			}
		}
		std::cout << std::endl;
	}
	return check_result;
}


bool check_duplicate_present2(std::vector <int> num_array){
	// The funciton with time complexity of O(n) as sorting is not required
	// But the space complexity increases to O(n)
	
	std::unordered_set<int> hash_set;
	bool check_result = false;
	if (num_array.size() >= 2){
		for (auto it = num_array.begin(); it != (num_array.end()); ++it){
			std::cout << *it << " ";
			if (hash_set.find(*it) != hash_set.end()) {
				check_result = true;
				// return check_result;
			}
			else {
				hash_set.insert(*it);
		
			}
		}
		std::cout << std::endl;
	}
	return check_result;

}
int main(){
	std::vector <int> nums {1, 8, 6, 2,3,4,5, 8};
	bool result = check_duplicate_present2(nums);
	std::cout << "Thr original array" << std::endl;
	for (auto it = nums.begin(); it != nums.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "The array contains duplicates: " << result << std::endl; 
	return 0;
}
