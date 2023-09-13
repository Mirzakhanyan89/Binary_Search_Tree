/*	Main_Test_BST.cpp	*/

#include "BST.h"  

int main() {
    // Create a BST instance and insert some values
    BST bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(8);
    bst.insert(13);
    bst.insert(7);
    bst.insert(9);
    bst.insert(12);

    // Test search	
    BST::Node* foundNode = bst.search(8);
    if (foundNode) {
        std::cout << "Found node with value 8." << std::endl;
    } else {
        std::cout << "Node with value 8 not found." << std::endl;
    }

    // Test minimum value
    int minVal = bst.get_min();
    std::cout << "Minimum value in the BST: " << minVal << std::endl;

    // Test maximum value
    int maxVal = bst.get_max();
    std::cout << "Maximum value in the BST: " << maxVal << std::endl;

    // Test height			
    int height = bst.get_height();
 	std::cout << "Height of the BST: " << height << std::endl;

    // Test successor
    BST::Node* successorNode = bst.successor(8);
    if (successorNode) {
        std::cout << "Successor of 8: " << successorNode->value << std::endl;
    } else {
        std::cout << "No successor for 8." << std::endl;
    }

    // Test predecessor
    BST::Node* predecessorNode = bst.predecessor(8);
    if (predecessorNode) {
        std::cout << "Predecessor of 8: " << predecessorNode->value << std::endl;
    } else {
        std::cout << "No predecessor for 8." << std::endl;
    }

    // Test delete_node
    int keyToDelete = 8;
    BST::Node* deletedNode = bst.delete_node(bst.get_root(), keyToDelete);
    if (deletedNode) {
        std::cout << "Deleted node with value " << keyToDelete << std::endl;
    } else {
        std::cout << "Node with value " << keyToDelete << " not found for deletion." << std::endl;
    }

    // Test tree traversals
    std::cout << "In-order traversal: ";
    bst.inorder_traversal(bst.get_root());
    std::cout << std::endl;

    std::cout << "Pre-order traversal: ";
    bst.preorder_traversal(bst.get_root());
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    bst.postorder_traversal(bst.get_root());
    std::cout << std::endl;

    return 0;
}




