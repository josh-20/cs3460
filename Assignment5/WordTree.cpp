#include "WordTree.hpp"

#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <string>

std::size_t helperForAdd(std::string word, std::shared_ptr<TreeNode> root)
{

    if (word == "")
    {
        if (root->m_endOfWord == false)
        {
            root->m_endOfWord = true;
            return 1;
        }
        return 0;
    };
    int index = int(word[0]) - 'a';
    if (root->m_children[index] == NULL)
    {
        root->m_children[index] = std::make_shared<TreeNode>();
        word = word.erase(0, 1);
        return helperForAdd(word, root->m_children[index]);
    }
    word = word.erase(0, 1);
    return helperForAdd(word, root->m_children[index]);
}
void WordTree::add(std::string word)
{
    // recursive helper
    if (word != "")
    {
        m_size += helperForAdd(word, m_root);
    }
}

bool helperforfind(std::string word, std::shared_ptr<TreeNode> root)
{
    int index = int(word[0]) - 'a';
    if (word == "" && root->m_endOfWord == true)
    {
        return true;
    }
    else if (word == "" && root->m_endOfWord == false || root->m_children[index] == NULL)
    {
        return false;
    }
    word = word.erase(0, 1);
    return helperforfind(word, root->m_children[index]);
}
bool WordTree::find(std::string word)
{
   return helperforfind(word, m_root);

}
std::vector<std::string> helperforPartial(std::vector<std::string> words, std::string partial, std::uint8_t howmany, std::shared_ptr<TreeNode> root, std::string wordToSave){
    if (words.size() == howmany){
        return words;
    }
    for(int i = 0; i < root->m_children.size(); i++){
        if(root->m_children[i] == NULL){
            return words;
        }

                
    }
}
std::vector<std::string> WordTree::predict(std::string partial, std::uint8_t howMany){
    std::vector<std::string> words = std::vector<std::string>();
    std::string word;
    words = helperforPartial(words, partial, howMany, m_root, word); 
    return words;
}
std::size_t WordTree::size()
{
    return m_size;
}
