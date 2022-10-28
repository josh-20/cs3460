#include "WordTree.hpp"
#include "rlutil.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

std::shared_ptr<WordTree> readDictionary(std::string filename)
{
    auto wordTree = std::make_shared<WordTree>();
    std::ifstream inFile = std::ifstream(filename, std::ios::in);

    while (!inFile.eof())
    {
        std::string word;
        std::getline(inFile, word);
        // Need to consume the carriage return character for some systems, if it exists
        if (!word.empty() && word[word.size() - 1] == '\r')
        {
            word.erase(word.end() - 1);
        }
        // Keep only if everything is an alphabetic character -- Have to send isalpha an unsigned char or
        // it will throw exception on negative values; e.g., characters with accent marks.
        if (std::all_of(word.begin(), word.end(), [](unsigned char c)
                        { return std::isalpha(c); }))
        {
            std::transform(word.begin(), word.end(), word.begin(), [](char c)
                           { return static_cast<char>(std::tolower(c)); });
            wordTree->add(word);
        }
    }

    return wordTree;
}

int main()
{
    std::shared_ptr<WordTree> tree = readDictionary("dictionary.txt");
    auto x = 1;
    auto y = 1;
    auto x2 = 1;
    auto y2 = 4;
    std::string word = "";
    std::string text = "--- prediction ---";

    while (true)
    {
        rlutil::locate(1, 1);
        rlutil::setString(word);
        rlutil::locate(static_cast<int>(word.size() + 1), y);
        char key = static_cast<char>(rlutil::getkey());
        if (key == rlutil::KEY_BACKSPACE)
        {
            if (word != "")
            {
                rlutil::locate(x - 1, y);
                word.pop_back();
                rlutil::setChar(rlutil::KEY_SPACE);
            }
        }
        else
        {
            std::string s(1, key);
            word += s;
            rlutil::showcursor();
            rlutil::setChar(key);
        }
        rlutil::cls();
        rlutil::locate(x, y + 3);
        rlutil::setString(text);
        std::vector<std::string> words = tree->predict(word, static_cast<uint8_t>(rlutil::trows() - 5));
        for (std::string i : words)
        {
            rlutil::locate(x2, y2 += 1);
            rlutil::setString(i);
        }
        y2 = 4;
    }
}