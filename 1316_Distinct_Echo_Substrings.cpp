class Solution {
public:
    int distinctEchoSubstrings(string text) {
        switch (text.size()) {
            case 1: // length of echo substrings >= 2
                return 0;
            case 2: // at most 1 echo substring (itself)
                return (text[0] == text[1]);
            case 3: // at most 1 echo substring
                return (text[0] == text[1]) || (text[1] == text[2]);
            default: {
                uint16_t ret = 0; // at most half of the text length (max 1000 here)
                for (uint16_t i = 0; i < text.size()-1; i++) // don't care about the last letter
                    for (uint16_t ii = text.find(text[i], i+1);
                         string::npos != ii
                         && (ii << 1) <= i + text.size(); // possible echo length
                         ii = text.find(text[i], ii+1) // longer match
                        )
                        if (text.substr(i, ii-i) == text.substr(ii, ii-i) // "echo"
                            && text.find(text.substr(i, (ii-i)<<1), 0) == i // "distinct"
                           )
                            ++ret;
                return ret;
            }
        }
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
        string text = stringToString(line);
        
        int ret = Solution().distinctEchoSubstrings(text);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
