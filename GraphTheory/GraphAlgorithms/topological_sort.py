"""
Topological sort (Kahn's algorithm). Works on DAGs.
Input: adjacency list as dict {node: [neighbors]}.
Output: list with a valid topological order.
"""

def topological_sort(graph):
    in_degree = {node: 0 for node in graph}
    for node, neighbors in graph.items():
        for neighbor in neighbors:
            if neighbor not in in_degree:
                in_degree[neighbor] = 0
            in_degree[neighbor] += 1

    queue = [node for node, degree in in_degree.items() if degree == 0]
    order = []

    while queue:
        node = queue.pop(0)
        order.append(node)
        for neighbor in graph.get(node, []):
            in_degree[neighbor] -= 1
            if in_degree[neighbor] == 0:
                queue.append(neighbor)

    if len(order) != len(in_degree):
        return None
    return order


if __name__ == "__main__":
    graph = {
        "A": ["C"],
        "B": ["C", "D"],
        "C": ["E"],
        "D": ["F"],
        "E": ["H", "F"],
        "F": ["G"],
        "G": [],
        "H": []
    }

    order = topological_sort(graph)
    if order is None:
        print("Graph has a cycle")
    else:
        print("Topological order:")
        print(order)
