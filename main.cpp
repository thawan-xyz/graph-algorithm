#include <bits/stdc++.h>
#define array vector
#define map unordered_map
using namespace std;

// @author: Thawan Ribeiro, 2024-03-14
// @algorithm: Graph for Competitive Programming
// @url: https://github.com/thawan-xyz

class Graph {
private:
    const int VERTICES; int edges;
    array<map<int, int>> adjacency; array<bool> marked;

    int get_first_adjacent(int v) const {
        for (int w = 0; w < VERTICES; ++w) {
            if (has_edge(v, w)) return w;
        }
        return VERTICES;
    }

    int get_next_adjacent(int v, int p) const {
        for (int w = p + 1; w < VERTICES; ++w) {
            if (has_edge(v, w)) return w;
        }
        return VERTICES;
    }

    int get_last_adjacent(int v) const {
        for (int w = VERTICES - 1; w >= 0; --w) {
            if (has_edge(v, w)) return w;
        }
        return VERTICES;
    }

    bool is_marked(int v) const {
        return marked[v];
    }

    void set_mark(int v, bool b = true) {
        marked[v] = b;
    }

    void depth_first_search(int v, array<int>& result) {
        result.push_back(v); set_mark(v);

        int w = get_first_adjacent(v);
        while (w < VERTICES) {
            if (!is_marked(w)) depth_first_search(w, result);
            w = get_next_adjacent(v, w);
        }
    }

    void breadth_first_search(int v, array<int>& result) {
        queue<int> trail; trail.push(v); set_mark(v);

        while (!trail.empty()) {
            v = trail.front(); trail.pop(); result.push_back(v);

            int w = get_first_adjacent(v);
            while (w < VERTICES) {
                if (!is_marked(w)) {
                    trail.push(w); set_mark(w);
                }
                w = get_next_adjacent(v, w);
            }
        }
    }

public:
    Graph(const int N) : VERTICES(N), edges(0), adjacency(N), marked(N) {}

    ~Graph() = default;

    bool has_edge(int v, int w) const {
        return adjacency[v].count(w);
    }

    void set_edge(int v, int w, int x = 1) {
        if (!has_edge(v, w)) edges++;

        adjacency[v][w] = x;
    }

    void del_edge(int v, int w) {
        if (has_edge(v, w)) edges--;

        adjacency[v].erase(w);
    }

    int get_weight(int v, int w) const {
        if (!has_edge(v, w)) return 0;

        return adjacency[v].at(w);
    }

    int num_vertices() const {
        return VERTICES;
    }

    int num_edges() const {
        return edges;
    }

    array<int> dfs_traversal() {
        array<int> result; marked.assign(VERTICES, false);
        for (int v = 0; v < VERTICES; ++v) {
            if (!is_marked(v)) depth_first_search(v, result);
        }
        return result;
    }

    array<int> bfs_traversal() {
        array<int> result; marked.assign(VERTICES, false);
        for (int v = 0; v < VERTICES; ++v) {
            if (!is_marked(v)) breadth_first_search(v, result);
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
