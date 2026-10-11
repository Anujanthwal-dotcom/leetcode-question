// 3. Longest Substring Without Repeating Characters
// Difficulty: Medium
// URL: https://leetcode.com/problems/longest-substring-without-repeating-characters/
//
// Given a string s, find the length of the longest substring without duplicate characters.
//
//
//
// Example 1:
//
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
//
// Example 2:
//
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
//
// Example 3:
//
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
//
//
//
// Constraints:
//
// 	  * 0 <= s.length <= 105
//
// 	  * s consists of English letters, digits, symbols and spaces.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int stringSize = s.size();
        int l = 0;
        int mx = 0;

        unordered_map<char,int> map;

        for(int r = 0;r<stringSize;r++){
            map[s[r]]++;
            
            while(map[s[r]] > 1){
                map[s[l]]--;
                l++;
            }

            mx = max(mx, r-l+1);
        }

        return mx;
    }
};