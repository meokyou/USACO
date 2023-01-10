/*
ID: christi104
TASK: friday
LANG: C++
*/

// Chapter 1, section 1.2, solution 3
// Last edit 26 December 2022 15:53
#include <bits/stdc++.h>
using namespace std;

int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap(int year)
{
    if (year % 100 == 0)
    {
        if (year % 400 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (year % 4 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int length(int month, bool leap_year)
{
    if (month == 2 && leap_year == true)
        return 29;
    else
        return months[month - 1];
}

int main(int argc, char *argv[])
{
    // File init
    ifstream fin("friday.in");
    ofstream fout("friday.out");

    long long n;
    fin >> n;
    int dotw = 1, ans[7];

    int i = 0;
    do
    {
        ans[i] = 0;
        i++;
    } while (i != 7);

    // Loops through years, months, and days
    for (int y = 1900; y < 1900 + n; y++)
    {
        bool in_year = is_leap(y);
        for (int m = 1; m <= 12; m++)
        {
            int in_month = length(m, in_year);
            for (int d = 1; d <= in_month; d++)
            {
                // Checks then stores 13th day of the month
                if (d == 13)
                    ans[dotw - 1] += 1;

                dotw = (dotw == 7) ? 1 : (dotw + 1);
            }
        }
    }

    // Print solution
    fout << ans[5] << " " << ans[6] << " ";
    for (int i = 0; i < 4;)
    {
        fout << ans[i] << " ";
        i++;
    }
    fout << ans[4] << std::endl;
    return 0;
}
