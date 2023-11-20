#include <iostream>
#include <string>
#include "tree.h"

using namespace std;

void display(const Tree<string>& t)
{
    t.display();
}

int main()
{
    Tree<string> root("Root");
    Tree<string> t2("Peter");
    root.add_subtree(t2);
    Tree<string> t3("Zara");
    root.add_subtree(t3);
    Tree<string> t4("Savannah");
    root.add_subtree(t4);
    cout << "Size: " << root.size() << endl;
    display(root);
    return 0;
}



