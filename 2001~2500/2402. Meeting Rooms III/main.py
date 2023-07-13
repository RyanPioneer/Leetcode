"""
Source: https://rb.gy/zgo1q
Date: 2023/7/12
Skill:
Ref:
Runtime: 1598 ms, faster than 62.24%
Memory Usage: 62.6 MB, less than 82.57%
Time complexity:
Space complexity:
Constraints:

"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        used, free, sz = [], [i for i in range(n)], len(meetings)
        heapify(used)
        heapify(free)
        meetings.sort(key=lambda x: x[0])
        cnt, res = [0 for _ in range(n)], 0
        for i in range(sz):
            while used and used[0][0] <= meetings[i][0]:
                _, room_number = heappop(used)
                heappush(free, room_number)
            if free:
                room = heappop(free)
                cnt[room] += 1
                heappush(used, [meetings[i][1], room])
            else:
                time, room = heappop(used)
                cnt[room] += 1
                heappush(used, [time + (meetings[i][1] - meetings[i][0]), room])

        for i in range(1, n):
            if cnt[i] > cnt[res]:
                res = i
        return res


if __name__ == "__main__":
    s = Solution()
