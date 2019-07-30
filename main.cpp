#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

// https://leetcode.com/problems/long-pressed-name/

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isLongPressedName(string& name, string& typed) {
        if (typed.length() < name.length()) return false;
        int i = 0;
        int j = 0;
        while (i < name.length() && j < typed.length()) {
            if (name[i] == typed[j]) {
                ++i;
                ++j;
            } else {
                if ((j > 0) && (typed[j-1] == typed[j])) {
                    ++j;
                } else {
                    return false;
                }
            }
        }
        if (i != name.length()) return false;
        while ((j > 0) && (j < typed.length()) && typed[j] == typed[j-1]) ++j;
        return j == typed.length();
    }
};

void test1() {
    string name = "alex", typed = "aaleex";


//    cout << "1 ? " << Solution().isLongPressedName(name, typed) << endl;
//
//    name = "saeed", typed = "ssaaedd";
//
//    cout << "0 ? " << Solution().isLongPressedName(name, typed) << endl;

    name = "sxrmc"; typed = "sxxrrmmc";

    cout << "1 ? " << Solution().isLongPressedName(name, typed) << endl;

}

void test2() {

}

void test3() {

}