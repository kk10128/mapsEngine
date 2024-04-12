#include <graph.hpp>
#include <queue>

struct EdgeKeyComparison {
    constexpr bool operator()(const Edge &a, const Edge &b) const noexcept {
        return a.w > b.w;
    }
};

std::vector<int> searchShortestPath(Graph &G, int start, int destination) {
    
    G.reset();
    G.distance(start) = 0;

    for (int i = 1; i <= G.n - 1; ++i) 
    {
        int u, minDistance = INT_MAX;
        for (int i = 0; i < G.n; ++i) 
        {
            if (G.isVisited(i) == false && G.distance(i) < minDistance)
            {
                u = i, minDistance = G.distance(i);
            }
        }
        G.setVisited(u);

        for (int i = 0; i < G.e[u].size(); ++i) 
        {
            int v = G.e[u][i].v;
            int w = G.e[u][i].w;
            if (G.distance(u) + w < G.distance(v) && G.isVisited(v) == false) {
                G.distance(v) = G.distance(u) + w;
                G.setTrace(v, u);
            }
        }
    }

    std::vector<int> path;
    int u = destination;
    while (u != -1) 
    {
    	path.push_back(u);
    	u = G.trace(u);
    }

    std::reverse(path.begin(), path.end());

    return path;

}

