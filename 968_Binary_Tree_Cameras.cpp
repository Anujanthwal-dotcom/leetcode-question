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

//can't do on my own

struct NodeState {
    int withCamera; //a self monitor
    int coveredNoCamera; //b monitor by children
    int notCovered; //c monitored by parent
};

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        auto [a,b,c] = dfs(root);
        return min(a,b);
    }

private:
    NodeState dfs(TreeNode* node){
        if(!node){
            return {1<<29,0,0};
        }

        auto [la,lb,lc] = dfs(node->left);
        auto [ra,rb,rc] =dfs(node->right);

        int a = 1+ min({la,lb,lc})+min({ra,rb,rc});
        int b = min({la+ra, la+rb,lb+ra});
        int c = lb+rb;

        return {a,b,c};
    }
};