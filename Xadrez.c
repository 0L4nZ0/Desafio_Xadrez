#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//biblioteca de variaveis e constantes:
/*
 torre = 5;//5 casas para direita (for)
 bispo = 5;//5 casas na diagonal "cima,direita" (while)
 rainha = 8;//8 casas para a esquerda (do while)
 cavalo1 = 2;//2 casas para baixo(for)
 cavalo2 = 1;//1 casa para esquerda(while/do while)
 */

//constantes para facilitar a exibição das direções, usando vetores para armazenar as strings separadas por suas devidas direções
const char *horizontal[2] = {"Esquerda", "Direita"};
const char *vertical[2] = {"Cima", "Baixo"};
const char *diagonal[4] = {"Diagonal superior esquerda", "Diagonal superior direita", "Diagonal inferior esquerda", "Diagonal inferior direita"};

//variáveis para serem utilizadas no menu e na escolha das peças
int sair_menu = 0;
int escolha_menu, escolha_movimento, escolha_movimento_2, escolha_casas = 0;

// Função para limpar o buffer do stdin depois de cada coleta de dados
int limparBuffer() {
    
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return 0;
}

//função para dar espaçamento de linhas
void espacamento(){
    
    printf("\n");
    printf("\n-----------------------------------------------------\n");
    printf("\n");

}
  

/* Função de cada peça utilizando loops como pedido nos primeiros níveis

void movimento_torre(int mov_torre, int casas_torre){
    
    //condicional para decidir qual a direção escolhida da torre
    if (mov_torre == 1 || mov_torre == 2){
        
        //loop para movimentar a torre horizontalmente
        for (int i = 0; i < casas_torre; i++)
            {
                printf("%s\n", horizontal[mov_torre - 1]);//[move_torre - 1] é para transcrever o valor 1 e 2 para as strings em horizontal[0], [1]
            }

   }
   else if(mov_torre == 3 || mov_torre == 4){
        
        //loop para movimentar a torre verticalmente
        for (int i = 0; i < casas_torre; i++)
                {
                printf("%s\n", vertical[mov_torre - 3]);//[move_torre - 3] é para transcrever o valor 3 e 4 para as strings em vertical[0], [1]
                }

   }
   espacamento();

}

void movimento_bispo(int mov_bispo, int casas_bispo){
    
    int i = 0;//utilizado para controle do loop

    //condicional para confirmar a opção válida do bispo
    if (mov_bispo >= 1 && mov_bispo <= 4){
        
        //loop para movimentar o bispo diagonalmente, sendo controlado pela variável i
        while (i < casas_bispo)
        {
            printf("%s\n", diagonal[mov_bispo - 1]);//[move_bispo - 1] é para transcrever o valor 1 a 4 para as strings em diagonal[0], [1], [2], [3]
            i++;//adiciona 1 a i para ser recalculado no while
        }

   }
   espacamento();


}

void movimento_rainha(int mov_rainha, int casas_rainha){

    int i = 0;//utilizado para controle do loop

    //condicional caso a rainha escolheu se mover na horizontal
    if(mov_rainha == 1 || mov_rainha == 2){
        do
        {
            printf("%s\n", horizontal[mov_rainha - 1]);//[move_rainha - 3] é para transcrever o valor 3 e 4 para as strings em horizontal[0], [1]
            i++;//adiciona 1 a i para ser recalculado no while
        } while (i < casas_rainha);
        
    }

        //condicional caso a rainha escolheu se mover na vertical
    else if(mov_rainha == 3 || mov_rainha == 4){
        do
        {
            printf("%s\n", vertical[mov_rainha - 3]);//[move_rainha - 3] é para transcrever o valor 3 e 4 para as strings em vertical[0], [1]
            i++;//adiciona 1 a i para ser recalculado no while
        } while (i < casas_rainha);
    }

    //condicional caso a rainha escolheu se mover na diagonal
    else if(mov_rainha >= 5 && mov_rainha <= 8){
        do
        {
            printf("%s\n", diagonal[mov_rainha - 5]);//[move_rainha - 5] é para transcrever o valor 5 a 8 para as strings em diagonal[0], [1], [2], [3]
            i++;//adiciona 1 a i para ser recalculado no while
        } while (i < casas_rainha);
    }   

    espacamento();

    
}

*/

//funções utilizando recursividade
void movimento_torre(int mov_torre, int casas_torre){

    //condicional para verificar se a função será executada
    if(casas_torre > 0){

        //condicional para decidir qual a direção escolhida da torre
        if (mov_torre == 1 || mov_torre == 2){
            
            printf("%s\n", horizontal[mov_torre - 1]);//[move_torre - 1] é para transcrever o valor 1 e 2 para as strings em horizontal[0], [1]


        }
        //loop para movimentar a torre verticalmente
        else if(mov_torre == 3 || mov_torre == 4){
        
            printf("%s\n", vertical[mov_torre - 3]);//[move_torre - 3] é para transcrever o valor 3 e 4 para as strings em vertical[0], [1]
        }
        casas_torre--;//decrementa e logo após chama a função novamente, até que casas_torre seja igual a 0 e pare de ser executada
        movimento_torre(mov_torre, casas_torre);
    }
}

void movimento_bispo(int mov_bispo, int casas_bispo){
    
    //condicional para verificar se a função será executada
    if(casas_bispo > 0){
        
        //condicional para confirmar a opção válida do bispo 
        if (mov_bispo >= 1 && mov_bispo <= 4){ 
            printf("%s\n", diagonal[mov_bispo - 1]);//[move_bispo - 1] é para transcrever o valor 1 a 4 para as strings em diagonal[0], [1], [2], [3]
        }
        casas_bispo--;//decrementa e logo após chama a função novamente, até que casas_bispo seja igual a 0 e pare de ser executada
        movimento_bispo(mov_bispo, casas_bispo);
    }
}

void movimento_rainha(int mov_rainha, int casas_rainha){
    
    //condicional para verificar se a função será executada
    if(casas_rainha > 0){
        if(mov_rainha == 1 || mov_rainha == 2){
            printf("%s\n", horizontal[mov_rainha - 1]);//[move_rainha - 1] é para transcrever o valor 1 e 2 para as strings em horizontal[0], [1]
        }
        else if(mov_rainha == 3 || mov_rainha == 4){
            printf("%s\n", vertical[mov_rainha - 3]);//[move_rainha - 3] é para transcrever o valor 3 e 4 para as strings em vertical[0], [1]
        }
        else if(mov_rainha >= 5 && mov_rainha <= 8){
            printf("%s\n", diagonal[mov_rainha - 5]);//[move_rainha - 5] é para transcrever o valor 1 a 4 para as strings em diagonal[0], [1], [2], [3]
        }

        casas_rainha--;//decrementa e logo após chama a função novamente, até que casas_rainha seja igual a 0 e pare de ser executada
        movimento_rainha(mov_rainha, casas_rainha);
    }
}

void movimento_cavalo(int mov_cavalo_1, int mov_cavalo_2){
    
    int x = 0;//variável utilizada para controlar o loop while

    if(mov_cavalo_1 == 1 || mov_cavalo_1 == 2){
        
        /*loop for possuíndo um loop interno while. O loop for tem o total de 1 repetição, que passa por while, que por sua vez, tem 2 repetições
        estando no interior de for, while é executado por completo, até sua ultima repetição, antes que o for seja executado primeiramente*/
        //condicional que vai exibir o looping caso a primeira escolha for um movimento horizontal
        for(int i = 0; i < 1; i++){
            while(x  < 2){
                printf("%s\n", horizontal[mov_cavalo_1 - 1]);
                x++;
                continue;
            }
            printf("%s\n", vertical[mov_cavalo_2 - 1]);
            break;
        }
        x++;
    }

     /*loop for possuíndo um loop interno while. O loop for tem o total de 1 repetição, que passa por while, que por sua vez, tem 2 repetições
    estando no interior de for, while é executado por completo, até sua ultima repetição, antes que o for seja executado primeiramente*/
    //condicional que vai exibir o looping caso a primeira escolha for um movimento vertical
    else if(mov_cavalo_1 == 3 || mov_cavalo_1 == 4){
        for(int i = 0; i < 1; i++){
            while(x  < 2){
                printf("%s\n", vertical[mov_cavalo_1 - 3]);
                x++;
            }
            printf("%s\n", horizontal[mov_cavalo_2 - 1]);
        }
    }

    espacamento();
}

int main(){
    setlocale(LC_ALL, "Portuguese");//define o idioma do sistema 

    //looping para exibição e uso do menu
    do
    {
        espacamento();
        printf("Menu principal: \n");
        printf("1 - Movimento da Torre\n");
        printf("2 - Movimento do Bispo\n");
        printf("3 - Movimento da Rainha\n");
        printf("4 - Movimento do Cavalo\n");
        printf("5 - Sair\n");
        scanf("%d", &escolha_menu);
        limparBuffer();

        //switch para escolha das opções
        switch (escolha_menu)
        {
        case 1:
            printf("\nA torre pode se mover até 7 casas para a horizontal ou vertical\n");
            printf("Escolha a direção do movimento da Torre:\n");
            printf("1 - Movimento para a esquerda\n");
            printf("2 - Movimento para a direita\n");
            printf("3 - Movimento para cima\n");
            printf("4 - Movimento para baixo\n");
            scanf("%d", &escolha_movimento);
            limparBuffer();
            
            //condicional para verificar se a escolha do movimento está dentro do aceitavel
            if(escolha_movimento >= 1 && escolha_movimento <= 4){
               
                printf("Agora escolha a quantidade de casas que a torre irá se mover:\n");
                scanf("%d", &escolha_casas);
                limparBuffer();
                //condicional para verificar se a escolha das casas está dentro do aceitavel
                if(escolha_casas >= 1 && escolha_casas <= 7){
                    movimento_torre(escolha_movimento,escolha_casas);
                }
                else{
                    printf("A quantidade de casas deve ser entre 1 e 7.\n");
                }
            }
            //casos os movimentos 
            else{
                printf("Movimento inválido\n");
            }
        break;

        //condiconais de verificação se repetem em cada case
        
        case 2:
            printf("\nO bispo pode se mover até 5 casas para a diagonal\n");
            printf("Escolha a direção do movimento do Bispo:\n");
            printf("1 - Movimento para a diagonal superior esquerda\n");
            printf("2 - Movimento para a diagonal superior direita\n");
            printf("3 - Movimento para a diagonal inferior esquerda\n");
            printf("4 - Movimento para a diagonal inferior direita\n");
            scanf("%d", &escolha_movimento);
            limparBuffer();
            
            if(escolha_movimento >= 1 && escolha_movimento <= 4){
               
                printf("Agora escolha a quantidade de casas que o bispo irá se mover:\n");
                scanf("%d", &escolha_casas);
                limparBuffer();
                if(escolha_casas >= 1 && escolha_casas <= 5){
                    movimento_bispo(escolha_movimento,escolha_casas);
                }
                else{
                    printf("A quantidade de casas deve ser entre 1 e 5.\n");
                }
            }
            else{
                printf("Movimento inválido\n");
            }
        break;
        case 3: 
            printf("\nA rainha pode se mover até 8 casas para todas as direções\n");
            printf("Escolha a direção do movimento da rainha:\n");
            printf("1 - Movimento para a esquerda\t  5 - Movimento para a diagonal superior esquerda\n");
            printf("2 - Movimento para a direita \t  6 - Movimento para a diagonal superior direita\n");
            printf("3 - Movimento para cima      \t  7 - Movimento para a diagonal inferior esquerda\n");
            printf("4 - Movimento para baixo     \t  8 - Movimento para a diagonal inferior direita\n");
            scanf("%d", &escolha_movimento);
            limparBuffer();

            if(escolha_movimento == 1 || escolha_movimento == 2){
                printf("Agora escolha a quantidade de casas que a rainha irá se mover:\n");
                scanf("%d", &escolha_casas);
                limparBuffer();
                if(escolha_casas >= 1 && escolha_casas <= 8){
                    movimento_rainha(escolha_movimento, escolha_casas);
                }
                else{
                    printf("A quantidade de casas deve ser entre 1 e 8.\n");
                }

            }
            else if(escolha_movimento == 3 || escolha_movimento == 4){
                printf("Agora escolha a quantidade de casas que a rainha irá se mover:\n");
                scanf("%d", &escolha_casas);
                limparBuffer();
                if(escolha_casas >= 1 && escolha_casas <= 8){
                    movimento_rainha(escolha_movimento, escolha_casas);
                }
                else{
                    printf("A quantidade de casas deve ser entre 1 e 8.\n");
                }
            }
            else if(escolha_movimento >= 5 && escolha_movimento <= 8){
                printf("Agora escolha a quantidade de casas que a rainha irá se mover:\n");
                scanf("%d", &escolha_casas);
                limparBuffer();
                if(escolha_casas >= 1 && escolha_casas <= 8){
                    movimento_rainha(escolha_movimento, escolha_casas);
                }
                else{
                    printf("A quantidade de casas deve ser entre 1 e 8.\n");
                }

            }
            else{
                printf("Movimento inválido\n");
            }
        break;
        case 4:
            printf("O cavalo pode se mover inicialmente 2 casas para a horizontal ou vertical, e em seguida 1 casa para a outra direção.\n");
            printf("Escolha a primeira direção do movimento do cavalo:\n");
            printf("1 - Movimento para a esquerda\n");
            printf("2 - Movimento para a direita\n");
            printf("3 - Movimento para cima\n");
            printf("4 - Movimento para baixo\n");
            scanf("%d", &escolha_movimento);
            limparBuffer();

            if(escolha_movimento == 1 || escolha_movimento == 2){
                printf("Agora escolha o proximo sentido do movimento: \n");
                printf("1 - Movimento para cima\n");
                printf("2 - Movimento para baixo\n");   
                scanf("%d", &escolha_movimento_2);
                limparBuffer();

                if(escolha_movimento_2 == 1 || escolha_movimento_2 == 2){
                    movimento_cavalo(escolha_movimento, escolha_movimento_2);
                }
                else{
                    printf("Movimento inválido\n");
                }
            }
            else if( escolha_movimento == 3 || escolha_movimento == 4){
                printf("Agora escolha o proximo sentido do movimento: \n");
                printf("1 - Movimento para a esquerda\n");
                printf("2 - Movimento para a direita\n");
                scanf("%d", &escolha_movimento_2);
                limparBuffer();

                if(escolha_movimento_2 == 1 || escolha_movimento_2 == 2){
                    movimento_cavalo(escolha_movimento, escolha_movimento_2);
                }
                else{
                    printf("Movimento inválido\n");
                }
            }
            else{
                printf("Movimento inválido\n");
                }
        break;
        case 5:
          sair_menu = 1;
          printf("Saindo...");
          espacamento();

        default:
            printf("Peça inválida\n");
            break;
        }


    

    } while (sair_menu == 0);
    





    return 0;
}