'''
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false'''
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        sorteds=sorted(s) #makes the string sorted, but separates the letters.
        sortedt=sorted(t)
        joineds="".join(sorteds) #to join the separated letters
        joinedt="".join(sortedt)
        return joineds==joinedt