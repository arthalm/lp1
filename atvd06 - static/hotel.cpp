#include <iostream>
#include <string>
using namespace std;

struct Funcionario
{
    static string id;
    string nome;
    double salario;
};

struct Validador
{
    static bool validarSalario(Funcionario f)
    {
        if (f.salario >= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class Hotel
{
    int capacidade;
    int quant_funcionarios;
    Funcionario *dados;

    void aumentarCapacidade()
    {
        capacidade += 1;
        Funcionario *novo = new Funcionario[capacidade];

        for (int i = 0; i < quant_funcionarios; i++)
        {
            novo[i] = dados[i];
        }

        delete[] dados;
        dados = novo;
    }

public:
    Hotel(int cpcd = 1) : capacidade(cpcd), quant_funcionarios(0)
    {
        if (capacidade <= 999)
        {
            dados = new Funcionario[capacidade];
        }
        else
        {
            cerr << "Erro! Limite máximo de funcionários atingido. (MAX = 999)" << endl;
        }
    }

    ~Hotel()
    {
        delete[] dados;
    }

    void adicionarFuncionario(Funcionario f)
    {
        if (quant_funcionarios >= capacidade)
        {
            aumentarCapacidade();
        }
        dados[quant_funcionarios] = f;
        int i;
        if (quant_funcionarios < 10)
        {
            string cod_id = "Nº00" + to_string(quant_funcionarios + 1);
        }
        else if (quant_funcionarios < 100)
        {
            string cod_id = "Nº0" + to_string(quant_funcionarios + 1);
        }
        else if (quant_funcionarios < 999)
        {
            string cod_id = "Nº" + to_string(quant_funcionarios + 1);
        }
        else
        {
            cout << "Limite de funcionários atingido" << endl;
        }
    }
};