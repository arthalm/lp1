#include <iostream>
using namespace std;

struct Aluno
{
    string id;
    string nome;
    int idade;
    double notas[3];

    /*Aluno(string id, string nome, int idade, double notas[3])
    {
        this->id = id;
        this->nome = nome;
        this->idade = idade;
        for (int i = 0; i < 3; i++)
        {
            this->notas[i] = notas[i];
        }
    }*/

    void exibirAluno()
    {
        cout << "==========@==========\n";
        cout << "ID: " << id << '\n';
        cout << "Nome: " << nome << '\n';
        cout << "Idade: " << idade << '\n';
        cout << "Notas: ";
        for (int i = 0; i < 3; i++)
        {
            cout << notas[i] << " ";
        }
        cout << "\n---------------------\n" << endl;
    }

    double calcularMedia()
    {
        double media = 0.0;
        for (int i = 0; i < 3; i++)
        {
            media += notas[i];
        }
        media = media / 3;
        cout << "A média de " << nome << " é de " << media << endl;
        return media;
    }
};

class Escola
{
    int capacidade;
    int quant_alunos;
    Aluno *dados;

    void aumentarCapacidade()
    {
        capacidade += 1;
        Aluno *novo = new Aluno[capacidade];

        for (int i = 0; i < quant_alunos; i++)
        {
            novo[i] = dados[i];
        }

        delete[] dados;
        dados = novo;
    }

public:
    Escola(int cpcd = 1) : capacidade(cpcd), quant_alunos(0)
    {
        dados = new Aluno[capacidade];
    }

    ~Escola()
    {
        delete[] dados;
    }

    void adicionarAluno(Aluno aluno)
    {
        if (quant_alunos >= capacidade)
        {
            aumentarCapacidade();
        }
        dados[quant_alunos] = aluno;
        quant_alunos++;
    }

    void exibirAlunos()
    {
        for (int i = 0; i < quant_alunos; i++)
        {
            Aluno x = dados[i];
            x.exibirAluno();
        }
    }

    void buscarAluno(string id)
    {
        bool n_existe_aluno = true;
        for (int i = 0; i < quant_alunos; i++)
        {
            Aluno x = dados[i];
            if (id == x.id)
            {
                x.exibirAluno();
                n_existe_aluno = false;
                break;
            }
        }
        if (n_existe_aluno)
        {
            cout << "Erro! O ID inserido não está vinculado a nenhum aluno.\n";
            cout << "ID inserido: " << id << "\n" << endl;
        }
    }

    void exibirMediaGeral()
    {
        double media_geral = 0.0;
        for (int i = 0; i < quant_alunos; i++)
        {
            Aluno x = dados[i];
            media_geral += x.calcularMedia();
        }
        media_geral = media_geral / quant_alunos;
        cout << "A média geral dos alunos é de " << media_geral << endl;
    }
};

int main()
{
    Escola e;
    Aluno a, b, c;
    a.id = "001";
    a.nome = "Antônio";
    a.idade = 20;
    b.id = "002";
    b.nome = "Beatriz";
    b.idade = 21;
    c.id = "003";
    c.nome = "Camila";
    c.idade = 18;
    double notas_a[3] = {4.7, 6.9, 5.3};
    double notas_b[3] = {7.1, 8.2, 6.8};
    double notas_c[3] = {3.5, 5.4, 9.2};
    for (int i = 0; i < 3; i++)
    {
        a.notas[i] = notas_a[i];
        b.notas[i] = notas_b[i];
        c.notas[i] = notas_c[i];
    }

    e.adicionarAluno(a);
    e.adicionarAluno(b);
    e.adicionarAluno(c);

    e.buscarAluno("001");
    e.buscarAluno("002");
    e.buscarAluno("003");
    e.buscarAluno("004");

    e.exibirAlunos();

    e.exibirMediaGeral();
}