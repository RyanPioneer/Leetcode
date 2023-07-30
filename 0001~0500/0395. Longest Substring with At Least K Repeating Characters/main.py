"""
Source: https://rb.gy/3v7p2
Date: 2023/7/30
Skill:
Ref:
Runtime: 150 ms, faster than 46.59%
Memory Usage: 16.41 MB, less than 61.17%
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
    def longestSubstring(self, s: str, k: int) -> int:
        sz, res, freq = len(s), 0, [0 for _ in range(26)]

        def helper(num):
            nonlocal res
            char_set, char_freq, right, count = set(), defaultdict(int), 0, 0
            for i in range(sz):
                while right < sz and (len(char_set) < num or s[right] in char_set):
                    char_set.add(s[right])
                    char_freq[s[right]] += 1
                    if char_freq[s[right]] == k:
                        count += 1
                    right += 1
                if count == len(char_set):
                    res = max(res, right - i)
                char_freq[s[i]] -= 1
                if char_freq[s[i]] == k - 1:
                    count -= 1
                if char_freq[s[i]] == 0:
                    char_set.remove(s[i])

        for i in range(1, 27):
            helper(i)
        return res


if __name__ == "__main__":
    s = Solution()
