#include <stdio.h>
#include <conio.h>
#include <windows.h>

struct LISTA{
	int num;
	LISTA *prox;
	LISTA *ant;
};


LISTA *intercalar_lista(LISTA *primeira, LISTA*segunda, LISTA *result)
{
	LISTA *aux,*aux2,*anterior;
	aux = primeira;
	aux2 = segunda;
	
	do{
		if(result == NULL)
		{
			LISTA *novo = new LISTA();
			novo->num = aux->num;
			result = novo;
			novo->ant = result;
			anterior = novo;
			novo->prox = NULL;
			aux = aux->prox;
		}
		else
		{
			LISTA *novo = new LISTA();
			novo->num = aux2->num;
			anterior->prox = novo;
			novo->ant = anterior;
			anterior = novo;
			novo->prox = NULL;
			aux2 = aux2->prox;
			
			LISTA *novo2 = new LISTA();
			novo2->num = aux->num;
			anterior->prox = novo2;
			novo2->ant = anterior;
			anterior = novo2;
			novo2->prox = NULL;
			aux = aux->prox;
			
		}
	}while(aux2->prox != segunda);
		
		if(aux2->prox == segunda)
		{
			LISTA *novo = new LISTA();
			novo->num = aux2->num;
			anterior->prox = novo;
			novo->ant = anterior;
			anterior = novo;
			novo->prox = NULL;
			aux2 = aux2->prox;	
		}
		
		anterior->prox = result;
		result->ant = anterior;
		printf("Listas Intercaladas!");
		return result;
}

void consultar_listas(LISTA *primeira,LISTA *segunda,LISTA *resultado)
{
	LISTA *aux1,*aux2,*aux3;
	aux1 = primeira;
	aux2 = segunda;
	aux3 = resultado;
	
	if(aux1 == NULL)
	{
		printf("\nLista 1 esta vazia.\n");
	}
	else
	{
		printf("\nLista 1:\n");
		do{
			printf("%d ",aux1->num);
			aux1 = aux1->prox;
		}while(aux1 != primeira);
		printf("\n");
	}
	
	if(aux2 == NULL)
	{
		printf("\nLista 2 esta vazia.\n");
	}
	else
	{
		printf("\nLista 2:\n");
		do{
			printf("%d ",aux2->num);
			aux2 = aux2->prox;
		}while(aux2 != segunda);
		printf("\n");
	}
	if(aux3 == NULL)
	{
		printf("\nLista 3 esta vazia.\n");
	}
	else
	{
		printf("\nLista 3:\n");
		do{
			printf("%d ",aux3->num);
			aux3 = aux3->prox;
		}while(aux3 != resultado);
	}
}

LISTA *inserir_lista(LISTA *inicio)
{
	printf("\nDigite os numeros.\n");
	for(int i = 0; i < 5; i++)
	{
		LISTA *novo = new LISTA();
		scanf("%d",&novo->num);
		LISTA *aux = inicio;
		if(inicio == NULL)
		{
			inicio = novo;
			inicio->prox = novo;
		}
		else
		{
			LISTA *aux = inicio;
			while(aux->prox != inicio)
			{
				aux = aux->prox;
			}
			aux->prox = novo;
			novo->prox = inicio;
		}
	}
	printf("\nLista cadastrada com sucesso !\n");
	return inicio;
}

int main()
{
	LISTA * primeira = NULL;
	LISTA * segunda = NULL;
	LISTA * result = NULL;
	int ljp = 0;
	int ljp2 = 0;
	int interc = 0;
	int menu;
	
	do {
		system("cls");
		printf("\nMENU DE OPCOES");
		printf("\n1 - Inserir na lista.");
		printf("\n2 - Intercalar listas.");
		printf("\n3 - Consultar listas.");
		printf("\n4 - Sair.");
		printf("\nDigite a opcao desejada:");
		scanf("%d",&menu);
		switch(menu){
			case 1:
				int opcao;
				printf("\nDigite qual lista deseja criar?");
				printf("\n1 - Lista 1.");
				printf("\n2 - Lista 2.\n");
				scanf("\n%d",&opcao);
				if(opcao == 1)
				{
					if(ljp == 1){
						printf("Lista ja preenchida.");
					}
					else
					{
						primeira = inserir_lista(primeira);
						ljp = 1;
					}
				}
				else if(opcao == 2)
				{
					if(ljp2 == 1){
						printf("Lista ja preenchida.");
					}
					else
					{	
						segunda = inserir_lista(segunda);
						ljp2 = 1;	
					}
				}
				break;
			case 2:
				if(interc == 1)
				{
					printf("\nListas ja intercaladas\n");
				}
				else
				{
					if(primeira == NULL)
					{
						printf("Antes de intercalar, crie a lista '1' na opcao 1.\n");
					}
					else if(segunda == NULL)
					{
						printf("Antes de intercalar, crie a lista '2' na opcao 1.\n");
					}
					else
					{
						result = intercalar_lista(primeira,segunda,result);
						interc = interc + 1;
					}
				}
					break;
			case 3:
				consultar_listas(primeira,segunda,result);
				break;	
		}
		getch();
	}while (menu != 4);
}

