"""
Kruskal's algorithm for Minimum Spanning Tree.
Graph as list of edges: (u, v, weight).
"""

class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, a, b):
        root_a = self.find(a)
        root_b = self.find(b)
        if root_a == root_b:
            return False
        if self.rank[root_a] < self.rank[root_b]:
            self.parent[root_a] = root_b
        elif self.rank[root_a] > self.rank[root_b]:
            self.parent[root_b] = root_a
        else:
            self.parent[root_b] = root_a
            self.rank[root_a] += 1
        return True


def kruskal_mst(num_vertices, edges):
    uf = UnionFind(num_vertices)
    mst = []
    total_weight = 0

    for u, v, w in sorted(edges, key=lambda x: x[2]):
        if uf.union(u, v):
            mst.append((u, v, w))
            total_weight += w
    return mst, total_weight


if __name__ == "__main__":
    edges = [
        (0, 1, 10),
        (0, 2, 6),
        (0, 3, 5),
        (1, 3, 15),
        (2, 3, 4)
    ]
    mst, weight = kruskal_mst(4, edges)
    print("MST edges:")
    print(mst)
    print("Total weight:")
    print(weight)
