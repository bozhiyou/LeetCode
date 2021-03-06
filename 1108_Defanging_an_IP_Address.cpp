class Solution {
public:
    /**
     * @Author: Bozhi You (游博智)
     */
    string defangIPaddr(const string& address) const {
        string ret("");
        for (auto c : address)
            switch (c) {
                default:
                    ret += c;
                    break;
                case '.':
                    ret += "[.]";
            }
        return ret;
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

int main() {
    string line;
    while (getline(cin, line)) {
        string address = stringToString(line);
        
        string ret = Solution().defangIPaddr(address);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
