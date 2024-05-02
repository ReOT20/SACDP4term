#include <iostream>

using namespace std;

bool f(const string& s) {
    int state = 0;
    long unsigned int i = 0;
    while (s[i] != '\0')
    {
        switch (state)
        {
        case 0: switch(s[i])
            {
            case '0': state = 0; break;
            case '1': state = 2;
            }
           break;
        case 1: switch(s[i])
            {
            case '0': state = 3; break;
            case '1': state = 0;
            }
            break;
        case 2: switch(s[i])
            {
            case '0': state = 1; break;
            case '1': state = 3;
            }
            break;
        case 3: switch(s[i])
            {
            case '0': state = 4; break;
            case '1': state = 1;
            }
           break;
        case 4: switch(s[i])
            {
            case '0': state = 2; break;
            case '1': state = 4;
            }
           break;
        }
        i++;
    }
    return (state == 0);
}

int main() {
    cout << f("10001001");
    return 0;
}