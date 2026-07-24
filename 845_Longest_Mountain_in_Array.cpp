// 845. Longest Mountain in Array
// Difficulty: Medium
// URL: https://leetcode.com/problems/longest-mountain-in-array/
//
// You may recall that an array arr is a mountain array if and only if:
//
// 	  * arr.length >= 3
//
// 	  * There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
//
// 		  * arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
//
// 		  * arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
//
//
//
//
// Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.
//
//
//
// Example 1:
//
// Input: arr = [2,1,4,7,3,2,5]
// Output: 5
// Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
//
// Example 2:
//
// Input: arr = [2,2,2]
// Output: 0
// Explanation: There is no mountain.
//
//
//
// Constraints:
//
// 	  * 1 <= arr.length <= 104
//
// 	  * 0 <= arr[i] <= 104
//
//
//
// Follow up:
//
// 	  * Can you solve it using only one pass?
//
// 	  * Can you solve it in O(1) space?

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        int j = 0;
        int size = 0;
        
        if(n<3){
            return 0;
        }

        while(j<n-1 && arr[j]>=arr[j+1]){
            j++;
        }

        if(j == n-1){
            return 0;
        }

        i = j;

        while(j<n-1){
            bool isSholder = false;
            while(j<n-1 && arr[j]<=arr[j+1]){ 
                if(arr[j] == arr[j+1]) isSholder = true;
                j++;
            }

            if(j==n-1){
                return 0;
            }

            if(isSholder){
                i = j;
                continue;
            }

            while(j<n-1 && arr[j]>arr[j+1]) j++;

            size = max(size, j-i+1);
            i = j;
        }

        return size;
    }
};