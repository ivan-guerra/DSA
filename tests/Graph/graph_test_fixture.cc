#include "graph_test_fixture.h"

void GraphTest::InitSearchGraph() {
    /* See https://www.guru99.com/breadth-first-search-bfs-graph-example.html
       or a visualization of the search graph. */
    search_graph_.AddEdge(0, 1);
    search_graph_.AddEdge(0, 2);

    search_graph_.AddEdge(1, 0);
    search_graph_.AddEdge(1, 2);
    search_graph_.AddEdge(1, 3);
    search_graph_.AddEdge(1, 4);

    search_graph_.AddEdge(2, 0);
    search_graph_.AddEdge(2, 1);
    search_graph_.AddEdge(2, 3);
    search_graph_.AddEdge(2, 5);

    search_graph_.AddEdge(3, 1);
    search_graph_.AddEdge(3, 2);
    search_graph_.AddEdge(3, 4);
    search_graph_.AddEdge(3, 5);

    search_graph_.AddEdge(4, 1);
    search_graph_.AddEdge(4, 3);

    search_graph_.AddEdge(5, 2);
    search_graph_.AddEdge(5, 3);
}

void GraphTest::SetUp() {
    for (int i = 0; i < kDefaultNumVertices; ++i) {
        for (int j = 0; j < kDefaultNumVertices; ++j) {
            if (i != j) fully_connected_graph_.AddEdge(i, j);
        }
    }

    InitSearchGraph();
}
