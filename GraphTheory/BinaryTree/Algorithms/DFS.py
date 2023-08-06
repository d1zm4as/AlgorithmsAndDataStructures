

# Deapht First Search(DFS) é um algoritmo de travessia de grafo que começa de um nó e visita todas as vértices do grafo. O  algoritmo visita um nó e depois os nós vizinhos do nó de forma recursiva até chegar no fim do caminho após isso ele volta até o último nó visitado e continua a traversia de la.



from collections import defaultdict

# classe do grafo
class Graph:

	# Construtor
	def __init__(self):

		# um dicionário para guardar o gráfico
		self.graph = defaultdict(list)

	
    # função para adicionar uma  aresta(conexão)
	def addEdge(self, u, v):
		self.graph[u].append(v)

	
	# A função do DSF
	def DFSUtil(self, v, visited):

		# marcando o no atual como visitado e printando
		visited.add(v)
		print(v, end=' ')

		# percorrendo todos os vértices adjacentes do vertice atual
		for neighbour in self.graph[v]:
			if neighbour not in visited:
				self.DFSUtil(neighbour, visited)

	
	
	def DFS(self, v):

		
		visited = set()

		# criando a chamada recursiva da busca
		self.DFSUtil(v, visited)



if __name__ == "__main__":
	g = Graph()
	g.addEdge(0, 1)
	g.addEdge(0, 2)
	g.addEdge(1, 2)
	g.addEdge(2, 0)
	g.addEdge(2, 3)
	g.addEdge(3, 3)

	
	
	g.DFS(2)




