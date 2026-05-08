#include <iostream>
#include <vector>
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
    vector<Produto *> lista_exibicao;

    cout << "SUPERMERCADO LYMPIA\nO que deseja realizar?\n1 - Cadastrar produto de limpeza\n2 - Cadastrar produto alimentício\n3 - Cadastrar produto eletrônico\n4 - Exibir lista de produtos cadastrados\n0 - Sair\nSua escolha: ";
    cin >> operacao;

    while (operacao != 0)
    {
        if (operacao == 1)
        {
            ProdutoLimpeza *pl = new ProdutoLimpeza();
            string nm, tipo;
            double pr;
            cout << "Digite o nome do produto: ";
            cin >> nm;
            pl->setNome(nm);
            cout << "Digite o preço do produto em R$ (use '.' para simbolizar a vírgula): ";
            cin >> pr;
            pl->setPreco(pr);
            cout << "Digite o tipo do produto (opções disponíveis: Doméstico, Hospitalar, Industrial): ";
            cin >> tipo;
            pl->setTipo(tipo);
            lista_exibicao.push_back(pl);
            cout << "Encerrando cadastro de produto de limpeza...\n";
        }
        else if (operacao == 2)
        {
            ProdutoAlimenticio *pa = new ProdutoAlimenticio();
            string nm, val;
            double pr;
            cout << "Digite o nome do produto: ";
            cin >> nm;
            cout << "Digite o preço do produto em R$ (use '.' para simbolizar a vírgula): ";
            cin >> pr;
            cout << "Digite a data de validade do produto (use o formato DD/MM/AAAA com as barras inclusas): ";
            cin >> val;
            pa->setPreco(pr);
            pa->setNome(nm);
            pa->setValidade(val);
            lista_exibicao.push_back(pa);
            cout << "Encerrando cadastro de produto alimentício...\n";
        }
        else if (operacao == 3)
        {
            ProdutoEletronico *pe = new ProdutoEletronico();
            int gar, volt;
            string nm;
            double pr;
            cout << "Digite o nome do produto: ";
            cin >> nm;
            pe->setNome(nm);
            cout << "Digite o preço do produto em R$ (use '.' para simbolizar a vírgula): ";
            cin >> pr;
            pe->setPreco(pr);
            cout << "Digite a voltagem do produto em volts: ";
            cin >> volt;
            pe->setVoltagem(volt);
            cout << "Digite a garantia do produto em anos :";
            cin >> gar;
            pe->setGarantia(gar);
            lista_exibicao.push_back(pe);
            cout << "Encerrando cadastro de produto eletrônico...\n";
        }
        else if (operacao == 4)
        {
            cout << "Exibindo a lista de produtos cadastrados: \n";
            for (Produto *p : lista_exibicao)
            {
                p->exibirInformacoes();
                cout << endl;
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
        cout << "SUPERMERCADO LYMPIA\nO que deseja realizar?\n1 - Cadastrar produto de limpeza\n2 - Cadastrar produto alimentício\n3 - Cadastrar produto eletrônico\n4 - Exibir lista de produtos cadastrados\n0 - Sair\nSua escolha: ";
        cin >> operacao;
    }
}