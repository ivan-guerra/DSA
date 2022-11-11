#include <gtest/gtest.h>

#include "graph.h"

class GraphTest : public ::testing::Test {
   protected:
    const int kDefaultNumVertices = 16;

    void InitSearchGraph();
    void SetUp() final;

    data_structures::Graph<int> empty_graph_;
    data_structures::Graph<int> fully_connected_graph_;
    data_structures::Graph<int> search_graph_;
};
