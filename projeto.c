//Emyle Santana da Silva
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "projeto.h"

//Prototipo de fun��o para mensagem final das manipula��es
void mensagem_final(void);

int main(void) {
    setlocale (LC_ALL, "");

    //Declara��o de vari�veis
    int opcao = 0, lin = 0, col = 0, brilho = 0, limite = 0, diferenca, media;
    //Variaveis para calculos auxiliares
    int auxopc = 0, auxvalid, validacao, auxlin = 0, auxcol = 0;
    char opc[5];

    //Inicio do Menu
    do{
        printf("\n\n\t\t ********************************************************** \n");
        printf(      "\t\t *                                                        *\n");
        printf(      "\t\t *                     PIXEL WIZARD!                      *\n");
        printf(      "\t\t *                                                        *\n");
        printf(      "\t\t *                         MENU                           *\n");
        printf(      "\t\t ********************************************************** \n\n");

        printf("\t\tSelecione a op��o desejada: \n\n");
        printf("\t\t0. Encerrar\n");
        printf("\t\t1. Rota��o de 90 graus\n");
        printf("\t\t2. Rota��o de -90 graus\n");
        printf("\t\t3. Invers�o horizontal\n");
        printf("\t\t4. Invers�o vertical\n");
        printf("\t\t5. Negativo\n");
        printf("\t\t6. Aumento de brilho\n");
        printf("\t\t7. Diminui��o de brilho\n");
        printf("\t\t8. Detec��o e corre��o de ru�dos\n");
        printf("\t\tOp��o: ");
        scanf("%[^\n]", opc);
        scanf("%*c");

        //Transformar char em int (VALIDA��O DE ENTRADA)
        for(auxopc = 0; opc[auxopc]!= '\0'; auxopc++);
            if(auxopc > 1){
                opcao = 10;
            }else if(opc[0] >= 48 && opc[0] <= 56){
                opcao = opc[0] - 48;
            }else opcao = 10;
     //Fim da valida��o

        //Opera��es a serem realizadas
        switch(opcao){
            case 0: //Encerrar
                    system("clear || cls");
                    printf("\n\n\t\t ********************************************************** \n");
                    printf(      "\t\t *                                                        *\n");
                    printf(      "\t\t *                     FINALIZADO!                        *\n");
                    printf(      "\t\t *          Pressione ENTER para fechar a janela....      *\n");
                    printf(      "\t\t *                                                        *\n");
                    printf(      "\t\t ********************************************************** \n\n");
                    break;

            case 1: {//Rota��o 90 graus
                    printf("\n\n\t\t***************** ROTA��O DE IMAGEM: 90� *****************\n");
                    abrir_imagem();
                    int matrizaux[nlin][ncol];

                    //Cria��o de matriz auxiliar para substitui��o de valores na imagem
                    for(lin = 0; lin < nlin; lin++){
                        for(col = 0; col < ncol; col++){
                            matrizaux[lin][col] = imagem[lin][col];
                        }//Fim: la�o coluna
                    }//Fim: la�o linha

                    //Opera��o para rotacionar no sentido hor�rio
                    for(lin = 0; lin < nlin; lin++){
                        for(col = 0; col < ncol; col++){
                            auxlin = col;
                            auxcol = nlin - lin - 1;
                            imagem[auxlin][auxcol] = matrizaux[lin][col];
                        }//Fim: la�o coluna
                    }//Fim: la�o linha

                    fechar_imagem();
                    mensagem_final();
                    break;
            }//Fim: case 1

            case 2: {//Rota��o -90 graus
                    printf("\n\n\t\t***************** ROTA��O DE IMAGEM: -90� *****************\n");
                    abrir_imagem();

                    int matrizaux[nlin][ncol];
                    for(lin = 0; lin < nlin; lin++){
                        for(col = 0; col < ncol; col++){
                            matrizaux[lin][col] = imagem[lin][col];
                        }//Fim: la�o coluna
                    }//Fim: la�o linha

                    //Opera��o para rotacionar no sentido anti-hor�rio
                    for(lin = 0; lin < nlin; lin++){
                        for(col = 0; col < ncol; col++){
                            auxlin = ncol - col - 1;
                            auxcol = lin;
                            imagem[auxlin][auxcol] = matrizaux[lin][col];
                        }//Fim: la�o coluna
                    }//Fim: la�o linha

                    fechar_imagem();
                    mensagem_final();
                    break;
            }//Fim: case 2

            case 3: //Inversao horizontal
                    printf("\n\n\t\t***************** INVERS�O HORIZONTAL *****************\n");
                    abrir_imagem();
                    //Calculo para invers�o horizontal
                    for(lin = 0; lin < nlin; lin++){
                        for(col = 0; col < (ncol/2); col++){
                            auxcol = imagem[lin][col];
                            imagem[lin][col] = imagem[lin][ncol - col - 1];
                            imagem[lin][ncol - col - 1] = auxcol;
                        }//Fim: la�o coluna
                    }//Fim: la�o linha

                    fechar_imagem();
                    mensagem_final();
                    break;

            case 4: //Inversao Vertical
                    printf("\n\n\t\t***************** INVERS�O VERTICAL *****************\n");
                    abrir_imagem();
                    //calculo para invers�o vertical
                    for(lin = 0; lin < (nlin/2); lin++){
                        for(col = 0; col < ncol; col++){
                            auxlin = imagem[lin][col];
                            imagem[lin][col] = imagem[nlin - lin - 1][col];
                            imagem[nlin - lin - 1][col] = auxlin;
                        }//Fim: la�o coluna
                    }//Fim: la�o linha

                    fechar_imagem();
                    mensagem_final();
                    break;

            case 5: //Negativo
                    printf("\n\n\t\t***************** NEGATIVO *****************\n");
                    abrir_imagem();
                    //Calculo para negativo
                    for(lin = 0; lin < nlin; lin++){
                        for(col = 0; col < ncol; col++){
                            imagem[lin][col] = quant_nivel_cinza - imagem[lin][col];
                        }//Fim: La�o coluna
                    }//Fim: La�o linha
                    fechar_imagem();
                    mensagem_final();
                    break;

            case 6: //Aumento de Brilho
                    printf("\n\n\t\t***************** AUMENTAR BRILHO *****************\n");
                    printf("\n\t\tN�vel de brilho desejado, escolha entre 0 e 255"
                           "\n\t\tAumentar em:  ");
                    scanf("%[^\n]", opc);
                    scanf("%*c");

                    //VALIDA��O DE ENTRADA
                    do{
                        //Inicializa��o de variaveis
                        auxvalid = 1;
                        brilho = -1;
                        validacao = 0;

                        //Descobrir o tamanho da string e incrementar potencia
                        for(auxcol = 0; opc[auxcol] !=  '\0'; auxcol++){
                            if(auxcol > 0) auxvalid*=10;
                        }
                        //transforma��o de string para int e valida��o de entrada(tamanho da string/numero)
                        if(auxcol > 3){
                            validacao = 1;
                            brilho = -2;
                        }else{
                            for(int cont = 0; cont < auxcol; cont++){
                                if(opc[cont] >= 48 && opc[cont] <= 57){
                                    auxopc = opc[cont] - 48;
                                    brilho += (auxopc * auxvalid);
                                    auxvalid /= 10;
                                }else{
                                    validacao = 1;
                                    brilho = -2;
                                    break;
                                }
                            }//fim: transforma��o string-int
                        }//fim: valida��o de tamanho da string/numero

                        brilho++;
                        //Valida��o de intervalo do brilho
                        if(brilho < 0 || brilho > quant_nivel_cinza){
                            printf("\n\t\tERRO - O n�vel de brilho deve estar entre 0 e 255"
                                    "\n\t\tAumentar em: ");
                            scanf("%[^\n]", opc);
                            scanf("%*c");
                            brilho = 0;
                            validacao = 1;
                        }
                    }while(validacao);
                    //Fim: VALIDA��O DE ENTRADA

                    abrir_imagem();
                    //Aumentar intensidade do brilho
                    for(lin = 0; lin < nlin; lin++){
                        for(col = 0; col < ncol; col++){
                            imagem[lin][col] = imagem[lin][col] + brilho;
                            if(imagem[lin][col] > quant_nivel_cinza)
                                imagem[lin][col] = quant_nivel_cinza;
                        }//Fim: la�o coluna
                    }//Fim: la�o linha

                    fechar_imagem();
                    mensagem_final();
                    break;

            case 7: //Diminuicao de brilho
                    printf("\n\n\t\t***************** DIMINUIR BRILHO *****************\n");
                    printf("\n\t\tN�vel de brilho desejado, escolha entre 0 e 255"
                           "\n\t\tDiminuir em:  ");
                    scanf("%[^\n]", opc);
                    scanf("%*c");

                    //VALIDA��O DE ENTRADA
                    do{
                        //Inicializa��o de variaveis
                        auxvalid = 1;
                        brilho = -1;
                        validacao = 0;

                        //Descobrir o tamanho da string e incrementar potencia
                        for(auxcol = 0; opc[auxcol] !=  '\0'; auxcol++){
                            if(auxcol > 0) auxvalid*=10;
                        }
                        //transforma��o de string para int e valida��o de entrada(tamanho da string/numero)
                        if(auxcol > 3){
                            validacao = 1;
                            brilho = -2;
                        }else{
                            for(int cont = 0; cont < auxcol; cont++){
                                if(opc[cont] >= 48 && opc[cont] <= 57){
                                    auxopc = opc[cont] - 48;
                                    brilho += (auxopc * auxvalid);
                                    auxvalid /= 10;
                                }else{
                                    validacao = 1;
                                    brilho = -2;
                                    break;
                                }
                            }//fim: transforma��o string-int
                        }//fim: valida��o de tamanho da string/numero
                        brilho++;
                        //Valida��o de intervalo do brilho
                        if(brilho < 0 || brilho > quant_nivel_cinza){
                            printf("\n\t\tERRO - O n�vel de brilho deve estar entre 0 e 255"
                                    "\n\t\tDiminuir em: ");
                            scanf("%[^\n]", opc);
                            scanf("%*c");
                            brilho = 0;
                            validacao = 1;
                        }
                    }while(validacao);
                    //Fim: VALIDA��O DE ENTRADA

                    abrir_imagem();
                    //Diminuir intensidade do Brilho
                    for(lin = 0; lin < nlin; lin++){
                        for(col = 0; col < ncol; col++){
                            imagem[lin][col] = imagem[lin][col] - brilho;
                            if(imagem[lin][col] < 0)
                                imagem[lin][col] = 0;
                        }//Fim: la�o coluna
                    }//Fim: la�o linha

                    fechar_imagem();
                    mensagem_final();
                    break;

            case 8: //Deteccao e correcao de ruidos
                    printf("\n\n\t\t***************** DETEC��O E CORRE��O DE RU�DOS *****************\n");
                    printf("\n\t\tDigite o limite para ru�do na imagem");
                    printf("\n\t\tLimite: ");
                    scanf("%[^\n]", opc);
                    scanf("%*c");

                    //Transformar char em int (VALIDA��O DE ENTRADA)
                    do{
                        //Inicializa��o de variaveis
                        auxvalid = 1;
                        limite = -1;
                        validacao = 0;

                        //Descobrir o tamanho da string e incrementar potencia
                        for(auxcol = 0; opc[auxcol] !=  '\0'; auxcol++){
                            if(auxcol > 0) auxvalid*=10;
                        }
                        //transforma��o de string para int e valida��o de entrada(tamanho da string/numero)
                        if(auxcol > 3){
                            validacao = 1;
                            limite = -2;
                        }else{
                            for(int cont = 0; cont < auxcol; cont++){
                                if(opc[cont] >= 48 && opc[cont] <= 57){
                                    auxopc = opc[cont] - 48;
                                    limite += (auxopc * auxvalid);
                                    auxvalid /= 10;
                                }else{
                                    validacao = 1;
                                    limite = -2;
                                    break;
                                }
                            }//fim: transforma��o string-int
                        }//fim: valida��o de tamanho da string/numero

                        limite++;
                        //Valida��o de intervalo do limite
                        if(limite < 0 || limite > quant_nivel_cinza){
                            printf("\n\t\tERRO - Valor inv�lido para o limite. Digite novamente");
                            printf("\n\t\tLimite: ");
                            scanf("%[^\n]", opc);
                            scanf("%*c");
                            limite = 0;
                            validacao = 1;
                        }
                    }while(validacao);
                    //Fim da valida��o de entrada

                    abrir_imagem();

                    for(lin = 0; lin < nlin; lin++){
                        for(col = 0; col < ncol; col++){
                            //Teste para numeros que possuem 8 vizinhan�a
                            if(lin > 0 && lin < (nlin - 1) && col > 0 && col < (ncol - 1)){
                                media = ((imagem[lin-1][col-1]) +
                                        (imagem[lin-1][col]) +
                                        (imagem[lin-1][col+1]) +
                                        (imagem[lin][col-1]) +
                                        (imagem[lin][col+1]) +
                                        (imagem[lin+1][col-1]) +
                                        (imagem[lin+1][col]) +
                                        (imagem[lin+1][col+1])) * 0.125;
                            }//Fim: teste 8 vizanha�a
                            //TESTE PARA 4 PONTAS DAS EXTREMIDADES
                            else if(lin == 0 && col == 0 || lin == 0 && col == (ncol - 1)||
                                     lin == (nlin - 1) && col == 0 || lin == (nlin - 1) && col == (ncol - 1)){
                                    //Teste para as linhas
                                    if(lin == 0){
                                        auxlin = lin + 1;
                                    }else if(lin == (nlin - 1)){
                                        auxlin = lin - 1;
                                    }//Fim: teste para linha

                                    //Teste para as colunas
                                    if(col == 0){
                                        auxcol = col + 1;
                                    }else if(col == (ncol - 1)){
                                        auxcol = col - 1;
                                    }//Fim: teste para coluna

                                    media = ((imagem[auxlin][col]) +
                                             (imagem[lin][auxcol]) +
                                             (imagem[auxlin][auxcol])) * 0.33333333333;
                            }//Fim: teste para as 4 pontas
                            //TESTE PARA AS DEMAIS EXTREMIDADES
                            else {//Teste para linha 0 (extremidades)
                                if(lin == 0){
                                    media = ((imagem[lin + 1][col]) +
                                             (imagem[lin + 1][col + 1]) +
                                             (imagem[lin + 1][col - 1]) +
                                             (imagem[lin][col + 1]) +
                                             (imagem[lin][col - 1])) * 0.2;
                                }//Fim: teste linha 0 (extremidades)
                                else {//teste para linha n(extremidades)
                                   media = ((imagem[lin - 1][col]) +
                                            (imagem[lin - 1][col + 1]) +
                                            (imagem[lin - 1][col - 1]) +
                                            (imagem[lin][col + 1]) +
                                            (imagem[lin][col - 1])) * 0.2;
                                //teste para coluna 0(extremidades)
                                if(col == 0){
                                    media = ((imagem[lin][col + 1]) +
                                             (imagem[lin + 1][col + 1]) +
                                             (imagem[lin - 1][col + 1]) +
                                             (imagem[lin + 1][col]) +
                                             (imagem[lin - 1][col])) * 0.2;
                                }//Fim: teste coluna 0(extremidades)
                                else if(col == ncol - 1){
                                    media = ((imagem[lin][col - 1]) +
                                             (imagem[lin + 1][col - 1]) +
                                             (imagem[lin - 1][col - 1]) +
                                             (imagem[lin + 1][col]) +
                                             (imagem[lin - 1][col])) * 0.2;
                                }//Fim: teste coluna n (extremidades)
                                }//Fim: da linha n (extremidades)
                            }//Fim: teste das demais extremidades

                            //TESTE PARA SABER SE EXISTE RUIDO E CORRE��O

                            diferenca = media - imagem[lin][col];
                            diferenca = (diferenca < 0) ? diferenca * (-1) : diferenca;
                            if(diferenca > limite){
                                imagem[lin][col] = media;
                            }//Fim: corre��o de ruido

                        }//Fim: la�o da coluna
                    }//Fim: la�o da linha

                    fechar_imagem();
                    mensagem_final();
                    break;

            default: /*Em caso de entrada de dado errada no menu, o Usuario � direcionado ao Switch case,
                       para que possa voltar ao menu e selecionar uma nova op��o.
                     */
                     system("clear || cls");
                     printf("\n\t\t==================================================================\n\n");
                     printf("\n\t\t        ERRO - OP��O INEXISTENTE... Selecione novamente.\n\n\n");
                     printf("\t\t                (Aperte ENTER para retornar ao menu)");
                     printf("\n\n\t\t==================================================================");
                     scanf("%*c");
                     system("clear || cls");
                     break;
        }//Fim: switch
    }while(opcao);//Fim: menu

    return 0;
}

//Fun��o de mensagem final
void mensagem_final(void){
    printf("\n\n\t\t ********************************************************** \n");
    printf(      "\t\t *                                                        *\n");
    printf(      "\t\t *          IMAGEM SALVA!                                 *\n");
    printf(      "\t\t *          Pressione ENTER para continuar....            *\n");
    printf(      "\t\t *                                                        *\n");
    printf(      "\t\t ********************************************************** \n\n");
    scanf("%*c");
    system("clear || cls");
}


