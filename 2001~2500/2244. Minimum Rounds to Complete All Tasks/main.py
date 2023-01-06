"""
Source: https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/
Date: 2023/1/4
Skill:
Runtime: 2457 ms, faster than 35.58%
Memory Usage: 28.1 MB, less than 96.23%
Time complexity:
Space complexity:
Constraints:

"""

from typing import List, Optional
from collections import defaultdict

# Definition for singly-linked list.
class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        dict, res = defaultdict(int), 0
        for task in tasks:
            dict[task] += 1

        for level, num in dict.items():
            if num == 1: return -1
            if num%3 == 0: res += num//3
            elif num%3 == 1:
                res += (num-4)//3+2 if num != 4 else 2
            else:
                res += (num-2)//3+1

        return res




if __name__ == "__main__":
    s = Solution