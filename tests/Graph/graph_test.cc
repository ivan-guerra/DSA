#include <gtest/gtest.h>

#include "graph_test_fixture.h"

TEST_F(GraphTest, ShouldReturnZeroVertexCount) {
    EXPECT_EQ(empty_graph_.VertexCount(), 0);
}

TEST_F(GraphTest, ShouldReturnNumOfUniqueVertices) {
    EXPECT_EQ(fully_connected_graph_.VertexCount(), kDefaultNumVertices);
}

TEST_F(GraphTest, ShouldReturnZeroEdgeCount) {
    EXPECT_EQ(empty_graph_.EdgeCount(), 0);
}

TEST_F(GraphTest, ShouldReturnFullyConnectedGraphEdgeCount) {
    EXPECT_EQ(fully_connected_graph_.EdgeCount(),
              kDefaultNumVertices * (kDefaultNumVertices - 1));
}

TEST_F(GraphTest, ShouldReturnTrueOnEmptyGraph) {
    EXPECT_TRUE(empty_graph_.Empty());
}

TEST_F(GraphTest, ShouldReturnFalseOnNonEmptyGraph) {
    EXPECT_FALSE(fully_connected_graph_.Empty());
}

TEST_F(GraphTest, ShouldReturnTrueWhenAddingNonExistingEdge) {
    ASSERT_TRUE(empty_graph_.AddEdge(0, 1));
    ASSERT_FALSE(empty_graph_.Empty());
    ASSERT_EQ(empty_graph_.VertexCount(), 2);
    ASSERT_EQ(empty_graph_.EdgeCount(), 1);
}

TEST_F(GraphTest, ShouldReturnFalseWhenAttemptingToAddingExistingEdge) {
    EXPECT_FALSE(fully_connected_graph_.AddEdge(0, 1));
}

TEST_F(GraphTest, ShouldReturnFalseWhenAttemptingToDeleteNonExistingEdge) {
    EXPECT_FALSE(empty_graph_.RemoveEdge(0, 1));
}

TEST_F(GraphTest, ShouldReturnTrueWhenAttemptingToDeleteExistingEdge) {
    for (int i = 0; i < kDefaultNumVertices; ++i) {
        for (int j = 0; j < kDefaultNumVertices; ++j) {
            if (i != j) {
                ASSERT_TRUE(fully_connected_graph_.RemoveEdge(i, j));
            }
        }
    }
    ASSERT_FALSE(fully_connected_graph_.Empty());
    ASSERT_EQ(fully_connected_graph_.VertexCount(), kDefaultNumVertices);
    ASSERT_EQ(fully_connected_graph_.EdgeCount(), 0);
}

TEST_F(GraphTest, ShouldReturnTrueForExistingPathViaDfs) {
    EXPECT_TRUE(search_graph_.DoesPathExistDfs(0, 5));
}

TEST_F(GraphTest, ShouldReturnFalseorNonExistingPathViaDfs) {
    EXPECT_FALSE(search_graph_.DoesPathExistDfs(0, 6));
}

TEST_F(GraphTest, ShouldReturnTrueForExistingPathViaBfs) {
    EXPECT_TRUE(search_graph_.DoesPathExistBfs(0, 5));
}

TEST_F(GraphTest, ShouldReturnFalseorNonExistingPathViaBfs) {
    EXPECT_FALSE(search_graph_.DoesPathExistBfs(0, 6));
}
