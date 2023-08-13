"""
Source: https://rb.gy/symgh
Date: 2023/8/13
Skill:
Ref:
Runtime: 6719 ms, faster than 11.76%
Memory Usage: 3619 MB, less than 94.12%
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
    def maximumScore(self, nums: List[int], k: int) -> int:
        def eratosthenes(num):
            prime_score = [0 for _ in range(num + 1)]
            for i in range(2, num + 1):
                if prime_score[i] > 0:
                    continue
                prime_score[i] = 1
                j = i * 2
                while j <= num:
                    prime_score[j] += 1
                    j += i
            return prime_score

        prime_score_for_nums, mod, sz, res = eratosthenes(max(nums)), 10 ** 9 + 7, len(nums), 1

        def power(n, x):
            if x == 0:
                return 1
            elif x == 1:
                return n
            else:
                if x % 2:
                    rem = n
                else:
                    rem = 1
                return power(n * n % mod, x // 2) * rem

        prime_score = []
        for i in range(sz):
            prime_score.append(prime_score_for_nums[nums[i]])

        prime_score.append(sys.maxsize)
        smaller_after, stack = [0 for _ in range(sz)], [sz]
        for i in range(sz - 1, -1, -1):
            while stack and prime_score[stack[-1]] <= prime_score[i]:
                stack.pop()
            smaller_after[i] = stack[-1] - i - 1
            stack.append(i)

        prime_score.insert(0, sys.maxsize)
        smaller_before, stack = [0 for _ in range(sz)], [0]
        for i in range(1, sz + 1):
            while stack and prime_score[stack[-1]] < prime_score[i]:
                stack.pop()
            smaller_before[i - 1] = i - stack[-1] - 1
            stack.append(i)

        num_list, idx = [[nums[i], i] for i in range(sz)], 0
        num_list.sort(reverse=True)
        while k > 0 and idx < sz:
            num, cnt = num_list[idx][0], (smaller_after[num_list[idx][1]] + 1) * (smaller_before[num_list[idx][1]] + 1)
            res *= power(num, min(k, cnt))
            res %= mod
            k -= min(k, cnt)
            idx += 1
        return res % mod


if __name__ == "__main__":
    s = Solution()
    nums, k = [1, 7, 11, 1, 5], 14
    res = s.maximumScore(nums, k)
    print(res)
