#include "debug.hpp"

auto main(int, char **) -> int
{
    using namespace std;

    int i = 42;
    string s = "abc";
    pair<int, string> p(1, string("2"));
    tuple<int, string, int> t{1, "2", 3};
    vector<int> v{1, 2, 3, 4, 5, 6, 7};

    debug(i, s, p, t, v);

    return 0;
}
