/* Given an array of integers nums and an integer target, 
 * return indices of the two numbers such that they add up to target.*/

#include <iostream>
#include <vector>
#include <algorithm>

vector<int> twoSum(vector<int>& nums, int target) {
        int front_index = 0, back_index = nums.size() - 1; 
        vector<int> indices;
        // for (int i=0; i < nums.size(); ++i){
        //     indices.push_back(i);
        // }
        // sort(nums.begin(), nums.end());
        while (nums.size() > 2){
            if (nums.front() + nums.back() != target ){
                if (nums.front() < nums.back()){
                    nums.pop_back();
                    back_index -= 1;
                } else {
                    nums.erase(nums.begin());
                    front_index += 1;
                }
            } else {
                break;
            }
        }
        indices = {front_index, back_index};
        return indices;
        
    }












