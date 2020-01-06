class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() < 2 || A.size() != B.size())
            return false;
        char a, b;                // 2 byte
        uint8_t n = 0;            // 1 byte
        bool self_buddy = false;  // 1 byte
        string check("");
        for (auto x = A.begin(), y = B.begin();
            x != A.end(); x++, y++) {
            if (*x != *y) {
                switch (++n) {
                    default:
                        return false;
                    case 1:
                        a = *x;
                        b = *y;
                        break;
                    case 2:
                        if (a != *y || b != *x)
                            return false;
                        break;
                }
            }
            if (!self_buddy) {
                for (auto i = check.begin(); i != check.end(); i++) {
                    if (*i == *x) {
                        self_buddy = true;
                        break;
                    }
                }
                if (!self_buddy) {
                    check += *x;
                }
            }
        }
        return self_buddy || (n > 0);
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string A = stringToString(line);
        getline(cin, line);
        string B = stringToString(line);
        
        bool ret = Solution().buddyStrings(A, B);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
