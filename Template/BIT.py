class BIT:
    def __init__(self, n):
        self.n = n
        self.arr = [0 for _ in range(n + 1)]

    def update_delta(self, idx, delta):
        while idx <= self.n:
            self.arr[idx] += delta
            idx += idx & (-idx)

    def query_presum(self, idx):
        res = 0
        while idx > 0:
            res += self.arr[idx]
            idx -= idx & (-idx)
        return res

    def sum_range(self, left, right):
        return self.query_presum(right) - self.query_presum(left - 1)
