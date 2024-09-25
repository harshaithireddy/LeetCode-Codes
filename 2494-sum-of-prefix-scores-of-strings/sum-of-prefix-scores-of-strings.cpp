class TrieNode {
public:
    int count = 0;
    unordered_map<char, TrieNode*> children;
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for(char c : word) {
            if(!node->children[c]) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->count++;
        }
    }

    int getPrefixScore(string prefix) {
        TrieNode* node = root;
        int score = 0;
        for(char c : prefix) {
            if(!node->children[c]) {
                return 0;
            }
            node = node->children[c];
            score += node->count;
        }
        return score;
    }
};

class Solution {
public:
    int speedup = []{ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
    
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        vector<int> res;

        for(string word : words) {
            trie.insert(word);
        }

        for(string word : words) {
            int score = trie.getPrefixScore(word);
            res.push_back(score);
        }
        return res;
    }
};
