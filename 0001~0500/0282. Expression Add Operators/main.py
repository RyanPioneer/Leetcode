"""
Source: https://leetcode.com/problems/expression-add-operators/
Date: 2023/4/4
Skill:
Runtime: 741 ms, faster than 91.6%
Memory Usage: 14.7 MB, less than 34.64%
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


class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        sz, res = len(num), []

        def back_tracking(cur_pos, cur_string, prev_val, cur_val):
            if cur_pos == sz:
                if cur_val == target:
                    res.append(cur_string)
                return
            for i in range(cur_pos + 1, sz + 1):
                if num[cur_pos] == "0" and i > cur_pos + 1:
                    return
                val = int(num[cur_pos:i])
                if cur_pos == 0:
                    back_tracking(i, num[cur_pos:i], val, val)
                else:
                    back_tracking(i, cur_string + "+" + num[cur_pos:i], val, cur_val + val)
                    back_tracking(i, cur_string + "-" + num[cur_pos:i], -val, cur_val - val)
                    back_tracking(i, cur_string + "*" + num[cur_pos:i], prev_val * val, cur_val - prev_val + prev_val * val)

        back_tracking(0, "", 0, 0)
        return res


if __name__ == "__main__":
    s = Solution()
