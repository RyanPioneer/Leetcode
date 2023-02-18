"""
Source: https://leetcode.com/problems/decode-the-message/
Date: 2023/2/18
Skill:
Runtime: 37 ms, faster than 61.59%
Memory Usage: 13.9 MB, less than 31.91%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def decodeMessage(self, key: str, message: str) -> str:
        i, idx, sz, key2value, res = 0, 0, len(key), defaultdict(), ""
        while i < sz:
            if key[i] != " ":
                if key[i] not in key2value:
                    key2value[key[i]] = chr(ord("a")+idx)
                    idx += 1
            i += 1

        for i in range(len(message)):
            if message[i] != " ":
                res += key2value[message[i]]
            else:
                res += " "

        return res


if __name__ == "__main__":
    s = Solution