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
    bool differByOne(string& a, string& b) {
        int count = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                count++;
            }
        }
        if (count == 1)
            return true;
        return false;
    }

    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        // bfs for min count
        int length = 0;
        bool found = false;
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited;

        while (!q.empty()) {
            int size = q.size();
            length++;

            while (size-- > 0) {
                string front = q.front();
                q.pop();

                if (front == endWord) {
                    found = true;
                    break;
                }

                visited.insert(front);
                
                for (int i = 0; i < wordList.size(); i++) {
                    if (visited.find(wordList[i]) != visited.end())
                        continue;
                    if (differByOne(front, wordList[i])) {
                        q.push(wordList[i]);
                    }
                }
            }

            if (found == true) {
                break;
            }
        }

        if (found == false) {
            return 0;
        }
        return length;
    }
};