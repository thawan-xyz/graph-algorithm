#include <bits/stdc++.h>
#define array vector
#define umap unordered_map
using namespace std;

// @author: Thawan Ribeiro, 2024-03-14
// @algorithm: Graph for Competitive Programming
// @url: https://github.com/thawan-xyz

class Graph {
private:
    const int VERTICES; int edges;
    array<umap<int, int>> adjacency; array<bool> marked;

    bool is_marked(int x) const {
        return marked[x];
    }

    void set_mark(int x, bool m = true) {
        marked[x] = m;
    }

    void depth_first_search(int x, array<int>& result) {
        result.push_back(x); set_mark(x);

        for (auto [y, w] : adjacency[x]) {
            if (!is_marked(y)) depth_first_search(y, result);
        }
    }

    void breadth_first_search(int x, array<int>& result) {
        queue<int> trail; trail.push(x); set_mark(x);

        while (!trail.empty()) {
            x = trail.front(); trail.pop(); result.push_back(x);

            for (auto [y, w] : adjacency[x]) {
                if (!is_marked(y)) {
                    trail.push(y); set_mark(y);
                }
            }
        }
    }

public:
    Graph(const int N) : VERTICES(N), edges(0), adjacency(N), marked(N) {}

    ~Graph() = default;

    bool has_edge(int x, int y) const {
        return adjacency[x].count(y);
    }

    void set_edge(int x, int y, int w = 1) {
        if (!has_edge(x, y)) edges++;

        adjacency[x][y] = w;
    }

    void del_edge(int x, int y) {
        if (has_edge(x, y)) edges--;

        adjacency[x].erase(y);
    }

    int get_weight(int x, int y) const {
        if (!has_edge(x, y)) return 0;

        return adjacency[x].at(y);
    }

    int num_vertices() const {
        return VERTICES;
    }

    int num_edges() const {
        return edges;
    }

    array<int> dfs_traversal() {
        array<int> result; marked.assign(VERTICES, false);

        for (int x = 0; x < VERTICES; ++x) {
            if (!is_marked(x)) depth_first_search(x, result);
        }

        return result;
    }

    array<int> bfs_traversal() {
        array<int> result; marked.assign(VERTICES, false);

        for (int x = 0; x < VERTICES; ++x) {
            if (!is_marked(x)) breadth_first_search(x, result);
        }

        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cerr << "Thawan";
    return 0;
}
