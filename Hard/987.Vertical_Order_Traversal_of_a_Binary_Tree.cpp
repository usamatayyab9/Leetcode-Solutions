/**
 * @file 987_Vertical_Order_Traversal_of_a_Binary_Tree.cpp
 * @author Usama Tayyab (usamtayyab9@gmail.com)
 * @brief
 * Problem : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
 * Statement :
 * Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
 * For each node at position (row, col), its left and right children will be at positions
 * (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).
 * The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each
 * column index starting from the leftmost column and ending on the rightmost column.
 * There may be multiple nodes in the same row and same column. In such a case, sort these
 * nodes by their values.
 * 
 * Return the vertical order traversal of the binary tree
 * 
 * Constraints:
 * The number of nodes in the tree is in the range [1, 1000].
 * 0 <= Node.val <= 1000
 * 
 * @copyright Copyright (c) 2024
 */


class Solution {
    void verticalTraversal_Rec(TreeNode* root, const int &row_idx, const int &col_idx, map<int, vector<pair<int, int>>> &traversal_map)
    {
        if (nullptr != root)
        {
            auto &current_nodes = traversal_map[col_idx];
            auto insert_pos     = lower_bound(cbegin(current_nodes), cend(current_nodes), pair{ row_idx, root->val },
            [](const pair<int, int> &tuple1, const pair<int, int> &tuple2){
                auto flag = true;
                if      (tuple1.first < tuple2.first)  { flag = true;                          }
                else if (tuple1.first == tuple2.first) { flag = tuple1.second < tuple2.second; }
                else                                   { flag = false;                         }
                return flag;
            });
            current_nodes.insert(insert_pos, { row_idx, root->val });
            verticalTraversal_Rec(root->left , row_idx + 1, col_idx - 1, traversal_map);
            verticalTraversal_Rec(root->right, row_idx + 1, col_idx + 1, traversal_map);
        }
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        auto traversal_map = map<int, vector< pair<int, int> > >{};
        verticalTraversal_Rec(root, 0, 0, traversal_map);
        auto vertical_order_vec = vector<vector<int>>{};
        for (const auto &[kVerticalLevel, kNodes] : traversal_map)
        {
            auto vec = vector<int>(size(kNodes));
            transform(cbegin(kNodes), cend(kNodes), begin(vec), [](const pair<int, int> &p){ return p.second; });
            vertical_order_vec.emplace_back(vec);
        }
        return vertical_order_vec;
    }
};