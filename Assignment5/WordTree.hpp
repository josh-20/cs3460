#pragma once
#include <vector>

struct TreeNode{
    bool m_endOfWord = false;
    std::array<std::shared_ptr<TreeNode>,26> m_children;
};

class WordTree{
    public:
        void add(std::string);
        bool find();
        std::vector<std::string> predict();
        std::size_t size();
    private:
        std::shared_ptr<TreeNode> m_root = std::make_shared<TreeNode>(TreeNode());
              
};
