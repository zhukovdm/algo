#include <utility>
#include <vector>

class dsu {
private:
    std::vector<int> comps_;

public:
    dsu(int size) : comps_(size, -1)
    {
    }

    auto find(int v) -> int
    {
        return comps_[v] < 0 ? v : (comps_[v] = find(comps_[v]));
    }

    auto size(int v) -> int
    {
        return -comps_[find(v)];
    }

    auto are_same(int u, int v) -> bool
    {
        return find(u) == find(v);
    }

    auto unite(int u, int v) -> bool
    {
        u = find(u);
        v = find(v);
        if (u == v) {
            return false;
        }
        if (comps_[u] > comps_[v]) {
            std::swap(u, v);
        }
        comps_[u] += comps_[v];
        comps_[v] = u;
        return true;
    }
};
