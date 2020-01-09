/**
 *Validate if a given string can be interpreted as a decimal number.
 */
class Solution {
public:
    bool isNumber(string s) {
        if (s.size() == 0)
            return false;
        // strip whitespace
        auto i = s.begin();
        while (isspace(*i)) {
            if (++i == s.end())
                return false;
        }
        uint8_t flag = 0; // 0: init, 1: dot, 2: sci
        // first sign
        switch (*i) {
            case '.':
                flag = 1; // ".0" is valid
            // signed
            case '+':
            case '-':
                if (++i == s.end())
                    return false;
                // first integral digit
                if (*i == '.' && 0 == flag) {
                    i++; // "+.0" is valid
                    flag = 1;
                }
            // unsigned
            default:
                if (*i > '9' || *i < '0')
                    return false;
                if (++i == s.end())
                    return true;
        }
        // skip integeral digits (part-I)
        while ('0' <= *i && *i <= '9') {
            if (++i == s.end())
                return true;
        }
        // strip tail whitespace
        if (isspace(*i)) {
            do {
                if (++i == s.end())
                    return true;
            } while (isspace(*i));
            return false;
        }
        // first separator
        switch (*i) {
            case '.':
                if (1 == flag) // "dot-dot (or e-dot, impossible here)"
                    return false;
                flag = 1;
                if (++i == s.end())
                    return true; // "0." is valid
                break;
            case 'e':
                flag = 2;
                if (++i == s.end())
                    return false;
                switch (*i) {
                    case '+':
                    case '-':
                        if (++i == s.end())
                            return false;
                    default:
                        break;
                }
            // should not directly get here
            default:
                // first decimal digit
                if ((*i > '9' || *i < '0'))
                    return false;
                if (++i == s.end())
                    return true;
        }
        // skip decimal digits (part-II)
        while ('0' <= *i && *i <= '9') {
            if (++i == s.end())
                return true;
        }
        // strip tail whitespace
        if (isspace(*i)) {
            do {
                if (++i == s.end())
                    return true;
            } while (isspace(*i));
            return false;
        }
        // second separator
        switch (*i) {
            // scientific
            case 'e':
                if (2 == flag) // "...e...e..."
                    return false;
                if (++i == s.end())
                    return false;
                // now it's sci-number
                switch (*i) {
                    case '+':
                    case '-':
                        if (++i == s.end())
                            return false;
                    default:
                        break;
                }
            // should not directly get here
            default:
                // first exponent digit
                if (*i > '9' || *i < '0')
                    return false;
                if (++i == s.end())
                    return true;
        }
        // skip exponent digits (part-III)
        while ('0' <= *i && *i <= '9') {
            if (++i == s.end())
                return true;
        }
        // strip tail whitespace
        while (isspace(*i)) {
            if (++i == s.end())
                return true;
        }
        return false;
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
        string s = stringToString(line);
        
        bool ret = Solution().isNumber(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
