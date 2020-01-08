// WRONG
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
            // unsigned
            default:
                // first integral digit
                if (*i == '.' && 0 == flag) {
                    i++; // "+.0" is valid
                    flag = 1;
                }
                else if (*i > '9' || *i < '0')
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
            case 'e':
                flag = (flag == 1? 1 : 2);
                if (++i == s.end())
                    return (1 == flag); // "0." is valid
                if (2 == flag) {
                    switch (*i) {
                        case '+':
                        case '-':
                            if (++i == s.end())
                                return false;
                        default:
                            break;
                    }
                }
            // should not directly get here
            default:
                // first decimal digit
                if (*i > '9' || *i < '0')
                    return (0 == flag);
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
                // now it's sci-number: sci = true
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
