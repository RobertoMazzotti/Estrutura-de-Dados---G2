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
    printf("\n\n");
    if(lista_exibe==NULL){
        printf("Lista Vazia!!!!");
    }
        while(lista_exibe!=NULL){
            printf("|%d| -> ", lista_exibe->idade);
            lista_exibe=lista_exibe->proximo;
    }
    printf("\n");
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
	printf("6. Adicionar no inicio da lista\n");
	printf("7. Inserir em uma determinada posicao (informar o indice)\n");
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
lista * remove_inicio (lista * lista_remove){

    lista * aux=lista_remove;
    if(lista_remove==NULL){
        printf("A lista ja estava vazia!!!!");
        return NULL;
    }
    if(lista_remove->proximo){
        free(lista_remove);
        printf("A lista ficou vazia");
    }
    aux=aux->proximo;
    free(lista_remove);
    lista_remove=aux;
    return lista_remove;
}

lista * insert_inicio (lista *lista_insert, lista *novo ){

    if(lista_insert==NULL){
        return novo;
    }
        novo->proximo= lista_insert;
        return novo;
}

lista * insert_indice (lista *lista_insert, lista *novo, int indice){
    lista *aux=lista_insert;
    lista *aux2=aux;
    int i;
    printf("Infome a posicao que ira inserir: "); scanf("%d",&indice);
        if(aux==NULL){
            return novo;
        }else{

    for(i=0;i<indice-1;i++){
        if (aux->proximo==NULL){
            break;

        }else{
        aux=aux->proximo;
        }
    }
    for(i=0;i<indice-2;i++){
            if (aux2->proximo==NULL){
                break;
        }else{
        aux2=aux2->proximo;
        }
    }
    aux2->proximo=novo;
    novo->proximo=aux;

    return lista_insert;
        }
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
                case 6:
                    e1= create_new_element();
                    lista_inicio=insert_inicio(lista_inicio,e1);
                    system("pause");
                    system("cls");
                    break;
                case 7:
                    e1= create_new_element();
                    lista_inicio=insert_indice(lista_inicio,e1,indice);
                    system("pause");
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
