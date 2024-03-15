#include <iostream>
#include <iterator>
#include <tuple>
#include <vector>

template <typename T>
auto to_string(const T &x) -> std::string
{
    return std::to_string(x);
}

auto to_string(const std::string &s) -> std::string
{
    return '"' + s + '"';
}

auto to_string(const char *s) -> std::string
{
    return to_string(std::string(s));
}

template <typename F, typename S>
auto to_string(const std::pair<F, S> &p) -> std::string
{
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A0, typename A1, typename A2>
auto to_string(const std::tuple<A0, A1, A2> &t) -> std::string
{
    return "(" + to_string(std::get<0>(t)) + ", " + to_string(std::get<1>(t)) + ", " + to_string(std::get<2>(t)) + ")";
}

template <typename T>
auto to_string(const std::vector<T> &v) -> std::string
{
    std::string res;
    res += '{';
    for (int i = 0; i < (int)v.size(); ++i) {
        res += ((i == 0) ? "" : ", ") + to_string(v[i]);
    }
    res += '}';
    return res;
}

auto debug_impl() -> void
{
    std::cerr << std::endl;
}

template <typename H, typename... T>
auto debug_impl(H &&h, T &&...t) -> void
{
    std::cerr << ' ' << to_string(h);
    debug_impl(t...);
}

#ifdef LOCAL
#define debug(...) std::cerr << "[" << #__VA_ARGS__ << "]:", debug_impl(__VA_ARGS__)
#else
#define debug(...) 42
#endif
