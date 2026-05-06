#include <string>
#include <iostream>

enum Cargo
{
    RH = 1,
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
        if (capacidade <= 9999)
        {
            dados = new Funcionario[capacidade];
        }
        else
        {
            std::cerr << "Erro! Capacidade máxima atingida (MAX = 9999)" << std::endl;
        }
    }

    ~Cadastro()
    {
        delete[] dados;
    }

    void cadastrarFuncionario(Funcionario f)
    {
        if (quant_funcionarios >= capacidade)
        {
            aumentarCapacidade();
        }
        dados[quant_funcionarios] = f;
        int i;
        if (quant_funcionarios < 10)
        {
            std::string cod_id = "Nº000" + std::to_string(quant_funcionarios + 1);
        }
        else if (quant_funcionarios < 100)
        {
            std::string cod_id = "Nº00" + std::to_string(quant_funcionarios + 1);
        }
        else if (quant_funcionarios < 1000)
        {
            std::string cod_id = "Nº0" + std::to_string(quant_funcionarios + 1);
        }
        else if (quant_funcionarios < 9999)
        {
            std::string cod_id = "Nº" + std::to_string(quant_funcionarios + 1);
        }
        else
        {
            std::cout << "Limite de funcionários atigido" << std::endl;
        }
        std::cout << "=====CADASTRO=DE=FUNCIONÁRIO=====\n";
        std::cout << "1 - DIGITE O SEU NOME: ";
        std::cin >> f.nome;
        std::cout << "2 - DIGITE O SEU CARGO (1 - RH, 2 - FINANÇAS, 3 - GESTÃO): ";
        std::cin >> i;
        f.cargo = (Cargo)(i);
        quant_funcionarios++;
    }

    void mostrarFuncionarios()
    {
        std::cout << "=====LISTA=DE=FUNCIONÁRIOS=====\n";
        for (int i = 0; i < quant_funcionarios; i++)
        {
            std::cout << dados->id << '\n';
            std::cout << dados->nome << '\n';
            std::cout << dados->cargo << '\n';
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        }
        std::cout << "================================" << std::endl;
    }
};