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

    void exibirInformacoes() override
    {
        Produto::exibirInformacoes();
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

    void exibirInformacoes() override
    {
        Produto::exibirInformacoes();
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

    void exibirInformacoes() override
    {
        Produto::exibirInformacoes();
        cout << "Voltagem (V): " << voltagem << "\nGarantia (anos): " << garantia << endl;
    }
};

int main()
{
    int operacao;

    cout << "SUPERMERCADO LYMPIA\nO que deseja realizar?\n1 - Cadastrar novo produto\n0 - Sair\nSua escolha: ";
    cin >> operacao;

    if (operacao == 1)
    {
        while (operacao != 0)
        {
            cout << "Qual tipo de produto você deseja cadastrar?\n1 - Produto de limpeza\n2 - Produto alimentício\n3 - Produto eletrônico\n4 - Sair\nSua escolha: ";
            cin >> operacao;
            if (operacao == 1)
            {
                ProdutoLimpeza* pl = new ProdutoLimpeza();
                string nm, tipo;
                double pr;
                cout << "Digite o nome do produto: ";
            }
        }
    }
    else if (operacao == 0)
    {
        cout << "Saindo..." << endl;
    }
    else
    {
        throw invalid_argument("Erro! A operação digitada não está disponível. Tente novamente.");
    }
}