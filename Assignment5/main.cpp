#include "WordTree.hpp"
#include "rlutil.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

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

std::string getCurrentWord(std::vector<std::string> words)
{
    return words[words.size() - 1];
}

int main()
{
    std::shared_ptr<WordTree> tree = readDictionary("dictionary.txt");
    auto x = 1;
    auto y = 1;
    auto x2 = 1;
    auto y2 = 4;
    std::vector<std::string> words;
    std::string current = "";
    words.push_back("");
    std::string text = "--- prediction ---";
    rlutil::cls();

    while (true)
    {
        rlutil::locate(x2, y2);
        rlutil::setString(text);
        rlutil::locate(x, y);
        char key = static_cast<char>(rlutil::getkey());
        if (isalpha(key))
        {
            rlutil::setChar(key);
            key = static_cast<char>(tolower(key));
            words[words.size() - 1] += key;
            x += 1;
        }
        else if (key == rlutil::KEY_BACKSPACE)
        {
            if (words[0] != "")
            {
                if (words[words.size() - 1] != "")
                {
                    rlutil::locate(x -= 1, y);
                    rlutil::setChar(rlutil::KEY_SPACE);
                    words[words.size() - 1].pop_back();
                }
                else
                {
                    rlutil::locate(x -= 1, y);
                    rlutil::setChar(rlutil::KEY_SPACE);
                    words.pop_back();
                }
            }
        }
        else if (key == rlutil::KEY_SPACE)
        {
            x += 1;
            rlutil::locate(x, y);
            words.push_back("");
        }
        std::vector<std::string> predictions = tree->predict(words[words.size() - 1], static_cast<uint8_t>(rlutil::trows() - 5));
        for (int i = 0; i < static_cast<int>(rlutil::trows() - 5); i++)
        {
            rlutil::locate(x2, y2 += 1);
            rlutil::setString("                                       ");
        }
        y2 = 4;
        for (std::string i : predictions)
        {
            rlutil::locate(x2, y2 += 1);
            rlutil::setString(i);
        }
        y2 = 4;
    }
}