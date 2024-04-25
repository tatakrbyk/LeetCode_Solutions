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

public class Solution {
    public bool IsIsomorphic(string s, string t) {
        int[] dS = new int[256];
        int[] dT = new int[256];

        for(int i = 0; i < s.Length; ++i){
            if(dS[s[i]] != dT[t[i]]){
                return false;
            }
            dS[s[i]] = i + 1;
            dT[t[i]] = i+ 1;
            

        }
        return true;
    }
}