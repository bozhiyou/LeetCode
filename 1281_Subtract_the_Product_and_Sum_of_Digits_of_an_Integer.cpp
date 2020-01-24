class Solution {
    /**
     * @Author: Bozhi You (游博智)
     */
public:
    int subtractProductAndSum(int n) {
        int product = 1, sum = 0;
        string s = to_string(n);
        for (auto i : s) {
            product *= i - '0';
            sum += i - '0';
        }
        return product - sum;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().subtractProductAndSum(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
