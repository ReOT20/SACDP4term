#include <iostream>
#include <set>

using namespace std;

bool f(const string& s) {
    set<int> states;
    set<int> ns;
    int n;
    states.insert(0);
    long unsigned int i = 0;
    set<int>::iterator j;
    while (s[i] != '\0')
    {
        n = int(s[i]) - 48;

        for (j = states.begin(); j !=states.end(); j++) {
            if (*j == 0) {
                for (int m = 0; m < 10; m++) {
                    if (m != n) ns.insert(m + 1);
                }
            } else if (*j <= 10) {
                if (n == *j - 1) ns.insert(11);
                else ns.insert(*j);
            }
        }

        states = ns;
        ns.clear();
        i++;
    }
    return (states.count(11) == 1);
}

int main() {
    cout << f("912110");
    // cout << int(char(57));
    return 0;
}