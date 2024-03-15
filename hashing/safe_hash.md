Standard `unordered_map` or `unordered_set` can be easily hacked due to the hardcoded prime numbers into the standard library.

- https://codeforces.com/blog/entry/62393
- https://codeforces.com/blog/entry/60737
- https://usaco.guide/gold/hashmaps?lang=cpp
- http://xorshift.di.unimi.it/splitmix64.c

The $1^{\text{st}}$ definitions of `safe_map` and `safe_set` are type aliases of the standard containers with improved hash function.

The $2^{\text{nd}}$ pair are alternative presumably faster GNU-specific containers with similar interface.

- https://gcc.gnu.org/onlinedocs/libstdc++/ext/pb_ds/gp_hash_table.html
