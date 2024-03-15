#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>

class safe_hash {
public:
    static auto splitmix64(uint64_t x) -> uint64_t
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    auto operator()(uint64_t x) const -> std::size_t // !
    {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// template <typename K, typename V>
// using safe_map = std::unordered_map<K, V, safe_hash>;

// template <typename V>
// using safe_set = std::unordered_set<V, safe_hash>;

template <typename K, typename V>
using safe_map = __gnu_pbds::gp_hash_table<K, V, safe_hash>;

template <typename V>
using safe_set = __gnu_pbds::gp_hash_table<V, __gnu_pbds::null_type, safe_hash>;
