/**
 * Source: t.ly/DBw28
 * Date: 2023/11/6
 * Skill:
 * Runtime: 269 ms, faster than 94.55% of C++ online submissions
 * Memory Usage: 142.29 MB, less than 92.54% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class SeatManager {
    priority_queue<int, vector<int>, greater<>> pq;
    int start = 1;
public:
    SeatManager(int n) {
    }

    int reserve() {
        if (!pq.empty()) {
            int num = pq.top();
            pq.pop();
            return num;
        }
        return start++;
    }

    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */

int main() {

}