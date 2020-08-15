/**
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.

*/


class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> pal;
        int ans = 0;
        bool mid = false;
        
        //put string into map
        for(auto i: s) {
            pal[i]++;
        }
        
        //filter values to find which are a palindrome
        for(int i = 0; i < pal.size(); i++) {
                if(pal[i] % 2 == 0 ) {
                   ans += pal[i]; 
                } else {
                    ans += pal[i] - 1;
                    mid = true;
                }
        }
        
        //add +1 for the single middle character
        if(mid) {
            ans++;
        }

        return ans;
        
    }
};
