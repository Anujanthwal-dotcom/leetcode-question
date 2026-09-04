// 968. Binary Tree Cameras
// Difficulty: Hard
// URL: https://leetcode.com/problems/binary-tree-cameras/
//
// You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.
//
// Return the minimum number of cameras needed to monitor all nodes of the tree.
//
//
//
// Example 1:
//
// Input: root = [0,0,null,0,0]
// Output: 1
// Explanation: One camera is enough to monitor all nodes if placed as shown.
//
// Example 2:
//
// Input: root = [0,0,null,0,null,0,null,null,0]
// Output: 2
// Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
//
//
//
// Constraints:
//
// 	  * The number of nodes in the tree is in the range [1, 1000].
//
// 	  * Node.val == 0

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int,int> dfs(TreeNode* node){
        if(!node){
            return make_pair(1e9,0);
        }

        auto [l,nl] = dfs(node->left);
        auto [r,nr] = dfs(node->right);

        int current = 1+nl+nr;
        int notCurrent = min(l,nl) + min(r,nr);

        return make_pair(current,notCurrent);
    }

    int minCameraCover(TreeNode* root) {
        auto [current,notCurrent] = dfs(root);
        return min(current, notCurrent);
    }
};