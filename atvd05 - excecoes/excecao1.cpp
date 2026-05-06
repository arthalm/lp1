#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, i;
    vector<int> vetor;

    for (int i = 0; i < 5; i++)
    {
        cout << "Digite um número qualquer: ";
        cin >> n;
        vetor.push_back(n);
    }

    cout << "Agora, digite um índice para acessar um valor no vector: ";
    cin >> i;

    try
    {
        cout << vetor.at(i);
    }
    catch (const out_of_range &e)
    {
        cerr << "Erro! Índice inserido está fora do limite do vector." << e.what() << endl;
    }
}