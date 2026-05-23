#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

class Calculos {
public:
    float calcularEnergiaPotencial(float m, float h, float g) {
        float Ep = m * g * h;
        return Ep;
    }

    float calcularEnergiaCinetica(float m, float v) {
        float Ec = (m * pow(v, 2)) / 2.0f;
        return Ec;
    }

    float calcularEnergiaMecanica(float m, float h, float g, float v) {
        float Ep = calcularEnergiaPotencial(m, h, g);
        float Ec = calcularEnergiaCinetica(m, v);
        return Ep + Ec;
    }
};

void ValoresEp(float &mas, float &alt) {
    cout << "Digite o valor da massa(kg): ";
    cin >> mas;

    cout << "Digite o valor da altura(m): ";
    cin >> alt;
}

void ValoresEc(float &mas, float &vel) {
    cout << "Digite o valor da massa(kg): ";
    cin >> mas;

    cout << "Digite o valor da velocidade(km/h): ";
    cin >> vel;
    vel /= 3.6f;
}

void ValoresEm(float &mas, float &alt, float &vel) {
    cout << "Digite o valor da massa(kg)";
    cin >> mas;

    cout << "Digite o valor da altura(m): ";
    cin >> alt;

    cout << "Digite o valor da velocidade(Km/h): ";
    cin >> vel;
    vel /= 3.6f;
}

void menuEnergias() {
    int opcao = 1;
    Calculos calc;
    float Ep, Ec, Em;
    float massa, altura, velocidade;
    float gravidade = 10;
    while (opcao != 0) {
        system("cls");

        cout << "Desenvolvido por Marcus" << endl;

        cout << "\n-------CALCULADOR DE ENERGIAS-------\n";
        cout << "Menu:\n";
        cout << "1-Energia Potencial\n";
        cout << "2-Energia Cinetica\n";
        cout << "3-Energia Mecanica\n";
        cout << "4-Sobre\n";
        cout << "0-Sair\n";
        cout << "Escolha uma opcao: ";

        cin >> opcao;

        if (opcao == 0) {
            cout << "Programa Encerrado";
            break;
        }

        system("cls");

        switch (opcao)
        {
            case 1:
                ValoresEp(massa, altura);
                cout << "Calculando Energia Potencial...\n";
                Ep = calc.calcularEnergiaPotencial(massa, altura, gravidade);
                cout << "Energia Potencial: " << Ep << " J\n" << endl;

                cout << "Pressione qualquer tecla para voltar..." << endl;
                cin.ignore();
                cin.get();
                break;
            case 2:
                ValoresEc(massa, velocidade);
                cout << "Calculando Energia Cinetica...\n";
                Ec = calc.calcularEnergiaCinetica(massa, velocidade);
                cout << "Energia Cinetica: " << Ec << " J\n";

                cout << "Pressione qualquer tecla para voltar..." << endl;
                cin.ignore();
                cin.get();
                break;
            case 3:
                ValoresEm(massa, altura, velocidade);

                cout << "Calculando Energia Mecanica...\n";
                Em = calc.calcularEnergiaMecanica(massa, altura, gravidade, velocidade);

                cout << "Energia Mecanica: " << Em << " J\n";

                cout << "Pressione qualquer tecla para voltar..." << endl;
                cin.ignore();
                cin.get();
                break;
            case 0:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opcao invalida!\n";

                cout << "Pressione qualquer tecla para voltar..." << endl;
                cin.ignore();
                cin.get();
        }
    }
}

int main() {
    menuEnergias();
    return 0;
}