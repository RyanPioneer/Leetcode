"""
Source: https://leetcode.com/problems/decode-string/
Date: 2023/3/18
Skill:
Runtime: 39 ms, faster than 15.70%
Memory Usage: 13.9 MB, less than 59.31%
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
    def decodeString(self, s: str) -> str:
        num, string, idx, sz, cur_str = [], [], 0, len(s), ""
        while idx < sz:
            if s[idx].isnumeric():
                number = s[idx]
                while idx+1 < sz and s[idx+1].isnumeric():
                    idx += 1
                    number += s[idx]
                idx += 1
                num.append(int(number))
                string.append(cur_str)
                cur_str = ""
            elif s[idx] == "]":
                prev = string.pop()
                t = num.pop()
                temp = cur_str
                for i in range(t-1):
                    cur_str += temp
                cur_str = prev + cur_str
            else:
                cur_str += s[idx]
            idx += 1

        return cur_str


if __name__ == "__main__":
    s = Solution()
