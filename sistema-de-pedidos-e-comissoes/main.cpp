#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Arrays para armazenar dados dos 4 representantes (índices 1 a 4)
    int itensvendidos[5] = {0};
    float totalVendas[5] = {0.0f};
    float totalComissao[5] = {0.0f};

    int cod_repres, itens_venda, opcao;
    float valor_venda;
    bool continuar = true;

    do {
        cout << "\n==== MENU - SISTEMA DE COMISSOES ====" << endl;
        cout << "1 - Registrar nova venda" << endl;
        cout << "2 - Exibir total de vendas processadas" << endl;
        cout << "3 - Exibir total de comissoes por representante" << endl;
        cout << "4 - Exibir total de comissoes pagas pela empresa" << endl;
        cout << "5 - Vendedor com o maior valor de vendas" << endl;
        cout << "6 - Vendedor com a menor quantidade de itens vendidos" << endl;
        cout << "7 - Sair" << endl;
        cout << "Digite uma das opcoes acima: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                char novavenda;
                do {
                    cout << "Informe o codigo do representante (1-4): ";
                    cin >> cod_repres;

                    if (cod_repres >= 1 && cod_repres <= 4) {
                        cout << "Informe a quantidade de itens da venda: ";
                        cin >> itens_venda;
                        cout << "Informe o valor total da venda: R$ ";
                        cin >> valor_venda;

                        // Regra de Comissão baseada na quantidade de itens
                        float taxa;
                        if (itens_venda < 20) {
                            taxa = 0.10f; // 10%
                        } else if (itens_venda >= 20 && itens_venda <= 49) {
                            taxa = 0.15f; // 15%
                        } else if (itens_venda >= 50 && itens_venda <= 74) {
                            taxa = 0.20f; // 20%
                        } else {
                            taxa = 0.25f; // 25%
                        }

                        float comissaoVenda = valor_venda * taxa;

                        // Atualiza dados acumulados do representante
                        itensvendidos[cod_repres] += itens_venda;
                        totalVendas[cod_repres] += valor_venda;
                        totalComissao[cod_repres] += comissaoVenda;

                        cout << fixed << setprecision(2);
                        cout << "Comissao desta venda: R$ " << comissaoVenda << endl;
                        cout << "Venda registrada com sucesso!" << endl;
                    } else {
                        cout << "Codigo do representante invalido." << endl;
                    }

                    cout << "Deseja informar mais uma venda? (S/N): ";
                    cin >> novavenda;
                } while (toupper(novavenda) == 'S');
                break;
            }
            case 2: {
                float totalGeralVendas = 0;
                for (int i = 1; i <= 4; i++) {
                    totalGeralVendas += totalVendas[i];
                }
                cout << fixed << setprecision(2);
                cout << "Total acumulado de vendas processadas: R$ " << totalGeralVendas << endl;
                break;
            }
            case 3: {
                cout << "--- Total de comissoes por representante ---" << endl;
                cout << fixed << setprecision(2);
                for (int i = 1; i <= 4; i++) {
                    cout << "Representante " << i << ": R$ " << totalComissao[i] << endl;
                }
                break;
            }
            case 4: {
                float totalGeralComissoes = 0;
                for (int i = 1; i <= 4; i++) {
                    totalGeralComissoes += totalComissao[i];
                }
                cout << fixed << setprecision(2);
                cout << "Total geral de comissoes pagas pela fabrica: R$ " << totalGeralComissoes << endl;
                break;
            }
            case 5: {
                int melhorVendedor = 1;
                for (int i = 2; i <= 4; i++) {
                    if (totalVendas[i] > totalVendas[melhorVendedor]) {
                        melhorVendedor = i;
                    }
                }
                cout << fixed << setprecision(2);
                cout << "O vendedor com o maior valor de vendas eh o Representante " << melhorVendedor
                     << ", com um total de R$ " << totalVendas[melhorVendedor] << endl;
                break;
            }
            case 6: {
                int piorVendedor = 1;
                for (int i = 2; i <= 4; i++) {
                    if (itensvendidos[i] < itensvendidos[piorVendedor]) {
                        piorVendedor = i;
                    }
                }
                cout << "O vendedor com a menor quantidade de itens vendidos eh o Representante " << piorVendedor
                     << ", com um total de " << itensvendidos[piorVendedor] << " itens." << endl;
                break;
            }
            case 7:
                continuar = false;
                break;
            default:
                cout << "Opcao invalida, digite uma das opcoes do menu." << endl;
                break;
        }
    } while (continuar);

    cout << "Sistema encerrado. Obrigado!" << endl;

    return 0;
}
