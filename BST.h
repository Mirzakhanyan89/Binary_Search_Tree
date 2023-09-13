/*	BST.h	*/

#ifndef BST_H
#define BST_h

#include <iostream>
#include <algorithm>


class BST {
public:
	struct Node {
		Node* left;
		Node* right;
		int value;
		Node () : left{nullptr}, right{nullptr}, value{} { }
		Node (int value) : left(nullptr), right{nullptr}, value{value} { }
		Node (int value, Node* left) : left{left}, right{nullptr}, value{value} { }
		Node (int value, Node* left, Node* right) : left{left}, right{right}, value{value} { }
	};
public:
	BST() : root{nullptr} { }
	BST(int key) : root{new Node(key)} { }
	BST::Node* get_root() {return root; } 
	BST::Node* search(int key);
	int get_min();
	BST::Node* find_min_node(Node* node);
	int get_max();
	int get_height();
//	BST::Node* insert(int key);
	bool insert(int key);
	BST::Node* delete_node(Node* node, int key);	
	BST::Node* successor(int key);
	BST::Node* predecessor(int key);
	void preorder_traversal(Node* node);
	void inorder_traversal(Node* node);
	void postorder_traversal(Node* node);
private:
	Node* root;
	BST::Node* search_helper(Node* node, int key);
	int get_height_helper(Node* node);
	BST::Node* insert_helper(Node* node, int key);
};


/*
	INSERT README_BST
*/
BST::Node* BST::search_helper(Node* node, int key) {
    if (!node or node-> value == key) {
        return node;
    }
    if (key > node-> value) {
        return search_helper(node-> right, key);
    }
    return search_helper(node-> left, key);
}
	
BST::Node* BST::search(int key) {
	return search_helper(root, key);
}

int BST::get_min() {
	if (!root) {
		return -1;
		}
	Node* current {root};
	while (current-> left) {
		current = current-> left;
		}
	return current-> value;
}
	
BST::Node* BST::find_min_node(Node* node) {
	while (node-> left) {
		node = node-> left;
		}
	return node;
}

int BST::get_max() {
	if (!root) {
		return -1;
		}
	Node* current {root};
	while (current-> right) {
		current = current-> right; 
		}
	return current-> value;
}

int BST::get_height_helper(Node* node) {
	if (!node) {
		return 0;
		}
	return std::max(get_height_helper(node-> right), get_height_helper(node-> left)) + 1;
}

int BST::get_height() {
	return get_height_helper(root);
}

BST::Node* BST::insert_helper(Node* root, int key) {
	if (!root) {
		return new Node(key);
		}
	if (key > root-> value) {
		root-> right = insert_helper(root-> right, key);
	} else {	
		root-> left = insert_helper(root-> left, key);
		}
	return root;
}

bool BST::insert(int key) {
    // Call the insert_helper function to perform the insertion
    root = insert_helper(root, key);

    // Check if the insertion was successful
    BST::Node* insertedNode = search(key);
    return (insertedNode != nullptr && insertedNode->value == key);
}
/*
BST::Node* BST::insert(int key) {
	return insert_helper(root, key);
}		
*/
BST::Node* BST::delete_node(Node* node, int key) {
	if (!node) {
		return node;
		}
	if (key > node-> value) {
		node-> right = delete_node(node-> right, key);
		}
	else if (key < node-> value) {
		node-> left = delete_node(node-> left, key);
	} else {
		if (!node-> left) {
			Node* tmp {node-> right};
			delete node;
			return tmp;
			}	
		if (!node-> right) {
			Node* tmp {node-> left};
			delete node;
			return tmp;
		} else {
			Node* tmp {find_min_node(node-> right)};	
			node-> value = tmp-> value;
			node-> right = delete_node(node-> right, tmp-> value);
			}
		}
	return node;
}	

BST::Node* BST::successor(int key) {
	if (!root) {
		return root;
		}	
	Node* successor { search(key) }; 
	if (successor-> right) {
		successor = successor-> right;
		while (successor-> left) {
			successor = successor-> left;
			} 
		return successor;
	} else {
		successor = root;
		Node* current {root};
		while (current) {
			if (key > current-> value) {
				current = current-> right;
				} 
			else if (key < current-> value) {
				successor = current; 
				current = current-> left;
			} else {
				return successor;
				}
			}
		}
	return nullptr;	
}

BST::Node* BST::predecessor(int key) {
	if (!root) {
		return root;
		}
	Node* predecessor { search(key) };
	if (predecessor-> left) {
		predecessor = predecessor-> left;
		while (predecessor-> right) {
			predecessor = predecessor-> right;
			}
		return predecessor;
	} else {
		predecessor = root;
		Node* current {root};
		while (current) {
			if (key > current-> value) {
				predecessor = current;
				current = current-> right;
				}
			else if (key < current-> value) {
				current = current-> left;
			} else {
				return predecessor;
				}
			}
		}
	return nullptr;
}

void BST::preorder_traversal(Node* node) {
	if (!node) {
		return;
		}
	std::cout<< node-> value << '\t';
	preorder_traversal(node-> left);
	preorder_traversal(node-> right);
}

void BST::inorder_traversal(Node* node) {
	if (!node) {
		return;
		}
	inorder_traversal(node-> left);
	std::cout<< node-> value << '\t';
	inorder_traversal(node-> right);
}

void BST::postorder_traversal(Node* node) {
	if (!node) {
		return;
		}
	postorder_traversal(node-> left);
	postorder_traversal(node-> right);
	std::cout<< node-> value << '\t';
}




#endif 		//BST_H

