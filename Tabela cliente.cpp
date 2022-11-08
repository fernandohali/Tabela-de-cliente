#include <iostream>
#include <locale.h>
#include <conio.h>
#include <fstream> // fluxo de arquivo
#include <string.h>
#include <iomanip>

using namespace std;

//______________Função CLIENTE_______________________
int inserir_cliente(struct CLIENTE *Cliente, int);
int imprimir_cliente(struct CLIENTE *Cliente, int);
int imprimir_selecionado_cliente(struct CLIENTE *Cliente, int);

//______________Função Inserir ENDERECO_______________
int inserir_endereco(struct ENDERECO *Endereco, struct CLIENTE *Cliente, int);
int imprimir_endereco(struct ENDERECO *Endereco, int);

struct CLIENTE
{
	int id;
	string nome;

} Cliente;

struct ENDERECO
{
	int *id_endereco = &Cliente.id;

	int numero;
	string logradouro;
	string bairro;
	string cidade;

	// CLIENTE info_cliente;

} Endereco;

//_____________ SALVAR TEXTO____________
fstream Cliente_txt;
fstream Endereco_txt;

int main()
{

	string opcao;
	int op;
	int tamanho = 0, i = 0;
	int tamanho_endereco = 0, tamanho_endereco_i = 0;

	CLIENTE Cliente[100];
	ENDERECO Endereco[100];

	do
	{
		cout << endl;
		cout << "|-----------------------------------------------|" << endl;
		cout << "|                TABELA CLIENTE                 |" << endl;
		cout << "|_______________________________________________|" << endl;
		cout << "|                                               |" << endl;
		cout << "|A) MENU do cliente                             |" << endl;
		cout << "|B) MENU dos endereco                           |" << endl;
		cout << "|F) DELETA todas as informacoes                 |" << endl;
		cout << "|S) Sair do menu                                |" << endl;
		cout << "|MENU: ";
		cin >> opcao;

		if (opcao == "a")
		{
			cout << "\n|-----------------------------------------------|" << endl;
			cout << "|                 CLIENTE                       |" << endl;
			cout << "|_______________________________________________|" << endl;
			cout << "|                                               |" << endl;
			cout << "|1) Inserir as informacoes do cliente           |" << endl; // OK
			cout << "|2) Imprimir o cliente selecionado              |" << endl; // OK
			cout << "|3) Imprimir todos os clientes                  |" << endl; // OK
			cout << "|4) Deletar o cliente selecionado               |" << endl; // FAZER AINDA
			cout << "|5) Deletar todos os clientes                   |" << endl; // FAZER AINDA
			cout << "|0) Para voltar ao MENU                         |" << endl; // OK
			cout << "|MENU: ";
			cin >> op;
		}

		if (opcao == "b")
		{
			cout << "\n|-----------------------------------------------|" << endl;
			cout << "|                   ENDERECO                     |" << endl;
			cout << "|________________________________________________|" << endl;
			cout << "|                                                |" << endl;
			cout << "|6) Inserir as informacoes do endereco           |" << endl; // OK
			cout << "|7) Imprimir o endereco selecionado              |" << endl; // OK
			cout << "|8) Imprimir todos os endereco                   |" << endl; // OK
			cout << "|9) Deletar o endereco selecionado               |" << endl; // FAZER AINDA
			cout << "|10) Deletar todos os endereco                   |" << endl; // FAZER AINDA
			cout << "|0) Para voltar ao MENU                          |" << endl;
			cout << "|MENU: ";
			cin >> op;
		}

		if (op == 1)
		{
			tamanho = i;
			i++;
		}
		if (op == 6)
		{
			tamanho_endereco = tamanho_endereco_i;
			tamanho_endereco_i++;
		}

		switch (op)
		{
		case 1:
		{

			inserir_cliente(Cliente, tamanho); // OK
		}
		break;

		case 2:
		{
			imprimir_selecionado_cliente(Cliente, tamanho);
		}
		break;

		case 3:
		{
			imprimir_cliente(Cliente, tamanho);
		}
		break;

		case 4:
		{
			// deletar_selecionado_cliente(Cliente, tamanho);
		}
		break;

		case 5:
		{
			// remover_cliente();
		}
		break;

			//        << "  |------------------------------------------------|" << endl;
			//          << "|                   ENDERECO                     |" << endl;
			//           <<"|________________________________________________|" << endl;

		case 6:
		{
			inserir_endereco(Endereco, Cliente, tamanho_endereco);
		}
		break;

		case 8:
		{
			imprimir_endereco(Endereco, tamanho_endereco);
		}
		break;

		default:
			break;
		}

	} while (opcao != "s");

	return 0;
}

//________________CLIENTE_________________________

int inserir_cliente(struct CLIENTE *Cliente, int tamanho)
{
	// ENDERECO Endereco[100];

	for (int i = tamanho; i <= tamanho; i++)
	{

		cout << "\nDigite o nome do cliente: ";
		cin >> Cliente[i].nome;

		Cliente[i].id = i;
	}

	return imprimir_cliente(Cliente, tamanho);
}

int imprimir_cliente(struct CLIENTE *Cliente, int tamanho)
{
	Cliente_txt.open("Cliente.txt", ios::app | ios::out);
	string linha;

	cout << "\n";
	for (int i = 0; i <= tamanho; i++)
	{
		Cliente_txt << "________________________" << endl;
		Cliente_txt << "|     Tabela Cliente    |" << endl;
		Cliente_txt << "| ID | NOME             |" << endl;
		Cliente_txt << "| " << Cliente[i].id << "  |    " << Cliente[i].nome << "  " << endl;
	}
	Cliente_txt.close();

	/* 	Cliente_txt.open("Cliente.txt", ios::app | ios::in);

		if (Cliente_txt.is_open())
		{
			while (getline(Cliente_txt, linha))
			{
				cout << linha << endl;
			}
			Cliente_txt.close();
		}

		else
		{
			cout << "Nao foi possivel abrir o arquivo" << endl;
		} */
}

int imprimir_selecionado_cliente(struct CLIENTE *Cliente, int tamanho)
{
	int quantidade;
	int cliente_id;
	string linha;

	cout << "\nQual cliente voce que imprimir:\n";
	cout << "Digite o id do cliente: ";
	cin >> cliente_id;

	for (int i = 0; i <= tamanho; i++)
	{
		if (cliente_id == Cliente->id)
		{
			cout << "________________________" << endl;
			cout << "|     Tabela Cliente    |" << endl;
			cout << "| ID | NOME             |" << endl;
			cout << "| " << Cliente[i].id << "  |    " << Cliente[i].nome << "  " << endl;
		}
	}
}

//        << "  |------------------------------------------------|" << endl;
//          << "|                   ENDERECO                     |" << endl;
//           <<"|________________________________________________|" << endl;

int inserir_endereco(struct ENDERECO *Endereco, struct CLIENTE *Cliente, int tamanho)
{

	int cliente_id;
	cout << "\nDigite as informacoes do endereco!\n";
	cout << "Digite o ID do cliente para colocar o endereco: ";
	cin >> cliente_id;

	for (int i = tamanho; i <= tamanho; i++)
	{
		if (cliente_id == Cliente[cliente_id].id)
		{

			cout << "\nDigite a cidade: ";
			cin >> Endereco[i].cidade;

			cout << "Digite o bairro: ";
			cin >> Endereco[i].bairro;

			cout << "Digite logradouro: ";
			cin >> Endereco[i].logradouro;

			cout << "Digite o numero: ";
			cin >> Endereco[i].numero;

			*Endereco[i].id_endereco = Cliente[cliente_id].id; // ok
		}
	}

	return imprimir_endereco(Endereco, tamanho);
}

int imprimir_endereco(struct ENDERECO *Endereco, int tamanho)
{
	Endereco_txt.open("Endereco.txt", ios::app | ios::out);
	string linha;

	cout << "\n";
	for (int i = 0; i <= tamanho; i++)
	{

		Endereco_txt << "\n________________________" << endl;
		Endereco_txt << "|     Tabela endereco   |" << endl;
		Endereco_txt << "| ID :" << *Endereco[i].id_endereco << endl;
		Endereco_txt << "| CIDADE: " << Endereco[i].cidade << endl;
		Endereco_txt << "| BAIRRIO: " << Endereco[i].bairro << endl;
		Endereco_txt << "| LOGRADOURO: " << Endereco[i].logradouro << endl;
		Endereco_txt << "| NUMERO: " << Endereco[i].numero << endl;
	}
	Endereco_txt.close();

	/* Endereco_txt.open("Endereco.txt", ios::in);

	if (Endereco_txt.is_open())
	{
		while (getline(Endereco_txt, linha))
		{
			cout << linha << endl;
		}
		Endereco_txt.close();
	}
	else
	{
		cout << "Nao foi possivel abrir o arquivo" << endl;
	} */
}
