#include <iostream>
#include <vector>
using namespace std;

class Personagem
{
    double attack;
    double current_health;
    double max_health;
    int current_mana;
    int max_mana;

public:
    Personagem(double atk, double hp, int mn) : attack(atk), max_health(hp), current_health(hp), max_mana(mn), current_mana(mn) {}
    virtual ~Personagem() {}
    double getAttack()
    {
        return attack;
    }
    double getCurrentHealth()
    {
        return current_health;
    }
    double getMaxHealth()
    {
        return max_health;
    }
    int getCurrentMana()
    {
        return current_mana;
    }
    int getMaxMana()
    {
        return max_mana;
    }

    virtual double ataqueSimples() = 0;
    virtual double ataqueCarregado() = 0;

    void passagemTurno()
    {
        if (current_health < max_health)
        {
            current_health += max_health * 0.1;
            if (current_health > max_health)
            {
                current_health = max_health;
            }
        }

        if (current_mana < max_mana)
        {
            current_mana += max_mana * 0.1;
            if (current_mana > max_mana)
            {
                current_mana = max_mana;
            }
        }
    }

    bool usarMana()
    {
        if (current_mana >= max_mana * 0.15)
        {
            current_mana -= max_mana * 0.15;
            return true;
        }
        else
        {
            cout << "Mana abaixo de 15%! Espere a rodada acabar." << endl;
            return false;
        }
    }

    void tomarDano(double dmg)
    {
        current_health -= dmg;
    }

    bool estaVivo()
    {
        if (current_health > 0.00)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class Mago : public Personagem
{
public:
    Mago() : Personagem(15.00, 300.00, 250) {}

    double ataqueSimples() override
    {
        cout << "O Mago ataca com a sua magia!" << endl;
        return getAttack();
    }

    double ataqueCarregado() override
    {
        if (usarMana() == true)
        {
            cout << "O Mago usa Magia Suprema!" << endl;
            getAttack() * 2;
        }
        else
        {
            return 0;
        }
    }
};

class Guerreiro : public Personagem
{
public:
    Guerreiro() : Personagem(20.00, 500.00, 100) {}

    double ataqueSimples() override
    {
        cout << "O Guerreiro ataca com a sua espada!" << endl;
        return getAttack();
    }

    double ataqueCarregado() override
    {
        if (usarMana() == true)
        {
            cout << "O Guerreiro usa Corte Dimensional!" << endl;
            getAttack() * 2;
        }
        else
        {
            return 0;
        }
    }
};

class Arqueiro : public Personagem
{
public:
    Arqueiro() : Personagem(25.00, 150.00, 150) {}

    double ataqueSimples() override
    {
        cout << "O Arqueiro atira uma flecha!" << endl;
        return getAttack();
    }

    double ataqueCarregado() override
    {
        if (usarMana() == true)
        {
            cout << "O Arqueiro usa Flecha Perfurante!" << endl;
            getAttack() * 2;
        }
        else
        {
            return 0;
        }
    }
};

void acaoPersonagem(Personagem *p, vector<Personagem *> &players, int opcao)
{
    vector<string> classes{"Mago", "Guerreiro", "Arqueiro"};
    vector<string> advers;

    for (int i = 0; i < classes.size(); i++)
    {
        if (i != opcao)
        {
            advers.push_back(classes[i]);
        }
    }

    cout << "---- Atacante: " << classes[opcao] << " ----" << endl;
    cout << "HP atual: " << p->getCurrentHealth() << " - Mana atual: " << p->getCurrentMana() << endl;

    cout << "Quem você deseja atacar?" << endl;
    vector<Personagem *> adversarios;

    int incrementador = 1;
    for (int i = 0; i < players.size(); i++)
    {
        if (players[i] != p && players[i]->estaVivo())
        {
            cout << "Opções de quem atacar" << endl;
            cout << incrementador << " - " << classes[i] << " - HP atual: " << players[i]->getCurrentHealth() << " - Mana atual: " << players[i]->getCurrentMana() << endl;
            adversarios.push_back(players[i]);
            incrementador++;
        }
    }

    int atk_adv;
    cin >> atk_adv;
    do
    {
        cerr << "Erro! o número digitado não corresponde a nenhum dos personagens disponíveis. Tente novamente." << endl;
        cin >> atk_adv;
    } while (atk_adv < 1 || atk_adv > adversarios.size());
    Personagem *adversario = adversarios[atk_adv - 1];

    cout << "Qual tipo de ataque deseja realizar?\n1 - Ataque Normal\n2 - Ataque Carregado\nSua escolha: ";
    int esc_atk;
    cin >> esc_atk;
    do
    {
        cerr << "Erro! o número digitado não corresponde a nenhum dos ataques disponíveis. Tente novamente." << endl;
        cin >> esc_atk;
    } while (esc_atk < 1 || esc_atk > 2);

    double dmg = 0.00;
    if (esc_atk == 1)
    {
        dmg = p->ataqueSimples();
    }
    else
    {
        dmg = p->ataqueCarregado();
    }
    adversario->tomarDano(dmg);

    cout << classes[opcao] << " deu " << dmg << " pontos de dano ao " << advers[atk_adv - 1] << "." << endl;
    cout << "O" << advers[atk_adv - 1] << " se encontra com " << adversario->getCurrentHealth() << " pontos de HP." << endl;

    if (!adversario->estaVivo())
    {
        cout << advers[atk_adv - 1] << " foi derrotado. Parabéns " << classes[opcao] << "!" << endl;
    }
}

int main()
{
    Mago m;
    Guerreiro g;
    Arqueiro a;
    int turnos = 1;
    bool jogo_ativo = true;
    vector<Personagem *> personagens = {&m,
                                        &g,
                                        &a};

    do
    {
        cout << "---- INÍCIO DO TURNO " << turnos << " ----" << endl;

        for (int i = 0; i < personagens.size(); i++)
        {
            if (personagens[i]->estaVivo())
            {
                personagens[i]->passagemTurno();
            }
        }

        for (int j = 0; j < personagens.size(); j++)
        {
            if (personagens[j]->estaVivo())
            {
                int quant_vivos = 0;
                for (int k = 0; k < personagens.size(); k++)
                {
                    if (personagens[k]->estaVivo())
                    {
                        quant_vivos++;
                    }
                }
                if (quant_vivos <= 1)
                {
                    cout << "Parabéns! O " << "placeholder" << " é o campeão do jogo.";
                    jogo_ativo = false;
                }
                acaoPersonagem(personagens[j], personagens, );
            }
        }
        turnos++;
    } while (jogo_ativo);
}