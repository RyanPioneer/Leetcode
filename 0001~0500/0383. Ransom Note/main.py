"""
Source: https://leetcode.com/problems/ransom-note/
Date: 2023/3/17
Skill:
Runtime: 41 ms, faster than 90.84%
Memory Usage: 14.1 MB, less than 89.58%
Time complexity:
Space complexity:
Constraints:
    1 <= ransomNote.length, magazine.length <= 10^5
    ransomNote and magazine consist of lowercase English letters.
"""

import math
import random
from typing import List, Optional
from collections import defaultdict, deque, Counter
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools
from sortedcontainers import SortedList


class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        cnt = Counter(magazine)
        for w in ransomNote:
            if cnt[w] == 0:
                return False
            cnt[w] -= 1

        return True


if __name__ == "__main__":
    s = Solution()
