/*
ID: christi104
TASK: ride
LANG: C++
*/
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define arr array
#define v  vector
#define pb push_back
#define gl getline

using namespace std;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ifstream fin ("ride.in");
    ofstream fout ("ride.out");
    
    string ln1, ln2;
    arr <int, 2> prod = {};

    fill(prod.begin(), prod.end(), 1);
    fin >> ln1 >> ln2;
    
    for (int i = 0; i < ln1.size(); i++)
    {
        prod[0] = prod[0] * ((int)(ln1[i]) - 64);
    }

    for (int j = 0; j < ln2.size(); j++)
    {
        prod[1] = prod[0] * ((int)(ln2[j]) - 64);
    }
    
    if (prod[0] % 47 == prod[1] % 47)
    {
        fout << "GO" << endl;
    }
    else
    {
        fout << "STAY" << endl;
    }
    return 0;
}
