#include <iostream>
using namespace std;

class Produto
{
    string nome;
    double preco;

public:
    string getNome()
    {
        return nome;
    }

    double getPreco()
    {
        return preco;
    }
};

class ProdutoLimpeza : public Produto
{
    enum tipoUso
    {
        DOMESTICO,
        HOSPITALAR,
        INDUSTRIAL
    };
};