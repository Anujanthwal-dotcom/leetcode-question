// 834. Sum of Distances in Tree
// Difficulty: Hard
// URL: https://leetcode.com/problems/sum-of-distances-in-tree/
//
// There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.
//
// You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
//
// Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes.
//
//
//
// Example 1:
//
// Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
// Output: [8,12,6,10,10,10]
// Explanation: The tree is shown above.
// We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
// equals 1 + 1 + 2 + 2 + 2 = 8.
// Hence, answer[0] = 8, and so on.
//
// Example 2:
//
// Input: n = 1, edges = []
// Output: [0]
//
// Example 3:
//
// Input: n = 2, edges = [[1,0]]
// Output: [1,1]
//
//
//
// Constraints:
//
// 	  * 1 <= n <= 3 * 104
//
// 	  * edges.length == n - 1
//
// 	  * edges[i].length == 2
//
// 	  * 0 <= ai, bi < n
//
// 	  * ai != bi
//
// 	  * The given input represents a valid tree.

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // Build adjacency list representation of the tree
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            int nodeA = edge[0];
            int nodeB = edge[1];
            graph[nodeA].push_back(nodeB);
            graph[nodeB].push_back(nodeA);
        }
      
        // result[i] will store the sum of distances from node i to all other nodes
        vector<int> result(n);
        // subtreeSize[i] will store the number of nodes in the subtree rooted at node i
        vector<int> subtreeSize(n);

        // First DFS: Calculate the sum of distances for root node (node 0)
        // and the size of each subtree
        function<void(int, int, int)> calculateRootDistance = [&](int currentNode, int parent, int depth) {
            // Add current depth to the total distance sum for root
            result[0] += depth;
            // Initialize subtree size with current node
            subtreeSize[currentNode] = 1;
          
            // Traverse all children (excluding parent)
            for (int& neighbor : graph[currentNode]) {
                if (neighbor != parent) {
                    calculateRootDistance(neighbor, currentNode, depth + 1);
                    // Add child's subtree size to current subtree
                    subtreeSize[currentNode] += subtreeSize[neighbor];
                }
            }
        };

        // Second DFS: Calculate sum of distances for all other nodes using re-rooting technique
        // When moving from parent to child, the formula is:
        // result[child] = result[parent] - subtreeSize[child] + (n - subtreeSize[child])
        function<void(int, int, int)> reRootTree = [&](int currentNode, int parent, int parentSum) {
            // Set the sum of distances for current node
            result[currentNode] = parentSum;
          
            // Calculate sum for all children
            for (int& neighbor : graph[currentNode]) {
                if (neighbor != parent) {
                    // When re-rooting from currentNode to neighbor:
                    // - Nodes in neighbor's subtree get 1 closer (subtract subtreeSize[neighbor])
                    // - Nodes outside neighbor's subtree get 1 farther (add n - subtreeSize[neighbor])
                    int newSum = parentSum - subtreeSize[neighbor] + (n - subtreeSize[neighbor]);
                    reRootTree(neighbor, currentNode, newSum);
                }
            }
        };

        // Execute both DFS traversals
        calculateRootDistance(0, -1, 0);
        reRootTree(0, -1, result[0]);
      
        return result;
    }
};
