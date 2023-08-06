"""
Breadth First Search(BFS), é um algoritmo básico de busca usado para explorar nodes e edges de um gráfico, particulamente útil para achar o caminho mais curto de um grafo sem pesos. A ideia do algortimo é visitar todos os nós do nível atual antes de ir para o proximo nivel.


"""


def breadth_first_traversal(root):
    if root is not None:
        qeue = [root]
        while len(qeue)>0:
            node = qeue.pop(0)
            node.visit()
            if node.left is not None:
                qeue.append(node.left)
            if node.right is not None:
                qeue.append(node.right)
