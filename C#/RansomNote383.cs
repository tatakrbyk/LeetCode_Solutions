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

public class Solution {
    public bool CanConstruct(string ransomNote, string magazine) {
        Dictionary<char, int> magazineDict = new();

        foreach(char c in magazine){
            if(magazineDict.ContainsKey(c))
                magazineDict[c]++;
            else
                magazineDict[c] = 1;
        }

        foreach(char c in ransomNote){
            if(!magazineDict.ContainsKey(c) || magazineDict[c] == 0)
                return false;

            magazineDict[c]--;
        }

        return true;
    }
}

/*
public class Solution {
    public bool CanConstruct(string ransomNote, string magazine) {
        int[] count = new int[26];

        foreach(char ch in magazine){
            count[ch - 'a']++;
        }
        foreach(var ch in ransomNote){
            if(count[ch - 'a'] -- <= 0){
                return false;
            }
        }

        return true;
    }
}
*/