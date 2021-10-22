#include"Datastruct.h"
using namespace std;
class WordDictionary {
public:
    WordDictionary() {
        m_set.clear();
    }

    void addWord(string word) {
        m_set.insert(word);
    }

    bool search(string word) {

    }
private:
    set<string> m_set;
};