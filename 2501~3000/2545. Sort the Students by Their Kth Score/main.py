"""
Source: https://leetcode.com/problems/sort-the-students-by-their-kth-score/
Date: 2023/1/22
Skill:
Runtime: 678 ms, faster than 64.71%
Memory Usage: 20.1 MB, less than 47.6%
Time complexity:
Space complexity:
Constraints:
    score consists of distinct integers.
    0 <= k < n
"""

from typing import List
from functools import lru_cache, cache

class Solution:
    def sortTheStudents(self, score: List[List[int]], k: int) -> List[List[int]]:
        score.sort(key=lambda x: -x[k])
        return score