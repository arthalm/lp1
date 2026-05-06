#include <iostream>
using namespace std;

struct Conta
{
    string nome;
    double saldo;
};

class Operacoes
{
public:

    void fazerSaque(double saque)
    {
        Conta c;
        c.saldo - saque;
    }
};