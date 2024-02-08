/**
 * @file 65. Valid Number.cpp
 * @author Usama Tayyab (usamatayyab9@gmail.com)
 * @brief 
 * Problem : https://leetcode.com/problems/valid-number/description/
 * Statement :
 *  A valid number can be split up into these components (in order):
 *      1. A decimal number or an integer.
 *      2. (Optional) An 'e' or 'E', followed by an integer.
 *  A decimal number can be split up into these components (in order):
 *      1. (Optional) A sign character (either '+' or '-').
 *      2. One of the following formats:
 *          1. One or more digits, followed by a dot '.'.
 *          2. One or more digits, followed by a dot '.', followed by one or more digits.
 *          3. A dot '.', followed by one or more digits.
 *  An integer can be split up into these components (in order):
 *      1. (Optional) A sign character (either '+' or '-').
 *      2. One or more digits.
 *  For example, all the following are valid numbers:
 *  ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"],
 *  while the following are not valid numbers: ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].
 * 
 * Given a string s, return true if s is a valid number.
 * 
 * Example 1:
 *  Input: s = "0"
 *  Output: true
 * Example 2:
 *  Input: s = "e"
 *  Output: false
 * Example 3:
 *  Input: s = "."
 *  Output: false
 * Constraints:
 *  1 <= s.length <= 20
 * 
 * s consists of only English letters (both uppercase and lowercase), digits (0-9), plus '+', minus '-', or dot '.'.
 * 
 * @copyright Copyright (c) 2024
 * 
 */


class Solution {
private:
  enum state : int {
    q0 = 0,
    q1 = 1,
    q2 = 2,
    q3 = 3,
    q4 = 4,
    q5 = 5,
    q6 = 6,
    q7 = 7,
    q8 = 8,
    q9 = 9,
    q10 = 10,
    q11 = 11,
    q12 = 12
    };
  enum alphabets : int {plus = 0 , minus = 1, dot = 2, digit = 3, e = 4};
  const vector<vector<state>> state_table{{
            /*+    -   .    d     e */
    /*q0: */{q1 , q1 , q6 , q4 , q11},
    /*q1: */{q11, q11, q2 , q4 , q11},
    /*q2: */{q11, q11, q11, q3 , q11},
    /*q3: */{q11, q11, q11, q3 , q12},
    /*q4: */{q11, q11, q5 , q4 , q12},
    /*q5: */{q11, q11, q11, q8 , q12},
    /*q6: */{q11, q11, q11, q7 , q11},
    /*q7: */{q11, q11, q11, q7 , q12},
    /*q8: */{q11, q11, q11, q8 , q12},
    /*q9: */{q11, q11, q11, q10, q11},
    /*q10:*/{q11, q11, q11, q10, q11},
    /*q11:*/{q11, q11, q11, q11, q11},
    /*q12:*/{q9 , q9 , q11, q10, q11}
  }};
  const state fail_state{q11};
  const unordered_set<state> final_accepted_states{q3, q4, q5, q7, q8, q10};
public:
    bool isNumber(string s)
    {
        auto state = state::q0; // state
        for (const auto &ch : s)
        {
            if      (ch == '+')              { state = state_table[state][plus];  }
            else if (ch == '-')              { state = state_table[state][minus]; }
            else if (ch == '.')              { state = state_table[state][dot];   }
            else if (isdigit(ch))            { state = state_table[state][digit]; }
            else if (ch == 'e' || ch == 'E') { state = state_table[state][e];     }
            else                             { state = fail_state; break;         }
        }
        
        auto flag = final_accepted_states.count(state);
        return flag;
    }
};