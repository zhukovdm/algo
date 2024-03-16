#include <memory>
#include <string>
#include <vector>

class Trie {
private:
    static const char BASE = 'a';
    static const std::size_t SIZE = 26;

    template <std::size_t N>
    class Node {
    public:
        bool term_;
        std::vector<std::unique_ptr<Node>> edges_;

        Node() : term_(false), edges_(N, nullptr)
        {
        }

        auto add(int idx) -> Node * /* observer */
        {
            return (edges_[idx] != nullptr) ? edges_[idx] : (edges_[idx] = new Node());
        }
    };

    std::unique_ptr<Node<SIZE>> root_;

public:
    Trie() : root_(new Node<SIZE>()) /* proper init! */
    {
    }

    auto insert(const std::string &word) -> void
    {
        auto node = root_.get();

        for (auto &&l : word) {
            node = node->add((int)l - (int)BASE);
        }
        node->term_ = true;
    }

    auto search(const std::string &word) -> bool
    {
        auto node = root_.get();

        for (auto const &l : word) {
            node = node->edges_[(int)l - (int)BASE].get();
            if (node == nullptr) {
                return false;
            }
        }
        return node->term_;
    }

    auto starts_with(const std::string &prefix) -> bool
    {
        auto node = root_.get();

        for (auto const &l : prefix) {
            node = node->edges_[(int)l - (int)BASE].get();
            if (node == nullptr) {
                return false;
            }
        }
        return true;
    }
};
