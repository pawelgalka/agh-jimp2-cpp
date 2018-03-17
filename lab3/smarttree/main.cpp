//
// Created by pawel on 16.03.18.
//

#include <iostream>
#include <fstream>
#include "SmartTree.h"
using namespace datastructures;
int main(){
    std::filebuf fb;
    std::ostream out(&fb);
    std::unique_ptr<SmartTree> root;
    root = CreateLeaf(99);
    root = InsertLeftChild(move(root), CreateLeaf(100));
    root = InsertRightChild(move(root), CreateLeaf(88));
    root->left = InsertLeftChild(move(root->left), CreateLeaf(1234));
    root->left = InsertRightChild(move(root->left), CreateLeaf(4321));
    root->right = InsertLeftChild(move(root->right), CreateLeaf(897));
    root->right = InsertRightChild(move(root->right), CreateLeaf(761));
    std::string tree = "[99 [100 [1234 [none] [none]] [4321 [none] [none]]] [88 [897 [none] [none]] [761 [none] [none]]]]";
    std::string tree1 = "[-13 [none] [none]]";
    std::string tree2 = "[none]";
    std::string tree3 = "[-189 [17 [none] [-90 [none] [none]]] [none]]";

    std::cout<< std::endl;

    std::unique_ptr<SmartTree> root1 = RestoreTree(tree);
    std::unique_ptr<SmartTree> root2 = RestoreTree(tree1);
    std::unique_ptr<SmartTree> root3 = RestoreTree(tree2);
    std::unique_ptr<SmartTree> root4 = RestoreTree(tree3);

    std::cout << DumpTree(root1) << std::endl;
    std::cout << DumpTree(root2) << std::endl;
    std::cout << DumpTree(root3) << std::endl;
    std::cout << DumpTree(root4) << std::endl;

    return 0;
}