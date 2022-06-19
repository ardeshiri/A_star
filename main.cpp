#include <iostream>
#include <vector>
#include <utility>
#include <optional>
#include <unordered_map>
#include <queue>
#include <map>
#include <tuple>
#include <functional>
#include <algorithm>
#include <initializer_list>
#include <Dijkstra_graph.h>

using namespace std;



int main()
{
    dijk_g::node s{.id="s", .added_weight=10};
    dijk_g::node a{.id="a", .added_weight=9};
    dijk_g::node b{.id="b", .added_weight=7};
    dijk_g::node c{.id="c", .added_weight=8};
    dijk_g::node d{.id="d", .added_weight=8};
    dijk_g::node e{.id="e", .added_weight=0};
    dijk_g::node f{.id="f", .added_weight=6};
    dijk_g::node g{.id="g", .added_weight=3};
    dijk_g::node h{.id="h", .added_weight=6};
    dijk_g::node i{.id="i", .added_weight=4};
    dijk_g::node j{.id="j", .added_weight=4};
    dijk_g::node k{.id="k", .added_weight=3};
    dijk_g::node l{.id="l", .added_weight=6};

    dijk_g dj{{{s,a}, 7}, {{s,b}, 2}, {{s,c}, 3},
              {{a,s}, 7}, {{a,b}, 3}, {{a,d}, 4},
              {{b,a}, 3}, {{b,s}, 2}, {{b,h}, 1}, {{b,d}, 4},
              {{c,s}, 3}, {{c,l}, 2},
              {{d,a}, 4}, {{d,b}, 4}, {{d,f}, 5},
              {{e,g}, 2}, {{e,k}, 5},
              {{f,d}, 5}, {{f,h}, 3},
              {{g,e}, 2}, {{g,h}, 2},
              {{h,b}, 1}, {{h,f}, 3}, {{h,g}, 2},
              {{i,l}, 4}, {{i,j}, 6}, {{i,k}, 4},
              {{j,l}, 4}, {{j,i}, 6}, {{j,k}, 4},
              {{k,i}, 4}, {{k,j}, 4}, {{k,e}, 5},
              {{l,i}, 4}, {{l,j}, 4}, {{l,c}, 2}
              };

    dj.calculate_from_to("s","e");

    auto res = dj.trace_back_from("e");
    for(auto [n,w]: res)
    {
        cout<<n<<"   "<<w<<endl;
    }
    return 0;
}
