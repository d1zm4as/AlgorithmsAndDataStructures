"""
existem trẽs casos:

1 - o nó não tem filhos, nesse caso o no é simplesmente excluido

2 - o nó tem apenas um filho, nesse caso o no sera substituido pelo filho

3 - o no tem dois filhos, nesse caso o no sera substituido pelo no mais a esquerda da sub-arvore a direita



"""


class Node:
    left  = None
    right = None

    def __init__(self,key):
        self.key = key
    
    def delete(self,key):
        if self.root is None:
            print("ta vazia")
        return

        # começa a busca
        del_node = self.root
        parent = None

        while del_node is not None and del_node.key != key:
            parent  = del_node
            if del_node.key <key:
                del_node = del_node.right
            else:
                del_node = del_node.left
        
        if del_node is None:
            print("Node não esta na arvore")
            return

        

        is_root = del_node ==self.root
        is_left_child = not is_root and parent.key >key

        # caso 1

        if del_node.left is None and del_node.right is None:
            if is_root:
                self.root = None
            elif is_left_child:
                parent.left = None
            else:
                parent.right = None
        
        #  caso 2

        elif del_node.left is None or del_node.right is None:
            child = del_node.left if(del_node.left is not None)else del_node.right
            if is_root:
                self.root = child

            else:
                if is_left_child:
                    parent.left = child
                else:
                    parent.right = child

        # caso 3
        # procurando o no mais a esquerda do filho direito do nó alvo
        else:

            successor = del_node.right
            successor_parent = del_node

            while successor.left is not Node:
                successor_parent = successor
                successor = successor.left
            
            if successor != del_node.right:
                successor_parent.left = successor.right
                successor.right = del_node.right

            successor.left = del_node.left

            if is_root:
                self.root = successor
            elif is_left_child:
                parent.left = successor
            else:
                parent.right = successor



































