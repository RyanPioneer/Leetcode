"""
Source: t.ly/VhvYg
Date: 2023/9/26
Skill:
Runtime: 33 ms, faster than 100%
Memory Usage: 16.3 MB, less than 25%
Time complexity:
Space complexity:
Constraints:

"""

import math
import sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
from functools import cache


class Solution:
    def countAnagrams(self, s: str) -> int:
        res, sz, idx, mod = 1, len(s), 0, 1e9+7
        while idx < sz:
            num, cnt = 0, [0 for _ in range(26)]
            while s[idx] != ' ':
                num += 1
                cnt[s[idx] - 'a'] += 1
                idx += 1
            res *= math.factorial(num)
            for i in range(26):
                if cnt[i] > 1:
                    res /= math.factorial(cnt[i])
            idx += 1
        return res % mod


if __name__ == "__main__":
    s = Solution()
