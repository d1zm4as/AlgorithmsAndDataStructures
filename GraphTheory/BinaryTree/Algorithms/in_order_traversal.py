"""
É um algoritmo que processa a arvóre binaria de uma forma especifica

o algoritmo visita primeiramente todos os nos da sub-arvore a esquerda, depois visitta o nó em si e finalmento os nós da sub-arvore a esquerda


pode ser implementado de duas formas

"""

# de forma recursiva em ordem de travessia

def recursive_in_order_traverse(node):
    if node is None:
        return 

    # percorrendo de maneira recursiva a sub-arvore da esquerda
    recursive_in_order_traverse(node.left)
    node.visit()

    # percorrendo de maneira recursiva a sub-arvore da direita
    recursive_in_order_traverse(node.right)
    node.visit()


#  de forma interativa em ordem de traverssia


def recursive_in_order_traverse(root):
    if root is None:
        return 
    
    stack = []

    node = root

    while stack or node is not None:
        if node is not None:
            # adiciona o node na pilha
            # para o seu filho a esquerda
            stack.append(node)
            node = node.left
        else:
            # se o node for nulo, elemine-o da pilha 
            # visite-o e move para o filho a direita
            
            node = stack.pop()
            node = visit()
            node = node.right


"""
A forma iterativa em ordem tem um pouco mais de complexidade em comparação a forma pre-ordem, isso porque a forma de traversia em ordem precisa visitar a sub-arvore a esquerda antes de visitar o raiz da sub-arvore a direita

"""

















