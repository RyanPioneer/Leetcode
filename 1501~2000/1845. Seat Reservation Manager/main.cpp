/**
 * Source: t.ly/DBw28
 * Date: 2023/11/6
 * Skill:
 * Runtime: 489 ms, faster than 8.18% of C++ online submissions
 * Memory Usage: 190.93 MB, less than 8.32% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class SeatManager {
    set<int> seats;
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) seats.insert(i);
    }

    int reserve() {
        int seat = *seats.begin();
        seats.erase(seat);
        return seat;
    }

    void unreserve(int seatNumber) {
        seats.insert(seatNumber);
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