#include <stdio.h>
#include <stdlib.h>

int exibe_N_NumerosCrescente(int n){
   if(n > 0){
        n--;
        exibe_N_NumerosCrescente(n);
        printf("%d \n",n);
    }
}

int exibe_N_NumerosDecrescente(int n){
   if(n > 0){
       n--;
       printf("%d \n",n);
        exibe_N_NumerosDecrescente(n);
    }
}
int exibe_N_NumerosSoma(int n){
        if(n == 1) {
            return 1;
        }else{
            return ( n + exibe_N_NumerosSoma(n-1) );
        }
}

int main(){
    int i;
     printf(" Inicio ! \n");
     exibe_N_NumerosCrescente(3);
        printf(" Fim !\n");
    printf(" Inicio ! \n");
     exibe_N_NumerosDecrescente(3);
    // i=exibe_N_NumerosSoma(2);
  //   printf("Soma: %d", i);

     printf(" Fim !");
}
