/**
 * Source: t.ly/KCS1f
 * Date: 2023/11/6
 * Skill:
 * Runtime: 453 ms, faster than 56.68% of C++ online submissions
 * Memory Usage: 188.58 MB, less than 41.71% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class NumberContainers {
    unordered_map<int, int> idx2num;
    unordered_map<int, set<int>> nums;
public:
    NumberContainers() {
    }

    void change(int index, int number) {
        if (idx2num.find(index) != idx2num.end()) {
            nums[idx2num[index]].erase(index);
        }
        idx2num[index] = number;
        nums[number].insert(index);
    }

    int find(int number) {
        if (nums[number].empty()) return -1;
        return *begin(nums[number]);
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

int main() {
}