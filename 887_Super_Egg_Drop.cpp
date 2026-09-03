// 887. Super Egg Drop
// Difficulty: Hard
// URL: https://leetcode.com/problems/super-egg-drop/
//
// You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.
//
// You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.
//
// Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.
//
// Return the minimum number of moves that you need to determine with certainty what the value of f is.
//
//
//
// Example 1:
//
// Input: k = 1, n = 2
// Output: 2
// Explanation: 
// Drop the egg from floor 1. If it breaks, we know that f = 0.
// Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
// If it does not break, then we know f = 2.
// Hence, we need at minimum 2 moves to determine with certainty what the value of f is.
//
// Example 2:
//
// Input: k = 2, n = 6
// Output: 3
//
// Example 3:
//
// Input: k = 3, n = 14
// Output: 4
//
//
//
// Constraints:
//
// 	  * 1 <= k <= 100
//
// 	  * 1 <= n <= 104

class Solution {
public:
    int superEggDrop(int k, int n) {
        if(n == 0 || n ==1) return n;
        if(k == 1) return n;


        vector<vector<int>> dp(k+1,vector<int>(n+1,0));


        for(int i = 0;i<=k;i++) dp[i][0] = 0, dp[i][1] = 1;
        for(int i  = 0;i<=n;i++) dp[0][i] = 0, dp[1][i] = i;


        for(int i= 2;i<k+1;i++){
            for(int j = 2;j<n+1;j++){
                int l = 1;
                int h = j;
                int temp = 0;
                int ans = 100000;

                while(l<=h){
                    int mid = (l+h)/2;
                    int left = dp[i-1][mid-1];
                    int right = dp[i][j-mid];

                    temp = 1+ max(left,right);

                    if(left<right){
                        l = mid+1;
                    } else{
                        h = mid-1;
                    }

                    ans = min(ans,temp);
                }

                dp[i][j] = ans;
            }
        } 

        return dp[k][n];
    }
};