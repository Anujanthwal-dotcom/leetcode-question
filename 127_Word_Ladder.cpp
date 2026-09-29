// 127. Word Ladder
// Difficulty: Hard
// URL: https://leetcode.com/problems/word-ladder/
//
// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
//
// 	  * Every adjacent pair of words differs by a single letter.
//
// 	  * Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
//
// 	  * sk == endWord
//
// Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
//
//
//
// Example 1:
//
// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
//
// Example 2:
//
// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
// Output: 0
// Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
//
//
//
// Constraints:
//
// 	  * 1 <= beginWord.length <= 10
//
// 	  * endWord.length == beginWord.length
//
// 	  * 1 <= wordList.length <= 5000
//
// 	  * wordList[i].length == beginWord.length
//
// 	  * beginWord, endWord, and wordList[i] consist of lowercase English letters.
//
// 	  * beginWord != endWord
//
// 	  * All the words in wordList are unique.

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Convert word list to unordered set for O(1) lookup
        unordered_set<string> availableWords(wordList.begin(), wordList.end());
      
        // Initialize BFS queue with the starting word
        queue<string> bfsQueue;
        bfsQueue.push(beginWord);
      
        // Track the transformation sequence length (starting from 1)
        int sequenceLength = 1;
      
        // Perform level-order BFS traversal
        while (!bfsQueue.empty()) {
            // Increment length for each level of BFS
            ++sequenceLength;
          
            // Process all words at the current level
            int currentLevelSize = bfsQueue.size();
            for (int i = 0; i < currentLevelSize; ++i) {
                // Get and remove the front word from queue
                string currentWord = bfsQueue.front();
                bfsQueue.pop();
              
                // Try changing each character position
                for (int charIndex = 0; charIndex < currentWord.size(); ++charIndex) {
                    // Store original character for restoration
                    char originalChar = currentWord[charIndex];
                  
                    // Try all possible lowercase letters
                    for (char newChar = 'a'; newChar <= 'z'; ++newChar) {
                        // Replace character at current position
                        currentWord[charIndex] = newChar;
                      
                        // Skip if the transformed word is not in the available word set
                        if (!availableWords.count(currentWord)) {
                            continue;
                        }
                      
                        // Check if we've reached the target word
                        if (currentWord == endWord) {
                            return sequenceLength;
                        }
                      
                        // Add valid transformation to queue for next level
                        bfsQueue.push(currentWord);
                      
                        // Remove word from available set to avoid revisiting
                        availableWords.erase(currentWord);
                    }
                  
                    // Restore the original character for next iteration
                    currentWord[charIndex] = originalChar;
                }
            }
        }
      
        // No transformation sequence found
        return 0;
    }
};
