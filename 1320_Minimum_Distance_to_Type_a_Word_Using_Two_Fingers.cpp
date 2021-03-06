// Wrong
class Solution {
    void distHardCodeGen() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6 && 6*i+j < 26; j++) {
                cout << '{';
                for (int ii = 0; ii < 5; ii++) {
                    for (int jj = 0; jj < 6 && 6*ii+jj < 26; jj++) {
                        cout << abs(ii-i) + abs(jj-j);
                        if (6*ii+jj < 25)
                            cout << ", ";
                    }
                }
                cout << '}';
                if (6*i+j < 25)
                    cout << ',';
                cout << endl;
            }
        }
    }
    void neighborsHardCodeGen() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6 && 6*i+j < 26; j++) {
                cout << '{';
                for (int comma = 0, d = 0; d < 10; d++) {
                    for (int n = 0; n < 26; n++) {
                        if (dist[6*i+j][n] == d) {
                            if (comma)
                                cout << ", ";
                            else
                                comma = true;
                            cout << n;
                        }
                    }
                }
                cout << '}';
                if (6*i+j < 25)
                    cout << ',';
                cout << endl;
            }
        }
    }
    void neighborsByDistHardCodeGen() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6 && 6*i+j < 26; j++) {
                cout << '{';
                for (int d = 0; d < 10; d++) {
                    cout << '{';
                    for (int comma = 0, n = 0; n < 26; n++) {
                        if (dist[6*i+j][n] == d) {
                            if (comma)
                                cout << ", ";
                            else
                                comma = true;
                            cout << n;
                        }
                    }
                    cout << '}';
                    if (d < 9)
                        cout << ", ";
                }
                cout << '}';
                if (6*i+j < 25)
                    cout << ',';
                cout << endl;
            }
        }
    }
    void prefixSumHardCodeGen() {
        for (int i = 0; i < 26; i++) {
            cout << '{';
            for (int d = 0; d < 10; d++) {
                int prefix_sum = 0;
                for (int s = 0; s <= d; s++) {
                    prefix_sum += neighborsByDist[i][s].size();
                }
                cout << prefix_sum;
                if (d < 9)
                    cout << ", ";
            }
            cout << '}';
            if (i < 25)
                cout << ',';
            cout << endl;
        }
    }
    const uint8_t dist[26][26] = {
        {0, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 6, 2, 3, 4, 5, 6, 7, 3, 4, 5, 6, 7, 8, 4, 5}, // A
        {1, 0, 1, 2, 3, 4, 2, 1, 2, 3, 4, 5, 3, 2, 3, 4, 5, 6, 4, 3, 4, 5, 6, 7, 5, 4}, // B
        {2, 1, 0, 1, 2, 3, 3, 2, 1, 2, 3, 4, 4, 3, 2, 3, 4, 5, 5, 4, 3, 4, 5, 6, 6, 5}, // C
        {3, 2, 1, 0, 1, 2, 4, 3, 2, 1, 2, 3, 5, 4, 3, 2, 3, 4, 6, 5, 4, 3, 4, 5, 7, 6}, // D
        {4, 3, 2, 1, 0, 1, 5, 4, 3, 2, 1, 2, 6, 5, 4, 3, 2, 3, 7, 6, 5, 4, 3, 4, 8, 7}, // E
        {5, 4, 3, 2, 1, 0, 6, 5, 4, 3, 2, 1, 7, 6, 5, 4, 3, 2, 8, 7, 6, 5, 4, 3, 9, 8}, // F
        {1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 6, 2, 3, 4, 5, 6, 7, 3, 4}, // G
        {2, 1, 2, 3, 4, 5, 1, 0, 1, 2, 3, 4, 2, 1, 2, 3, 4, 5, 3, 2, 3, 4, 5, 6, 4, 3}, // H
        {3, 2, 1, 2, 3, 4, 2, 1, 0, 1, 2, 3, 3, 2, 1, 2, 3, 4, 4, 3, 2, 3, 4, 5, 5, 4}, // I
        {4, 3, 2, 1, 2, 3, 3, 2, 1, 0, 1, 2, 4, 3, 2, 1, 2, 3, 5, 4, 3, 2, 3, 4, 6, 5}, // J
        {5, 4, 3, 2, 1, 2, 4, 3, 2, 1, 0, 1, 5, 4, 3, 2, 1, 2, 6, 5, 4, 3, 2, 3, 7, 6}, // K
        {6, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1, 0, 6, 5, 4, 3, 2, 1, 7, 6, 5, 4, 3, 2, 8, 7}, // L
        {2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 6, 2, 3}, // M
        {3, 2, 3, 4, 5, 6, 2, 1, 2, 3, 4, 5, 1, 0, 1, 2, 3, 4, 2, 1, 2, 3, 4, 5, 3, 2}, // N
        {4, 3, 2, 3, 4, 5, 3, 2, 1, 2, 3, 4, 2, 1, 0, 1, 2, 3, 3, 2, 1, 2, 3, 4, 4, 3}, // O
        {5, 4, 3, 2, 3, 4, 4, 3, 2, 1, 2, 3, 3, 2, 1, 0, 1, 2, 4, 3, 2, 1, 2, 3, 5, 4}, // P
        {6, 5, 4, 3, 2, 3, 5, 4, 3, 2, 1, 2, 4, 3, 2, 1, 0, 1, 5, 4, 3, 2, 1, 2, 6, 5}, // Q
        {7, 6, 5, 4, 3, 2, 6, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1, 0, 6, 5, 4, 3, 2, 1, 7, 6}, // R
        {3, 4, 5, 6, 7, 8, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 1, 2}, // S
        {4, 3, 4, 5, 6, 7, 3, 2, 3, 4, 5, 6, 2, 1, 2, 3, 4, 5, 1, 0, 1, 2, 3, 4, 2, 1}, // T
        {5, 4, 3, 4, 5, 6, 4, 3, 2, 3, 4, 5, 3, 2, 1, 2, 3, 4, 2, 1, 0, 1, 2, 3, 3, 2}, // U
        {6, 5, 4, 3, 4, 5, 5, 4, 3, 2, 3, 4, 4, 3, 2, 1, 2, 3, 3, 2, 1, 0, 1, 2, 4, 3}, // V
        {7, 6, 5, 4, 3, 4, 6, 5, 4, 3, 2, 3, 5, 4, 3, 2, 1, 2, 4, 3, 2, 1, 0, 1, 5, 4}, // W
        {8, 7, 6, 5, 4, 3, 7, 6, 5, 4, 3, 2, 6, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1, 0, 6, 5}, // X
        {4, 5, 6, 7, 8, 9, 3, 4, 5, 6, 7, 8, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 0, 1}, // Y
        {5, 4, 5, 6, 7, 8, 4, 3, 4, 5, 6, 7, 3, 2, 3, 4, 5, 6, 2, 1, 2, 3, 4, 5, 1, 0}  // Z
    };
    const vector<uint8_t> neighbors[26] = {
        {0, 1, 6, 2, 7, 12, 3, 8, 13, 18, 4, 9, 14, 19, 24, 5, 10, 15, 20, 25, 11, 16, 21, 17, 22, 23},
        {1, 0, 2, 7, 3, 6, 8, 13, 4, 9, 12, 14, 19, 5, 10, 15, 18, 20, 25, 11, 16, 21, 24, 17, 22, 23},
        {2, 1, 3, 8, 0, 4, 7, 9, 14, 5, 6, 10, 13, 15, 20, 11, 12, 16, 19, 21, 17, 18, 22, 25, 23, 24},
        {3, 2, 4, 9, 1, 5, 8, 10, 15, 0, 7, 11, 14, 16, 21, 6, 13, 17, 20, 22, 12, 19, 23, 18, 25, 24},
        {4, 3, 5, 10, 2, 9, 11, 16, 1, 8, 15, 17, 22, 0, 7, 14, 21, 23, 6, 13, 20, 12, 19, 18, 25, 24},
        {5, 4, 11, 3, 10, 17, 2, 9, 16, 23, 1, 8, 15, 22, 0, 7, 14, 21, 6, 13, 20, 12, 19, 18, 25, 24},
        {6, 0, 7, 12, 1, 8, 13, 18, 2, 9, 14, 19, 24, 3, 10, 15, 20, 25, 4, 11, 16, 21, 5, 17, 22, 23},
        {7, 1, 6, 8, 13, 0, 2, 9, 12, 14, 19, 3, 10, 15, 18, 20, 25, 4, 11, 16, 21, 24, 5, 17, 22, 23},
        {8, 2, 7, 9, 14, 1, 3, 6, 10, 13, 15, 20, 0, 4, 11, 12, 16, 19, 21, 5, 17, 18, 22, 25, 23, 24},
        {9, 3, 8, 10, 15, 2, 4, 7, 11, 14, 16, 21, 1, 5, 6, 13, 17, 20, 22, 0, 12, 19, 23, 18, 25, 24},
        {10, 4, 9, 11, 16, 3, 5, 8, 15, 17, 22, 2, 7, 14, 21, 23, 1, 6, 13, 20, 0, 12, 19, 18, 25, 24},
        {11, 5, 10, 17, 4, 9, 16, 23, 3, 8, 15, 22, 2, 7, 14, 21, 1, 6, 13, 20, 0, 12, 19, 18, 25, 24},
        {12, 6, 13, 18, 0, 7, 14, 19, 24, 1, 8, 15, 20, 25, 2, 9, 16, 21, 3, 10, 17, 22, 4, 11, 23, 5},
        {13, 7, 12, 14, 19, 1, 6, 8, 15, 18, 20, 25, 0, 2, 9, 16, 21, 24, 3, 10, 17, 22, 4, 11, 23, 5},
        {14, 8, 13, 15, 20, 2, 7, 9, 12, 16, 19, 21, 1, 3, 6, 10, 17, 18, 22, 25, 0, 4, 11, 23, 24, 5},
        {15, 9, 14, 16, 21, 3, 8, 10, 13, 17, 20, 22, 2, 4, 7, 11, 12, 19, 23, 1, 5, 6, 18, 25, 0, 24},
        {16, 10, 15, 17, 22, 4, 9, 11, 14, 21, 23, 3, 5, 8, 13, 20, 2, 7, 12, 19, 1, 6, 18, 25, 0, 24},
        {17, 11, 16, 23, 5, 10, 15, 22, 4, 9, 14, 21, 3, 8, 13, 20, 2, 7, 12, 19, 1, 6, 18, 25, 0, 24},
        {18, 12, 19, 24, 6, 13, 20, 25, 0, 7, 14, 21, 1, 8, 15, 22, 2, 9, 16, 23, 3, 10, 17, 4, 11, 5},
        {19, 13, 18, 20, 25, 7, 12, 14, 21, 24, 1, 6, 8, 15, 22, 0, 2, 9, 16, 23, 3, 10, 17, 4, 11, 5},
        {20, 14, 19, 21, 8, 13, 15, 18, 22, 25, 2, 7, 9, 12, 16, 23, 24, 1, 3, 6, 10, 17, 0, 4, 11, 5},
        {21, 15, 20, 22, 9, 14, 16, 19, 23, 3, 8, 10, 13, 17, 18, 25, 2, 4, 7, 11, 12, 24, 1, 5, 6, 0},
        {22, 16, 21, 23, 10, 15, 17, 20, 4, 9, 11, 14, 19, 3, 5, 8, 13, 18, 25, 2, 7, 12, 24, 1, 6, 0},
        {23, 17, 22, 11, 16, 21, 5, 10, 15, 20, 4, 9, 14, 19, 3, 8, 13, 18, 25, 2, 7, 12, 24, 1, 6, 0},
        {24, 18, 25, 12, 19, 6, 13, 20, 0, 7, 14, 21, 1, 8, 15, 22, 2, 9, 16, 23, 3, 10, 17, 4, 11, 5},
        {25, 19, 24, 13, 18, 20, 7, 12, 14, 21, 1, 6, 8, 15, 22, 0, 2, 9, 16, 23, 3, 10, 17, 4, 11, 5}
    };
    const vector<uint8_t> neighborsByDist[26][10] = {
        {{0}, {1, 6}, {2, 7, 12}, {3, 8, 13, 18}, {4, 9, 14, 19, 24}, {5, 10, 15, 20, 25}, {11, 16, 21}, {17, 22}, {23}, {}},
        {{1}, {0, 2, 7}, {3, 6, 8, 13}, {4, 9, 12, 14, 19}, {5, 10, 15, 18, 20, 25}, {11, 16, 21, 24}, {17, 22}, {23}, {}, {}},
        {{2}, {1, 3, 8}, {0, 4, 7, 9, 14}, {5, 6, 10, 13, 15, 20}, {11, 12, 16, 19, 21}, {17, 18, 22, 25}, {23, 24}, {}, {}, {}},
        {{3}, {2, 4, 9}, {1, 5, 8, 10, 15}, {0, 7, 11, 14, 16, 21}, {6, 13, 17, 20, 22}, {12, 19, 23}, {18, 25}, {24}, {}, {}},
        {{4}, {3, 5, 10}, {2, 9, 11, 16}, {1, 8, 15, 17, 22}, {0, 7, 14, 21, 23}, {6, 13, 20}, {12, 19}, {18, 25}, {24}, {}},
        {{5}, {4, 11}, {3, 10, 17}, {2, 9, 16, 23}, {1, 8, 15, 22}, {0, 7, 14, 21}, {6, 13, 20}, {12, 19}, {18, 25}, {24}},
        {{6}, {0, 7, 12}, {1, 8, 13, 18}, {2, 9, 14, 19, 24}, {3, 10, 15, 20, 25}, {4, 11, 16, 21}, {5, 17, 22}, {23}, {}, {}},
        {{7}, {1, 6, 8, 13}, {0, 2, 9, 12, 14, 19}, {3, 10, 15, 18, 20, 25}, {4, 11, 16, 21, 24}, {5, 17, 22}, {23}, {}, {}, {}},
        {{8}, {2, 7, 9, 14}, {1, 3, 6, 10, 13, 15, 20}, {0, 4, 11, 12, 16, 19, 21}, {5, 17, 18, 22, 25}, {23, 24}, {}, {}, {}, {}},
        {{9}, {3, 8, 10, 15}, {2, 4, 7, 11, 14, 16, 21}, {1, 5, 6, 13, 17, 20, 22}, {0, 12, 19, 23}, {18, 25}, {24}, {}, {}, {}},
        {{10}, {4, 9, 11, 16}, {3, 5, 8, 15, 17, 22}, {2, 7, 14, 21, 23}, {1, 6, 13, 20}, {0, 12, 19}, {18, 25}, {24}, {}, {}},
        {{11}, {5, 10, 17}, {4, 9, 16, 23}, {3, 8, 15, 22}, {2, 7, 14, 21}, {1, 6, 13, 20}, {0, 12, 19}, {18, 25}, {24}, {}},
        {{12}, {6, 13, 18}, {0, 7, 14, 19, 24}, {1, 8, 15, 20, 25}, {2, 9, 16, 21}, {3, 10, 17, 22}, {4, 11, 23}, {5}, {}, {}},
        {{13}, {7, 12, 14, 19}, {1, 6, 8, 15, 18, 20, 25}, {0, 2, 9, 16, 21, 24}, {3, 10, 17, 22}, {4, 11, 23}, {5}, {}, {}, {}},
        {{14}, {8, 13, 15, 20}, {2, 7, 9, 12, 16, 19, 21}, {1, 3, 6, 10, 17, 18, 22, 25}, {0, 4, 11, 23, 24}, {5}, {}, {}, {}, {}},
        {{15}, {9, 14, 16, 21}, {3, 8, 10, 13, 17, 20, 22}, {2, 4, 7, 11, 12, 19, 23}, {1, 5, 6, 18, 25}, {0, 24}, {}, {}, {}, {}},
        {{16}, {10, 15, 17, 22}, {4, 9, 11, 14, 21, 23}, {3, 5, 8, 13, 20}, {2, 7, 12, 19}, {1, 6, 18, 25}, {0, 24}, {}, {}, {}},
        {{17}, {11, 16, 23}, {5, 10, 15, 22}, {4, 9, 14, 21}, {3, 8, 13, 20}, {2, 7, 12, 19}, {1, 6, 18, 25}, {0, 24}, {}, {}},
        {{18}, {12, 19, 24}, {6, 13, 20, 25}, {0, 7, 14, 21}, {1, 8, 15, 22}, {2, 9, 16, 23}, {3, 10, 17}, {4, 11}, {5}, {}},
        {{19}, {13, 18, 20, 25}, {7, 12, 14, 21, 24}, {1, 6, 8, 15, 22}, {0, 2, 9, 16, 23}, {3, 10, 17}, {4, 11}, {5}, {}, {}},
        {{20}, {14, 19, 21}, {8, 13, 15, 18, 22, 25}, {2, 7, 9, 12, 16, 23, 24}, {1, 3, 6, 10, 17}, {0, 4, 11}, {5}, {}, {}, {}},
        {{21}, {15, 20, 22}, {9, 14, 16, 19, 23}, {3, 8, 10, 13, 17, 18, 25}, {2, 4, 7, 11, 12, 24}, {1, 5, 6}, {0}, {}, {}, {}},
        {{22}, {16, 21, 23}, {10, 15, 17, 20}, {4, 9, 11, 14, 19}, {3, 5, 8, 13, 18, 25}, {2, 7, 12, 24}, {1, 6}, {0}, {}, {}},
        {{23}, {17, 22}, {11, 16, 21}, {5, 10, 15, 20}, {4, 9, 14, 19}, {3, 8, 13, 18, 25}, {2, 7, 12, 24}, {1, 6}, {0}, {}},
        {{24}, {18, 25}, {12, 19}, {6, 13, 20}, {0, 7, 14, 21}, {1, 8, 15, 22}, {2, 9, 16, 23}, {3, 10, 17}, {4, 11}, {5}},
        {{25}, {19, 24}, {13, 18, 20}, {7, 12, 14, 21}, {1, 6, 8, 15, 22}, {0, 2, 9, 16, 23}, {3, 10, 17}, {4, 11}, {5}, {}}
    };
    const vector<uint8_t> prefixSum[26] = {
        {1, 3, 6, 10, 15, 20, 23, 25, 26, 26},
        {1, 4, 8, 13, 19, 23, 25, 26, 26, 26},
        {1, 4, 9, 15, 20, 24, 26, 26, 26, 26},
        {1, 4, 9, 15, 20, 23, 25, 26, 26, 26},
        {1, 4, 8, 13, 18, 21, 23, 25, 26, 26},
        {1, 3, 6, 10, 14, 18, 21, 23, 25, 26},
        {1, 4, 8, 13, 18, 22, 25, 26, 26, 26},
        {1, 5, 11, 17, 22, 25, 26, 26, 26, 26},
        {1, 5, 12, 19, 24, 26, 26, 26, 26, 26},
        {1, 5, 12, 19, 23, 25, 26, 26, 26, 26},
        {1, 5, 11, 16, 20, 23, 25, 26, 26, 26},
        {1, 4, 8, 12, 16, 20, 23, 25, 26, 26},
        {1, 4, 9, 14, 18, 22, 25, 26, 26, 26},
        {1, 5, 12, 18, 22, 25, 26, 26, 26, 26},
        {1, 5, 12, 20, 25, 26, 26, 26, 26, 26},
        {1, 5, 12, 19, 24, 26, 26, 26, 26, 26},
        {1, 5, 11, 16, 20, 24, 26, 26, 26, 26},
        {1, 4, 8, 12, 16, 20, 24, 26, 26, 26},
        {1, 4, 8, 12, 16, 20, 23, 25, 26, 26},
        {1, 5, 10, 15, 20, 23, 25, 26, 26, 26},
        {1, 4, 10, 17, 22, 25, 26, 26, 26, 26},
        {1, 4, 9, 16, 22, 25, 26, 26, 26, 26},
        {1, 4, 8, 13, 19, 23, 25, 26, 26, 26},
        {1, 3, 6, 10, 14, 19, 23, 25, 26, 26},
        {1, 3, 5, 8, 12, 16, 20, 23, 25, 26},
        {1, 3, 6, 10, 15, 20, 23, 25, 26, 26}
    };
public:
    int minimumDistance(string word) {
        switch (word.size()) {
            case 2:
                return 0;
            case 3:
                return min({dist[word[0]-'A'][word[1]-'A'],
                            dist[word[0]-'A'][word[2]-'A'],
                            dist[word[1]-'A'][word[2]-'A']});
            default:
                uint16_t ret = 0;
                vector<uint8_t> index(word.begin(), word.end());
                for (auto& i : index)
                    i -= 'A';
                uint8_t c1, c2;
                for (uint8_t dFingers = dist[index[0]][index[1]], i = 2;
                     dFingers < 9 && i < index.size();
                     i++) {
                    if (prefixSum[index[i]][dFingers] == 26)
                        continue;
                    for (auto j = prefixSum[index[i]][dFingers];
                         j < 26;
                         j++) {
                        for (auto k = 0; k < i; k++) {
                            if (neighbors[index[i]][j] == index[k]) {
                                c1 = i; c2 = k;
                                assert(dist[index[i]][index[k]] > dFingers);
                                dFingers = dist[index[i]][index[k]];
                            }
                        }
                    }
                }
                vector<uint8_t> taps({index[c1], index[c1], index[c2], index[c2]});
                for (auto i = 0; i < index.size(); i++) {
                    if (i == c1 || i == c2)
                        continue;
                    vector<uint8_t> dists({dist[index[i]][taps[0]], dist[index[i]][taps[1]],
                                  dist[index[i]][taps[2]], dist[index[i]][taps[3]]});
                    auto d = min_element(dists.begin(), dists.end());
                    ret += *d;
                    taps[d-dists.begin()] = index[i];
                }
                return ret;
        }
    }
};
