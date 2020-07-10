/**
Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase. 

  

Example 1: 

Input: "Hello" 
Output: "hello" 
 

Example 2: 

Input: "here" 
Output: "here" 
 

Example 3: 

Input: "LOVELY" 
Output: "lovely" 

*/



class Solution { 

public: 

    string toLowerCase(string str) { 

         

        for(char& i : str) { 

            if(i >= 65 && i <= 90) { 

                i += 32; 

            } 

        } 

        return str; 

    } 

}; 
