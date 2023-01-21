"""
Source: https://leetcode.com/problems/k-closest-points-to-origin/
Date: 2023/1/21
Skill: QuickSelect
Runtime: 854 ms, faster than 67.7%
Memory Usage: 24.9 MB, less than 5.12%
Time complexity:
Space complexity:
Constraints:
    1 <= k <= points.length <= 10^4
"""

from typing import List
from collections import defaultdict

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        arr, sz, res = [], len(points), []
        for i in range(sz):
            arr.append([points[i][0] * points[i][0] + points[i][1] * points[i][1], i])

        def quickselect(front, end, num):
            a, b, c, pivot = front, end, front, arr[(front + end) // 2][0]
            while c <= b:
                if arr[c][0] < pivot:
                    arr[a], arr[c] = arr[c], arr[a]
                    a += 1
                    c += 1
                elif arr[c][0] > pivot:
                    arr[b], arr[c] = arr[c], arr[b]
                    b -= 1
                else:
                    c += 1

            if a - front > num:
                quickselect(front, a - 1, num)
            elif b - front + 1 >= num:
                return
            else:
                quickselect(b+1, end, num - (b - front + 1))

        quickselect(0, sz - 1, k)
        for i in range(k):
            res.append(points[arr[i][1]])

        return res

if __name__ == "__main__":
    s = Solution
    points = [[0,1],[1,0]]
    k = 2
    res = s.kClosest(s, points, k)
    for i in res:
        print(i[0])
        print(i[1])