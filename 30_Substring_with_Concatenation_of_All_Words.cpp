// 30. Substring with Concatenation of All Words
// Difficulty: Hard
// URL: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
//
// You are given a string s and an array of strings words. All the strings of words are of the same length.
//
// A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.
//
// 	  * For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
//
// Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.
//
//
//
// Example 1:
//
// Input: s = "barfoothefoobarman", words = ["foo","bar"]
//
// Output: [0,9]
//
// Explanation:
//
// The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
//
// The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.
//
// Example 2:
//
// Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
//
// Output: []
//
// Explanation:
//
// There is no concatenated substring.
//
// Example 3:
//
// Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
//
// Output: [6,9,12]
//
// Explanation:
//
// The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"].
//
// The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"].
//
// The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"].
//
//
//
// Constraints:
//
// 	  * 1 <= s.length <= 104
//
// 	  * 1 <= words.length <= 5000
//
// 	  * 1 <= words[i].length <= 30
//
// 	  * s and words[i] consist of lowercase English letters.

//please revise it...

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // Count frequency of each word in the words array
        unordered_map<string, int> wordCount;
        for (const auto& word : words) {
            wordCount[word]++;
        }

        vector<int> result;
        int stringLength = s.length();
        int wordArraySize = words.size();
        int wordLength = words[0].length();

        // Try starting from each possible offset (0 to wordLength-1)
        // This ensures we check all possible alignments
        for (int offset = 0; offset < wordLength; ++offset) {
            int left = offset;
            int right = offset;
            unordered_map<string, int> currentWindowCount;
          
            // Slide the window through the string
            while (right + wordLength <= stringLength) {
                // Extract the next word from position right
                string currentWord = s.substr(right, wordLength);
                right += wordLength;

                // If current word is not in our target words, reset the window
                if (!wordCount.contains(currentWord)) {
                    currentWindowCount.clear();
                    left = right;
                    continue;
                }

                // Add current word to our window
                currentWindowCount[currentWord]++;

                // Shrink window from left while we have excess of any word
                while (currentWindowCount[currentWord] > wordCount[currentWord]) {
                    string leftWord = s.substr(left, wordLength);
                    currentWindowCount[leftWord]--;
                  
                    // Remove from map if count becomes zero to keep map clean
                    if (currentWindowCount[leftWord] == 0) {
                        currentWindowCount.erase(leftWord);
                    }
                    left += wordLength;
                }

                // Check if current window size matches the total length of all words
                // If yes, we found a valid starting position
                if (right - left == wordArraySize * wordLength) {
                    result.push_back(left);
                }
            }
        }

        return result;
    }
};
