/**
 * @author Usama Tayyab (usamatayyab9@gmail.com)
 * @brief Converts a string into a zigzag pattern and reads it line by line.
 * Problem statement : https://leetcode.com/problems/zigzag-conversion/
 * 
 * My Approach:
 * Instead of simulating the zigzag pattern, we can directly compute the indices of characters.
 * Because simualting the zigzag pattern would require to generate a 2D array which will be O(N^2)
 * in both time and space complexity. So what I did is to calculate the indices of characters in each row.
 * 
 * After going throw some custom test cases and examples, I found out that the characters in the first 
 * and last rows are spaced evenly with a gap of 2*(numRows-1). For the middle rows, the characters
 * alternate between two different gaps: one going down the zigzag and one going up diagonally.
 * This observation allows us to directly compute the indices of characters in each row without
 * simulating the entire zigzag pattern.
 * 
 * Example 1:
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * Consider the zigzag pattern:
 * P | - | A | - | H | - | N |
 * A | P | L | S | I | I | G |
 * Y | - | I | - | R | - | - |
 * 
 * Reading line by line gives us "PAHNAPLSIIGYIR". Now lets review the above matrix again but this with indices:
 * P(0) | -    | A(4) | -    | H(8)  | -     | N(12) |
 * A(1) | P(3) | L(5) | S(7) | I(9)  | I(11) | G(13) |
 * Y(2) | -    | I(6) | -    | R(10) | -     | -     |
 * 
 * From the above matrix, we can see that:
 * - The first row (row 0) has characters at indices 0, 4, 8, 12 (gap of 4 == numRows - 1). 
 * Which means for first row indices will start 0 and increment by 4(numRows - 1) until the end of string.
 * 
 * - Middle rows (row = 1 to numRows - 2)
 * For each cycle starting at `base` (0, 4, 8, ...), there are up to two characters:
 * 
 * Vertical character:
 *   index = base + row
 *
 * Diagonal character:
 *   index = base + cycle - row
 *
 * Both indices are added if they are within the string length.
 * 
 * 
 * - The third/last row (row 2) has characters at indices 2, 6, 10 (gap of 4 == numRows - 1).
 * Which means for last row indices will start 2 and increment by 4(numRows - 1) until the end of string.
 * 
 *  
 */
class Solution {

    template<class InputIterator, class OutputIterator>
    OutputIterator CopyStride(InputIterator first, InputIterator last, const size_t &n,
        OutputIterator dest)
    {
        while (first < last)
        {
            *dest = *first;
            first += n;
            ++dest;
        }
        return dest;
    }

public:
    string convert(string s, int numRows)
    {
        if (1 == numRows)            { return s; }
        else if (numRows >= size(s)) { return s; }
        else
        {
            const auto kDiff = 2 * (numRows - 1);
            auto result      = string{};
            result.reserve(size(s));
            for (auto ii = size_t{ 0 }; ii < numRows ;++ii)
            {
                if ((0 == ii) || (numRows - 1 == ii))
                {
                    CopyStride(begin(s) + ii, end(s), kDiff, back_inserter(result));
                }
                else
                {
                    for (auto start_idx = size_t{ 0 }; start_idx + ii < size(s); start_idx += kDiff)
                    {
                        result.push_back(s[start_idx + ii]);// Vertical Direction
                        if (const auto kDiagonalIdx = start_idx + kDiff - ii; kDiagonalIdx < size(s))
                        {
                            result.push_back(s[kDiagonalIdx]);//Diagonal Direction
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
            return result;
        }
    }
};