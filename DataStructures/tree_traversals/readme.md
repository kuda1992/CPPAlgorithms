# Binary Search Tree
Is a tree in which all nodes to the left of the tree are less than the root node and all the nodes to the right of the tree are greater than the root node

## Basic Operations 

1. Search 
2. Insert 
3. Contains
4. Pre-Order Traversal 
5. In-Order Traversal
6. Post-Order Traversal
7. Remove

### Search Operation 
The search operation allows to search for an existing element in the binary search tree. The operations start at the root node where you check if the element being searched for is the equal to the root node. If the element is not equal to the root node you check the element is left than the root node or element is greater than the root node. If the element is greater than the root node traverse to the right node else if the element is less than the root node traverse to the left node. Do this recursively or iteratively until you reach to the leaf node. If you reach the leaf node without an element matched the element doesn't exist in the tree. 

#### Pseudo Code 
    
    search(int data) {
       node *current = root;
       
       while(current && current->data != data) {
            // go to the left 
            if(data < current->data) {
                current = current->left;
                continue;
            } else if(data > current->data) {
                // go to the right
                current = current->right;
                continue;
            }
            
            current = null;
            break;     
       }
       
       return current; 
    }
    