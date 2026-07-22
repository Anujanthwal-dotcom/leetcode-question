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
public:
    void dfs(unordered_map<int,int>& map, vector<int>& parent, vector<int>& leaf, TreeNode* node, int index,int level,int prt){
        if(node == NULL) return;

        parent[index] = prt;
        map[index] = level;
        if(node->left == NULL && node->right == NULL){
            leaf.push_back(index);
            return;
        }

        dfs(map,parent,leaf,node->left,2*index+1,level+1,index);
        dfs(map,parent,leaf,node->right,2*index+2,level+1,index);
    }

    int countPairs(TreeNode* root, int distance) {
        unordered_map<int,int> map;
        vector<int> parent(1030);
        vector<int> leaf;

        dfs(map,parent,leaf,root,0,0,-1);

        int cnt = 0;

        for(int i = 0;i<leaf.size();i++){
            for(int j = i+1;j<leaf.size();j++){
                int first_val = leaf[i];
                int second_val = leaf[j];
                
                vector<int> first;
                vector<int> second;

                while(parent[first_val] != -1){
                    first.push_back(parent[first_val]);
                    first_val = parent[first_val];
                }

                while(parent[second_val] != -1){
                    second.push_back(parent[second_val]);
                    second_val = parent[second_val];
                }

                int common_ancestor;

                for(int k = min(first.size(),second.size())-1;k>=0;k--){
                    if(first[k] == second[k]) {
                        common_ancestor = first[k];
                    }
                }

                int distance_between_first_second = (map[first_val] - map[common_ancestor]) + (map[second_val] - map[common_ancestor]);

                if(distance_between_first_second <= distance){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};