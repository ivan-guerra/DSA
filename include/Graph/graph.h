#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <algorithm>
#include <cstddef>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace data_structures {
template <typename T>
class Graph {
   public:
    Graph() : num_edges_(0) {}
    ~Graph() = default;

    Graph(const Graph&) = default;
    Graph& operator=(const Graph&) = default;

    Graph(Graph&&) = default;
    Graph& operator=(Graph&&) = default;

    std::size_t VertexCount() const { return nodes_.size(); }
    std::size_t EdgeCount() const { return num_edges_; }
    bool Empty() const { return nodes_.empty(); }

    bool AddEdge(const T& src, const T& dst);
    bool RemoveEdge(const T& src, const T& dst);

    bool DoesPathExistDfs(const T& src, const T& dst);
    bool DoesPathExistBfs(const T& src, const T& dst);

   private:
    using AdjList = std::unordered_map<T, std::vector<T>>;

    AdjList nodes_;
    std::size_t num_edges_;
};

template <typename T>
bool Graph<T>::AddEdge(const T& src, const T& dst) {
    /* Avoid adding duplicate edges. */
    if (std::find(nodes_[src].begin(), nodes_[src].end(), dst) !=
        nodes_[src].end()) {
        return false;
    }

    nodes_[src].push_back(dst);
    num_edges_++;

    /* Insert the destination node if does not already exist in the graph. */
    if (nodes_.find(dst) == nodes_.end())
        nodes_.insert({dst, std::vector<T>()});

    return true;
}

template <typename T>
bool Graph<T>::RemoveEdge(const T& src, const T& dst) {
    /* If the src/dst vertex doesn't exist, then the edge definitely doesn't. */
    if ((nodes_.find(src) == nodes_.end()) ||
        (nodes_.find(dst) == nodes_.end())) {
        return false;
    }

    /* Make sure an edge from src -> dst actually exists. */
    auto del_node = std::find(nodes_[src].begin(), nodes_[src].end(), dst);
    if (del_node == nodes_[src].end()) return false;

    nodes_[src].erase(del_node);
    num_edges_--;

    return true;
}

template <typename T>
bool Graph<T>::DoesPathExistDfs(const T& src, const T& dst) {
    std::unordered_set<T> visited;
    std::stack<T> pending;

    pending.push(src);
    while (!pending.empty()) {
        T curr = pending.top();
        pending.pop();
        visited.insert(curr);

        for (const auto& neighbor : nodes_[curr]) {
            /* Already seen this node. */
            if (visited.find(neighbor) != visited.end()) continue;

            /* Found the terminating node. */
            if (neighbor == dst) return true;

            pending.push(neighbor);
        }
    }
    return false;
}

template <typename T>
bool Graph<T>::DoesPathExistBfs(const T& src, const T& dst) {
    std::unordered_set<T> visited;
    std::queue<T> pending;

    pending.push(src);
    while (!pending.empty()) {
        T curr = pending.front();
        pending.pop();
        visited.insert(curr);

        for (const auto& neighbor : nodes_[curr]) {
            /* Already seen this node. */
            if (visited.find(neighbor) != visited.end()) continue;

            /* Found the terminating node. */
            if (neighbor == dst) return true;

            pending.push(neighbor);
        }
    }
    return false;
}

}  // namespace data_structures

#endif
