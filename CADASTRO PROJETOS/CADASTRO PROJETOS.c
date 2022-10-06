// BIBILIOTECAS INCLUIDAS NO PROJETO;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// DEFINE O NUMERO MAX DE CADASTROS;
#define MAX 200

// REGISTRO PARA ARMAZENAMENTO DE DADOS;

typedef struct dados
{
	int codigo,cod_status1,cod_status2,cod_status3;
	char ano[4],descricao[150],GPR[30],status[10],titulo[50],estado[20],telefone[14],faculdade[20];
}cadprojeto; 


cadprojeto cadastro[MAX];
int cont = 0;

// MENU INICIAL
void menu_inicial ()
{
	system("cls");
	printf("|*************************************************|\n");
	printf("|                GESTÃO DE  PROJETOS              |\n");
	printf("|*************************************************|\n");
	
	printf("| 01 - CADASTRAR NOVOS PROJETOS                   |\n");
	printf("| 02 - IMPRESSÃO DE TODOS PROJETOS                |\n");
	printf("| 03 - IMPRESSÃO DOS PROJETOS POR STATUS          |\n");
	printf("| 04 - PESQUISA DE PROJETOS PELO CODIGO           |\n");
	printf("| 05 - SAIR DO PROGAMA                            |\n");
	printf("|          < < ESCOLHA UMA OPÇÃO>>                |\n");
	printf("|*************************************************|\n");
}


// MENU DE CADASTRAR NOVOS PROJETOS

void menu_cadastro(cadprojeto cadastro[MAX])
{
	system("cls");
	printf("|***************************************************|\n");
	printf("|           CADASTRANDO O SEU PROJETO               |\n");
	printf("|***************************************************|\n\n");
	char resp = 's';
	int status_;
	
	while ( resp == 's' && cont < MAX)
	{
		cont++;
		cadastro[cont].codigo = cont;
		printf("\n O PROJETO È O DE CODIGO: %d\n",cadastro[cont].codigo);
		printf("----------------------------------------------------\n");
		printf("\n INFORME O TITULO DO PROJETO: ");
		fgets(cadastro[cont].titulo,50,stdin);
		fflush(stdin);
			
		printf("\n INFORME A DESCRIÇÃO DO PROJETO: ");
		fgets(cadastro[cont].descricao,150,stdin);
		fflush(stdin);
			
		printf("\n INFORME O GERENTE RESPONSAVEL DO PROJETO: ");
		fgets(cadastro[cont].GPR,30,stdin);
		fflush(stdin);
			
		printf("\n INFORME O TELEFONE DE CONTATO DO PROJETO: ");
		fgets(cadastro[cont].telefone,14,stdin);
		fflush(stdin);
			
		printf("\n INFORME O ESTADO DE ORIGEM DO PROJETO: ");
		fgets(cadastro[cont].estado,20,stdin);
		fflush(stdin);
			
		printf("\n INFORME A FACULDADE DO PROJETO: ");
		fgets(cadastro[cont].faculdade,20,stdin);
		fflush(stdin);
			
		printf("\n INFORME O ANO DO INICIO PROJETO: ");
		fgets(cadastro[cont].ano,4,stdin);
		fflush(stdin);
		
		printf("\n INFORME O STATUS DO PROJETO: ");
		printf("\n 1- A FAZER ");
		printf("\n 2- FAZENDO ");
		printf("\n 3-CONCLUIDO \n");
		scanf("%d",&status_);
		fflush(stdin);
	
		
		switch (status_)
		{
			case 1:
				strcpy(cadastro[cont].status,"A FAZER");
				cadastro[cont].cod_status1 = 1;
				break;
			case 2:
				strcpy(cadastro[cont].status,"FAZENDO");
				cadastro[cont].cod_status2 = 2;
				break;
			case 3:
				strcpy(cadastro[cont].status,"CONCLUIDO");
				cadastro[cont].cod_status3 = 3;
				break;
			default:
				printf(" OPÇÂO INVALIDA.STATUS NÃO FOI CADASTRADO.");	
		}
		
		if (cont < MAX)
		{
			printf ("\n\nDESEJA CADASTRAR OUTRO PROJETO ? [s]SIM [n]NÃO\n\n");
			scanf("%c",&resp);
			fflush(stdin);
			printf("----------------------------------------------------\n\n\n\n"); 
			system("cls");
		}
		else
		{
			printf ("|n\n O SEU LIMITE DE CADASTRO FOI ATINGIDO !!!\n");
			resp ='n';
			system("pause");
		}
		
	}
	system("cls");
}

// MENU IMPRESSÃO DE TODOS PROJETOS

void menu_imprimirtds(cadprojeto cadastro[MAX])
{
	system("cls");
	printf("|***************************************************|\n");
	printf("|         IMPRESSÃO DE TODOS PROJETOS               |\n");
	printf("|***************************************************|\n\n");
	
	int i=1 ;
	
	if ( cont >= 1)
	{
		while (i <=cont)
		{
			printf("\n|***************************************************|\n\n");
			printf("\n O PROJETO È O DE CODIGO : %d",cadastro[i].codigo);
			
			printf("\n O TITULO DO PROJETO: %s",cadastro[i].titulo);
						
			printf("\n A DESCRIÇÃO DO PROJETO: %s",cadastro[i].descricao);
		
			printf("\n O GERENTE RESPONSAVEL DO PROJETO: %s ",cadastro[i].GPR);
						
			printf("\n O TELEFONE DE CONTATO DO PROJETO: %s",cadastro[i].telefone);
					
			printf("\n O ESTADO DE ORIGEM DO PROJETO: %s",cadastro[i].estado);
						
			printf("\n A FACULDADE DO PROJETO: %s",cadastro[i].faculdade);
						
			printf("\n O ANO DO INICIO DO PROJETO: %s",cadastro[i].ano);
					
			printf("\n O STATUS DO PROJETO: %s",cadastro[i].status);
			printf("\n|***************************************************|\n\n");
			i++;
		}
		
	}
	else
	{
		printf("\n NENHUM PROJETO FOI CADASTRADO!\n");
		system("Pause");
	}
	
	system ("pause");
}

// IMPRESSÃO POR STATUS DO PROJETO;

void menu_impr_status(cadprojeto cadastro[MAX])
{
	int escolha_, cod1,cod2,cod3,i;
	
	system("cls");
	printf("|***************************************************|\n");
	printf("|       IMPRESSÃO DO PROJETOS POR STATUS            |\n");
	printf("|***************************************************|\n");
	printf("| 01 - IMPRIMIR TODOS PROJETOS COM STATUS: A FAZER  |\n");
	printf("| 02 - IMPRIMIR TODOS PROJETOS COM STATUS: FAZENDO  |\n");
	printf("| 03 - IMPRIMIR TODOS PROJETOS COM STATUS: CONCLUIDO|\n");
	printf("| 04 - VOLTAR AO MENU                               |\n");
	printf("|            < < ESCOLHA UMA OPÇÃO>>                |\n");
	printf("|***************************************************|\n");
	scanf("%d",&escolha_);
	fflush(stdin);
	
	switch (escolha_)
	{
		case 1:
			system("cls");
			printf("|***************************************************|\n");
			printf("|       IMPRESSÃO DO PROJETOS POR STATUS: A FAZER   |\n");
			printf("|***************************************************|\n");
			i=1;
			
			for (i;i<=cont;i++)
					{
						if (cadastro[i].cod_status1 != 0)
						{
						printf("\n|***************************************************|\n\n");
						printf("\n O PROJETO È O DE CODIGO : %d",cadastro[i].codigo);
						
						printf("\n O TITULO DO PROJETO: %s",cadastro[i].titulo);
									
						printf("\n A DESCRIÇÃO DO PROJETO: %s",cadastro[i].descricao);
					
						printf("\n O GERENTE RESPONSAVEL DO PROJETO: %s ",cadastro[i].GPR);
									
						printf("\n O TELEFONE DE CONTATO DO PROJETO: %s",cadastro[i].telefone);
								
						printf("\n O ESTADO DE ORIGEM DO PROJETO: %s",cadastro[i].estado);
									
						printf("\n A FACULDADE DO PROJETO: %s",cadastro[i].faculdade);
									
						printf("\n O ANO DO INICIO DO PROJETO: %s",cadastro[i].ano);
								
						printf("\n O STATUS DO PROJETO: %s",cadastro[i].status);
						printf("\n|***************************************************|\n\n");
						
						}
					
					
					}
				
			
			
		system("Pause");
		break;
		
		case 2:	
		system("cls");
			printf("|***************************************************|\n");
			printf("|       IMPRESSÃO DO PROJETOS POR STATUS: FAZENDO   |\n");
			printf("|***************************************************|\n");
			i=1;
			
			for (i;i<=cont;i++)
					{
						if (cadastro[i].cod_status2 != 0)
						{
						printf("\n|***************************************************|\n\n");
						printf("\n O PROJETO È O DE CODIGO : %d",cadastro[i].codigo);
						
						printf("\n O TITULO DO PROJETO: %s",cadastro[i].titulo);
									
						printf("\n A DESCRIÇÃO DO PROJETO: %s",cadastro[i].descricao);
					
						printf("\n O GERENTE RESPONSAVEL DO PROJETO: %s ",cadastro[i].GPR);
									
						printf("\n O TELEFONE DE CONTATO DO PROJETO: %s",cadastro[i].telefone);
								
						printf("\n O ESTADO DE ORIGEM DO PROJETO: %s",cadastro[i].estado);
									
						printf("\n A FACULDADE DO PROJETO: %s",cadastro[i].faculdade);
									
						printf("\n O ANO DO INICIO DO PROJETO: %s",cadastro[i].ano);
								
						printf("\n O STATUS DO PROJETO: %s",cadastro[i].status);
						printf("\n|***************************************************|\n\n");
						
						}
					}
		system("Pause");
		break;
		
		case 3:
			system("cls");
			printf("|***************************************************|\n");
			printf("|      IMPRESSÃO DO PROJETOS POR STATUS: CONLUIDO   |\n");
			printf("|***************************************************|\n");
			i=1;
			
			for (i;i<=cont;i++)
					{
						if (cadastro[i].cod_status3 != 0)
						{
						printf("\n|***************************************************|\n\n");
						printf("\n O PROJETO È O DE CODIGO : %d",cadastro[i].codigo);
						
						printf("\n O TITULO DO PROJETO: %s",cadastro[i].titulo);
									
						printf("\n A DESCRIÇÃO DO PROJETO: %s",cadastro[i].descricao);
					
						printf("\n O GERENTE RESPONSAVEL DO PROJETO: %s ",cadastro[i].GPR);
									
						printf("\n O TELEFONE DE CONTATO DO PROJETO: %s",cadastro[i].telefone);
								
						printf("\n O ESTADO DE ORIGEM DO PROJETO: %s",cadastro[i].estado);
									
						printf("\n A FACULDADE DO PROJETO: %s",cadastro[i].faculdade);
									
						printf("\n O ANO DO INICIO DO PROJETO: %s",cadastro[i].ano);
								
						printf("\n O STATUS DO PROJETO: %s",cadastro[i].status);
						printf("\n|***************************************************|\n\n");
						
						}
					}
		system("Pause");
		break;
		
		case 4:
			system("cls");
			printf("\n VOLTANDO AO MENU!\n");
			system("Pause");
			break;
			
		default:
			printf("\n CODIGO INVALIDO! \n");
			system("Pause");
	}
	
}

// BUSCA POR CODIGO

void menu_busca_codigo (cadprojeto cadastro[MAX])
{
	int codigo_,i=0,j=0;
	system("cls");
	printf("|***************************************************|\n");
	printf("|           BUSCA DE PROJETO POR CODIGO             |\n");
	printf("|***************************************************|\n");
	printf(" FAVOR DIGITAR O CODIGO PARA A BUSCA: ");
	scanf("%d",&codigo_);
	fflush(stdin);
	
	while((i == 0) && (j <= cont))
	{
		if(codigo_ == cadastro[j].codigo)
		{
			
			printf("\n|***************************************************|\n\n");
			
			printf("\n O PROJETO È O DE CODIGO : %d",cadastro[j].codigo);
			
			printf("\n O TITULO DO PROJETO: %s",cadastro[j].titulo);
			
			printf("\n A DESCRIÇÃO DO PROJETO: %s",cadastro[j].descricao);
			
			printf("\n O GERENTE RESPONSAVEL DO PROJETO: %s ",cadastro[j].GPR);
						
			printf("\n O TELEFONE DE CONTATO DO PROJETO: %s",cadastro[j].telefone);
					
			printf("\n O ESTADO DE ORIGEM DO PROJETO: %s",cadastro[j].estado);
						
			printf("\n A FACULDADE DO PROJETO: %s",cadastro[j].faculdade);
						
			printf("\n O ANO DO INICIO DO PROJETO: %s",cadastro[j].ano);
					
			printf("\n O STATUS DO PROJETO: %s",cadastro[j].status);
			
			printf("\n|***************************************************|\n\n");
			i = 1;
			system("Pause");
		}
		j++;
	}
		if(i == 0 )
		{
			printf("\n PROJETO NÃO ENCONTRADO COM O CODIGO %d \n", codigo_);
			system("Pause");
		}
}
	



int main()
{
	setlocale(LC_ALL,"Portuguese");
	
	
	int escolha;
	

	do
	{
	menu_inicial();
	scanf("%d",&escolha);
	fflush(stdin);
	system("cls");
	
	switch (escolha)
	{
		case 1: 
		menu_cadastro(cadastro);
		break;
		
		case 2: 
		menu_imprimirtds(cadastro);		
		break;
		
		case 3:
		menu_impr_status(cadastro);
		break;
		
		case 4: 
		menu_busca_codigo(cadastro);
		
		break;
		
		case 5:
			system("cls");
			printf(" OBRIGADO POR ULTIZAR O PROGAMA. ATÉ A PROXIMA!\n\n ");
			system("pause");
			system("cls");
			
		break;
		
		default :
			system("cls");
			printf(" OPÇÃO INVALIDA, FAVOR TENTAR NOVAMENTE.\n\n");
			system("pause");
			system("cls");
			
	}
	} while (escolha != 5);
	
	return 0;
	
	// Dev: William Lima Alves
}

