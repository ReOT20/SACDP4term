

#include <set>
#include <iostream>
#include <cstdlib>

using namespace std;

set<char> M[50][50];

ostream &operator<<(ostream &ost, set<char> S)
{
    for(set<char>::iterator i = S.begin(); i != S.end(); i++)
        ost<<*i;
    return ost;
}

bool cyk(char *s)
{
    int i, j, k, l;
    for(l = 0; l<50 && s[l]!=0; l++)
        switch(s[l])
        {
            case '(': M[l][l].insert('Y'); break;
            case ')': M[l][l].insert('Z'); break;
            case '+': M[l][l].insert('Q'); break;
            case '-': M[l][l].insert('U'); break;
            case '*': M[l][l].insert('V'); break;
            case '/': M[l][l].insert('W'); break;
            case '0': M[l][l].insert('S');
                M[l][l].insert('D');
                M[l][l].insert('A');
                M[l][l].insert('E'); break;
            case '1': M[l][l].insert('S');
                M[l][l].insert('D');
                M[l][l].insert('B');
                M[l][l].insert('E'); break;
            case '2': M[l][l].insert('S');
                M[l][l].insert('D');
                M[l][l].insert('C');
                M[l][l].insert('E'); break;
            case '3': M[l][l].insert('S');
                M[l][l].insert('D');
                M[l][l].insert('F');
                M[l][l].insert('E'); break;
            case '4': M[l][l].insert('S');
                M[l][l].insert('D');
                M[l][l].insert('G');
                M[l][l].insert('E'); break;
            case '5': M[l][l].insert('S');
                M[l][l].insert('D');
                M[l][l].insert('H');
                M[l][l].insert('E'); break;
            case '6': M[l][l].insert('S');
                M[l][l].insert('I');
                M[l][l].insert('D');
                M[l][l].insert('E'); break;
            case '7': M[l][l].insert('S');
                M[l][l].insert('D');
                M[l][l].insert('E');
                M[l][l].insert('J'); break;
            case '8': M[l][l].insert('S');
                M[l][l].insert('E');
                M[l][l].insert('D');
                M[l][l].insert('K'); break;
            case '9': M[l][l].insert('S');
                M[l][l].insert('E');
                M[l][l].insert('D');
                M[l][l].insert('L'); break;
            default: cerr<<"Unknown terminal symbol!"<<endl; 
                     exit(1);
        }
    for(j = 1; j<l; j++)
        for(i = 0; i+j<l; i++)
            for(k = i; k<i+j; k++)              
            {
                if(M[i][k].count('Y')>0 &&
                        M[k+1][i+j].count('R')>0)
                            M[i][i+j].insert('S');
                if(M[i][k].count('E')>0 &&
                        M[k+1][i+j].count('Z')>0)
                            M[i][i+j].insert('R');
                if(M[i][k].count('Q')>0 &&
                        M[k+1][i+j].count('E')>0)
                            M[i][i+j].insert('P');
                if(M[i][k].count('U')>0 &&
                        M[k+1][i+j].count('E')>0)
                            M[i][i+j].insert('M');
                if(M[i][k].count('V')>0 &&
                        M[k+1][i+j].count('E')>0)
                            M[i][i+j].insert('T');
                if(M[i][k].count('W')>0 &&
                        M[k+1][i+j].count('E')>0)
                            M[i][i+j].insert('O');
                if(M[i][k].count('E')>0 &&
                        M[k+1][i+j].count('P')>0)
                            M[i][i+j].insert('S');
                if(M[i][k].count('E')>0 &&
                        M[k+1][i+j].count('M')>0)
                            M[i][i+j].insert('S');
                if(M[i][k].count('E')>0 &&
                        M[k+1][i+j].count('T')>0)
                            M[i][i+j].insert('S');
                if(M[i][k].count('E')>0 &&
                        M[k+1][i+j].count('O')>0)
                            M[i][i+j].insert('S');
                if(M[i][k].count('Y')>0 &&
                        M[k+1][i+j].count('R')>0)
                            M[i][i+j].insert('E');
                if(M[i][k].count('E')>0 &&
                        M[k+1][i+j].count('P')>0)
                            M[i][i+j].insert('E');
                if(M[i][k].count('E')>0 &&
                        M[k+1][i+j].count('M')>0)
                            M[i][i+j].insert('E');
                if(M[i][k].count('E')>0 &&
                        M[k+1][i+j].count('T')>0)
                            M[i][i+j].insert('E');
                if(M[i][k].count('E')>0 &&
                        M[k+1][i+j].count('O')>0)
                            M[i][i+j].insert('E');
                if(M[i][k].count('A')>0 &&
                        M[k+1][i+j].count('D')>0)
                            M[i][i+j].insert('S');
                if(M[i][k].count('B')>0 &&
                        M[k+1][i+j].count('D')>0)
                            M[i][i+j].insert('S');
                if(M[i][k].count('C')>0 &&
                        M[k+1][i+j].count('D')>0)
                            M[i][i+j].insert('S');
                if(M[i][k].count('F')>0 &&
                        M[k+1][i+j].count('D')>0)
                            M[i][i+j].insert('S');
                if(M[i][k].count('G')>0 &&
                        M[k+1][i+j].count('D')>0)
                            M[i][i+j].insert('S');
                if(M[i][k].count('H')>0 &&
                        M[k+1][i+j].count('D')>0)
                            M[i][i+j].insert('S');
                if(M[i][k].count('I')>0 &&
                        M[k+1][i+j].count('D')>0)
                            M[i][i+j].insert('S');
                if(M[i][k].count('J')>0 &&
                        M[k+1][i+j].count('D')>0)
                            M[i][i+j].insert('S');
                if(M[i][k].count('K')>0 &&
                        M[k+1][i+j].count('D')>0)
                            M[i][i+j].insert('S');
                if(M[i][k].count('L')>0 &&
                        M[k+1][i+j].count('D')>0)
                            M[i][i+j].insert('S');
                if(M[i][k].count('A')>0 &&
                        M[k+1][i+j].count('D')>0)
                            M[i][i+j].insert('E');
                if(M[i][k].count('B')>0 &&
                        M[k+1][i+j].count('D')>0)
                            M[i][i+j].insert('E');
                if(M[i][k].count('C')>0 &&
                        M[k+1][i+j].count('D')>0)
                            M[i][i+j].insert('E');
                if(M[i][k].count('F')>0 &&
                        M[k+1][i+j].count('D')>0)
                            M[i][i+j].insert('E');
                if(M[i][k].count('G')>0 &&
                        M[k+1][i+j].count('D')>0)
                            M[i][i+j].insert('E');
                if(M[i][k].count('H')>0 &&
                        M[k+1][i+j].count('D')>0)
                            M[i][i+j].insert('E');
                if(M[i][k].count('I')>0 &&
                        M[k+1][i+j].count('D')>0)
                            M[i][i+j].insert('E');
                if(M[i][k].count('J')>0 &&
                        M[k+1][i+j].count('D')>0)
                            M[i][i+j].insert('E');
                if(M[i][k].count('K')>0 &&
                        M[k+1][i+j].count('D')>0)
                            M[i][i+j].insert('E');
                if(M[i][k].count('L')>0 &&
                        M[k+1][i+j].count('D')>0)
                            M[i][i+j].insert('E');
            }
    cout<<"L="<<l<<endl;
    for(i = 0; i<l; i++)
    {
        for(j = 0; j<l; j++)
            cout<<M[i][j]<<'\t';
        cout<<endl;
    }
    return l==0 || M[0][l-1].count('S')>0;
}

int main()
{
    char s[50];
    cin.getline(s, 50);
    if(cyk(s))
       cout<<"yes"<<endl;
    else
       cout<<"no"<<endl;
    return EXIT_SUCCESS;
}

