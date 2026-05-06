#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Corredor
{
    string nome;
    int tempo;

    bool operator<(const Corredor &c) const
    {
        return nome[0] < c.nome[0];
    }

};

struct Corredores
{
    queue<Corredor> lista_corredores;
    void cadastrarCorredores(Corredor c)
    {
        lista_corredores.push(c);
    }
};

int main()
{
    
}