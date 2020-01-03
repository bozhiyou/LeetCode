/**
 * Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.
 */

class Solution {
public:
  bool checkPossibility(vector<int>& nums) {
    if (nums.size() < 3) // trivial case
      return true;
    assert(nums.size() >= 3); // at least [0], [1], [2]
    int first = nums[0], second = nums[1]; // the first "edge"
    int c = 0; // counter for bad edges - at most 1
    
    for (auto i = 2; // num[2] is the first "node" after the first edge
         i < nums.size(); i++) {
      // bad edge (first, second)
      if (first > second) {
        if (++c > 1)
          return false;
        // bad node - then bad edge (second, nums[i])
        if (second > nums[i]) {
          if (++c > 1)
            return false;
        }
        // good node - not so bad :)
        else { assert(second <= nums[i]);
          // fix first and move on with good edge (second, nums[i])
          if (first > nums[i]) {
            first = second;
          }
          // fix second and move on with to (first, nums[i])
          else { assert(first <= nums[i]); }
          second = nums[i];
        }
      }
      // good edge :)
      else { assert(first <= second);
        // good edge - move on!
        if (second <= nums[i]) {
          first = second;
          second = nums[i];
        }
        // bad node - then bad edge (second, nums[i])
        else { assert(nums[i] < second);
          if (++c > 1)
            return false;
          // since we have a good edge- not so bad :)
          // fix second and move on with edge (first, nums[i])
          if (first <= nums[i]) {
            second = nums[i];
          }
          // just fix the bad node nums[i] and move on
          else { assert(nums[i] < first);
          }
        }
      }
      std::cout << first << second << std::endl;
    }
    return true;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        bool ret = Solution().checkPossibility(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
