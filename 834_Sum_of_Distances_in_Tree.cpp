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

/*
rerooting the graph

logic:
calculate distance sum from a assume root node say 0.

when we move to a child node, the sum of distance for that node will be sumforparent-count[the current node] + total_nodes - count[the current node]
*/

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n,vector<int>());
        for(auto e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<int> result(n,0);
        vector<int> count(n,1);

        function<void(int,int,int)> dfsForAssumedRoot = [&](int v,int parent,int depth){
            result[0] += depth;

            for(int& i: graph[v]){
                if(i != parent){
                    dfsForAssumedRoot(i,v,depth+1);
                    count[v] += count[i];
                }
            }
        };

        function<void(int,int,int)> dfsForReroot = [&](int v,int parent,int parentSum){
            result[v] = parentSum;
            
            for(int& i : graph[v]){
                if(i != parent){
                    int nextSum = result[v] - count[i] + n-count[i];
                    dfsForReroot(i,v,nextSum);
                }
            }
        };

        dfsForAssumedRoot(0,-1,0);
        dfsForReroot(0,-1, result[0]);

        return result;
    }
};