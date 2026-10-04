// 421. Maximum XOR of Two Numbers in an Array
// Difficulty: Medium
// URL: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
//
// Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.
//
//
//
// Example 1:
//
// Input: nums = [3,10,5,25,2,8]
// Output: 28
// Explanation: The maximum result is 5 XOR 25 = 28.
//
// Example 2:
//
// Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
// Output: 127
//
//
//
// Constraints:
//
// 	  * 1 <= nums.length <= 2 * 105
//
// 	  * 0 <= nums[i] <= 231 - 1

class TrieNode{
    public:
    TrieNode* child[2];

    TrieNode(){
        this->child[0] = nullptr;
        this->child[1] = nullptr;
    }
};

class Solution {
public:
    TrieNode* root;

    void insert(int n){
        bitset<32> bs(n);

        TrieNode* trv = root;

        for(int i = 32;i>=0;i--){
            if(trv->child[bs[i]] == nullptr) trv->child[bs[i]] = new TrieNode();
            trv = trv->child[bs[i]];
        }
    }

    int findMax(int n){
        bitset<32> bs(n);

        TrieNode* trv = root;

        int ans = 0;
        
        for(int i = 32;i>=0;i--){
            if(trv->child[!bs[i]] != nullptr) ans += (1<<i), trv = trv->child[!bs[i]];
            else trv = trv->child[bs[i]];
        }

        return ans;
    }

    int findMaximumXOR(vector<int>& nums) {
        root = new TrieNode();

        for(int num: nums){
            insert(num);
        }

        int ans = 0;

        for(int num: nums){
            ans = max(ans, findMax(num));
        }

        return ans;
    }
};