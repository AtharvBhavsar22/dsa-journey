#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {

        int n = points.size();
        int ans = 0;

        // Select each point as the reference point
        for (int i = 0; i < n; i++) {

            // Store the frequency of squared distances
            unordered_map<int, int> freq;

            // Calculate distances from the reference point
            for (int j = 0; j < n; j++) {

                // Skip the reference point itself
                if (i == j) continue;

                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];

                // Calculate squared distance
                int dist = dx * dx + dy * dy;

                // Increase frequency of this distance
                freq[dist]++;
            }

            // Count ordered pairs for each distance
            for (auto it = freq.begin(); it != freq.end(); it++) {

                int count = it->second;

                ans += count * (count - 1);
            }
        }

        return ans;
    }
};
