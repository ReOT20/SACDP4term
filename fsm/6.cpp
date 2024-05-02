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
            case '0': state = 1; break;
            case '1': state = 5;
            }
           break;
        case 1: switch(s[i])
            {
            case '0': state = 2; break;
            case '1': state = 6;
            }
            break;
        case 2: switch(s[i])
            {
            case '0': state = 3; break;
            case '1': state = 7;
            }
            break;
        case 3: switch(s[i])
            {
            case '0': state = 4; break;
            case '1': state = 8;
            }
           break;
        case 4: switch(s[i])
            {
            case '0': state = 0; break;
            case '1': state = 9;
            }
           break;
        case 5: switch(s[i])
            {
            case '0': state = 6; break;
            case '1': state = 10;
            }
           break;
        case 6: switch(s[i])
            {
            case '0': state = 7; break;
            case '1': state = 11;
            }
           break;
        case 7: switch(s[i])
            {
            case '0': state = 8; break;
            case '1': state = 12;
            }
           break;
        case 8: switch(s[i])
            {
            case '0': state = 9; break;
            case '1': state = 13;
            }
           break;
        case 9: switch(s[i])
            {
            case '0': state = 5; break;
            case '1': state = 14;
            }
           break;
        case 10: switch(s[i])
            {
            case '0': state = 11; break;
            case '1': state = 0;
            }
           break;
        case 11: switch(s[i])
            {
            case '0': state = 12; break;
            case '1': state = 1;
            }
           break;
        case 12: switch(s[i])
            {
            case '0': state = 13; break;
            case '1': state = 2;
            }
           break;
        case 13: switch(s[i])
            {
            case '0': state = 14; break;
            case '1': state = 3;
            }
           break;
        case 14: switch(s[i])
            {
            case '0': state = 10; break;
            case '1': state = 4;
            }
           break;
        }
        i++;
    }
    return (state == 0);
}

int main() {
    cout << f("00110110101");
    return 0;
}