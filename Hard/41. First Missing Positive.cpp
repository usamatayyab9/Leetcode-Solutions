/**
 * @file 41. First Missing Positive.cpp
 * @author Usama Tayyab (usamtayyab9@gmail.com)
 * @brief
 * Problem : https://leetcode.com/problems/first-missing-positive/description/
 * Statement :
 *  Given an unsorted integer array nums, return the smallest missing positive integer.
 *  You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space. 
 *  Example 1:
 *      Input: nums = [1,2,0]
 *      Output: 3
 *      Explanation: The numbers in the range [1,2] are all in the array.
 *  Example 2:
 *      Input: nums = [3,4,-1,1]
 *      Output: 2
 *      Explanation: 1 is in the array but 2 is missing.
 * Example 3:
 *      Input: nums = [7,8,9,11,12]
 *      Output: 1
 *      Explanation: The smallest positive integer 1 is missing.
 * Constraints:
 *      1 <= nums.length <= 105
 *      -231 <= nums[i] <= 231 - 1
 * 
 * @copyright Copyright (c) 2024
 */

//Uses extra space O(N)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        auto uset = unordered_set<int>{begin(nums), end(nums)};
        auto i    = 0;
        
        while (uset.find(++i) != end(uset)) { continue; }
        
        return i;
    }
};