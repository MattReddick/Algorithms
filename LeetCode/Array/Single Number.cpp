/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

Follow up: Could you implement a solution with a linear runtime complexity and without using extra memory?

 

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
 

Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.
/*

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::unordered_map<int,int> storedValues;
        for(int i = 0; i < nums.size(); i++){
            if(storedValues.find(nums[i]) != storedValues.end()){
                storedValues.erase(storedValues.find(nums[i]));
            }else{
                storedValues.insert(std::pair<int, int>{nums[i], nums[i]});
            }
        }
        return storedValues.begin()->first;
    }
};
