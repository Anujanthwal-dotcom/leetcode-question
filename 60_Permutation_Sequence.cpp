// 60. Permutation Sequence
// Difficulty: Hard
// URL: https://leetcode.com/problems/permutation-sequence/
//
// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
//
// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
//
// 	  * "123"
//
// 	  * "132"
//
// 	  * "213"
//
// 	  * "231"
//
// 	  * "312"
//
// 	  * "321"
//
// Given n and k, return the kth permutation sequence.
//
//
//
// Example 1:
//
// Input: n = 3, k = 3
// Output: "213"
// Example 2:
//
// Input: n = 4, k = 9
// Output: "2314"
// Example 3:
//
// Input: n = 3, k = 1
// Output: "123"
//
//
//
// Constraints:
//
// 	  * 1 <= n <= 9
//
// 	  * 1 <= k <= n!

class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        vector<int> sequence;
        
        for(int i = 1;i<=n;i++){
            sequence.push_back(i);
        }

        long fac[10];
        fac[0] =1;
        
        for(int i = 1;i<10;i++){
            fac[i] = i*fac[i-1];
        }

        while(n>0){

            int idx = k/fac[n-1];

            ans = ans + to_string(sequence[idx]);
            sequence.erase(sequence.begin()+idx);

            k = k%fac[n-1];
            n--;
        }

        return ans;
    }
};