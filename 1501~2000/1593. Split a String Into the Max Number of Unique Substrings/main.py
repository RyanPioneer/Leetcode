"""
Source: https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/
Date: 2023/4/16
Skill: dfs
Ref:
Runtime: 305 ms, faster than 53.5%
Memory Usage: 14 MB, less than 15.49%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 16
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        string_set, sz, res = set(), len(s), 0

        def dfs(cur_idx):
            nonlocal string_set, sz, res
            if cur_idx == sz:
                res = max(res, len(string_set))
                return
            for next_pos in range(cur_idx + 1, sz + 1):
                if s[cur_idx: next_pos] not in string_set:
                    string_set.add(s[cur_idx: next_pos])
                    dfs(next_pos)
                    string_set.remove(s[cur_idx: next_pos])

        dfs(0)
        return res


if __name__ == "__main__":
    s = Solution()
