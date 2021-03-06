#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <ctime>

using namespace std;
struct node {
    int val;
    bool operator < (const node& a) const {
        return val < a.val ? false : true;
    }
};
class cmp {
public :
    bool operator() (const node &a, const node &b) const {
        return a < b;
    }
};
/**
 * 消除重复的单词
 * @return
 */
void eliminateDuplicates(vector<string> &words) {
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());

    words.erase(end_unique, words.end());
}
auto f = [] (const string &s) {cout << s << " " ;};
int main() {
    cout << "Hello, World!" << endl;
    unsigned  u = 10;
    int i = -42;
    cout << i + i << endl;
    cout << u + i << endl;
    auto sss = "AAAAAAAAAAAAAAAAAAAAAA";
    string s1(10, 'A');
    for (auto c : s1)
        cout << c << "," ;
    decltype(s1.size()) p = 0;
    string::size_type n;
//    std::auto_ptr<string> ps(new std::string(s));
//    std::shared_ptr<string> ps1(new string(s));
//    std::unique_ptr<string> ps2(new string(s));

    priority_queue<node, vector<node>, cmp> q;
    node a, b, c, d;
    a.val = 5;
    b.val = 4;
    c.val = 2;
    d.val = 10;
    q.push(a);
    q.push(b);
    q.push(c);
    q.push(d);
    while (!q.empty()) {
        cout << q.top().val << "  ";
        q.pop();
    }
    string str;
    str.substr(8);
    //auto c = str.begin();
    //cout << stoi("123") << " " << iots(123) << endl;
    vector<int> vec;
    fill_n(back_inserter(vec), 10, 0);

   // auto it = back_inserter(vec);
   //*it = 42;

    int a1[] = {0,1,2,3,4,5,6,7,8,9};
    int a2[sizeof(a1)/sizeof(*a1)];
    auto ret = copy(begin(a1), end(a1), a2);

    vector<string> test={"fox","jumps", "over", "quick", "red", "red", "the", "slow", "the", "turtle"};
    cout << endl;
    eliminateDuplicates(test);
//    for (auto c: test)
//        cout << c << " ";
    auto sz = 4;
    auto wc = find_if(test.begin(), test.end(),
    [sz](const string &s) {return s.size() >= sz ;});

    for_each(wc, test.end(), f);

    int N;
    while (cin >> N) {
        srand(time(NULL));
        int i = 0;
        vector<int> arr;

        while (i < N) {
            int tmp = rand() % 1000 + 1;
            arr.push_back(tmp);
            i++;
        }
        sort(arr.begin(), arr.end());
        cout << arr.size() << endl;
        vector<int>::iterator it = arr.begin() + 1;
        while (it != arr.end()) {
            if (*it == *(it - 1))
                it = arr.erase(it);
            else
                it++;
        }
        cout << arr.size() << endl;
        for (auto c: arr) {
            cout << c << " ";
        }
        cout << endl;
    }
    unordered_map<int, int> map;
    return 0;
}