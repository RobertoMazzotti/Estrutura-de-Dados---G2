#include<stdio.h>
#include<stdlib.h>

typedef struct lista  {
    int idade;
    struct lista * proximo;
    }lista;
lista *insert_fim (lista *lista_insert, lista *novo ){
    lista *aux=lista_insert;
    if (aux == NULL) {
        return novo;
            }

    while (aux->proximo != NULL) {
       aux=aux->proximo;
    }
    aux->proximo=novo;
    return lista_insert;
}
lista *create_new_element (){
    int idade;
    printf("Informe a idade: ");
    scanf("%d",&idade);
    lista * novo= (lista *)malloc(sizeof(lista));

    novo-> idade=idade;
    novo->proximo = NULL;
    return novo;
}
lista * remove_last( lista * lista_remove){


    lista *aux = lista_remove;
    lista * aux2=aux;

    if (aux == NULL) {
            printf("A lista esta vazia!!!\n");
        return lista_remove;
            }

    if (aux->proximo == NULL) {
        printf("A lista ficou vazia!!\n");
        free(aux);
        return NULL;
    }

    while(aux->proximo!= NULL){
        aux2=aux;
        aux= aux->proximo;

    }

    aux2->proximo=NULL;
    free(aux);

return lista_remove;

}
void exibe_lista (lista * lista_exibe){
    if(lista_exibe==NULL){
        printf("Fim da lista!!!!\n");
    }else{
        if(lista_exibe!=NULL){
            printf("|%d| -> ", lista_exibe->idade);
            exibe_lista(lista_exibe->proximo);
    }
    }
}
int menu(void){
	int opt;

	printf("Escolha a opcao\n");
	printf("0. Sair\n");
	printf("1. Adicionar no fim da lista\n");
	printf("2. Remover do inicio da lista\n");
	printf("3. Remover do fim da lista\n");
	printf("4. Exibir lista\n");
	printf("5. Limpar a lista\n");
	printf("Opcao: "); scanf("%d", &opt);

	return opt;
}
lista * limpar_lista (lista * lista_limpar){

    lista * aux=lista_limpar;
    lista * aux2=aux;
        while(aux->proximo!=NULL){
            aux2=aux->proximo;
            free(aux);
            aux=aux2;
        }
        if(aux==NULL){
        return NULL;
        }
        if(aux->proximo==NULL){
        return NULL;
        }
        lista_limpar=aux;

}
int main() {
int escolha,indice=0;
    lista *e1 =NULL;
    lista *lista_inicio=NULL;
    lista *aux=NULL;
    aux=lista_inicio;
         while(!0){

            escolha=menu();
            switch (escolha){
                case 1:
                     printf("Adicionar ao final da lista \n");
                     e1= create_new_element();
                     lista_inicio=insert_fim(lista_inicio,e1);
                     system("cls");
                     break;
                case 2:
                    lista_inicio=remove_inicio(lista_inicio);
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    lista_inicio = remove_last(lista_inicio);
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    exibe_lista(lista_inicio);
                    system("pause");
                    system("cls");
                    break;
                case 5:
                    lista_inicio=limpar_lista(lista_inicio);
                    system("cls");
                    break;

                case 0:
                    return 0;
                    break;
                default:
                    printf("Valor Invalido\n");
                    system("pause");
                    system("cls");
                    break;
            }
        }


}
