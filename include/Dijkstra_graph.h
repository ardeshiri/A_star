#ifndef DIJKSTRA_GRAPH_H
#define DIJKSTRA_GRAPH_H
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <optional>
#include <map>

struct dijk_g
{

    struct node
    {
        std::string id{};
        size_t added_weight{0};
        std::optional<size_t> weight{std::nullopt};
        std::vector<std::pair<node*, size_t>> connections{};
        std::string prev{};
    };

    dijk_g(std::initializer_list<std::pair<std::pair<node, node>, size_t>> il);

    void calculate_from_to(const std::string& from_id, const std::string& to_id = {} );

    std::vector<std::pair<std::string, size_t>> trace_back_from(const std::string& dest);


private:

    std::map<std::string, node> nodes{};
    std::vector<node*> heap{};

    static bool node_greater(const node* a, const node* b);

    void update_neighbors(node* top);

    void calculate_until(const std::string& dest = {});
};

#endif // DIJKSTRA_GRAPH_H
