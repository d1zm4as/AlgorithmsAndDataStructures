"""
Breadth First Search(BFS), é um algoritmo básico de busca usado para explorar nodes e edges de um gráfico, particulamente útil para achar o caminho mais curto de um grafo sem pesos. A ideia do algortimo é visitar todos os nós do nível atual antes de ir para o proximo nivel.


"""

def breadth_first_traversal(graph, start_vertex):
    i = graph.get_vertexes().index(start_vertex)
    if  i == -1:
        print("nao tem")
        return


    queue = []
    start_vertex.visit()
    queue.append(start_vertex)
    while not len(queue) == 0:
        vertex   = queue.pop(0)
        while True: 
            adj_vertex = graph.get_univisited_adj_vertex(vertex)
            if adj_vertex is None:
                break
            adj_vertex.visit()
            queue.append(adj_vertex)
