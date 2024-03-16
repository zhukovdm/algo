#include "dsu.hpp"
#include <iostream>

auto main(int, char **) -> int
{
    dsu d(7);

    // d.unite(0, 2);
    // d.unite(1, 2);
    // d.unite(3, 5);
    // d.unite(4, 5);
    // d.unite(2, 6);
    // d.unite(5, 6);

    d.unite(0, 1);
    d.unite(1, 2);
    d.unite(2, 3);
    d.unite(3, 4);
    d.unite(4, 5);
    d.unite(5, 6);

    d.find(1);

    return 0;
}
