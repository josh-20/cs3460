#include "WordTree.hpp"

#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <queue>

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
std::vector<std::string> WordTree::predict(std::string partial, std::uint8_t howMany){
    auto index = partial[0] - 'a';
    std::vector<std::string> words;
    std::queue<std::tuple<std::shared_ptr<TreeNode>, std::string>> queue;
    std::string letter(1,partial[0]);
    queue.push({m_root->m_children[index],letter});
    // go down the tree starting at first child node AKA first letter.
    while(!queue.empty() || words.size() == howMany){
        // erase first letter of partial to get next letter for child
        partial = partial.erase(0,1);
        std::string nextLetter(1,partial[0]);
        // grab first child off the queue 
        std::tuple<std::shared_ptr<TreeNode>,std::string> current = queue.front();
        // see if the were at end of word if we are we add the word to the list of words
        if(std::get<0>(current)->m_endOfWord == true){
            words.push_back(std::get<1>(current));
        }else{
            // iterrate over all children and add them to the queue if not true
            for (std::shared_ptr<TreeNode> child : std::get<0>(current)->m_children){
                queue.push({child, std::get<1>(current) += nextLetter});
            }
        }
    }
    return words;
}
std::size_t WordTree::size()
{
    return m_size;
}
