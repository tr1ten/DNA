// value a a a b b b c c c
// index 0 1 2 3 4 5 6 7 8
// bound       l     u
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
	int operator()(int x) const { return x ^ RANDOM; }
};
template<class K,class V> using ht = gp_hash_table<
		K,
		null_type,
		hash<K>,
		equal_to<K>,
		direct_mask_range_hashing<>,
		linear_probe_fn<>,
		hash_standard_resize_policy<
			hash_exponential_size_policy<>,
			hash_load_check_resize_trigger<>,
			true
		>
>;

int main() {
	ht<int,null_type> g; g.resize(5);
    g.insert(1);
    g[1] = 2;
	cout << g.get_actual_size() << "\n"; // 8
	cout << g.size() << "\n"; // 0
}

// int main(int argc, char const *argv[])
// {
//     // lower_bound - first element eq or greator than x
//     // upper_bound - first el greator than x
//     auto cmp = [](int a, int b)
//     { return 1;};
//     std::set<int, decltype(cmp)> s;
//     return 0;
// }

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_map<long long, int, custom_hash> safe_map;