"""
Source: https://leetcode.com/problems/remove-palindromic-subsequences/
Date: 2023/2/18
Skill: We can delete all characters 'a' in the 1st operation,
        and then all characters 'b' in the 2nd operation.
        So return 2 in this case
Ref: https://reurl.cc/ml9539
Runtime: 34 ms, faster than 52.29%
Memory Usage: 13.8 MB, less than 43.89%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 1000
    s[i] is either 'a' or 'b'.
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def removePalindromeSub(self, s: str) -> int:
        return 2 - (s == s[::-1]) - (s == "")


if __name__ == "__main__":
    s = Solution