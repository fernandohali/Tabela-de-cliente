
#include <iostream>
#include <locale.h>
#include <conio.h>
#include <fstream>

using namespace std;

int inserir_cliente(struct CLIENTE *Cliente, int); // ok

int produto_cliente(struct PRODUTO *Produto, int);

int pedido_cliente(struct PEDIDO *Pedido, int);

int Intens_cliente(struct INTENS_POR_PEDIDO *Intens_por_pedido, int);

//_______________Função Imprimir____________________
int imprimir_cliente(struct CLIENTE *Cliente, int);

int imprimir_produto(struct PRODUTO *Produto, int);

int imprimir_pedido(struct PEDIDO *Pedido, int);

int imprimir_todo_tebela(struct CLIENTE *Cliente, struct PRODUTO *Produto, struct PEDIDO *Pedido, struct INTENS_POR_PEDIDO *Intens_por_pedido, int);

int imprimir_geral(struct CLIENTE *Cliente, struct PRODUTO *Produto, int);

// ___________________________Alterar tabela________________________

int alterar_cliente(struct CLIENTE *Cliente, int);

struct CLIENTE
{
	// ok
	string nome; // ok
	int cpf;	 // ok
	int id;

} Cliente;

struct PEDIDO
{
	int numero_pedido;

	int *CPF_cliente = &Cliente.cpf; // ok

} Pedido;

struct PRODUTO
{
	int numero_identificador;
	string nome;
	float preco;

} Produto;

struct INTENS_POR_PEDIDO
{
	int *numero_do_pedido_cliente = &Pedido.numero_pedido;

	int *numero_do_produto_comprado = &Produto.numero_identificador;

	int *tamanho;
	// Precisa de um contador para a quaidade de procutos comprados.

} Intens_por_pedido;

/* struct No_lista
{
	CLIENTE Lista_cliente;

}; */

//_____________PONTEIROS PARA SALVAR TEXTO____________
ofstream Cliente_txt;
ofstream Produto_txt;
ofstream Pedido_txt;
ofstream Intens_por_pedido_txt;
ofstream Tabela_geral_cleinte;

int main()
{
	string opcao;

	int op, i = 0;

	int *ptr;
	int tamanho = 0;

	int tamanho_produto = 0, tamanho_produto_i = 0;

	int tamanho_pedido = 0, tamanho_pedido_i = 0;

	int tamanho_Intens_por_pedido = 0, tamanho_Intens_por_pedido_i = 0;

	CLIENTE Cliente[100];
	PRODUTO Produto[100];
	PEDIDO Pedido[100];
	INTENS_POR_PEDIDO Intens_por_pedido[100];

	do
	{

		cout << endl;
		cout << "|-----------------------------------------------|" << endl;
		cout << "|                TABELA CLIENTE                 |" << endl;
		cout << "|_______________________________________________|" << endl;
		cout << "|                                               |" << endl;
		cout << "|A) Informacoes do cliente                      |" << endl;
		cout << "|B) Informacoes do Pedido                       |" << endl;
		cout << "|C) Informacoes dos produtos                    |" << endl;
		cout << "|D) Informacoes Itens por pedido                |" << endl;
		cout << "|E) Imprimir as informacoes                     |" << endl;
		cout << "|F) Deleta as informacoes                       |" << endl;
		cout << "|H) Alterar as informacoes                      |" << endl;
		cout << "|MENU: ";
		cin >> opcao;

		if (opcao == "A", "a")
		{
			cout << "\n|1) Inserir as informacoes do cliente           |" << endl;
			cout << "|2) Imprimir todos os clientes                  |" << endl;
			cout << "|3) Deleta todos os clientes                    |" << endl;
			cout << "|4) Alterar todos os clientes                   |" << endl;
			cout << "|MENU: ";
			cin >> op;
		}
		else if (opcao == "B", "b")
		{
			cout << "\n|5) Inserir pedido do cliente                   |" << endl;
			cout << "|6) Imprimir todos os pedidos                   |" << endl;
			cout << "|7) Deleta todos os pedidos                     |" << endl;
			cout << "|8) Alterar todos os pedidos                    |" << endl;
			cout << "|MENU: ";
			cin >> op;
		}
		else if (opcao == "C", "c")
		{
			cout << "\n|9) Escolha os produtos                         |" << endl;
			cout << "|10) Imprimir todos os produtos                  |" << endl;
			cout << "|11) Deleta todos os produtos                    |" << endl;
			cout << "|12) Alterar todos os produtos                   |" << endl;
			cout << "|MENU: ";
			cin >> op;
		}
		else if (opcao == "D", "e")
		{
			cout << "\n|13) Itens por pedido do cliente                 |" << endl;
			cout << "|MENU: ";
			cin >> op;
		}
		else if (opcao == "E", "e")
		{
			cout << "\n|14) Imprimir todas as informacoes               |" << endl;
			cout << "|15) Imrprimir toda tebela do cliente selecioado |" << endl;
			cout << "|MENU: ";
			cin >> op;
		}
		else if (opcao == "F", "f")
		{
			cout << "\n|16) Deleta todas as informacoes                 |" << endl;
			cout << "|17) Deleta toda tebela do cliente selecioado    |" << endl;
			cout << "|MENU: ";
			cin >> op;
		}
		else if (opcao == "H", "h")
		{
			cout << "\n|18) Alterar todas as informacoes do cliente              |" << endl;
			cout << "|MENU: ";
			cin >> op;
		}

		if (op == 1)
		{
			tamanho = i;
			i++;
		}

		if (op == 2)
		{
			tamanho_produto = tamanho_produto_i;
			tamanho_produto_i++;
		}
		if (op == 3)
		{
			tamanho_pedido = tamanho_pedido_i;
			tamanho_pedido_i++;
		}
		if (op == 4)
		{
			tamanho_Intens_por_pedido = tamanho_Intens_por_pedido_i;
			tamanho_Intens_por_pedido_i++;
		}

		switch (op)
		{
		case 1:
		{

			inserir_cliente(Cliente, tamanho);
		}

		break;

		case 2:
		{
			pedido_cliente(Pedido, tamanho_pedido);
		}
		break;

		case 3:
		{
			produto_cliente(Produto, tamanho_produto);
		}
		break;

		case 4:
		{
			// tamanho_Intens_por_pedido é um valor contador.
			Intens_cliente(Intens_por_pedido, tamanho_Intens_por_pedido);
		}
		break;

		case 5:
		{

			imprimir_cliente(Cliente, tamanho);
		}
		break;

		case 6:
		{
			imprimir_pedido(Pedido, tamanho_pedido);
		}
		break;

		case 7:
		{
			cout << "\n\nVAZIO\n\n";
		}
		break;

		case 8:
		{
			imprimir_geral(Cliente, Produto, tamanho);
		}
		break;

		case 9:
		{

			imprimir_todo_tebela(Cliente, Produto, Pedido, Intens_por_pedido, tamanho);
		}

		break;

		default:
			break;
		}

	} while (op != 0);

	return 0;
}

// ok
int inserir_cliente(struct CLIENTE *Cliente, int tamanho)
{
	int i = 0;

	PEDIDO Pedido[100];

	for (int i = tamanho; i <= tamanho; i++)
	{

		cout << "\nDigite o nome do cliente: ";
		cin >> Cliente[i].nome;

		cout << "Digite o CPf do cliente: ";
		cin >> Cliente[i].cpf;

		Cliente[i].id = i;

		*Pedido[i].CPF_cliente = Cliente[i].cpf;
	}

	return imprimir_cliente(Cliente, tamanho);
}

int imprimir_cliente(struct CLIENTE *Cliente, int tamanho)
{
	Cliente_txt.open("Cliente.txt", ios::app); // não subistiuir o valor anterio. (ios::app)

	cout << "\n";
	for (int i = 0; i <= tamanho; i++)
	{
		cout << "________________________" << endl;
		cout << "|     tabela cliente   |" << endl;
		cout << "|ID |    NOME    | CPF |" << endl;
		cout << "| " << Cliente[i].id << " | " << Cliente[i].nome << "   | " << Cliente[i].cpf << "   |" << endl;

		Cliente_txt << "________________________" << endl;
		Cliente_txt << "|     tabela cliente   |" << endl;
		Cliente_txt << "|ID |    NOME    | CPF |" << endl;
		Cliente_txt << "| " << Cliente[i].id << " | " << Cliente[i].nome << "   | " << Cliente[i].cpf << "   |" << endl;
	}

	Cliente_txt.close();
}

int produto_cliente(struct PRODUTO *Produto, int tamanho)
{

	cout << endl;
	for (int i = tamanho; i <= tamanho; i++)
	{
		cout << "Digete o nome do produto: ";
		cin >> Produto[i].nome;

		cout << "Preco do prutodo: ";
		cin >> Produto[i].preco;

		Produto[i].numero_identificador = i;
	}

	return imprimir_produto(Produto, tamanho);
}

int imprimir_produto(struct PRODUTO *Produto, int tamanho)
{
	Produto_txt.open("Produto.txt", ios::app);

	for (int i = 0; i <= tamanho; i++)
	{

		cout << "__________________________" << endl;
		cout << "|     tabela Protudo     |" << endl;
		cout << "|ID |    NOME    | preco |" << endl;
		cout << "| " << Produto[i].numero_identificador << " | " << Produto[i].nome << "   | " << Produto[i].preco << "   |" << endl;

		Produto_txt << "__________________________" << endl;
		Produto_txt << "|     tabela protudo     |" << endl;
		Produto_txt << "|ID |    NOME    | preco |" << endl;
		Produto_txt << "| " << Produto[i].numero_identificador << " | " << Produto[i].nome << "   | " << Produto[i].preco << "   |" << endl;
	}

	Produto_txt.close();
}

int pedido_cliente(struct PEDIDO *Pedido, int tamanho_pedido)
{
	cout << "\n";

	for (int i = tamanho_pedido; i <= tamanho_pedido; i++)
	{
		// cout << "Digite o numero do pedido: ";
		Pedido[i].numero_pedido = i;
	}

	return imprimir_pedido(Pedido, tamanho_pedido);
}

int imprimir_pedido(struct PEDIDO *Pedido, int tamanho_pedido)
{
	Pedido_txt.open("Pedido.txt", ios::app);

	for (int i = 0; i <= tamanho_pedido; i++)
	{
		cout << "_______________________________" << endl;
		cout << "|           tabela pedido     |" << endl;
		cout << "|Numero do pedido |    cpf    |" << endl;
		cout << "| " << Pedido[i].numero_pedido << "               |    " << *Pedido[i].CPF_cliente << "      | " << endl;

		Pedido_txt << "_______________________________" << endl;
		Pedido_txt << "|           tabela pedido     |" << endl;
		Pedido_txt << "|Numero do pedido |    cpf    |" << endl;
		Pedido_txt << "| " << Pedido[i].numero_pedido << "               |    " << *Pedido[i].CPF_cliente << "      | " << endl;
	}

	Pedido_txt.close();
}
int Intens_cliente(struct INTENS_POR_PEDIDO *Intens_por_pedido, int tamanho_Intens_por_pedido)
{

	int quantidade;

	cout << "\nQuantos itens voce deseja: ";
	cin >> quantidade;

	for (int i = 0; i < quantidade; i++)
	{
		/* code */
	}
}

int imprimir_todo_tebela(struct CLIENTE *Cliente, struct PRODUTO *Produto, struct PEDIDO *Pedido, struct INTENS_POR_PEDIDO *Intens_por_pedido, int tamanho)
{
	Tabela_geral_cleinte.open("Tabela_geral_cleinte.txt", ios::app);

	int escolher;

	cout << "\nDigite o ID do cliente\n";
	cout << "Qual cliente voce quer imprimir: ";
	cin >> escolher;

	for (int i = escolher; i <= tamanho; i++)
	{

		cout << "_____________________________________________________________________________" << endl;
		cout << "|     tabela cliente   |     tabela protudo     |        tabela pedido      |" << endl;
		cout << "|ID |    NOME    | CPF |ID |    NOME    | preco |Numero do pedido |    cpf  |" << endl;
		cout << "| " << Cliente[i].id << " | " << Cliente[i].nome << "   | " << Cliente[i].cpf
			 << "  | " << Produto[i].numero_identificador << " | " << Produto[i].nome << "       | " << Produto[i].preco
			 << "   | " << Pedido[i].numero_pedido << "               |    " << *Pedido[i].CPF_cliente << "      | " << endl;
	}

	Tabela_geral_cleinte.close();
}

int imprimir_geral(struct CLIENTE *Cliente, struct PRODUTO *Produto, int tamanho)
{

	for (int i = 0; i <= tamanho; i++)
	{
	}
}

int alterar_cliente(struct CLIENTE *Cliente, int quantidade)
{

	int clienteID, op;

	cout << "Digite o ID do cliente." << endl;
	cout << "Qual cliente quer alterar: ";
	cin >> clienteID;

	for (int i = 0; i <= quantidade; i++)
	{
		if (Cliente[i].id == clienteID)
		{
			cout << "1) Alterar nome do cliente" << endl;
			cout << "2) Alterar cpf fo cliente" << endl;

			if (op == 1)
			{
				cout << "Digite o novo nome do cliente: ";
				cin >> Cliente[i].nome;
				Cliente[i].nome = Cliente[i].nome;
			}
			if (op == 2)
			{
				cout << "Digite o novo cpf fo cliente: ";
				cin >> Cliente[i].cpf;

				Cliente[i].cpf = Cliente[i].cpf;
			}
		}
	}

	return imprimir_cliente(Cliente, quantidade);
}
