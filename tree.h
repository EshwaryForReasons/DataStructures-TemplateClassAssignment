
#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "binary_tree.h"

using namespace std;

/*
   A tree in which each node has an arbitrary number of children.
*/
template<typename T>
class Tree
{
public:
    /**
       Constructs an empty tree.
    */
    Tree() = default;

    /**
       Constructs a tree with one node and no children.
       @param root_data the data for the root
    */
    Tree(string root_data);

    /**
       Adds a subtree as the last child of the root.
    */
    void add_subtree(const Tree& subtree);

    /**
       Computes the size of this tree.
       @return the number of nodes in the tree
    */
    int size() const;

    // Additional methods will be added in later sections.


    void display() const;

private:

    binary_tree<T> tree;
};

template<typename T>
Tree<T>::Tree(string root_data)
{
    tree = binary_tree<T>(root_data);
}

template<typename T>
void Tree<T>::add_subtree(const Tree<T>& subtree)
{
    if (tree.empty()) {   // Adding tree at root    
        tree = subtree.tree;
    }
    else if (tree.left().empty()) {
        tree.set_left(subtree.tree);
    }
    else {
        binary_tree<T> t = tree.left();
        while (!t.right().empty()) {
            t = t.right();
        }
        t.set_left(t.right());
        t.set_right(subtree.tree);
    }
}

template<typename T>
int Tree<T>::size() const
{
    return tree.size();
}

static int indent = 0;
template<typename T>
void show(binary_tree<T> t)
{
    if (! t.empty()) {
        for (int i = 0; i < indent; i++ ) {
            cout << ' ';
        }
        cout << t.data() << endl;
        indent += 4;
        binary_tree<T> child = t.left();
        while (!child.empty()) {
            show(child);
            child = child.right();
        }
        indent -= 4;
    }
}

template<typename T>
void Tree<T>::display() const
{
    indent = 0;
    show(tree);
}