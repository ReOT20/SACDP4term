#include <iostream>
#include <set>

using namespace std;

bool f(const string& s) {
    set<int> states;
    set<int> ns;
    states.insert(0);
    long unsigned int i = 0;
    set<int>::iterator j;
    while (s[i] != '\0')
    {
        for (j = states.begin(); j !=states.end(); j++) {
            switch (*j)
            {
            case 0: switch(s[i])
                {
                case '0': ns.insert(0); break;
                case '1': ns.insert(0), ns.insert(1);
                }
               break;
            case 1: switch(s[i])
                {
                default: ns.insert(2);
                }
                break;
            case 2: switch(s[i])
                {
                default: ns.insert(3);
                }
                break;
            case 3: switch(s[i])
                {
                default: ns.insert(4);
                }
                break;
            case 4: switch(s[i])
                {
                default: ns.insert(5);
                }
                break;
            case 5: switch(s[i])
                {
                default: ns.insert(6);
                }
                break;
            case 6: switch(s[i])
                {
                default: ns.insert(7);
                }
                break;
            case 7: switch(s[i])
                {
                default: ns.insert(8);
                }
                break;
            case 8: switch(s[i])
                {
                default: ns.insert(9);
                }
                break;
            case 9: switch(s[i])
                {
                default: ns.insert(10);
                }
                break;
            }
        }
        states = ns;
        ns.clear();
        i++;
    }
    return (states.count(10) == 1);
}

int main() {
    cout << f("0101100000000");
    return 0;
}