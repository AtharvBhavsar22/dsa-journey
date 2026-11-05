#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {

        int n = points.size();
        int ans = 0;

        // Select each point as the reference point
        for (int i = 0; i < n; i++) {

            vector<int> distances;

            // Calculate distances from the reference point
            for (int j = 0; j < n; j++) {

                if (i == j) continue;

                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];

                int dist = dx * dx + dy * dy;

                distances.push_back(dist);
            }

            // Sort all calculated distances
            sort(distances.begin(), distances.end());

            // Count consecutive equal distances
            int count = 1;

            for (int j = 1; j < distances.size(); j++) {

                if (distances[j] == distances[j - 1]) {
                    count++;
                }
                else {
                    ans += count * (count - 1);
                    count = 1;
                }
            }

            // Process the last group
            ans += count * (count - 1);
        }

        return ans;
    }
};
