/**
 * Author: Bao Wenjie
 * Date: 2021/4/14
 * Link: https://leetcode-cn.com/problems/implement-trie-prefix-tree/
 */

 #include <iostream>
 #include <vector>
 #include <string>
 using namespace::std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie* charas[26] = {NULL};
    bool isWord = false;
    Trie() {

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        if(word.size() == 0)
        {
            this->isWord = true;
            return;
        }
        char c = word[0];
        string subword = word.substr(1, word.size() - 1);
        if(this->charas[c - 'a'] == NULL)
        {
            this->charas[c - 'a'] = new Trie();
        }
        this->charas[c - 'a']->insert(subword);
        return;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(word.size() == 0)
        {
            if(this->isWord)
                return true;
            return false;
        }
        char c = word[0];
        string subword = word.substr(1, word.size() - 1);
        if(this->charas[c - 'a'] == NULL)
            return false;
        return this->charas[c-'a']->search(subword);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(prefix.size() == 0)
        {
            return true;
        }
        char c = prefix[0];
        string subword = prefix.substr(1, prefix.size() - 1);
        if(this->charas[c-'a'] == NULL)
            return false;
        return this->charas[c-'a']->startsWith(subword);
    }
};


int main()
{
    Trie T = Trie();
    T.insert("hhffd");
    cout << "OK";
    T.search("fdsfdsf");
}
