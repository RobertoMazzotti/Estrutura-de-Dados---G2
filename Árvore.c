#include<stdio.h>
#include<stdlib.h>
typedef struct no_arv{
    int info;
    struct no_arv * esquerda;
    struct no_arv * direita;
}no_arv;
no_arv * create_new_element(int info){
    no_arv * novo = (no_arv *) malloc(sizeof(no_arv));
    novo->info = info;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}
void insere_folha(no_arv ** arv, no_arv * novo){
   if (*arv == NULL){
     *arv = novo;
   }else{
     if(novo->info < (*arv)->info){
        insere_folha(&(*arv)->esquerda, novo);
     }else if(novo->info > (*arv)->info){
        insere_folha(&(*arv)->direita, novo);
     }
   }
}
void show_arv_pre(no_arv * arvore){ //raiz esquerda direita
    if(arvore!=NULL){
     printf("%d ",arvore->info);
     show_arv_pre(arvore->esquerda);
      show_arv_pre(arvore->direita);
    }
}
void show_arv_em(no_arv * arvore){ // esquerda raiz direita
    if(arvore!=NULL){

     show_arv_em(arvore->esquerda);
     printf("%d ",arvore->info);
      show_arv_em(arvore->direita);
    }
}
void show_arv_pos(no_arv * arvore){ //esquerda direita raiz
    if(arvore!=NULL){

     show_arv_pos(arvore->esquerda);
    show_arv_pos(arvore->direita);
       printf("%d",arvore->info);
    }
}
void monta_menu(){

   printf("//////////////////////////////////////////////////////////////// \n");
   printf("Operacoes sobre Arvores \n");
   printf("Selecione a opcao Desejada: \n");
   printf("   1 - Incluir Folha\n");
   printf("   2 - Caminhar Em Pre-Ordem \n");
   printf("   3 - Caminhar Em Ordem \n");
   printf("   4 - Caminhar Em Pos-Ordem \n");
   printf("   5 - Buscar no vetor \n");
   printf("   6 - Verificar elemento na arvore \n");
   printf("   7 - Determinar o nivel de um nodo \n"); // Em desenvolvimento
   printf("   0 - Sair \n");
   printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n \n");
   printf("Qual a sua opcao: ");
}
no_arv * pesquisa_nodo(no_arv * arvore, int info){
     if(arvore!=NULL){
        if(arvore->info == info){
                return 1;
             }
        if(pesquisa_nodo(arvore->esquerda,info)== 1){
           return 1;
           }
        if(pesquisa_nodo(arvore->direita,info)== 1){
           return 1;
             }
        return NULL;
     }
}
int pesquisa_info (){
    int info;
    printf("Digite o numero:");
    scanf("%d",&info);
    return info;
}
int nivel_do_nodo(no_arv * arvore, int info,int nivel){
     printf("Nivel raiz: %d\n",nivel);
    if(arvore!=NULL){
        if(arvore->info == info){
                return nivel;
             }
            if(arvore->esquerda!=NULL){
                printf("esquerda\n");
                nivel ++;
                nivel_do_nodo(arvore->esquerda,info,nivel);
                return nivel;
            }
            if(arvore->direita!=NULL){
                printf("direita\n");
                nivel ++;
               nivel_do_nodo(arvore->direita,info,nivel++);
               return nivel;

             }
        }

        return nivel;
     }
void busca_vetor(int vet[]){
    no_arv * arvore=NULL;
    no_arv * novo =NULL;
    int i=0;

    while(vet[i]!= NULL){
    novo=create_new_element(vet[i]);
    insere_folha(&arvore,novo);
    i++;
   }

    show_arv_em(arvore);
}
int main(){
int pesquisa,pesquisa2 ,op = 1;
int vet[9]={8, 3, 10, 1, 6, 14, 4, 7, 13};
  int nivel = 0;
  int info,aux,aux2 ;
  no_arv * arvore = NULL;
  no_arv * novo = NULL;
  do{
        monta_menu();
        scanf("%d", &op);
        system("cls");

        switch(op){
            case 1:
                printf("Informe a letra a inserir na arvore: \n");
                scanf(" %d", &info);
                novo = create_new_element(info);
                insere_folha(&arvore, novo);
                break;
            case 2:
                show_arv_pre(arvore);
                 printf("\n\n:");
                break;
            case 3:
                show_arv_em(arvore);
                printf("\n\n:");
                break;
            case 4:
                show_arv_pos(arvore);
                printf("\n\n:");
                break;
            case 5:
               busca_vetor(vet);
               break;
            case 6:
                info=pesquisa_info();
                aux2=pesquisa_nodo(arvore,info);
                if(aux2 == 1){
                    printf("O elemento %d existe na arvore\n",info);
                }else{
                    printf("O elemento nao existe na arvore\n");
                 }
                 break;
            case 7:
                nivel=0;
                info=pesquisa_info();
                nivel=nivel_do_nodo(arvore,info,nivel);

                printf("O nivel do nodo %d eh %d\n",info,nivel);
        }
    }while (op != 0);
}
