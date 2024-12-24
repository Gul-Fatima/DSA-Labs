#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(const std::string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }

    // Search for a word in the Trie
    bool search(const std::string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return node->isEndOfWord;
    }

    // Get suggestions based on prefix
    void suggestWords(TrieNode* node, std::string prefix, std::vector<std::string>& suggestions) {
        if (node->isEndOfWord) {
            suggestions.push_back(prefix);
        }
        for (auto& pair : node->children) {
            suggestWords(pair.second, prefix + pair.first, suggestions);
        }
    }

    std::vector<std::string> getSuggestions(const std::string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return {}; // No suggestions if prefix is not found
            }
            node = node->children[c];
        }
        std::vector<std::string> suggestions;
        suggestWords(node, prefix, suggestions);
        return suggestions;
    }
};
int levenshteinDistance(const std::string& s1, const std::string& s2) {
    size_t len1 = s1.size();
    size_t len2 = s2.size();

    std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1));

    for (size_t i = 0; i <= len1; ++i) {
        for (size_t j = 0; j <= len2; ++j) {
            if (i == 0) {
                dp[i][j] = j; // Deleting all characters from s2
            }
            else if (j == 0) {
                dp[i][j] = i; // Inserting all characters from s1
            }
            else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // Characters match
            }
            else {
                dp[i][j] = 1 + std::min({ dp[i - 1][j],    // Deletion
                                          dp[i][j - 1],    // Insertion
                                          dp[i - 1][j - 1] // Substitution
                    });
            }
        }
    }
    return dp[len1][len2];
}
void loadDictionary(Trie& trie, const std::string& filename) {
    std::ifstream file(filename);
    std::string word;
    while (file >> word) {
        trie.insert(word);
    }
}

int main() {
    Trie trie;
    loadDictionary(trie, "dictionary.txt"); // Load your dictionary file

    std::string inputWord;
    std::cout << "Enter a word: ";
    std::cin >> inputWord;

    if (trie.search(inputWord)) {
        std::cout << inputWord << " is spelled correctly." << std::endl;
    }
    else {
        std::cout << inputWord << " is not found. Suggestions:" << std::endl;

        // Get suggestions based on the prefix
        std::vector<std::string> suggestions = trie.getSuggestions(inputWord.substr(0, 1));
        if (suggestions.empty()) {
            std::cout << "No suggestions found." << std::endl;
        }
        else {
            for (const std::string& suggestion : suggestions) {
                if (levenshteinDistance(inputWord, suggestion) <= 2) { // Allow a maximum distance of 2
                    std::cout << suggestion << std::endl;
                }
            }
        }
    }

    return 0;
}
