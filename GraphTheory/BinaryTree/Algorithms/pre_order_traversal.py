"""

Traversia pre-ordem é algoritmo para visitar todos nos de uma arvore binária,

o algoritmo primeiramente visita o no pai(root), depois de forma recursiva visita todos os nos da sub-arvore a esquerda e finalmente todos os nós das sub-arvores a direita.

Ha duas formas de implementar a traverssia pre-ordem de uma arvore binaria

1 - A forma recursiva- Essa implementação usa uma pilha para manter  a ordem de nodes que faltam visitar, mas essa abordagem pode gerar transbordagem da pilha se a árvore for muito grande/profunda

"""

# class Node:
#     def __init__(self,key):
#         self.key = key
#         self.left = None
#         self.right = None

#     def visit(self):
#         print(self.key, end = " ")


#     def recursive_pre_order_traverse(node):
#         if node is None:
#             return 
#         node.visit()

#         recursive_pre_order_traverse(node.left)
#         recursive_pre_order_traverse(node.right)

"""
2 - A forma interativa -  Essa abordagem também usa uma pilha(de maneira explicita) para manter a ordem dos nodes que faltam visitar, embora a implementação seja um mais complexa, ela consegue cuidar de arvores de todos os tamanhos
"""
class Node:
    def __init__(self,key):
        self.key = key
        self.left = None
        self.right = None

    def visit(self):
        print(self.key, end = " ")


    def recursive_pre_order_traverse(node):
        if node is None:
            return 
        stack = [node]
        
        while stack:
            # retirando o item do topo da pilha
            node = stack.pop()

            node.visit()
            # adicionando o filho da esquerda e da direita do no
            if node.right is not None:
                stack.append(node.right)        
            if node.left is not None:
                stack.append(node.left)    
"""
Ambas as formas visitam os nos da mesma maneira,a escolha de implementação vai depender dos requerimentos da aplicação e caracteristicas das arvores.


A complexidade de tempo de ambas as implementações é O(n), isso porque todos os nos sao visitados apenas uma vez.



















"""