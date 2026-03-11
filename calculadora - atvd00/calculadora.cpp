#include <iostream>
using namespace std;

int main()
{
    string texto_intro, texto_meio;
    texto_intro = "CALCULADORA \n Opções: \n 1 - SOMA \n 2 - SUBTRAÇÃO \n 3 - MULTIPLICAÇÃO \n 4 - DIVISÃO \n 0 - SAIR \n Digite a sua opção: ";
    texto_meio = "Agora, digite os dois números que deseja calcular: ";
    int opcao;
    double num1, num2, res;

    cout << texto_intro;
    cin >> opcao;

    while (true)
    {
        if (opcao == 0)
        {
            cout << "Saindo..." << endl;
            break;
        }
        else
        {
            cout << texto_meio;
            cin >> num1 >> num2;
            if (opcao == 1)
            {
                res = num1 + num2;
                cout << "O resultado da operação foi: " << res << endl;
            }
            else if (opcao == 2)
            {
                res = num1 - num2;
                cout << "O resultado da operação foi: " << res << endl;
            }
            else if (opcao == 3)
            {
                res = num1 * num2;
                cout << "O resultado da operação foi: " << res << endl;
            }
            else if (opcao == 4)
            {
                res = num1 / num2;
                cout << "O resultado da operação foi: " << res << endl;
            }
            else
            {
                cout << "Operação inválida! Tente novamente." << endl;
            }
        }
        cout << texto_intro;
        cin >> opcao;
    }

    return 0;
}