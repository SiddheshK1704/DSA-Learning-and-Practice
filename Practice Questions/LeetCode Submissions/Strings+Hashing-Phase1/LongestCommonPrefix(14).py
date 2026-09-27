'''Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.'''
class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        ans=""
        for i in range(len(strs[0])):
            c=strs[0][i] #to parse the first string,c is the characters of the first string
            for j in range(1,len(strs)):  #to compare with other words
                if i>=len(strs[j]) or strs[j][i]!=c: #if i goes beyond length of other word, or if the letter of the other word being compared is different. 
                    return ans
            ans+=c
        return ans