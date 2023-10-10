"""
O algoritmo de Dijkstra é um algoritmo para achar o caminho mais curto entre as vértices de um grafo. O algoritmo deve ser aplicado para grafos de pesos não negativos.

O algoritmo guarda as distâncias dos vértices, a cada passo o algoritmo selectiona de vértices ainda não processados, qual a distância mínima desse vértice para os seus vizinhos

Para encontrar um vértice não processado pode ser usado uma stack de prioridades, onde os vértice que faltam podem ser armazenados, organizados em ordem decrescente de distância.


No caso mais simples, onde o stack de prioridades é implementado (usando um array) e o grafo pode ser especificado usando uma matrix adjacente, o tempo de execução do algoritmo é O(n²) sendo n o número de vértices.


Se a stack de prioridades for baseada numa Fibonacci heap e o gráfico pode ser especificado usando uma lista de adjacencia, o tempo de execução é O(n log n+m), onde m é o numero de arestas do grafo

"""


#  ex

def dijkstra_algorithm(graph, source):
    distance_from_source_dict = dict()
    previous_vertex_dict = dict()
    que = PriorityQue(vertex_count)
    vertex_list = graph.get_vertex_list()
    for v in vertex_list:
        if v != source:
            distance_from_source_dict[v] = WeightedDirectedGraph.INFINITY
        else:
            distance_from_source_dict[v] = 0
        previous_vertex_dict[v] = None
        que.insert(v, distance_from_source_dict[v])
    while not que.is_empty():
        u = que.delete_min()
        neighbours = graph.get_neighbours(u)
        for v in neighbours:
            new_dist = distance_from_source_dict[u] + graph.get_distance(u, v)
            if new_dist < distance_from_source_dict[v]:
                que.update_distance(v, new_dist)
                distance_from_source_dict[v] = new_dist
                previous_vertex_dict[v] = u
    return ShortestPath(source, distance_from_source_dict, previous_vertex_dict)
