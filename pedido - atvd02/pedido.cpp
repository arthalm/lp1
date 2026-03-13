#include <iostream>
using namespace std;

struct Item
{
    string nome;
    int quantidade;
    double valor;

    void exibirItem()
    {
        cout << "=======ITEM=======\n";
        cout << "Nome: " << nome << '\n';
        cout << "Quantidade: " << quantidade << '\n';
        cout << "Valor unitário: R$" << valor << '\n';
        cout << "==================\n" << endl;
    }
};

struct Pedido
{
    int qtde_itens;
    int capacidade;
    Item *lista_itens;

    void aumentarLista()
    {
        capacidade += 1;
        Item *novo_item = new Item[capacidade];

        for (int i = 0; i < qtde_itens; i++)
        {
            novo_item[i] = lista_itens[i];
        }

        delete[] lista_itens;
        lista_itens = novo_item;
    }

public:
    Pedido(int cpcd = 1) : capacidade(cpcd), qtde_itens(0)
    {
        lista_itens = new Item[capacidade];
    }

    ~Pedido()
    {
        delete[] lista_itens;
    }

    void adicionarItem(Item item)
    {
        if (qtde_itens >= capacidade)
        {
            aumentarLista();
        }
        lista_itens[qtde_itens] = item;
        qtde_itens++;
    }

    void exibirItens()
    {
        int contador = 1;
        for (int i = 0; i < qtde_itens; i++)
        {
            cout << "======ITEM " << contador << "======\n";
            cout << "Nome: " << lista_itens[i].nome << '\n';
            cout << "Quantidade: " << lista_itens[i].quantidade << '\n';
            cout << "Valor unitário: R$" << lista_itens[i].valor << '\n';
            cout << "==================\n" << endl;
            contador++;
        }
    }

    void calcularTotalPedido()
    {
        double total = 0.0;
        for (int i = 0; i < qtde_itens; i++)
        {
            total += (lista_itens[i].quantidade * lista_itens[i].valor);
        }
        cout << "TOTAL DO PEDIDO: R$" << total << endl;
    }
};

struct Impressora
{
    void imprimir(Pedido pedido, char modo_impressao = 'R')
    {
        if (modo_impressao == 'R')
        {
            pedido.exibirItens();
            pedido.calcularTotalPedido();
            cout << "Impresso em modo Retrato\n" << endl;
        }
        else if (modo_impressao == 'P')
        {
            pedido.exibirItens();
            pedido.calcularTotalPedido();
            cout << "Impresso em modo Paisagem\n" << endl;
        }
        else
        {
            cout << "Erro! Modo de impressão inválido. Digite R para o modo Retrato ou P para o modo Paisagem\n";
            cout << "Caractere inserido: " << modo_impressao << endl;
        }
    };

    void imprimir(Item item, char modo_impressao = 'R')
    {
        if (modo_impressao == 'R')
        {
            item.exibirItem();
            cout << "Impresso em modo Retrato" << endl;
        }
        else if (modo_impressao == 'P')
        {
            item.exibirItem();
            cout << "Impresso em modo Paisagem" << endl;
        }
        else
        {
            cout << "Erro! Modo de impressão inválido. Digite R para o modo Retrato ou P para o modo Paisagem\n";
            cout << "Caractere inserido: " << modo_impressao << endl;
        }
    };
};

int main()
{
    Item a, b, c;
    Pedido p;
    Impressora i;

    a = {"Abacaxi", 2, 4.39};
    b = {"Barra de cereal", 3, 1.50};
    c = {"Carne (1kg)", 1, 40.00};

    p.adicionarItem(a);
    p.adicionarItem(b);
    p.adicionarItem(c);

    i.imprimir(p, 'R');
    i.imprimir(a, 'P');
    i.imprimir(b, 'J');
}