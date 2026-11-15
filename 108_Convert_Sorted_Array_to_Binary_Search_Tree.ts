// 108. Convert Sorted Array to Binary Search Tree
// Difficulty: Easy
// URL: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
//
// Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
//
//
//
// Example 1:
//
// Input: nums = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: [0,-10,5,null,-3,null,9] is also accepted:
//
// Example 2:
//
// Input: nums = [1,3]
// Output: [3,1]
// Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
//
//
//
// Constraints:
//
// 	  * 1 <= nums.length <= 104
//
// 	  * -104 <= nums[i] <= 104
//
// 	  * nums is sorted in a strictly increasing order.

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

function sortedArrayToBST(nums: number[]): TreeNode | null {
    return helper(nums,0, nums.length-1);
};

function helper(nums: number[], left: number, right: number): TreeNode | null {
    if(left > right) return null;

    let mid: number = left + Math.floor((right-left)/2);
    let nodeLeft: TreeNode = helper(nums,left,mid-1);
    let nodeRight: TreeNode = helper(nums,mid+1,right);

    let rootNode: TreeNode = new TreeNode(nums[mid],nodeLeft,nodeRight);

    return rootNode;
}