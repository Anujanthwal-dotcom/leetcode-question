// 1043. Partition Array for Maximum Sum
// Difficulty: Medium
// URL: https://leetcode.com/problems/partition-array-for-maximum-sum/
//
// Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.
//
// Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.
//
//
//
// Example 1:
//
// Input: arr = [1,15,7,9,2,5,10], k = 3
// Output: 84
// Explanation: arr becomes [15,15,15,9,10,10,10]
//
// Example 2:
//
// Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
// Output: 83
//
// Example 3:
//
// Input: arr = [1], k = 1
// Output: 1
//
//
//
// Constraints:
//
// 	  * 1 <= arr.length <= 500
//
// 	  * 0 <= arr[i] <= 109
//
// 	  * 1 <= k <= arr.length

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> dp(n+1,0);

        for(int i = 1;i<=n;i++){
            int mx = 0;

            for(int j = i;j>max(0,i-k);j--){
                mx = max(mx,arr[j-1]);

                dp[i] = max(dp[i],dp[j-1]+ mx*(i-j+1));
            }
        }

        return dp[n];
    }
};

// Calculate the sum if we partition from j to i
                // dp[j-1]: max sum up to position j-1
                // maxValue * (i - j + 1): contribution of current partition
                //   where all elements become maxValue