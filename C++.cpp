#include <stdio.h> // Biblioteca de entrada/saída
#include <stdlib.h> // Biblioteca para system("cls")
#include <locale.h> // Biblioteca para suporte regional
#include <string.h> // Biblioteca responsável por cuidar das string

int registro() // Função responsável por cadastrar os usuários no sistema
{
	// Início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da criação de variáveis/string
	
	printf("Dígite o CPF a ser cadastrado: "); // Coletando informação do usuário
	scanf("%s", cpf); // "%s" Refere-se a string
	
	strcpy(arquivo, cpf); // Responsavel por copiar os valores das string
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // Cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // Salva o valor da variavel
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" Refere-se ao modo de abertura append (adicionar) 
	fprintf(file,",");
	fclose(file);
	
	printf("Dígite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Dígite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Dígite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
		
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Dígite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: \n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Dígite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");	
	
	if(file == NULL)
	{
		printf("O usuário foi deletado com sucesso! \n");
		system("pause");
	}
}

int sair()
{
	printf("Você escolheu sair do programa!\n");
	system("pause");
}

int main()
{
	int opcao = 0; // Definindo variáveis 
	
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	while (1) { // Loop infinito até o usuário sair 
		system("cls"); // Limpa a tela (somente no Windows)
		
		// Exibe o menu
		printf("### Cartório da EBAC ###\n\n");
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair\n\n");
		printf("Opção: ");
		
		// Lê a escolha do usuário
		scanf("%d", &opcao);
		
		system("cls"); // Responsavel por limpar a tela 
		
		switch(opcao){ // Início da seleção do menu
			case 1:
			registro(); // Chamada de funções
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			sair();
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
			
		}
	}
}
