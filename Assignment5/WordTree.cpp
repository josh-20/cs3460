#include "WordTree.hpp"
#include <iostream>
#include <array>
#include <algorithm>
#include <string>
#include <fstream>



WordTree::WordTree(){

}

void helperForAdd(std::string word, std::shared_ptr<TreeNode> root){
    if (word == ""){
        root->m_endOfWord = true;
        return;
    };
    int index = int(word[0]) - 97;
    if (root->m_children[index] == NULL){
        root->m_children[index] = std::make_shared<TreeNode>(TreeNode());
        word = word.erase(0,1);
        helperForAdd(word,root->m_children[index]);
    }else{
        word = word.erase(0,1);
        helperForAdd(word, root->m_children[index]);
    }


}
void WordTree::add(std::string word){
    // recursive helper
    helperForAdd(word,m_root);
}
bool WordTree::find(std::string word){

}
std::vector<std::string> WordTree::predict(std::string partial, std::uint8_t howMany){

}
std::size_t WordTree::size(){

}
