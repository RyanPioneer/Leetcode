/**
 * Source: t.ly/Rt_rU
 * Date: 2023/11/7
 * Skill:
 * Runtime: 906 ms, faster than 75.32% of C++ online submissions
 * Memory Usage: 406.20 MB, less than 61.04% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


const int MX = 1e4+1;

typedef pair<int, int> pairs;

class MovieRentingSystem {
    map<pairs, int> movie2price;
    set<pairs> movies[MX];
    set<tuple<int, int, int>> totalmovies;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e: entries) {
            movie2price[{e[0], e[1]}] = e[2];
            movies[e[1]].insert({e[2], e[0]});
        }
    }

    vector<int> search(int movie) {
        vector<int> res;
        int i = 0;
        for (auto iter = movies[movie].begin(); iter != movies[movie].end() && i < 5; iter = next(iter), i++) {
            res.push_back(iter->second);
        }
        return res;
    }

    void rent(int shop, int movie) {
        int price = movie2price[{shop, movie}];
        totalmovies.insert({price, shop, movie});
        movies[movie].erase({price, shop});
    }

    void drop(int shop, int movie) {
        int price = movie2price[{shop, movie}];
        totalmovies.erase({price, shop, movie});
        movies[movie].insert({price, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;
        int i = 0;
        for (auto iter = totalmovies.begin(); iter != totalmovies.end() && i < 5; iter = next(iter), i++) {
            auto [price, shop, movie] = *iter;
            res.push_back({shop, movie});
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */


int main() {

}