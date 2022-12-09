#include <iostream>
#include <locale.h> // configurada adequadamente vai garantir que caracteres como “ç” e acentuação sejam exibidos normalmente em nosso programa.
#include <conio.h>	// é para desenhar tela, e é para dos/windows (as funções do conio são úteis para manipular caracteres na tela, especificar cor de carácter e de fundo.)
#include <fstream>	// fluxo de arquivo
#include <iomanip>	// O iomanip é uma biblioteca em C++ que nos ajuda a manipular a saída de qualquer programa C++

using namespace std;

//______________Função CLIENTE_______________________
int inserir_cliente(struct CLIENTE *Cliente, int); // OK

int imprimir_cliente(struct CLIENTE *Cliente, int); // OK

int imprimir_selecionado_cliente(struct CLIENTE *Cliente, int); // OK

int deletar_selecionado_cliente(struct CLIENTE *Cliente, struct ENDERECO *Endereco, int, int); // OK

//______________Função Inserir ENDERECO_______________
int inserir_endereco(struct ENDERECO *Endereco, struct CLIENTE *Cliente, int);

int imprimir_endereco(struct ENDERECO *Endereco, int);

int imprimir_selecionado_endereco(struct ENDERECO *Endereco, struct CLIENTE *Cliente, int);

int deletar_selecionado_endereco(struct ENDERECO *Endereco, int);

int deletar_endereco_cliente(struct ENDERECO *Endereco, int, int);

struct CLIENTE
{
	int id;
	string nome;

} Cliente;

struct ENDERECO
{
	int id_endereco;

	int numero;
	string logradouro; // ok
	string bairro;	   // ok
	string cidade;	   // ok

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
		cout << "|A) MENU do cliente                             |" << endl; // OK
		cout << "|B) MENU dos endereco                           |" << endl;
		cout << "|S) Sair do menu                                |" << endl;
		cout << "|MENU: ";
		cin >> opcao;

		if (opcao == "a" or opcao == "A")
		{
			// OK
			cout << "\n|-----------------------------------------------|" << endl;
			cout << "|                 CLIENTE                       |" << endl;
			cout << "|_______________________________________________|" << endl;
			cout << "|                                               |" << endl;
			cout << "|1) Inserir as informacoes do cliente           |" << endl; // OK
			cout << "|2) Imprimir o cliente selecionado              |" << endl; // OK
			cout << "|3) Imprimir todos os clientes                  |" << endl; // OK
			cout << "|4) Deletar o cliente selecionado               |" << endl; // OK
			cout << "|0) Para voltar ao MENU                         |" << endl;
			cout << "|MENU: ";
			cin >> op;
		}

		if (opcao == "b" or opcao == "B")
		{
			cout << "\n|-----------------------------------------------|" << endl;
			cout << "|                   ENDERECO                     |" << endl;
			cout << "|________________________________________________|" << endl;
			cout << "|                                                |" << endl;
			cout << "|5) Inserir as informacoes do endereco           |" << endl; // OK
			cout << "|6) Imprimir o endereco selecionado              |" << endl; // OK
			cout << "|7) Imprimir todos os endereco                   |" << endl; // OK
			cout << "|8) Deletar o endereco selecionado               |" << endl; // AINDA FAZER
			cout << "|0) Para voltar ao MENU                          |" << endl;
			cout << "|MENU: ";
			cin >> op;
		}

		if (op == 1)
		{
			tamanho = i;
			i++;
		}
		if (op == 5)
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
			imprimir_selecionado_cliente(Cliente, tamanho); // OK
		}
		break;

		case 3:
		{
			imprimir_cliente(Cliente, tamanho); // OK
		}
		break;

		case 4:
		{
			deletar_selecionado_cliente(Cliente, Endereco, tamanho, tamanho_endereco);
			tamanho--;
		}
		break;

			//        << "  |------------------------------------------------|" << endl;
			//          << "|                   ENDERECO                     |" << endl;
			//           <<"|________________________________________________|" << endl;

		case 5:
		{
			inserir_endereco(Endereco, Cliente, tamanho_endereco);
		}
		break;

		case 6:
		{
			imprimir_selecionado_endereco(Endereco, Cliente, tamanho_endereco);
		}

		break;

		case 7:
		{
			imprimir_endereco(Endereco, tamanho_endereco);
		}
		break;

		case 8:
		{
			deletar_selecionado_endereco(Endereco, tamanho_endereco);
			tamanho_endereco--;
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
	}

	for (int i = tamanho; i <= tamanho; i++)
	{

		Cliente[i].id = i;
	}

	return imprimir_cliente(Cliente, tamanho);
}

int imprimir_cliente(struct CLIENTE *Cliente, int tamanho)
{
	Cliente_txt.open("Cliente.txt", ios::app | ios::out);
	cout << "\n";

	for (int i = 0; i <= tamanho; i++)
	{
		cout << "________________________" << endl;
		cout << "|     Tabela Cliente    |" << endl;
		cout << "| ID | NOME             |" << endl;
		cout << "| " << Cliente[i].id << "  |    " << Cliente[i].nome << "  " << endl;
	}
	for (int i = tamanho; i <= tamanho; i++)
	{

		Cliente_txt << "________________________" << endl;
		Cliente_txt << "|     Tabela Cliente    |" << endl;
		Cliente_txt << "| ID | NOME             |" << endl;
		Cliente_txt << "| " << Cliente[i].id << "  |    " << Cliente[i].nome << "  " << endl;
	}
	Cliente_txt.close();
}

int imprimir_selecionado_cliente(struct CLIENTE *Cliente, int tamanho)
{
	int cliente_id;

	cout << "\nQual cliente voce que imprimir:\n";
	cout << "Digite o id do cliente: ";
	cin >> cliente_id;

	for (int i = 0; i <= tamanho; i++)
	{
		if (cliente_id == Cliente[i].id)
		{
			cout << "________________________" << endl;
			cout << "|     Tabela Cliente    |" << endl;
			cout << "| ID | NOME             |" << endl;
			cout << "| " << Cliente[i].id << "  |    " << Cliente[i].nome << "  " << endl;
		}
	}
}

int deletar_selecionado_cliente(struct CLIENTE *Cliente, struct ENDERECO *Endereco, int tamanho, int tamanho_endereco)
{
	int cliente_id;

	cout << "\nQual cliente voce que deletar:\n";
	cout << "Digite o id do cliente: ";
	cin >> cliente_id;

	for (int i = 0; i <= tamanho; i++)
	{

		if (cliente_id == Cliente[i].id)
		{

			for (int j = i; j < tamanho - 1; j++)
			{

				Cliente[j].id = Cliente[j + 1].id;
				Cliente[j].nome[i] = Cliente[j + 1].nome[i];
			}

			cout << "\nfuncao remover: " << endl;
			cout << "________________________" << endl;
			cout << "|     Tabela Cliente    |" << endl;
			cout << "| ID | NOME             |" << endl;
			cout << "| " << Cliente[i].id << "  |    " << Cliente[i].nome << "  " << endl;

			if (cliente_id == Endereco[cliente_id].id_endereco)
			{
				deletar_endereco_cliente(Endereco, cliente_id, tamanho_endereco);
				tamanho_endereco--;
			}
			else
			{
				cout << "\nEsse usuario nao tem endereco:\n";
			}
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

	if (cliente_id == Cliente[cliente_id].id)
	{
		for (int i = tamanho; i <= tamanho; i++)
		{

			cout << "\n1 - I: " << i << endl;

			cout << "\nDigite a cidade: ";
			cin >> Endereco[i].cidade;

			cout << "Digite o bairro: ";
			cin >> Endereco[i].bairro;

			cout << "Digite logradouro: ";
			cin >> Endereco[i].logradouro;

			cout << "Digite o numero: ";
			cin >> Endereco[i].numero;

			Endereco[i].id_endereco = Cliente[cliente_id].id; // ok
		}
		imprimir_endereco(Endereco, tamanho);
	}
}

int imprimir_endereco(struct ENDERECO *Endereco, int tamanho)
{

	Endereco_txt.open("Endereco.txt", ios::app | ios::out);

	for (int i = tamanho; i <= tamanho; i++)
	{

		Endereco_txt << "\n________________________" << endl;
		Endereco_txt << "|     Tabela endereco   |" << endl;
		Endereco_txt << "| ID :" << Endereco[i].id_endereco << endl;
		Endereco_txt << "| CIDADE: " << Endereco[i].cidade << endl;
		Endereco_txt << "| BAIRRIO: " << Endereco[i].bairro << endl;
		Endereco_txt << "| LOGRADOURO: " << Endereco[i].logradouro << endl;
		Endereco_txt << "| NUMERO: " << Endereco[i].numero << endl;
	}
	Endereco_txt.close();

	for (int i = 0; i <= tamanho; i++)
	{

		cout << "\n________________________" << endl;
		cout << "|     Tabela endereco   |" << endl;
		cout << "| ID :" << Endereco[i].id_endereco << endl;
		cout << "| CIDADE: " << Endereco[i].cidade << endl;
		cout << "| BAIRRIO: " << Endereco[i].bairro << endl;
		cout << "| LOGRADOURO: " << Endereco[i].logradouro << endl;
		cout << "| NUMERO: " << Endereco[i].numero << endl;
	}

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

int imprimir_selecionado_endereco(struct ENDERECO *Endereco, struct CLIENTE *Cliente, int tamanho)
{

	int endereco_id;
	cout << "\nQual endereco voce que imprimir:\n";
	cout << "Digite o id do endereco: ";
	cin >> endereco_id;

	for (int i = 0; i <= tamanho; i++)
	{
		if (endereco_id == Cliente[i].id)
		{

			cout << "\n________________________" << endl;
			cout << "|     Tabela endereco   |" << endl;
			cout << "| ID :" << Endereco[i].id_endereco << endl;
			cout << "| CIDADE: " << Endereco[i].cidade << endl;
			cout << "| BAIRRIO: " << Endereco[i].bairro << endl;
			cout << "| LOGRADOURO: " << Endereco[i].logradouro << endl;
			cout << "| NUMERO: " << Endereco[i].numero << endl;
		}
	}
}

int deletar_selecionado_endereco(struct ENDERECO *Endereco, int tamanho)
{
	int endereco_id;

	cout << "\nQual endereco voce que deletar:\n";
	cout << "Digite o id do endereco: ";
	cin >> endereco_id;

	for (int i = 0; i < tamanho; i++)
	{
		if (endereco_id == Endereco[i].id_endereco)
		{
			for (int j = i; j <= tamanho - 1; j++)
			{
				Endereco[i].id_endereco = Endereco[i].id_endereco;
				Endereco[i].cidade[i] = Endereco[i].cidade[i];
				Endereco[i].bairro[i] = Endereco[i].bairro[i];
				Endereco[i].logradouro[i] = Endereco[i].logradouro[i];
				Endereco[i].numero = Endereco[i].numero;
			}
			cout << "\n________________________" << endl;
			cout << "|     Tabela endereco   |" << endl;
			cout << "| ID :" << Endereco[i].id_endereco << endl;
			cout << "| CIDADE: " << Endereco[i].cidade << endl;
			cout << "| BAIRRIO: " << Endereco[i].bairro << endl;
			cout << "| LOGRADOURO: " << Endereco[i].logradouro << endl;
			cout << "| NUMERO: " << Endereco[i].numero << endl;
		}
	}
}

int deletar_endereco_cliente(struct ENDERECO *Endereco, int cliente_id, int tamanho)
{
	for (int i = 0; i <= tamanho; i++)
	{

		if (cliente_id == Endereco[i].id_endereco)
		{
			for (int j = i; j <= tamanho - 1; j++)
			{
				Endereco[i].id_endereco = Endereco[i].id_endereco;
				Endereco[i].cidade[i] = Endereco[i].cidade[i];
				Endereco[i].bairro[i] = Endereco[i].bairro[i];
				Endereco[i].logradouro[i] = Endereco[i].logradouro[i];
				Endereco[i].numero = Endereco[i].numero;
			}
			/* cout << "\n________________________" << endl;
			cout << "|     Tabela endereco   |" << endl;
			cout << "| ID :" << Endereco[i].id_endereco << endl;
			cout << "| CIDADE: " << Endereco[i].cidade[i] << endl;
			cout << "| BAIRRIO: " << Endereco[i].bairro[i] << endl;
			cout << "| LOGRADOURO: " << Endereco[i].logradouro[i] << endl;
			cout << "| NUMERO: " << Endereco[i].numero << endl; */
			imprimir_endereco(Endereco, tamanho);
		}
	}
}