class Solution {
public:
    bool distinct(vector<int>::iterator& i, vector<int>::const_iterator&& j, int& d) {
        for (d = *i; i != j; i++) {
            if (*i != d)
                return false;
        }
        return true;
    }
    int thirdMax(vector<int>& nums) {
        switch (nums.size()) {
            default: {
                int x, y, z;
                auto i = nums.begin();
                if (distinct(i, nums.cend(), x))
                    return x;
                if (distinct(i, nums.cend(), y))
                    return x > y? x : y;
                if (distinct(i, nums.cend(), z))
                    return x < y?
                            (x < z? x : (x == z? y : z)):
                            (y < z? y : z);
                
                std::make_heap(nums.begin(), nums.end());
                i = nums.end();
                do {
                    std::pop_heap(nums.begin(), i--);
                } while (*i == nums[0]);
                do {
                    std::pop_heap(nums.begin(), i--);
                } while (*i == nums[0]);
                return nums[0];
            }
            case 1:
                return nums[0];
            case 2:
                return nums[0] > nums[1]? nums[0] : nums[1];
        }
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().thirdMax(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
