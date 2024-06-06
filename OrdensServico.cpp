#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>
#include <iomanip>

using namespace std;

// Struct da ordem de serviço

struct OrdemServico {
    string sala;
    string descricao;
};

// ordem de serviço

#include <iostream>

OrdemServico criarOrdemServico() {
    OrdemServico ordem;
    cout << "Digite o nome da sala: ";
    getline(cin, ordem.sala); 
    cout << "Digite uma descrição do serviço necessário: "; // Add the std:: namespace prefix to cout
    getline(cin, ordem.descricao);
    return ordem;
}

// Função para anotar o horário da solicitação do serviço

    string getCurrentTimestamp() {
    auto now = chrono::system_clock::now();
    time_t now_c = chrono::system_clock::to_time_t(now);
    stringstream ss;
    ss << std::put_time(localtime(&now_c), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

//Função que vai criar o documentos com a lista de todas as ordens de serviço em txt

void criarDocumento(const vector<OrdemServico>& ordens) {
    ofstream arquivo("Serviços.txt", std::ios_base::app); // Abre o arquivo em modo de adição
    if (arquivo.is_open()) {
        for (const auto& ordem : ordens) {
            arquivo << "Sala: " << ordem.sala << "\n";
            arquivo << "Descrição: " << ordem.descricao << "\n";
            arquivo << "Solicitado em: " << getCurrentTimestamp() << "\n\n"; // Chama getCurrentTimestamp() aqui
        }
        arquivo.close();
        std::cout << "Documento de ordens de serviço criado com sucesso.\n";
    } else {
        std::cout << "Falha ao criar o documento de ordens de serviço.\n";
    }
}


int main(){
    
    vector<OrdemServico> ordens;

    char escolha;
    do {
        std::cout << "1. Criar uma nova ordem de serviço\n";
        std::cout << "2. Sair\n";
        std::cout << "Digite sua escolha: ";
        std::cin >> escolha;
        std::cin.ignore(); // Ignorar o caractere de nova linha

        switch (escolha) {
            case '1': {
                // Criar uma nova ordem de serviço
                OrdemServico ordem = criarOrdemServico();
                ordens.push_back(ordem);
                criarDocumento(ordens);
                break;
            }
            case '2':
                // Sair do programa
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Escolha inválida. Tente novamente.\n";
        }
    } while (escolha != '2');

    return 0;
}