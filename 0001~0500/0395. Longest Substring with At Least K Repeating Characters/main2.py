"""
Source: https://rb.gy/3v7p2
Date: 2023/7/30
Skill:
Ref:
Runtime: 42 ms, faster than 97.51%
Memory Usage: 16.44 MB, less than 61.17%
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
        sz, res, freq, flag, idx = len(s), 0, defaultdict(int), True, 0
        for c in s:
            freq[c] += 1
        for c in s:
            if freq[c] < k:
                flag = False
                break
        if flag:
            return sz

        while idx < sz:
            if freq[s[idx]] < k:
                idx += 1
                continue
            left = idx
            while idx < sz and freq[s[idx]] >= k:
                idx += 1
            res = max(res, self.longestSubstring(s[left: idx], k))
            idx += 1

        return res


if __name__ == "__main__":
    s = Solution()
    res = s.longestSubstring("aaabb", 3)
    print(res)
