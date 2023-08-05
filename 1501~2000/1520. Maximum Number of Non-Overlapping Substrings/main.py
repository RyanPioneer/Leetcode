"""
Source: https://rb.gy/7vur3
Date: 2023/8/4
Skill:
Ref:
Runtime: 580 ms, faster than 55.22%
Memory Usage: 17.66 MB, less than 97.01%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 10 ** 5
"""

import math
import sys
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def maxNumOfSubstrings(self, s: str) -> List[str]:
        start, end, sz, res = [-1 for _ in range(26)], [-1 for _ in range(26)], len(s), []
        for i in range(sz):
            if start[ord(s[i]) - ord("a")] == -1:
                start[ord(s[i]) - ord("a")] = i
            if end[ord(s[sz - 1 - i]) - ord("a")] == -1:
                end[ord(s[sz - 1 - i]) - ord("a")] = sz - 1 - i

        intervals = []
        for i in range(26):
            if start[i] == -1:
                continue
            left, right, flag = start[i] + 1, end[i], True
            while left < right:
                if start[ord(s[left]) - ord("a")] < start[i]:
                    flag = False
                    break
                right = max(right, end[ord(s[left]) - ord("a")])
                left += 1
            if flag:
                intervals.append([start[i], right])

        intervals.sort(key=lambda x: x[1] - x[0], reverse=True)
        remove_intervals = [False for _ in range(len(intervals))]
        for i in range(len(intervals)):
            for j in range(i + 1, len(intervals)):
                if intervals[i][0] < intervals[j][0] and intervals[i][1] > intervals[j][1]:
                    remove_intervals[i] = True
                    break

        for i in range(len(intervals)):
            if remove_intervals[i]:
                continue
            res.append(s[intervals[i][0]: intervals[i][1] + 1])

        return res


if __name__ == "__main__":
    s = Solution()
