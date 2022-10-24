#include "WordTree.hpp"
#include <iostream>


WordTree::WordTree(std::string letter, WordTree* parent, std::vector<WordTree*> children, bool end){
    m_letter = letter;
    m_parent = parent;
    m_children = children;
    m_end = end;
}

std::string getLetter(){
    return m_letter;
}
WordTree getParent(){
    return m_parent;
}

std::vector<WordTree> getChildren(){
    
}







