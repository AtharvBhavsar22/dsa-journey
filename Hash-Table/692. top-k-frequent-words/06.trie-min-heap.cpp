#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    struct TrieNode {
        TrieNode* children[26];
        int freq;
        string word;

        TrieNode() {
            freq = 0;
            word = "";

            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    using P = pair<int, string>;

    // Min-Heap comparator
    struct Compare {
        bool operator()(const P& a, const P& b) const {
            if (a.first == b.first) {
                return a.second < b.second;
            }

            return a.first > b.first;
        }
    };

    // Insert words into Trie
    void insert(TrieNode* root, const string& word) {
        TrieNode* curr = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
        }

        curr->freq++;
        curr->word = word;
    }

    // DFS traversal and maintain top k words
    void dfs(
        TrieNode* node,
        priority_queue<P, vector<P>, Compare>& pq,
        int k
    ) {
        if (node == nullptr) {
            return;
        }

        // Process a complete word
        if (node->freq > 0) {
            pq.push({node->freq, node->word});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Explore Trie children
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                dfs(node->children[i], pq, k);
            }
        }
    }

    // Delete allocated Trie nodes
    void deleteTrie(TrieNode* node) {
        if (node == nullptr) {
            return;
        }

        for (int i = 0; i < 26; i++) {
            deleteTrie(node->children[i]);
        }

        delete node;
    }

public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        // Step 1: Create Trie
        TrieNode* root = new TrieNode();

        // Step 2: Insert all words
        for (const string& word : words) {
            insert(root, word);
        }

        // Step 3: Create Min-Heap
        priority_queue<P, vector<P>, Compare> pq;

        // Step 4: Traverse Trie and maintain top k
        dfs(root, pq, k);

        // Step 5: Extract words
        vector<string> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        // Step 6: Reverse the result
        reverse(ans.begin(), ans.end());

        // Step 7: Free Trie memory
        deleteTrie(root);

        return ans;
    }
};
