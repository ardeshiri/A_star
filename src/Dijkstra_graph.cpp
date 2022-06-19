#include "Dijkstra_graph.h"


    dijk_g::dijk_g(std::initializer_list<std::pair<std::pair<node, node>, size_t>> il)
    {
        std::for_each(std::begin(il), std::end(il), [this](const auto& ftw){ nodes[ftw.first.first.id] = ftw.first.first; nodes[ftw.first.second.id] = ftw.first.second;});
        std::for_each(std::begin(il), std::end(il), [this](const auto& ftw){ nodes[ftw.first.first.id].connections.emplace_back(&nodes[ftw.first.second.id], ftw.second);});
    }


    void dijk_g::calculate_from_to(const std::string& from_id, const std::string& to_id )
    {
        nodes[from_id].weight = 0;
        std::transform(std::begin(nodes), std::end(nodes), std::back_inserter(heap), [](auto& n){ return &n.second;});
        std::make_heap(std::begin(heap), std::end(heap), node_greater);
        calculate_until(to_id);
    }


    std::vector<std::pair<std::string, size_t>> dijk_g::trace_back_from(const std::string& dest)
    {
        std::vector<std::pair<std::string, size_t>> res{};
        for(auto id = dest; id != ""; id = nodes[id].prev)
        {
            if(nodes[id].weight.has_value() && nodes[nodes[id].prev].weight.has_value())
            {
                res.emplace_back(nodes[id].prev, nodes[id].weight.value() - nodes[nodes[id].prev].weight.value());
            }
        }
        return res;
    }


    bool dijk_g::node_greater(const node* a, const node* b)
    {
        if(!b->weight.has_value())
        {
            return false;
        }
        else if(!a->weight.has_value())
        {
            return true;
        }
        else
        {
            return (a->weight.value() > b->weight.value());
        }
    }


    void dijk_g::update_neighbors(node* top)
    {
        for(const auto& [np, sz]: top->connections)
        {
            if(!np->weight.has_value() || np->weight.value() > top->weight.value() + sz )
            {
                np->weight = top->weight.value() + sz;
                np->prev = top->id;
            }
        }
    }


    void dijk_g::calculate_until(const std::string& dest)
    {
        while(!heap.empty())
        {
            std::pop_heap(std::begin(heap), std::end(heap), node_greater);
            auto top = heap.back();
            if(top->id == dest)
            {
                return;
            }
            heap.pop_back();

            update_neighbors(top);
            std::make_heap(std::begin(heap), std::end(heap), node_greater);
        }
    }
