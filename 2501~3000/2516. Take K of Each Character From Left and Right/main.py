"""
Source: https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/
Date: 2023/2/18
Skill:
Runtime: 340 ms, faster than 77.85%
Memory Usage: 14.9 MB, less than 59.37%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 10^5
    s consists of only the letters 'a', 'b', and 'c'.
    0 <= k <= s.length
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        left, right, sz, res = 0, 0, len(s), 0
        a_num, b_num, c_num = -k, -k, -k
        for i in range(sz):
            if s[i] == "a":
                a_num += 1
            elif s[i] == "b":
                b_num += 1
            else:
                c_num += 1

        if a_num < 0 or b_num < 0 or c_num < 0:
            return -1

        cur_a, cur_b, cur_c = 0, 0, 0
        for left in range(sz):
            while cur_a <= a_num and cur_b <= b_num and cur_c <= c_num:
                res = max(res, right - left)
                if right == sz:
                    return sz - res
                if s[right] == "a":
                    cur_a += 1
                elif s[right] == "b":
                    cur_b += 1
                else:
                    cur_c += 1
                right += 1

            if s[left] == "a":
                cur_a -= 1
            elif s[left] == "b":
                cur_b -= 1
            else:
                cur_c -= 1

        return sz - res


if __name__ == "__main__":
    s = Solution