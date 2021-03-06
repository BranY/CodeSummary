//
// Created by BranY on 2016/9/8.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// https://leetcode.com/problems/decode-string/

#include <iostream>
#include <cstdio>
#include <unistd.h>

using namespace std;
/**
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 */
string help(string &s, int &pos) {
    int num = 0;
    string res = "";
    for(; pos < s.size(); pos++) {
        char cur = s[pos];
        if(cur == '[') {
            string curStr = help(s, ++pos);
            for(; num > 0; num--) res += curStr;
            num = 0;
        } else if (cur >= '0' && cur <='9') {
            num = num * 10 + (cur - '0');
        } else if (cur == ']') {
            return res;
        } else {    // Normal characters
            res += cur;
        }
    }
    return res;
}
string decodeString(string s) {
    int pos = 0;
    return help(s, pos);
}

int main() {
    string str;
    while (getline(cin, str)) {
        cout << decodeString(str) << endl;
    }

    return 0;
}
