"""
Source: https://leetcode.com/problems/longest-repeating-character-replacement/
Date: 2023/3/18
Skill:
Runtime: 200 ms, faster than 24.30%
Memory Usage: 13.8 MB, less than 90.11%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        left, right, sz, cnt, res = 0, 0, len(s), [0 for _ in range(26)], 0
        cnt[ord(s[0]) - ord("A")] = 1

        while right < sz:
            while right < sz and (right - left + 1) - max(cnt) <= k:
                right += 1
                if right < sz:
                    cnt[ord(s[right]) - ord("A")] += 1
            res = max(res, right - left)
            cnt[ord(s[left]) - ord("A")] -= 1
            left += 1

        return res


if __name__ == "__main__":
    s = Solution()
