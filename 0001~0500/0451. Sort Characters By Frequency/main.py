"""
Source: https://leetcode.com/problems/sort-characters-by-frequency/
Date: 2022/12/3
Skill: 
Runtime: 135 ms, faster than 22.21%
Memory Usage: 16.2 MB, less than 27.43%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= s.length <= 5 * 10^5
    s consists of uppercase and lowercase English letters and digits.
"""

class Solution:
    def frequencySort(self, s: str) -> str:
        d = dict()
        for w in s:
            if w in d:
                d[w] += 1
            else:
                d[w] = 1
                
        od = dict(sorted(d.items(), key=lambda item: item[1], reverse=True)) # lambda function
        
        vec = []
        
        for key, value in od.items():
            for i in range(value):
                vec.append(key)
        
        return ''.join(vec)