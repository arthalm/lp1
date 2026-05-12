#include <iostream>
#include <string>
using namespace std;

class Autenticacao
{
    string user, senha, email, qr;
    
public:
    void autenticar()
    {
    }
};

class LoginAuth : public Autenticacao
{
};

class GoogleAuth : public Autenticacao
{
};

class QRCodeAuth : public Autenticacao
{
};