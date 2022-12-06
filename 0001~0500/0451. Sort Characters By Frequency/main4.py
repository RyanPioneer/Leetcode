"""
Source: https://leetcode.com/problems/sort-characters-by-frequency/
Date: 2022/12/3
Skill: Counting sort
Runtime: 161 ms, faster than 14.61%
Memory Usage: 23.8 MB, less than 7.96%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= s.length <= 5 * 10^5
    s consists of uppercase and lowercase English letters and digits.
"""

from collections import Counter

class Solution:
    def frequencySort(self, s: str) -> str:
        cnt = Counter(s)
        n = len(s)
        bucket = [[] for _ in range(n+1)]
        for c, freq in cnt.items():
            bucket[freq].append(c)
        res = []
        for freq in range(n,-1,-1):
            for i in bucket[freq]:
                res.append(i*freq)
        return ''.join(res)