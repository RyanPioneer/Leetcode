#define ll long long
const int MX = 1e5+7;


class BIT {
public:
    ll arr[MX] = {0};

    void update(int idx, ll num) {
        while (idx < MX) {
            arr[idx] += num;
            idx += idx & -idx;
        }
    }

    ll query_sum(int idx) {
        ll num = 0;
        while (idx > 0) {
            num += arr[idx];
            idx -= idx & -idx;
        }
        return num;
    }
};