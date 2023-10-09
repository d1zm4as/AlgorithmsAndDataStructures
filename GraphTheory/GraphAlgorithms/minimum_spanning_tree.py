"""
Minimum spanning tree(MST) é um subset de arestas que conectam todas as vértices juntas sem ciclos com o minumo de distância possível.

O algoritmo de Prim é similar com o de Dijkstra a diferença é que o último seleciona o o vértice que o caminho mais curto do nó inicial, enquanto o prim seleciona o destino com o caminho mais curto.


"""

# ex

def minimum_spanning_tree(graph, source):
    priority_que = PriorityQue(vertex_count)
    vertex_list = graph.get_vertex_list()
    vertex_in_tree = 0
    current_vertex_index = source.get_index()
    while vertex_in_tree < len(vertex_list) - 1:
        current_vertex = vertex_list[current_vertex_index]
        current_vertex.set_in_tree()
        vertex_in_tree += 1
        neighbours = graph.get_neighbours(current_vertex)
        for neighbour in neighbours:
            if not neighbour.is_in_tree():
                distance = graph.get_distance(current_vertex, neighbour)
                edge = priority_que.get_edge_for(neighbour)
                if edge is not None:
                    old_distance = edge.get_distance()
                    is_new_edge_shorter = old_distance > distance
                    if is_new_edge_shorter:
                        shorter_edge = Edge(current_vertex, neighbour, distance)
                        priority_que.replace(edge, shorter_edge)
                else:
                    edge = Edge(current_vertex, neighbour, distance)
                    priority_que.insert(edge)
        if priority_que.is_empty():
            return
        edge = priority_que.delete_min()
        current_vertex_index = edge.get_destination_vertex().get_index()
        print(f"{edge} ", end="")
