#include <iostream>
using namespace std;

class ContaBancaria
{
    string titular;
    string numeroConta;
    double saldo;

public:
    ContaBancaria(string tit, string nc, double sld) : titular(tit), numeroConta(nc), saldo(sld)
    {
        if (sld < 0)
        {
            sld = 0.0;
        }
    }

    string getTitular()
    {
        return this->titular;
    }

    string getNumeroConta()
    {
        return this->numeroConta;
    }

    double getSaldo()
    {
        return this->saldo;
    }

    double depositar(double valor)
    {
        if (valor > 0)
        {
            valor + getSaldo();
        }
        else
        {
            cerr << "O valor informado é menor do que zero! Tente novamente.";
        }
    }

    double sacar(double valor)
    {
        if (valor > 0 && getSaldo() >= valor)
        {
            getSaldo() - valor;
        }
        else
        {
            if(valor > 0){
                
            }
        }
    }
};