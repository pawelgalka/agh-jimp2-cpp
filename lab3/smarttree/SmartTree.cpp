//
// Created by pawel on 16.03.18.
//

#include <iomanip>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include "SmartTree.h"

namespace datastructures{

    std::unique_ptr <SmartTree> CreateLeaf(int value){
        std::unique_ptr<SmartTree> leaf = std::make_unique<SmartTree>();
        (*leaf).value = value;

        return leaf;
    }

    std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree){
        std::unique_ptr<SmartTree> new_root = std::move(tree);
        new_root->left = std::move(left_subtree);
        return new_root;
    }

    std::unique_ptr <SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree){
        std::unique_ptr<SmartTree> new_root = std::move(tree);
        new_root->right = std::move(right_subtree);
        return new_root;
    }

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out){
        if(unique_ptr) {
            if(unique_ptr->left) PrintTreeInOrder(unique_ptr->left,out);
            *out << unique_ptr->value <<", ";
            if(unique_ptr->right) PrintTreeInOrder(unique_ptr->right, out);
        }
    }

    std::string DumpTree(const std::unique_ptr<SmartTree> &tree){
        std::string dump_tree = "";
        if (tree){
            dump_tree+="[";
            if(tree) dump_tree+=std::to_string(tree->value);
            dump_tree+=" ";
            dump_tree+=DumpTree(tree->left);
            dump_tree+=" ";
            dump_tree+=DumpTree(tree->right);
            dump_tree+="]";
        }
        else{
            dump_tree+="[none]";
        }
        return dump_tree;
    }

    void MakeTree(std::unique_ptr<SmartTree> *Parent, int depth, std::vector<int> values, int values_length){
        if ((*Parent)!= nullptr && depth<values.size()/2) {
            if (2*depth+1<values_length && values[2*depth+1]!=INT32_MAX) {
                *Parent = InsertLeftChild(std::move(*Parent), CreateLeaf(values[2 * depth + 1]));
                MakeTree(&(*Parent)->left, 2 * depth + 1, values, values_length);
            }
            else {
                (*Parent)->left = nullptr;
            }
            if (2*depth+2<values_length && values[2*depth+2]!=INT32_MAX){
                *Parent = InsertRightChild(std::move(*Parent), CreateLeaf(values[2*depth+2]));
                MakeTree(&(*Parent)->right,2*depth+2,values, values_length);
            }
            else{
                (*Parent)->right = nullptr;
            }
        }
        else return;
    }

    void ConvertMapToArray(const std::vector<std::pair<int, int>> &values, std::vector<int> &array_of_values, int max_depth);

    void ConvertStringToMap(const std::string &tree, std::vector<std::pair<int, int>> &values, int depth, int current_value, int current_position, int current_depth, std::string &number);

    std::unique_ptr <SmartTree> RestoreTree(const std::string &tree){

        std::vector<std::pair<int, int >> values;
        std::vector<int> array_of_values;
        int depth = 0, current_value = 0, current_position = 0, current_depth = 0, max_depth = 0;;
        std::string number;

        ConvertStringToMap(tree, values, depth, current_value, current_position, current_depth, number);


        for (auto value : values){
            if (max_depth<value.first) max_depth = value.first;
        }

        ConvertMapToArray(values, array_of_values, max_depth);

        if (!array_of_values.empty() && array_of_values[0] != INT32_MAX){
            std::unique_ptr<SmartTree> root = CreateLeaf(array_of_values[0]);
            depth = 0;
            MakeTree(&root, depth, array_of_values, array_of_values.size());
            return root;
        }
        else return nullptr;

    }

    void ConvertStringToMap(const std::string &tree, std::vector<std::pair<int, int>> &values, int depth, int current_value, int current_position, int current_depth, std::string &number) {
        while (tree[current_position] != '\0'){
            if (tree[current_position]=='['){
                ++current_position;
                ++current_depth;
                number = "";
                while (tree[current_position]!=' ' && tree[current_position]!=']'){
                    number+=tree[current_position];
                    ++current_position;
                }

                if (number!="none") {
                    current_value = stoi(number);
                    values.emplace_back(std::make_pair(current_depth, current_value));
                    ++depth;
                }
                else{
                    values.emplace_back(std::make_pair(current_depth, INT32_MAX));
                }
            }
            if (tree[current_position]==']') --current_depth;
            ++current_position;
        }
    }

    void ConvertMapToArray(const std::vector<std::pair<int, int>> &values, std::vector<int> &array_of_values, int max_depth) {
        for (int i=1; i <= max_depth; ++i){
                for (auto value : values){
                    if (value.first == i && value.second!=INT32_MAX){
                        array_of_values.emplace_back(value.second);
                    }
                    else if (value.first==i && value.second==INT32_MAX){
                        array_of_values.emplace_back(INT32_MAX);
                    }
                }
            }
    }


}


