// 2681. Power of Heroes
// Difficulty: Hard
// URL: https://leetcode.com/problems/power-of-heroes/
//
// You are given a 0-indexed integer array nums representing the strength of some heroes. The power of a group of heroes is defined as follows:
//
// 	  * Let i0, i1, ... ,ik be the indices of the heroes in a group. Then, the power of this group is max(nums[i0], nums[i1], ... ,nums[ik])2 * min(nums[i0], nums[i1], ... ,nums[ik]).
//
// Return the sum of the power of all non-empty groups of heroes possible. Since the sum could be very large, return it modulo 109 + 7.
//
//
//
// Example 1:
//
// Input: nums = [2,1,4]
// Output: 141
// Explanation: 
// 1st group: [2] has power = 22 * 2 = 8.
// 2nd group: [1] has power = 12 * 1 = 1. 
// 3rd group: [4] has power = 42 * 4 = 64. 
// 4th group: [2,1] has power = 22 * 1 = 4. 
// 5th group: [2,4] has power = 42 * 2 = 32. 
// 6th group: [1,4] has power = 42 * 1 = 16. 
// ​​​​​​​7th group: [2,1,4] has power = 42​​​​​​​ * 1 = 16. 
// The sum of powers of all groups is 8 + 1 + 64 + 4 + 32 + 16 + 16 = 141.
//
// Example 2:
//
// Input: nums = [1,1,1]
// Output: 7
// Explanation: A total of 7 groups are possible, and the power of each group will be 1. Therefore, the sum of the powers of all groups is 7.
//
//
//
// Constraints:
//
// 	  * 1 <= nums.length <= 105
//
// 	  * 1 <= nums[i] <= 109

class Solution {
public:
    int MOD = (int)1e9+7;
    /*
    sort the elements because we don't care about the order of the heroes selected.

    factor stores the multiplication factor for each index.

    2,1,4 -> 1,2,4

    for the first element:
    1*1
    for second element:
    1*1 + 2*1 = 2*1 + 2*1 - 1
    for third element:
    1*2+2*1+4*1 = 4*1 + 1*2 + 2*2 - 2
    => these power of two comes from the fact that we will choose index i and j i>=j,
    elements between i and j will be choosen based on combinatorics.

    say 5 elements are between i and j: then 5c0+5c1+5c2+5c3+5c4+5c5 = 2^5

    this gives the equation:
    factor[i] = nums[i] + 2*factor[i-1] - nums[i-1]
    //this nums[i-1] is there because if j == i-1 or j == i, then there are no elements between them. Hence the factor is 1 and 1. 

    why this works:

    sorted elements ensure that current element is associated with elements smaller then it. This helps in determining maximum and minimums easily.
    */
    int sumOfPower(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int n = nums.size();

        vector<int> factor(n);

        factor[0] = nums[0];

        for(int i = 1;i<n;i++){
            factor[i] = (nums[i] + ((2*factor[i-1])%MOD-nums[i-1] + MOD)%MOD)%MOD; 
        }

        int sum = 0;

        for(int i = 0;i<n;i++){
            sum = (sum +
      ((1LL * nums[i] * nums[i]) % MOD * factor[i]) % MOD) % MOD;
        }

        return sum;
    }
};