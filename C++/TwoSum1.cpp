/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 
*/
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <utility>
// My Aproach  ( Brute force ) - O( n ^ 2)
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        
        std::vector<int> x ;
        for (int i = 0; i < nums.size(); i++){
            for (int j = 0; j < nums.size(); j++){
                if(i != j){
                    if(nums[i] + nums[j] == target){
                        x.push_back(i);
                        x.push_back(j);
                        return x;
                    }
                }
            }
        }
        return x;
    }
};


// Sorting Aproach O(nlogn)

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<std::pair<int,int>> temp;
        for(int i=0;i<nums.size();i++){
            temp.push_back({nums[i],i});
        }
        
        std::vector<int> ans;
        sort(temp.begin(), temp.end());
        int i=0, j=nums.size()-1;
        while(i<j){
            if(temp[i].first + temp[j].first == target){
                ans.push_back(temp[i].second);
                ans.push_back(temp[j].second);
                return ans;
            } else if(temp[i].first + temp[j].first < target){
                i++;
            } else{
                j--;
            }
        }
        return ans;
    }
};

// Hashmap O(n)

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        
        std::vector<int> x;
        std::unordered_map<int,int> seen;
        
        for(int i=0;i<nums.size();i++){
            if(seen.find(target - nums[i]) != seen.end()){
                x.push_back(i);
                x.push_back(seen[target - nums[i]]);
                return x;
            }
            else{
                seen.insert({nums[i], i});
            }
        }
        
        return x;
    }
};