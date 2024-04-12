#include <graph.hpp> 
#include <sort.hpp> 
#include <disjoint_set.hpp>

std::vector<Edge> constructMSTKruskal(Graph G) {
    std::vector<Edge> edges = G.exportEdges(); // Graph's edges
    DisjointSet T(G.n); 

    sort(edges, 0, edges.size() - 1); 

    std::vector<Edge> MST = {};
    
    for(Edge edge : edges)
    {
    	if(!T.isOnSameSet(edge.u, edge.v)) 
    	{
    		MST.push_back(edge); 
    		T.join(edge.u, edge.v);
   
    	}
    }
    return MST; 
}

