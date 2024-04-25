/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 
*/

#include <iostream>
class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        int count[26] = {0};
        for(char ch : magazine)
            count[ch - 'a']++;
        
        for(char ch : ransomNote)
            if(count[ch - 'a']-- <= 0)
                return false;
        
        return true;
    }
};