/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> charToIndex_s(128);
        vector<int> charToIndex_t(128);

        for(int i = 0; i < s.length(); ++i){
            if(charToIndex_s[s[i]] != charToIndex_t[t[i]])
                return false;
            charToIndex_s[s[i]] = i + 1;
            charToIndex_t[t[i]] = i + 1;

        }
        return true;
    }
};