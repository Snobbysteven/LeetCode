/**

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
 

Constraints:

s consists only of printable ASCII characters.

*/



class Solution {
public:
    bool isPalindrome(string s) {
        if(s == "") return true;
        
        s.erase(std::remove_if(s.begin(), s.end(), [](char c) { return !std::isalnum(c); }), s.end());
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string rev = s; 
        reverse(rev.begin(), rev.end());
        if(rev == s) {
           return true;
       } 
        return false; 
    }
    
};
