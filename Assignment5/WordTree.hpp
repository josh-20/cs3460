#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <stdint.h>



class WordTree{
    public:
        WordTree(std::string letter, WordTree* parent, std::vector<WordTree*> children, bool end);
        WordTree* getParent();
        std::vector<WordTree*> getChildren();
        std::string getLetter();

    private:
        std::string m_letter;
        WordTree* m_parent;
        std::vector<WordTree*> m_children;
        bool m_end;



        
}

add(std::string word);
bool find(std::string word);
std::vector<std::string> predict(std::string partial, std::uint8_t howMany);
std::size_t size();


