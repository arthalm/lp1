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
    int operacao_ini;
    int operacao_sec;
    int tamanho = 1;
    bool terminou;
    Produto *dados;
    Produto *lista_exibicao = new Produto[tamanho];

    cout << "SUPERMERCADO LYMPIA\nO que deseja realizar?\n1 - Cadastrar novo produto\n2 - Exibir lista de produtos cadastrados\n0 - Sair\nSua escolha: ";
    cin >> operacao_ini;

    while (operacao_ini != 0 && terminou == false)
    {
        if (operacao_ini == 1)
        {
            while (operacao_sec != 4 && terminou == false)
            {
                cout << "Qual tipo de produto você deseja cadastrar?\n1 - Produto de limpeza\n2 - Produto alimentício\n3 - Produto eletrônico\n4 - Sair\nSua escolha: ";
                cin >> operacao_sec;
                if (operacao_sec == 1)
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
                    lista_exibicao[tamanho - 1] = *pl;
                    tamanho++;
                    cout << "Encerrando cadastro de produto de limpeza...\n";
                }
                else if (operacao_sec == 2)
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
                    lista_exibicao[tamanho - 1] = *pa;
                    tamanho++;
                    cout << "Encerrando cadastro de produto alimentício...\n";
                }
                else if (operacao_sec == 3)
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
                    lista_exibicao[tamanho - 1] = *pe;
                    tamanho++;
                    cout << "Encerrando cadastro de produto eletrônico...\n";
                }
                else if (operacao_sec == 4)
                {
                    cout << "Saindo do cadastro de produtos...\n";
                    terminou = true;
                }
                else
                {
                    throw invalid_argument("Erro! A operação digitada não está disponível. Tente novamente.");
                }
            }
        }
        else if (operacao_ini == 2)
        {
            cout << "Exibindo a lista de produtos cadastrados: \n";
            for (int i = 0; i < tamanho; i++)
            {
                Produto p = dados[i];
                p.exibirInformacoes();
            }
        }
        else if (operacao_ini == 0)
        {
            cout << "Saindo..." << endl;
            terminou = true;
        }
        else
        {
            throw invalid_argument("Erro! A operação digitada não está disponível. Tente novamente.");
        }
        cout << "SUPERMERCADO LYMPIA\nO que deseja realizar?\n1 - Cadastrar novo produto\n2 - Exibir lista de produtos cadastrados\n0 - Sair\nSua escolha: ";
        cin >> operacao_ini;
    }
}