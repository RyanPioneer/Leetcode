"""
Source: https://leetcode.com/problems/minimum-window-substring/description/
Date: 2023/2/4
Skill: Sliding Window
Runtime: 134 ms, faster than 75.43%
Memory Usage: 14.7 MB, less than 77.65%
Time complexity:
Space complexity:
Constraints:
    s and t consist of uppercase and lowercase English letters.
"""

import math
from typing import List
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(s) < len(t): return ""
        cur_nums, target, need, zero = [0 for _ in range(52)], [0 for _ in range(52)], [0 for _ in range(52)], [0 for _ in range(52)]
        start, tail, res, sz = 0, 0, "", len(s)
        for i in range(len(t)):
            if ord(t[i]) >= ord("a"):
                target[26+ord(t[i])-ord("a")] += 1
                need[26 + ord(t[i]) - ord("a")] += 1
            else:
                target[ord(t[i]) - ord("A")] += 1
                need[ord(t[i]) - ord("A")] += 1

        while tail < sz:
            if ord(s[tail]) >= ord("a"):
                cur_char = 26 + ord(s[tail]) - ord("a")
            else:
                cur_char = ord(s[tail]) - ord("A")

            cur_nums[cur_char] += 1
            if need[cur_char] > 0:
                need[cur_char] -= 1
                if need == zero:
                    while True:
                        if ord(s[start]) >= ord("a"):
                            cur_char = 26 + ord(s[start]) - ord("a")
                        else:
                            cur_char = ord(s[start]) - ord("A")
                        if cur_nums[cur_char] > target[cur_char]:
                            cur_nums[cur_char] -= 1
                            start += 1
                        else:
                            break

                    break

            tail += 1

        if tail < sz:
            res = s[start:tail + 1]

        while tail+1 < sz:
            tail += 1
            if ord(s[tail]) >= ord("a"):
                cur_char = 26 + ord(s[tail]) - ord("a")
            else:
                cur_char = ord(s[tail]) - ord("A")

            cur_nums[cur_char] += 1
            if s[tail] == s[start]:
                while True:
                    if ord(s[start]) >= ord("a"):
                        cur_char = 26 + ord(s[start]) - ord("a")
                    else:
                        cur_char = ord(s[start]) - ord("A")
                    if cur_nums[cur_char] > target[cur_char]:
                        cur_nums[cur_char] -= 1
                        start += 1
                    else:
                        break

                if len(s[start:tail+1]) < len(res):
                    res = s[start:tail+1]

        return res

if __name__ == "__main__":
    s = Solution
    res = s.minWindow(s, "ADOBECODEBANC", "ABC")