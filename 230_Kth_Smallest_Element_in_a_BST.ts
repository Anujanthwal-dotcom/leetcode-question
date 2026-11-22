// 230. Kth Smallest Element in a BST
// Difficulty: Medium
// URL: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
//
// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
//
//
//
// Example 1:
//
// Input: root = [3,1,4,null,2], k = 1
// Output: 1
//
// Example 2:
//
// Input: root = [5,3,6,2,4,null,null,1], k = 3
// Output: 3
//
//
//
// Constraints:
//
// 	  * The number of nodes in the tree is n.
//
// 	  * 1 <= k <= n <= 104
//
// 	  * 0 <= Node.val <= 104
//
//
//
// Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?

/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

let preOrder: number[] = [];

function preorder(root: TreeNode | null) {
    if(root === null) return;
    if(root.left === null && root.right ===null){
        preOrder.push(root.val);
        return;
    }

    preorder(root.left);
    preOrder.push(root.val);
    preorder(root.right);
} 
function kthSmallest(root: TreeNode | null, k: number): number {
    preorder(root);    

    return preOrder[k-1];
};