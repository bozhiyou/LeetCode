class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int ret = 0;
        vector<int> taps;
        for (int i = 0; i < n; i++) {
            for (int t = 0; t < taps.size(); t++) {
                while (taps[t] - ranges[taps[t]] > i || i >= taps[t] + ranges[taps[t]]) {
                    taps.erase(taps.begin()+t);
                    if (t == taps.size())
                        break;
                }
            }
            if (taps.empty()) {
                ++ret;
                for (int t = 0; t < ranges.size(); t++) {
                    if (t - ranges[t] <= i && i < t + ranges[t]) {
                        taps.push_back(t);
                    }
                }
                if (taps.empty())
                    return -1;
            }
        }
        return ret;
    }
};
