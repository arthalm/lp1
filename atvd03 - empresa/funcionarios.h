#include <string>
#include <iomanip>
#include <iostream>

enum Cargo
{
    RH,
    FINANCAS,
    GESTAO
};

struct Funcionario
{
    std::string id;
    std::string nome;
    Cargo cargo;

    
};

class Cadastro
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
    Cadastro(int cpcd = 1) : capacidade(cpcd), quant_funcionarios(0)
    {
        dados = new Funcionario[capacidade];
    }

    ~Cadastro()
    {
        delete[] dados;
    }

    void cadastrarFuncionario()
    {
        std::cout << "=====CADASTRO=DE=FUNCIONÁRIO=====\n";
        std::cout << "1 - DIGITE O SEU NOME: ";
    }
};