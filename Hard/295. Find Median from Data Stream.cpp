/**
 * @file 295. Find Median from Data Stream.cpp
 * @author Usama Tayyab (usamatayyab9@gmail.com)
 * Compiled with gcc 9.4.0
 * 
 * @brief 
 * 
 * Problem: https://leetcode.com/problems/find-median-from-data-stream/description/
 * Statement :
 * The median is the middle value in an ordered integer list. If the size of the list is even,
 * there is no middle value, and the median is the mean of the two middle values.
 *  For example, for arr = [2,3,4], the median is 3.
 *  For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
 * Implement the MedianFinder class:
 *  MedianFinder() initializes the MedianFinder object.
 *  void addNum(int num) adds the integer num from the data stream to the data structure.
 *  double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 * 
 * Example 1:
 * Input
 *  ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
 *  [[], [1], [2], [], [3], []]
 * Output
 *  [null, null, null, 1.5, null, 2.0]
 * 
 * Explanation
 *  MedianFinder medianFinder = new MedianFinder();
 *  medianFinder.addNum(1);    // arr = [1]
 *  medianFinder.addNum(2);    // arr = [1, 2]
 *  medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
 *  medianFinder.addNum(3);    // arr[1, 2, 3]
 *  medianFinder.findMedian(); // return 2.0
 * 
 * Constraints:
 *  -10^5 <= num <= 10^5
 *  There will be at least one element in the data structure before calling findMedian.
 *  At most 5 * 10^4 calls will be made to addNum and findMedian.
 * 
 * Follow up:
 *  If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
 *  If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
 * 
 */

class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        ++value_counts[num];
        ++total_values;
    }
    
    double findMedian() {
        auto IsValueInRange = [](const auto &value, const auto &low, const auto &hi){
            return value >= low && value < hi;
        };
        const auto kMidIdx = total_values / 2;
        const auto kIsEven = (0 == (total_values % 2));
        const auto kValuesToFind = 1 + kIsEven;
        auto sum           = 0;
        auto values_found  = 0;
        auto idx           = size_t{ 0 };
        for (const auto &[value, frequency] : value_counts)
        {
            if (values_found == kValuesToFind) { break; }
            if (IsValueInRange(kMidIdx, idx, idx + frequency))
            {
                sum += value; ++values_found;
            }
            else if (kIsEven && IsValueInRange(kMidIdx - 1, idx, idx + frequency))
            {
                sum += value; ++values_found;
            }
            idx += frequency;
        }
        return sum / static_cast<double>(values_found);
    }
private:
    map<int, size_t> value_counts;
    size_t total_values{ 0 };
};