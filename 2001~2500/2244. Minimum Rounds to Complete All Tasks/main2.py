"""
Source: https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/
Date: 2023/1/4
Skill:
Runtime: 2212 ms, faster than 43.61%
Memory Usage: 28.5 MB, less than 44.10%
Time complexity:
Space complexity:
Constraints:

"""

from typing import List, Optional
from collections import defaultdict, Counter

# Definition for singly-linked list.
class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        freqs = Counter(tasks)
        res = 0
        for task, freq in freqs.items():
            if freq == 1:
                return -1
            res += (freq + 2) // 3
        return res


if __name__ == "__main__":
    s = Solution