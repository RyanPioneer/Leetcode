"""
Source: https://leetcode.com/problems/sort-characters-by-frequency/
Date: 2022/12/3
Skill: 
Runtime: 43 ms, faster than 94.70%
Memory Usage: 15.2 MB, less than 98.50%
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
        arr = [[c, freq] for c, freq in cnt.items()]
        arr.sort(key=lambda x:-x[1])  # sort in decreasing order by frequency
        ans = []
        for c, freq in arr:
            ans.append(c*freq)
        return "".join(ans)