/*
ID: christi104
LANG: C++14
PROG: gift1
*/
#include <fstream>

int findElement(std::string x, std::string arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (x == arr[i])
            return i;
    }
    return 0;
}

int main()
{
    std::ifstream fin ("gift1.in");
    std::ofstream fout ("gift1.out");
    int NP = 0;
    fin >> NP;

    int balance[NP + 1];
    for (int i = 0; i < NP; i++)
        balance[i] = 0;


    int amount, transactions, distribution, index, K;
    std::string query, recipient;
    std::string name[NP + 1];
    for (int i = 0; i < NP; i++)
        fin >> name[i];
    for (int j = 0; j < NP; j++)
    {

        fin >> query;
        fin >> amount >> transactions;
        if (amount > 0 && transactions > 0)
        {
            distribution = amount / transactions;
            K = findElement(query, name, NP);
            for (int i = 0; i < transactions; i++)
            {
                fin >> recipient;
                index = findElement(recipient, name, NP);
                balance[index] = balance[index] + distribution;
            }
            balance[K] = balance[K] - (transactions * distribution);
            
        }
        else
        {
            for (int i = 0; i < transactions; i++)
            {
                fin >> recipient;
            }
        }
    }

    for (int c = 0; c < NP; c++)
        fout << name[c] << " " << balance[c] << std::endl;

    return 0;  

}