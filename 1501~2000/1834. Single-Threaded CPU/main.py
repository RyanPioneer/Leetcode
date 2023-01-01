"""
Source: https://leetcode.com/problems/single-threaded-cpu/
Date: 2022/12/29
Skill:
Runtime: 1884 ms, faster than 99.18%
Memory Usage: 63.1 MB, less than 33.28%
Time complexity:
Space complexity:
Constraints:
    tasks.length == n
    1 <= n <= 10^5
    1 <= enqueueTimei, processingTimei <= 10^9
"""

from typing import List, Optional
import heapq

class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        tasks = sorted([(task[0], task[1], index) for index, task in enumerate(tasks)])
        res, time, h, index, sz = [], tasks[0][0], [], 0, len(tasks)
        while len(res) < sz:
            while index < sz and tasks[index][0] <= time:
                heapq.heappush(h, (tasks[index][1], tasks[index][2]))  # (processing_time, original_index)
                index += 1
            if h:
                processing_time, original_index = heapq.heappop(h)
                res.append(original_index)
                time += processing_time
            elif index < sz:
                time = tasks[index][0]

        return res


# if __name__ == "__main__":