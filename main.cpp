#include <bits/stdc++.h>
#define array vector
#define map unordered_map
using namespace std;

// @author: Thawan Ribeiro, 2024-03-14
// @problem: 1408 - Name (X)
// @url: https://github.com/thawan-xyz

class Graph {
private:
    const int VERTICES;
    int edges;
    array<map<int, int>> list;
    array<bool> marked;

    void depth_first_search(int v, array<int>& result) {
        set_mark(v); result.push_back(v);

        int w = get_first_adjacent(v);
        while (w < VERTICES) {
            if (!is_marked(w)) depth_first_search(w, result);
            w = get_next_adjacent(v, w);
        }
    }

    void breadth_first_search(int v, array<int>& result) {
        queue<int> queue; queue.push(v);

        set_mark(v);
        while (!queue.empty()) {
            v = queue.front(); queue.pop(); result.push_back(v);

            int w = get_first_adjacent(v);
            while (w < VERTICES) {
                if (!is_marked(w)) {
                    set_mark(w); queue.push(w);
                }
                w = get_next_adjacent(v, w);
            }
        }
    }

public:
    Graph(const int n) : VERTICES(n), edges(0), list(n, map<int, int>()), marked(n, false) {}

    ~Graph() = default;

    void set_edge(const int v, const int w, const int x = 1) {
        if (!has_edge(v, w)) edges++;
        list[v][w] = x;
    }

    void del_edge(const int v, const int w) {
        if (has_edge(v, w)) edges--;
        list[v].erase(w);
    }

    bool has_edge(const int v, const int w) const {
        if (list[v].count(w) != 0) return true;

        return false;
    }

    int get_weight(const int v, const int w) const {
        if (has_edge(v, w)) return list[v].at(w);

        return 0;
    }

    int get_first_adjacent(const int v) const {
        for (int w = 0; w < VERTICES; ++w) {
            if (has_edge(v, w)) return w;
        }

        return VERTICES;
    }

    int get_next_adjacent(const int v, const int p) const {
        for (int w = p + 1; w < VERTICES; ++w) {
            if (has_edge(v, w)) return w;
        }

        return VERTICES;
    }

    int get_last_adjacent(const int v) const {
        for (int w = VERTICES - 1; w > -1; --w) {
            if (has_edge(v, w)) return w;
        }

        return VERTICES;
    }

    void set_mark(const int v) {
        marked[v] = true;
    }

    void del_mark(const int v) {
        marked[v] = false;
    }

    bool is_marked(const int v) const {
        return marked[v];
    }

    int num_vertices() const {
        return VERTICES;
    }

    int num_edges() const {
        return edges;
    }

    array<int> dfs_traversal() {
        array<int> result;

        marked.assign(VERTICES, false);
        for (int v = 0; v < VERTICES; ++v) {
            if (!is_marked(v)) depth_first_search(v, result);
        }

        return result;
    }

    array<int> bfs_traversal() {
        array<int> result;

        marked.assign(VERTICES, false);
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
