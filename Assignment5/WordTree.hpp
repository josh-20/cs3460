#pragma once
#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

struct TreeNode
{
    bool m_endOfWord = false;
    std::array<std::shared_ptr<TreeNode>, 26> m_children;
};

class WordTree
{
  public:
    void add(std::string word);
    bool find(std::string word);
    std::vector<std::string> predict(std::string partial, std::uint8_t howMany);
    std::size_t size();

  private:
    std::size_t m_size = 0;
    std::shared_ptr<TreeNode> m_root = std::make_shared<TreeNode>();
};
