
/**
 * @file 480. Sliding Window Median.cpp 
 * @author Usama Tayyab (usamatayyab9@gmail.com)
 * Compiled with gcc 9.4.0
 * 
 * @brief
 * 
 * Problem : https://leetcode.com/problems/sliding-window-median/description/
 * Statement:
 * The median is the middle value in an ordered integer list. If the size of the list is even,
 * there is no middle value. So the median is the mean of the two middle values.
 *  For examples, if arr = [2,3,4], the median is 3.
 *  For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.
 * You are given an integer array nums and an integer k. There is a sliding window of size k
 * which is moving from the very left of the array to the very right. You can only see the k
 * numbers in the window. Each time the sliding window moves right by one position.
 * Return the median array for each window in the original array. Answers within 10^-5 of the
 * actual value will be accepted.
 * 
 * Example 1:
 * Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
 * Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
 * Explanation: 
 * Window position                Median
 * ---------------                -----
 * [1  3  -1] -3  5  3  6  7        1
 *  1 [3  -1  -3] 5  3  6  7       -1
 *  1  3 [-1  -3  5] 3  6  7       -1
 *  1  3  -1 [-3  5  3] 6  7        3
 *  1  3  -1  -3 [5  3  6] 7        5
 *  1  3  -1  -3  5 [3  6  7]       6
 * 
 * Example 2:
 * Input: nums = [1,2,3,4,2,3,1,4,2], k = 3
 * Output: [2.00000,3.00000,3.00000,3.00000,2.00000,3.00000,2.00000]
 * 
 * Constraints:
 * 1 <= k <= nums.length <= 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 * 
 * 
 */
class Solution {
    double Average(const double &a, const double &b)
    {
        return a + (b - a) / 2.0;
    }
    double CalculateMedian(const vector<int> &sorted_window)
    {
        const auto kSz     = size(sorted_window);
        const auto kIsEven = (0 == (kSz % 2));
        const auto kMidIdx = kSz / 2;
        auto median        = 0.0;
        if (kIsEven)
        {
            median = Average(sorted_window[kMidIdx] , sorted_window[kMidIdx - 1]);
        }
        else
        {
            median = sorted_window[kMidIdx];
        }
        return median;
    }

    void UpdateSlidingWindow(vector<int> &sorted_window, const int &kElementToRemove, const int &kElementToAdd)
    {
        sorted_window.erase(lower_bound(
            cbegin(sorted_window),
            cend(sorted_window),
            kElementToRemove)
        );
        sorted_window.insert(lower_bound(
                cbegin(sorted_window),
                cend(sorted_window),
                kElementToAdd),
            kElementToAdd
        );
    }
public:
    vector<double> medianSlidingWindow(vector<int>& nums, const int k)
    {
        auto sorted_window = vector<int>{ begin(nums), begin(nums) + k };
        sort(begin(sorted_window), end(sorted_window));
        auto medians = vector<double>{ CalculateMedian(sorted_window) };// Insert median of first k elements
        auto prev    = cbegin(nums);
        auto next    = cbegin(nums) + k;
        auto last    = cend(nums);
        while (next != last)
        {
            UpdateSlidingWindow(sorted_window, *prev, *next);//Remove the first inserted element and insert the latest value
            medians.push_back(CalculateMedian(sorted_window));
            ++prev;
            ++next;
        }
        return medians;
    }
};