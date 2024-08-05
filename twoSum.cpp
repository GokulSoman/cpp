/* Given an array of integers nums and an integer target, 
 * return indices of the two numbers such that they add up to target.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
vector<int> twoSum(vector<int>& nums, int target) {
    int front_index = 0, back_index = nums.size() - 1; 
    vector<int> indices {};
    std::unordered_map <int, int> index_map;

    for (int i=0; i<nums.size(); ++i){
        int complement = target - nums[i];
        if (index_map.contains(complement)){
            indices = {index_map[complement], i};
            return indices;
        } else {
            index_map[nums[i]] = i;
        }
    }
    // indices = {front_index, back_index};
    return indices;
}











