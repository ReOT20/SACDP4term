
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
                ns.insert(0);
                ns.insert(n + 1);
            } else if (*j <= 10) {
                ns.insert(*j);
                if (n == *j - 1) ns.insert(11);
            }
        }

        states = ns;
        ns.clear();
        i++;
    }
    return (states.count(11) == 1);
}

int main() {
    cout << f("9102110");
    // cout << int(char(57));
    return 0;
}