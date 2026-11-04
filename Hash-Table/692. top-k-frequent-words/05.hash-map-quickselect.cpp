#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Step 1: Partition the vector around a random pivot
    int partition(vector<pair<string, int>>& freq, int left, int right) {

        int randomIndex = left + rand() % (right - left + 1);

        swap(freq[randomIndex], freq[right]);

        pair<string, int> pivot = freq[right];

        int i = left;

        for (int j = left; j < right; j++) {

            // Higher frequency first.
            // If frequencies are equal, alphabetical order first.
            if (freq[j].second > pivot.second ||
                (freq[j].second == pivot.second &&
                 freq[j].first < pivot.first)) {

                swap(freq[i], freq[j]);
                i++;
            }
        }

        swap(freq[i], freq[right]);

        return i;
    }

    // Step 2: Find the position of the kth most frequent word
    void quickSelect(vector<pair<string, int>>& freq, int k) {

        int left = 0;
        int right = freq.size() - 1;

        while (left <= right) {

            int pivotIndex = partition(freq, left, right);

            if (pivotIndex == k - 1) {
                return;
            }
            else if (pivotIndex > k - 1) {
                right = pivotIndex - 1;
            }
            else {
                left = pivotIndex + 1;
            }
        }
    }

    // Step 3: Find the k most frequent words
    vector<string> topKFrequent(vector<string>& words, int k) {

        // Step 1: Count frequencies
        unordered_map<string, int> mp;

        for (const string& word : words) {
            mp[word]++;
        }

        // Step 2: Store words and their frequencies
        vector<pair<string, int>> freq;

        for (auto entry : mp) {
            freq.push_back({entry.first, entry.second});
        }

        // Step 3: Apply Quickselect
        quickSelect(freq, k);

        // Step 4: Collect the first k words
        vector<string> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(freq[i].first);
        }

        // Step 5: Sort the selected words
        sort(ans.begin(), ans.end(),
             [&mp](const string& a, const string& b) {

                 if (mp[a] == mp[b]) {
                     return a < b;
                 }

                 return mp[a] > mp[b];
             });

        return ans;
    }
};
