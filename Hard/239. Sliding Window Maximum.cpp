/**
 * @file 239. Sliding Window Maximum.cpp
 * @author Usama Tayyab (usamatayyab9@gmail.com)
 * @brief 
 * 
 * Problem: https://leetcode.com/problems/sliding-window-maximum/description/
 * Statement : 
 * You are given an array of integers nums, there is a sliding window of size k which is moving
 * from the very left of the array to the very right. You can only see the k numbers in the window.
 * Each time the sliding window moves right by one position.
 * 
 * Return the max sliding window.
 * 
 * Example 1:
 *  Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
 *  Output: [3,3,5,5,6,7]
 *  Explanation: 
 *  Window position                Max
 *  ---------------               -----
 *  [1  3  -1] -3  5  3  6  7      3
 *  1 [3  -1  -3] 5  3  6  7       3
 *  1  3 [-1  -3  5] 3  6  7       5
 *  1  3  -1 [-3  5  3] 6  7       5
 *  1  3  -1  -3 [5  3  6] 7       6
 *  1  3  -1  -3  5 [3  6  7]      7
 * 
 * Example 2:
 *  Input: nums = [1], k = 1
 *  Output: [1]
 * 
 * Constraints:
 *  1 <= nums.length <= 105
 *  -104 <= nums[i] <= 104
 *  1 <= k <= nums.length
 * 
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        auto uset = multiset<int, std::greater<int>>{cbegin(nums), cbegin(nums) + k, std::greater<int>{}};
        auto vec  = vector<int>{}; 
        for (auto prev = 0, next = k; next < size(nums); ++prev, ++next)
        {
            // cout << "Before: " << endl;
            // copy(cbegin(uset), cend(uset), ostream_iterator<int>{cout," "});
            // cout << endl;
            
            // cout << "prev : " << nums[prev] << endl;
            // cout << "next : " << nums[next] << endl;
            
            vec.push_back(*cbegin(uset));
            
            // uset.erase(nums[prev]);
            auto [a, b] = uset.equal_range(nums[prev]);
            uset.erase(a, ++a);
            
            uset.insert(nums[next]);
            
            // cout << "After: " << endl;
            // copy(cbegin(uset), cend(uset), ostream_iterator<int>{cout," "});
            // cout << endl;
            
            // cout << endl;
        }
        vec.push_back(*cbegin(uset));
        return vec;
    }
};