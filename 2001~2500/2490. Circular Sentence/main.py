"""
Source: https://leetcode.com/problems/circular-sentence/
Date: 2022/12/6
Skill: 
Runtime: 59 ms, faster than 41.14% 
Memory Usage: 13.9 MB, less than 12.12%
Time complexity: 
Space complexity: 
Constraints: 
    
"""

class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        cur, sz = 0, len(sentence)
        while cur < sz and sentence[cur] != ' ':
            cur += 1
        w = sentence[cur-1]
        for i in range(cur,sz):
            if sentence[i] == ' ':
                if w != sentence[i+1]:
                    return False
            elif i+1 < sz and sentence[i+1] == ' ':
                w = sentence[i]
        if sentence[0] == sentence[sz-1]:
            return True
        else:
            return False