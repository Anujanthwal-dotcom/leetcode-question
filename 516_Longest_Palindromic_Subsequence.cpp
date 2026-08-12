// 516. Longest Palindromic Subsequence
// Difficulty: Medium
// URL: https://leetcode.com/problems/longest-palindromic-subsequence/
//
// Given a string s, find the longest palindromic subsequence's length in s.
//
// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
//
//
//
// Example 1:
//
// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb".
//
// Example 2:
//
// Input: s = "cbbd"
// Output: 2
// Explanation: One possible longest palindromic subsequence is "bb".
//
//
//
// Constraints:
//
// 	  * 1 <= s.length <= 1000
//
// 	  * s consists only of lowercase English letters.

/*
solutions:
1. create subsequences exponential complexity
2. use dp -> quadratic complexity

compare string and reverse string
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string rs = s;
        reverse(rs.begin(),rs.end());

        int dp[n+1][n+1];
        for(int i = 0;i<=n;i++) dp[0][i] = 0;
        for(int j = 0;j<=n;j++) dp[j][0] = 0;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(s[i] == rs[j]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        for(int i = 0;i<=n;i++){
            for(int j = 0;j<=n;j++){
                cout<<dp[i][j]<<" "<<endl;
            }
            cout<<endl;
        }

        return dp[n][n];
    }
};