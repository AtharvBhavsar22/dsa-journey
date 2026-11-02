#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partition(vector<pair<int, int>>& freq, int left, int right) {
        int randomIndex = left + rand() % (right - left + 1);

        swap(freq[randomIndex], freq[right]);

        int pivot = freq[right].second;
        int i = left;

        for (int j = left; j < right; j++) {
            if (freq[j].second > pivot) {
                swap(freq[i], freq[j]);
                i++;
            }
        }

        swap(freq[i], freq[right]);

        return i;
    }

    void quickSelect(vector<pair<int, int>>& freq, int k) {
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

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int num : nums) {
            mp[num]++;
        }

        vector<pair<int, int>> freq;

        for (auto entry : mp) {
            freq.push_back({entry.first, entry.second});
        }

        quickSelect(freq, k);

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(freq[i].first);
        }

        return ans;
    }
};
