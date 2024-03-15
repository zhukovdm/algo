#include "safe_hash.hpp"
#include <iostream>

using namespace std;

auto main(int argc, char **argv) -> int
{
    safe_map<int, int> map;
    map.insert({1, 1});

    safe_set<int> set;
    set.insert(1);

    for (auto &&[f, s] : map) {
        cout << f << ' ' << s << '\n';
    }

    return 0;
}
