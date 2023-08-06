"""
O algoritmo de inserção faz o seguintem se a raiz(root) for Null então a arvore está vazia e o node inserido se tornanara o root,caso contrário começando da raiz o valor será inserido a esquerda ou a direita se for maior que determinado no pai


"""

class Node:
    left = None
    right = None

    def __init__(self,key):
        self.key = key

    def insert(self,key):
        node = Node(key)
        if self.root is None:
            self.root = node
        else:
            current = self.root
            parent = None
            # buscando pelo nó pai
            while current is not None:
                parent = current
                if node.key <current.key:
                    current = current.left
                elif node.key >current.key:
                    current = current.right
                else:
                    print("falha na inserção")
                return 
            if node.key < parent.key:
                parent.left = node            else:
                parent.right = node