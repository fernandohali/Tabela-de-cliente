
#include <iostream>
#include <locale.h>
#include <conio.h>
#include <fstream>

using namespace std;

//______________Função Inserir_______________________

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

// ___________________________Alterar tabela_____________

int alterar_cliente(struct CLIENTE *Cliente, int);

int alterar_produto(struct PRODUTO *Produto, int);

int alterar_pedido(struct PEDIDO *Pedido, int);

//____________________Função Deletar_____________________

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

//_____________ SALVAR TEXTO____________
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
		cout << "|A) MENU do cliente                             |" << endl;
		cout << "|B) MENU dos produtos                           |" << endl;
		cout << "|C) MENU do Pedido                              |" << endl;
		cout << "|D) MENU Itens por pedido                       |" << endl;
		cout << "|E) IMPRIMIR todas as informacoes               |" << endl;
		cout << "|F) DELETA todas as informacoes                 |" << endl;
		cout << "|S) Sair do menu                                |" << endl;
		cout << "|MENU: ";
		cin >> opcao;

		do
		{

			if (opcao == "a")
			{
				cout << "\n|-----------------------------------------------|" << endl;
				cout << "|                 CLIENTE                       |" << endl;
				cout << "|_______________________________________________|" << endl;
				cout << "|                                               |" << endl;
				cout << "|1) Inserir as informacoes do cliente           |" << endl; // ok
				cout << "|2) Imprimir o cliente selecionado              |" << endl;
				cout << "|3) Imprimir todos os clientes                  |" << endl; // ok
				cout << "|4) Deleta o cliente selecionado                |" << endl;
				cout << "|4) Deleta todos os clientes                    |" << endl;
				cout << "|5) Alterar o cliente selecionado               |" << endl;
				cout << "|0) Para voltar ao MENU                         |" << endl;
				cout << "|MENU: ";
				cin >> op;
			}
			else if (opcao == "b")
			{
				cout << "\n|-----------------------------------------------|" << endl;
				cout << "|                   PRODUTO                      |" << endl;
				cout << "|________________________________________________|" << endl;
				cout << "|                                               |" << endl;
				cout << "|10) Inserir o produto do cliente                |" << endl;
				cout << "|2) Imprimir o produtos selecionado              |" << endl;
				cout << "|11) Imprimir todos os produtos                  |" << endl;
				cout << "|12) Deleta todos os produtos                    |" << endl;
				cout << "|13) Alterar todos os produtos                   |" << endl;
				cout << "|0) Para voltar ao MENU                         |" << endl;
				cout << "|MENU: ";
				cin >> op;
			}
			else if (opcao == "c")
			{
				cout << "\n|-----------------------------------------------|" << endl;
				cout << "|                   PEDIDO                      |" << endl;
				cout << "|_______________________________________________|" << endl;
				cout << "|                                               |" << endl;
				cout << "|6) Inserir pedido do cliente                   |" << endl;
				cout << "|2) Imprimir o pedido selecionado               |" << endl;
				cout << "|7) Imprimir todos os pedidos                   |" << endl;
				cout << "|8) Deleta todos os pedidos                     |" << endl;
				cout << "|9) Alterar todos os pedidos                    |" << endl;
				cout << "|0) Para voltar ao MENU                         |" << endl;
				cout << "|MENU: ";
				cin >> op;
			}
			else if (opcao == "d")
			{
				cout << "\n|-----------------------------------------------|" << endl;
				cout << "|              INTENS POR PEDIDO                 |" << endl;
				cout << "|________________________________________________|" << endl;
				cout << "|                                               |" << endl;
				cout << "|14) Itens por pedido do cliente                 |" << endl;
				cout << "|2) Imprimir o Itens selecionado                 |" << endl;
				cout << "|0) Para voltar ao MENU                          |" << endl;
				cout << "|MENU: ";
				cin >> op;
			}
			else if (opcao == "e")
			{
				cout << "\n|-----------------------------------------------|" << endl;
				cout << "|                   IMPRIMIR                     |" << endl;
				cout << "|________________________________________________|" << endl;
				cout << "|15) Imprimir todas as informacoes               |" << endl;
				cout << "|16) Imrprimir toda tebela do cliente selecioado |" << endl;
				cout << "|0) Para voltar ao MENU                          |" << endl;
				cout << "|MENU: ";
				cin >> op;
			}
			else if (opcao == "f")
			{
				cout << "\n|-----------------------------------------------|" << endl;
				cout << "|                   DELETAR                      |" << endl;
				cout << "|________________________________________________|" << endl;
				cout << "|17) Deleta todas as informacoes                 |" << endl;
				cout << "|18) Deleta toda tebela do cliente selecioado    |" << endl;
				cout << "|0) Para voltar ao MENU                          |" << endl;
				cout << "|MENU: ";
				cin >> op;
			}
			else if (opcao == "h")
			{
				cout << "\n|-----------------------------------------------|" << endl;
				cout << "|                      VAZIO                     |" << endl;
				cout << "|________________________________________________|" << endl;
				cout << "\n|19) Alterar todas as informacoes do cliente   |" << endl;
				cout << "|0) Para voltar ao MENU                          |" << endl;
				cout << "|MENU: ";
				cin >> op;
			}
		} while (op != 0);

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

			// CLIENTES:
		case 1:
		{

			inserir_cliente(Cliente, tamanho);
		}

		break;

		case 3:
		{

			imprimir_cliente(Cliente, tamanho);
		}
		break;

		case 5:
		{
			alterar_cliente(Cliente, tamanho);
		}

		break;

			// PEDIDO:

		case 6:
		{
			pedido_cliente(Pedido, tamanho_pedido);
		}
		break;

		case 7:
		{
			imprimir_pedido(Pedido, tamanho_pedido);
		}
		break;

			// PRODUTO:

		case 10:
		{
			produto_cliente(Produto, tamanho_produto);
		}
		break;

		case 12:
		{
			alterar_produto(Produto, tamanho_produto);
		}

		break;

			// INTENS POR PEDIDO

		case 14:
		{
			// tamanho_Intens_por_pedido é um valor contador.
			Intens_cliente(Intens_por_pedido, tamanho_Intens_por_pedido);
		}
		break;

			// IMPRIMIR GERAL:

		case 8:
		{
			imprimir_geral(Cliente, Produto, tamanho);
		}
		break;

		case 20:
		{

			imprimir_todo_tebela(Cliente, Produto, Pedido, Intens_por_pedido, tamanho);
		}

		break;

		default:
			break;
		}

	} while (opcao != "s");

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

//____________________fUNÇÃO iMPRIMIR__________________________

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

//____________________fUNÇÃO ALTERAR__________________________

int alterar_cliente(struct CLIENTE *Cliente, int tamanho)
{

	int clienteID, op;

	cout << "\bDigite o ID do cliente que quer alterar: " << endl;
	cout << "MENU: ";
	cin >> clienteID;

	do
	{

		for (int i = 0; i <= tamanho; i++)
		{
			if (Cliente[i].id == clienteID)
			{
				cout << "\n1) Alterar nome do cliente" << endl;
				cout << "2) Alterar cpf fo cliente" << endl;
				cout << "0) para sair" << endl;
				cout << "MENU: ";
				cin >> op;

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
	} while (op != 0);

	return imprimir_cliente(Cliente, tamanho);
}

int alterar_produto(struct PRODUTO *Produto, int tamanho)
{
	int produtoID, op;

	cout << "\nDigite o ID do produto que quer alterar:";
	cin >> produtoID;

	do
	{

		for (int i = 0; i <= tamanho; i++)
		{
			if (Produto[i].numero_identificador == produtoID)
			{
				cout << "1) Alterar o nome do produto: " << endl;
				cout << "2) Alterar o preco do produto: " << endl;
				cout << "0) para sair" << endl;
				cout << "MENU: ";
				cin >> op;

				if (op == 1)
				{
					cout << "Digite o novo nome do produto: ";
					cin >> Produto[i].nome;

					Produto[i].nome = Produto[i].nome;
				}
				if (op == 2)
				{
					cout << "Digite o novo preco do produto: ";
					cin >> Produto[i].preco;

					Produto[i].preco = Produto[i].preco;
				}
			}
		}
	} while (op != 0);

	return imprimir_produto(Produto, tamanho);
}

int alterar_pedido(struct PEDIDO *Pedido, int tamanho)
{
	int pedidoID, op;
	int *cpf;

	cout << "\nDigite o ID do pedido que quer alterar:";
	cin >> pedidoID;

	do
	{

		for (int i = 0; i <= tamanho; i++)
		{
			if (Pedido[i].numero_pedido == pedidoID)
			{
				cout << "1) Alterar o numero do pedido: " << endl;
				// cout << "2) Alterar o cpf do pedido: " << endl;
				cout << "0) para sair" << endl;
				cout << "MENU: ";
				cin >> op;

				if (op == 1)
				{
					cout << "Digite o numero do pedido: ";
					cin >> Pedido[i].numero_pedido;

					Pedido[i].numero_pedido = Pedido[i].numero_pedido;
				}
				/* if (op == 2)
				{
					cout << "Digite o cpf do pedido: ";
					cin >> *cpf;

					Pedido[i].CPF_cliente = cpf;
				} */
			}
		}
	} while (op != 0);

	return imprimir_pedido(Pedido, tamanho);
}

//____________________fUNÇÃO DELETAR__________________________
