"""
Source: https://leetcode.com/problems/buddy-strings/
Date: 2023/7/3
Skill:
Ref:
Runtime: 40 ms, faster than 94.59%
Memory Usage: 16.7 MB, less than 28.16%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        if len(s) != len(goal) or len(s) == 1:
            return False
        has_duplicate, diff, mydict = False, [], defaultdict(int)
        for i in range(len(s)):
            if s[i] in mydict:
                has_duplicate = True
            mydict[s[i]] += 1
            if s[i] != goal[i]:
                diff.append(i)
                if len(diff) > 2:
                    return False
        if (len(diff) == 0 and has_duplicate) or (len(diff) == 2 and
                s[diff[0]] == goal[diff[1]] and s[diff[1]] == goal[diff[0]]):
            return True
        return False


if __name__ == "__main__":
    s = Solution()
