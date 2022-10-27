#include "WordTree.hpp"

#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>

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
std::vector<std::string> WordTree::predict(std::string partial, std::uint8_t howMany)
{
    auto index = partial[0] - 'a';
    std::vector<std::string> words;
    if (partial == "")
    {
        return words;
    }
    else if (m_root->m_children[index] == NULL)
    {
        return words;
    }
    std::queue<std::tuple<std::shared_ptr<TreeNode>, std::string>> queue;
    auto first = std::make_tuple(m_root->m_children[index], partial);
    std::shared_ptr<TreeNode> tempNode = m_root;
    auto count = index;
    std::string word = partial;
    for (char i : partial)
    {
        if (tempNode->m_children[count] == NULL)
        {
            return words;
        }
        tempNode = tempNode->m_children[count];
        if (i == partial.back())
        {
            queue.push(std::make_tuple(tempNode, partial));
        }
        word = word.erase(0, 1);
        count = word[0] - 'a';
    }
    // go down the tree starting at first child node AKA first letter.
    while (!queue.empty())
    {
        // grab first child off the queue
        if (words.size() == howMany)
        {
            return words;
        }
        std::tuple<std::shared_ptr<TreeNode>, std::string> current = queue.front();
        queue.pop();
        // see if the were at end of word if we are we add the word to the list of words
        if (std::get<0>(current)->m_endOfWord == true && std::get<1>(current) == partial)
        {
            words.push_back(std::get<1>(current));
            return words;
        }
        if (std::get<0>(current)->m_endOfWord == true)
        {
            words.push_back(std::get<1>(current));
        }
        // iterrate over all children and add them to the queue if not true
        for (int i = 0; i < std::get<0>(current)->m_children.size(); i++)
        {
            if (std::get<0>(current)->m_children[i] != NULL)
            {
                char charNum = static_cast<char>(i + 'a');
                auto add = std::make_tuple(std::get<0>(current)->m_children[i], std::get<1>(current) + charNum);
                queue.push(add);
            }
        }
    }
    return words;
}
std::size_t WordTree::size()
{
    return m_size;
}
