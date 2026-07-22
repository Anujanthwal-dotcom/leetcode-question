// 1530. Number of Good Leaf Nodes Pairs
// Difficulty: Medium
// URL: https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/
//
// You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.
//
// Return the number of good leaf node pairs in the tree.
//
//
//
// Example 1:
//
// Input: root = [1,2,3,null,4], distance = 3
// Output: 1
// Explanation: The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. This is the only good pair.
//
// Example 2:
//
// Input: root = [1,2,3,4,5,6,7], distance = 3
// Output: 2
// Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The pair [4,6] is not good because the length of ther shortest path between them is 4.
//
// Example 3:
//
// Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
// Output: 1
// Explanation: The only good pair is [2,5].
//
//
//
// Constraints:
//
// 	  * The number of nodes in the tree is in the range [1, 210].
//
// 	  * 1 <= Node.val <= 100
//
// 	  * 1 <= distance <= 10

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
private:
    vector<int> postOrder(TreeNode* currentNode, int distance){
        if(!currentNode) return vector<int>(12);
        else if(!currentNode->left && !currentNode->right){
            vector<int> current(12);
            current[0] = 1;
            return current;
        }

        vector<int> left = postOrder(currentNode->left, distance);
        vector<int> right = postOrder(currentNode->right,distance);

        vector<int> current(12);


        for(int i = 0;i<10;i++){
            current[i+1] = left[i] + right[i];
        }

        current[11] += left[11] + right[11];

        for(int d1 = 0;d1<=distance;d1++){
            for(int d2 = 0;d2<=distance;d2++){
                if(2+d1+d2 <=distance){
                    current[11] +=left[d1]*right[d2];
                }
            }
        }

        return current;
    }

public:
    int countPairs(TreeNode* root, int distance) {
        return postOrder(root, distance)[11];
    }
};