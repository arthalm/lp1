#include <iostream>
using namespace std;

class Produto
{
    string nome;
    double preco;

public:
    void setNome(string nm)
    {
        nome = nm;
    }

    void setPreco(double pr)
    {
        preco = pr;
    }

    virtual void exibirInformacoes()
    {
        cout << "DADOS DO PRODUTO\nNome: " << nome << "\nPreço (R$): " << preco << '\n';
    }
};

class ProdutoLimpeza : public Produto
{
    string tipoUso;

public:
    void setTipo(string tp)
    {
        if (tp == "Doméstico" || tp == "Hospitalar" || tp == "Industrial")
        {
            tipoUso = tp;
        }
        else
        {
            throw invalid_argument("O tipo de produto digitado não está correto!");
        }
    }

    void exibirInformacoes()
    {
        cout << "Tipo de produto: " << tipoUso << endl;
    };
};

class ProdutoAlimenticio : public Produto
{
    string validade;

public:
    void setValidade(string vd)
    {
        validade = vd;
    }

    void exibirInformacoes()
    {
        cout << "Validade do produto (DD/MM/AAAA): " << validade << endl;
    }
};

class ProdutoEletronico : public Produto
{
    int voltagem;
    int garantia;

public:
    void setVoltagem(int vt)
    {
        voltagem = vt;
    }

    void setGarantia(int gr)
    {
        garantia = gr;
    }

    void exibirInformacoes()
    {
        cout << "Voltagem (V): " << voltagem << "\nGarantia (anos): " << garantia << endl;
    }
};

int main()
{
    ProdutoLimpeza pl;

    pl.setNome("Vanish");
    pl.setPreco(34.99);
    pl.setTipo("Doméstico");
    pl.exibirInformacoes();
}