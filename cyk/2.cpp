

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
            case '0': M[l][l].insert('B'); break;
            case '1': M[l][l].insert('C'); break;
            default: cerr<<"Unknown terminal symbol!"<<endl; 
                     exit(1);
        }
    for(j = 1; j<l; j++)
        for(i = 0; i+j<l; i++)
            for(k = i; k<i+j; k++)              
            {
                if(M[i][k].count('B')>0 &&
                    M[k+1][i+j].count('B')>0)
                        M[i][i+j].insert('S');
                if(M[i][k].count('B')>0 &&
                    M[k+1][i+j].count('D')>0)
                        M[i][i+j].insert('S');
                if(M[i][k].count('A')>0 &&
                    M[k+1][i+j].count('B')>0)
                        M[i][i+j].insert('D');
                if(M[i][k].count('C')>0 &&
                    M[k+1][i+j].count('C')>0)
                        M[i][i+j].insert('S');
                if(M[i][k].count('C')>0 &&
                    M[k+1][i+j].count('E')>0)
                        M[i][i+j].insert('S');
                if(M[i][k].count('A')>0 &&
                    M[k+1][i+j].count('C')>0)
                        M[i][i+j].insert('E');
                if(M[i][k].count('B')>0 &&
                    M[k+1][i+j].count('B')>0)
                        M[i][i+j].insert('A');
                if(M[i][k].count('B')>0 &&
                    M[k+1][i+j].count('D')>0)
                        M[i][i+j].insert('A');
                if(M[i][k].count('C')>0 &&
                    M[k+1][i+j].count('C')>0)
                        M[i][i+j].insert('A');
                if(M[i][k].count('C')>0 &&
                    M[k+1][i+j].count('E')>0)
                        M[i][i+j].insert('A');
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

