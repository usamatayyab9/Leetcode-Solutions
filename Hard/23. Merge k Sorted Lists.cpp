/**
 * @file 23. Merge k Sorted Lists.cpp
 * @author Usama Tayyab (usamatayyab9@gmail.com)
 * @brief
 * Problem : https://leetcode.com/problems/merge-k-sorted-lists/description/
 * Problem statement : 
 * You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 * Merge all the linked-lists into one sorted linked-list and return it.
 * Example 1:
 *  Input: lists = [[1,4,5],[1,3,4],[2,6]]
 *  Output: [1,1,2,3,4,4,5,6]
 *  Explanation: The linked-lists are:
 *  [
 *    1->4->5,
 *    1->3->4,
 *    2->6
 *  ]
 *  merging them into one sorted list: 1->1->2->3->4->4->5->6
 * Example 2:
 *  Input: lists = []
 *  Output: []
 * Example 3:
 *  Input: lists = [[]]
 *  Output: []
 * Constraints:
 *  k == lists.length
 *  0 <= k <= 104
 *  0 <= lists[i].length <= 500
 *  -104 <= lists[i][j] <= 104
 *  lists[i] is sorted in ascending order.
 *  The sum of lists[i].length will not exceed 104. 
 * 
 * @copyright Copyright (c) 2024
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

    ListNode* InsertNode(ListNode *&head_ptr, ListNode *current, int val)
    {
        if (nullptr == head_ptr)
        {
            head_ptr = current = new ListNode{val};
        }
        else
        {
            current->next = new ListNode{val};
            current = current->next;
        }
        return current;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head   { nullptr };
        ListNode* current{ head };
        while (true)
        {
            auto pos = min_element(begin(lists), end(lists), [](auto first, auto smallest)
            {
                if (nullptr == first && nullptr == smallest) { return false; }
                if (nullptr == first && nullptr != smallest) { return false; }
                if (nullptr != first && nullptr == smallest) { return true; }
                if (nullptr != first && nullptr != smallest) { return first->val < smallest->val; }
                return false;
            });
            if (pos == end(lists) || nullptr == *pos) { break; }
            current = InsertNode(head, current, (*pos)->val);
            *pos = (*pos)->next;
        }
        return head;    
    }
};