
#pragma once

#include <string>

using namespace std;

template<typename T>
class binary_tree;

template<typename T>
class Node {
private:
    T data;
    Node<T>* left;
    Node<T>* right;

    friend class binary_tree<T>;
};

/*
   A binary tree in which each node has two children.
*/
template<typename T>
class binary_tree
{
public:
    /**
       Constructs an empty tree.
    */
    binary_tree();

    /**
       Constructs a tree with one node and no children.
       @param root_data the data for the root
    */
    binary_tree(T root_data);

    /**
       Constructs a binary tree.
       @param root_data the data for the root
       @param left the left subtree
       @param right the right subtree
    */
    binary_tree(T root_data, binary_tree left, binary_tree right);

    /**
       Returns the height of this tree.
       @return the height
    */
    int height() const;

    /**
       Checks whether this tree is empty.
       @return true if this tree is empty
    */
    bool empty() const;

    /**
       Gets the data at the root of this tree.
       @return the root data
    */
    T data() const;

    /**
       Gets the left subtree of this tree.
       @return the left child of the root
    */
    binary_tree left() const;

    /**
       Gets the right subtree of this tree.
       @return the right child of the root
    */
    binary_tree right() const;
	
    /**
       Returns the number of nodes in the subtree
       @return the number of nodes in the subtree
    */
    int tree_size(Node<T>*) const;

    /**
       Returns the number of nodes in the current tree
       @return the number of nodes in the current tree
    */
    int size() const;

	// Added the following to avoid inefficiency of having to
	// implement add_subtree recursively
    void set_left(const binary_tree tree);
    /**
       Set the right subtree
    */
    void set_right(const binary_tree tree);

private:

    /**
       Returns the height of the subtree whose root is the given node.
       @param n a node or nullptr
       @return the height of the subtree, or 0 if n is nullptr
    */
    int height(const Node<T>* n) const;

    Node<T>* root;
};

template<typename T>
binary_tree<T>::binary_tree()
{
    root = nullptr;
}

template<typename T>
binary_tree<T>::binary_tree(T root_data)
{
    root = new Node<T>;
    root->data = root_data;
    root->left = nullptr;
    root->right = nullptr;
}

template<typename T>
binary_tree<T>::binary_tree(T root_data, binary_tree<T> left, binary_tree<T> right)
{
    root = new Node<T>;
    root->data = root_data;
    root->left = left.root;
    root->right = right.root;
}

template<typename T>
int binary_tree<T>::height(const Node<T>* n) const
{
    if (n == nullptr) {
        return 0;
    }
    else {
        return 1 + max(height(n->left), height(n->right));
    }
}

template<typename T>
int binary_tree<T>::height() const
{
    return height(root);
}

template<typename T>
bool binary_tree<T>::empty() const
{
    return root == nullptr;
}

template<typename T>
T binary_tree<T>::data() const
{
    return root->data;
}

template<typename T>
binary_tree<T> binary_tree<T>::left() const
{
    binary_tree<T> result;
    result.root = root->left;
    return result;
}

template<typename T>
binary_tree<T> binary_tree<T>::right() const
{
    binary_tree<T> result;
    result.root = root->right;
    return result;
}

template<typename T>
int binary_tree<T>::tree_size(Node<T>* n) const
{
    if (n == nullptr) {
        return 0;
    }
    return 1 + tree_size(n->left) + tree_size(n->right);
}

template<typename T>
int binary_tree<T>::size() const
{
    return tree_size(root);
}

template<typename T>
void binary_tree<T>::set_left(const binary_tree<T> tree)
{
    root->left = tree.root;
}

template<typename T>
void binary_tree<T>::set_right(const binary_tree<T> tree)
{
    root->right = tree.root;
}