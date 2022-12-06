"""
Source: https://leetcode.com/problems/circular-sentence/
Date: 2022/12/6
Skill: 
Runtime: 39 ms, faster than 78.62% 
Memory Usage: 13.8 MB, less than 60.14%
Time complexity: 
Space complexity: 
Constraints: 
    
"""

class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        words = sentence.split(' ')
        for i in range(len(words) - 1):
            if words[i][-1] != words[i + 1][0]:
                return False
        
        if words[-1][-1] != words[0][0]:
            return False
        
        return True