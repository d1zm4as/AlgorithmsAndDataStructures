"""
Post-order traversal

É um método para visitar todos os nós de uma árvore binária, a ordem que os nodes da árvore é, os nós da sub-árvore a esquerda são visitados primeiro, depois a sub-árvore a direita e finalmente o nó em sí.


O algoritmo é particulamente útil para deletar uma árvore, porque o algoritmo se  encarrega de deletar os nós children antes do no root nodes. Em algoritmos como pre-order traversal ou in-order traversal, o algoritmo pode acabar deletando o nó pai antes do no filho , o que pode gerar vazamento de memória (em linguagens onde a memoria  é declarada de forma explícita, como no C ou C++, em linguagens como Python ou Java a operação de deleção é simples, basta atualizar o valor do no raiz para null e deixar que o garbage collector faz o resto )

"""

# Há duas formas de implementação

# 1 - Recursiva,a forma mais simples de implementação

# 2 - Interativa,o método que se assemelha a forma recursiva mas usa uma stack explícita e involve uma segunda stack para manter a ordem dos nós.



# 1

def recursive_post_order_traverse(root):
    if root is not None:
        recursive_post_order_traverse(root.left)
        recursive_post_order_traverse(root.right)
        root.visit()


# 2 


def iterative_post_order_traverse(root):
    if root is None:
        return 

    stack1  = []
    stack2  = []

    stack1.append(root)

    while stack1:
        node =stack1.pop()
        stack2.append(node)

        if node.left is not None:
            stack1.append(node.left)
        if node.right is not None:
            stack1.append(node.right)
    while stack2:
        stack2.pop().visit()