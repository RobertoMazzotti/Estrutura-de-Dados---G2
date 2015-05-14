#include<stdio.h>
#include<stdlib.h>

typedef struct lista  {
    int idade;
    struct lista * proximo;
    }lista;
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

    if (aux->proximo == lista_remove) {
        printf("A lista ficou vazia!!\n");
        free(aux);
        return NULL;
    }

    while (aux->proximo != lista_remove) {
        aux2=aux;
       aux=aux->proximo;
    }

    aux2->proximo=lista_remove;
    free(aux);

return lista_remove;

}
void exibe_lista (lista * lista_exibe){
    lista *aux=lista_exibe;
    lista *aux2=lista_exibe;
    printf("\n\n");
    if(lista_exibe==NULL){
        printf("Lista Vazia!!!!\n");
        return 0;
    }
        while(aux->proximo!=lista_exibe){

            printf("Endereco|%d| -> \n", aux);
            printf("idade :|%d| -> \n", aux->idade);
            printf("Proximo|%d| -> \n", aux->proximo);
            printf("\n\n");
            aux=aux->proximo;

    }
            printf("Endereco|%d| -> \n", aux);
            printf("idade: |%d| -> \n", aux->idade);
            printf("Proximo|%d| -> \n", aux->proximo);
            printf("\n\n");
            aux=aux->proximo;
    printf("\n");
}
int menu(void){
	int opt;

	printf("Escolha a opcao\n");
	printf("0. Sair\n");
	printf("1. Adicionar a lista circular\n");
	printf("2. Remover da lista circular\n");
	//printf("3. Remover do fim da lista\n");
	printf("3. Exibir lista\n");
	printf("4. Limpar a lista\n");
	//printf("6. Adicionar no inicio da lista\n");
	//printf("7. Inserir em uma determinada posicao (informar o indice)\n");
	printf("Opcao: "); scanf("%d", &opt);

	return opt;
}
lista * limpar_lista (lista * lista_limpar){

    lista * aux=lista_limpar;
    lista * aux2=lista_limpar;
    if(aux==NULL){
        printf("A lista ja estava vazia!!!!!\n");
        return NULL;
        }
        if(aux->proximo==lista_limpar){
            printf("LISTA VAZIA!!!!\n");
        return NULL;
        }
        while(aux->proximo!=lista_limpar){
            aux2=aux->proximo;
            free(aux);
            aux=aux2;
        }

        lista_limpar=aux;
        printf("LISTA VAZIA!!!!\n");
        return NULL;

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

lista *insert_fim (lista *lista_insert, lista *novo ){
    lista *aux=lista_insert;
    lista *aux2=lista_insert;
    if (aux == NULL) {
        novo->proximo=novo;

        return novo;
            }



    while (aux->proximo != lista_insert) {
       aux=aux->proximo;
    }
    novo->proximo=lista_insert;
    aux->proximo=novo;
    return lista_insert;
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
                     printf("Adicionar a lista circular \n");
                     e1= create_new_element();
                     lista_inicio=insert_fim(lista_inicio,e1);

                     system("cls");
                     break;
                /*case 2:
                    lista_inicio=remove_inicio(lista_inicio);
                    system("pause");
                    system("cls");
                    break;*/
                case 2:
                    lista_inicio = remove_last(lista_inicio);
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    exibe_lista(lista_inicio);
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    lista_inicio=limpar_lista(lista_inicio);
                    system("pause");
                    system("cls");
                    break;
               /*case 6:
                    e1= create_new_element();
                    lista_inicio=insert_inicio(lista_inicio,e1);
                    system("pause");
                    system("cls");
                    break;*/
                /*case 7:
                    e1= create_new_element();
                    lista_inicio=insert_indice(lista_inicio,e1,indice);
                    system("pause");
                    system("cls");
                    break;*/
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
