#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class BrowserHistory {
private:
    vector<string> history;
    int currentIndex;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        currentIndex = 0;
    }
    void visit(string url) {
        history.resize(currentIndex + 1);
        history.push_back(url);
        currentIndex++;
    }
    string back(int steps) {
        currentIndex = max(0, currentIndex - steps);
                //max to ensure it never goes beyond 0 i.e. neg
        return history[currentIndex];
    }
    string forward(int steps) {
        currentIndex = min((int)history.size() - 1, currentIndex + steps);
        return history[currentIndex];
    }
};
int main() {
    BrowserHistory browser("leetcode.com");
    browser.visit("google.com");
    browser.visit("facebook.com");
    browser.visit("youtube.com");
    cout << browser.back(1) << endl;  // facebook.com
    cout << browser.back(1) << endl;  // google.com
    cout << browser.forward(1) << endl;  // facebook.com
    browser.visit("linkedin.com");
    cout << browser.forward(2) << endl;  // linkedin.com
    cout << browser.back(2) << endl;  // google.com
    cout << browser.back(7) << endl; //leetcode
    return 0;
}
