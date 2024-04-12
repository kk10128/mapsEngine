#include <graph.hpp> 
#include <sort.hpp> 
#include <disjoint_set.hpp>
#include <queue>

struct EdgeKeyComparison {
    constexpr bool operator()(const Edge &a, const Edge &b) const noexcept {
        return a.w > b.w;
    }
};

std::vector<Edge> constructMSTPrim(Graph G) {
    G.reset();
    G.setVisited(0); // T = { 0 }

    std::vector<Edge> MST;

    for (int i = 0; i < G.e[0].size(); ++i) 
    {
        int v = G.e[0][i].v;
        int w = G.e[0][i].w;
        G.distance(v) = w; // distance[v] = w;
        G.setTrace(v, 0); // parent[v] = 0;
    }

    for (int i = 1; i <= G.n - 1; ++i) 
    {
        int u, minDistance = INT_MAX;
        for (int i = 0; i < G.n; ++i) 
            if (G.isVisited(i) == false && G.distance(i) < minDistance)
                u = i, minDistance = G.distance(i);
        G.setVisited(u);
        MST.push_back(Edge(u, G.trace(u), G.distance(u)));
        for (int i = 0; i < G.e[u].size(); ++i) 
        {
            int v = G.e[u][i].v;
            int w = G.e[u][i].w;
            if (w < G.distance(v) && G.isVisited(v) == false) {
                G.distance(v) = w;
                G.setTrace(v, u);
            }
        }
    }

    return MST; 


}

