"""
Source: https://leetcode.com/problems/flip-string-to-monotone-increasing/
Date: 2023/1/17
Skill: Dynamic Programming
Ref:
Runtime: 123 ms, faster than 94.55%
Memory Usage: 15 MB, less than 72.76%
Time complexity:
Space complexity:
Constraints:

"""

from typing import List, Optional
from collections import defaultdict

class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        res, num_of_one = 0, 0
        for letter in s:
            if letter == "1": num_of_one += 1
            else: res = min(res+1, num_of_one) # flip letter, not flip letter but flip all the before 1's

        return res