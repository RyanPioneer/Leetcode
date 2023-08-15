"""
Source: https://rb.gy/nd7kf
Date: 2023/8/15
Skill:
Ref:
Runtime: 326 ms, faster than 48.19%
Memory Usage: 18.88 MB, less than 39.86%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 10 ** 5
    s consists of uppercase English letters only.
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def uniqueLetterString(self, s: str) -> int:
        prev_num, char2pos, sz, res = [], defaultdict(), len(s), 0
        after_num = [sz - i for i in range(sz)]
        for i in range(sz):
            if s[i] in char2pos:
                prev_num.append(i - char2pos[s[i]])
                after_num[char2pos[s[i]]] = i - char2pos[s[i]]
            else:
                prev_num.append(i + 1)
            char2pos[s[i]] = i

        for i in range(sz):
            res += prev_num[i] * after_num[i]
        return res


if __name__ == "__main__":
    s = Solution()

