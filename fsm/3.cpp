#include <iostream>

using namespace std;

bool f(const string& s) {
    int state = 1;
    long unsigned int i = 0;
    while (s[i] != '\0')
    {
        switch (state)
        {
        case 1: switch(s[i])
            {
            case '0': state = 2; break;
            case '1': state = 1;
            }
            break;
        case 2: switch(s[i])
            {
            case '0': state = 3; break;
            case '1': state = 1;
            }
            break;
        case 3: switch(s[i])
            {
            case '0': state = 3; break;
            case '1': state = 1;
            }
           break;
        }
        i++;
    }
    return state == 3;
}

int main() {
    cout << f("1101100");
    return 0;
}