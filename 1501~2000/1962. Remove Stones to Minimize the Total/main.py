"""
Source: https://leetcode.com/problems/remove-stones-to-minimize-the-total/
Date: 2022/12/28
Skill: Greedy + Max Heap
Runtime: 1791 ms, faster than 94.34%
Memory Usage: 28.6 MB, less than 67.75%
Time complexity:
Space complexity:
Constraints:
    1 <= piles[i] <= 10^4
"""

from typing import List, Optional
import heapq

class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        heap = [-num for num in piles]
        heapq.heapify(heap)
        for _ in range(k):
            cur = -heapq.heappop(heap)
            remove = cur//2
            heapq.heappush(heap, -(cur-remove))

        return  -sum(heap)

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    print('PyCharm')

# See PyCharm help at https://www.jetbrains.com/help/pycharm/





