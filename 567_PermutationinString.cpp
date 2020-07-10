/**
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Constraints:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //create map for all letters
        int map[26] = {0};
        //put all letters into map
        for(char c : s1) {
            map[c - 'a']++;
        }
        //create variables needed for counting
        int j = 0;
        int i = 0;
        int charCount = s1.size();
        //find every set in s1 that is of size s2 and compared it to s2 for anagram
        while(j < s2.size()) {
            if(map[s2.at(j++) - 'a']-- > 0) {
                charCount--;
            }
            //if none return true
            if(charCount == 0) return true;
            if(j -i == s1.size() && map[s2.at(i++) - 'a']++ >= 0) {
                charCount++;
            }
        }
        return false;
        
    }
};





