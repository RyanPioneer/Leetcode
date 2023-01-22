"""
Source: https://leetcode.com/problems/palindrome-partitioning/
Date: 2023/1/22
Skill: Backtracking with Dynamic Programming
Runtime: 784 ms, faster than 44.72%
Memory Usage: 37.7 MB, less than 5.29%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 16
    s contains only lowercase English letters.
"""

from typing import List
from functools import lru_cache, cache

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        dp, sz = [[0 for _ in range(len(s))] for _ in range(len(s))], len(s)
        for i in range(sz): dp[i][i] = 1
        for i in range(sz-1):
            if s[i] == s[i+1]:
                dp[i][i+1] = 1
        for length in range(3, sz+1):
            for i in range(sz-length+1):
                if s[i] == s[i+length-1] and dp[i+1][i+length-2]:
                    dp[i][i+length-1] = 1

        def dfs(index):
            if index == sz: return [[]]
            res = []
            for i in range(index, sz):
                if dp[index][i]:
                    for next_res in dfs(i+1):
                        res.append([s[index:i+1]]+next_res)
            return res

        return dfs(0)