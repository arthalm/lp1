#include <iostream>
#include <string>
using namespace std;

class Autenticacao
{

public:
    virtual void coletarDados() = 0;

    virtual bool validarDados() = 0;

    virtual void iniciarSessao()
    {
        cout << "Sessão iniciada com sucesso! Seja bem vindo/a/e ";
    }

    void autenticar()
    {
        coletarDados();
        if (validarDados())
        {
            iniciarSessao();
        }
        else
        {
            throw invalid_argument("Erro ao autenticar! Tente novamente mais tarde.");
        }
    }
};

class LoginAuth : public Autenticacao
{
    string user, senha;

public:
    void coletarDados() override
    {
        cout << "Digite o seu nome de usuário (não pode haver espaços): ";
        cin >> user;
        cout << "Digite a sua senha (não pode haver espaços): ";
        cin >> senha;
    };

    bool validarDados() override
    {
        if (user.size() > 4 && senha.size() > 8)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void iniciarSessao() override
    {
        Autenticacao::iniciarSessao();
        cout << user << "!" << endl;
    }
};

class GoogleAuth : public Autenticacao
{
    string email;

public:
    void coletarDados() override
    {
        cout << "Digite o seu e-mail do Google: ";
        cin >> email;
    }

    bool validarDados() override
    {
        string gmail = "@gmail.com";
        if (email.size() > gmail.size() && email.substr(email.size() - gmail.size()) == gmail)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void iniciarSessao() override
    {
        Autenticacao::iniciarSessao();
        cout << email << "!" << endl;
    }
};

class QRCodeAuth : public Autenticacao
{
    string qr;

public:
    void coletarDados() override
    {
        cout << "Digite o código textual do QR Code: ";
        cin >> qr;
    }

    bool validarDados() override
    {
        if (qr == "QR12345")
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void iniciarSessao() override
    {
        cout << "QR Code validado. ";
        Autenticacao::iniciarSessao();
    }
};

int main()
{
    int login;

    cout << "Digite a forma de login que deseja efetuar\n1 - Usuário e senha\n2 - E-mail\n3 - QR Code\n0 - Sair\nSua escolha: ";
    cin >> login;

    if (login == 1)
    {
        LoginAuth *la = new LoginAuth();
        la->autenticar();
        delete la;
    }
    else if (login == 2)
    {
        GoogleAuth *ga = new GoogleAuth();
        ga->autenticar();
        delete ga;
    }
    else if (login == 3)
    {
        QRCodeAuth *qa = new QRCodeAuth();
        qa->autenticar();
        delete qa;
    }
    else if (login == 0)
    {
        cout << "Saindo do login...";
    }
    else
    {
        throw invalid_argument("Erro! A operação digitada não está disponível. Tente novamente mais tarde.");
    }
}