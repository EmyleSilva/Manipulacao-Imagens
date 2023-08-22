#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "projeto.h"

//Prototipo de funções
void mensagem_final(void);
int validacao_entrada(char[]);

int main(void) {
    setlocale (LC_ALL, "");

    int opcao = 0, lin = 0, col = 0, brilho = 0, limite = 0, diferenca, media;
    int auxopc = 0, auxvalid, validacao, auxlin = 0, auxcol = 0, maxlin = 0, maxcol = 0;
    int ajusteCol = 0;
    float quantVizinhos = 0.0;
    char opc[5];

    //Inicio do Menu
    do{
        printf("\n\n\t\t ********************************************************** \n");
        printf(      "\t\t *                                                        *\n");
        printf(      "\t\t *                     PIXEL WIZARD!                      *\n");
        printf(      "\t\t *                                                        *\n");
        printf(      "\t\t *                         MENU                           *\n");
        printf(      "\t\t ********************************************************** \n\n");

        printf("\t\tSelecione a opção desejada: \n\n");
        printf("\t\t0. Encerrar\n");
        printf("\t\t1. Rotação de 90 graus\n");
        printf("\t\t2. Rotação de -90 graus\n");
        printf("\t\t3. Inversão horizontal\n");
        printf("\t\t4. Inversão vertical\n");
        printf("\t\t5. Negativo\n");
        printf("\t\t6. Aumento de brilho\n");
        printf("\t\t7. Diminuição de brilho\n");
        printf("\t\t8. Detecção e correção de ruídos\n");
        printf("\t\tOpção: ");
        scanf("%[^\n]", opc);
        scanf("%*c");

        //Transformar char em int (VALIDACAO DE ENTRADA)
        for(auxopc = 0; opc[auxopc]!= '\0'; auxopc++);
            if(auxopc > 1){
                opcao = 10;
            }else if(opc[0] >= 48 && opc[0] <= 56){
                opcao = opc[0] - 48;
            }else opcao = 10;
     //Fim da validacao

        //Operacoes a serem realizadas
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

            case 1: {//Rotacao 90 graus
                    printf("\n\n\t\t***************** ROTAÇÃO DE IMAGEM: 90º *****************\n");
                    abrir_imagem();
                    int matrizaux[nlin][ncol];

                    //Cria��o de matriz auxiliar para substituicao de valores na imagem
                    for(lin = 0; lin < nlin; lin++){
                        for(col = 0; col < ncol; col++){
                            matrizaux[lin][col] = imagem[lin][col];
                        }//Fim: laço coluna
                    }//Fim: la�o linha

                    //Operacao para rotacionar no sentido horario
                    for(lin = 0; lin < nlin; lin++){
                        for(col = 0; col < ncol; col++){
                            auxlin = col;
                            auxcol = nlin - lin - 1;
                            imagem[auxlin][auxcol] = matrizaux[lin][col];
                        }//Fim: laco coluna
                    }//Fim: laco linha

                    fechar_imagem();
                    mensagem_final();
                    break;
            }//Fim: case 1

            case 2: {//Rotacao -90 graus
                    printf("\n\n\t\t***************** ROTAÇÃO DE IMAGEM: -90º *****************\n");
                    abrir_imagem();

                    int matrizaux[nlin][ncol];
                    for(lin = 0; lin < nlin; lin++){
                        for(col = 0; col < ncol; col++){
                            matrizaux[lin][col] = imagem[lin][col];
                        }//Fim: laco coluna
                    }//Fim: laco linha

                    //Operacao para rotacionar no sentido anti-horario
                    for(lin = 0; lin < nlin; lin++){
                        for(col = 0; col < ncol; col++){
                            auxlin = ncol - col - 1;
                            auxcol = lin;
                            imagem[auxlin][auxcol] = matrizaux[lin][col];
                        }//Fim: laco coluna
                    }//Fim: laco linha

                    fechar_imagem();
                    mensagem_final();
                    break;
            }//Fim: case 2

            case 3: //Inversao horizontal
                    printf("\n\n\t\t***************** INVERSÃO HORIZONTAL *****************\n");
                    abrir_imagem();
                    //Calculo para inversao horizontal
                    for(lin = 0; lin < nlin; lin++){
                        for(col = 0; col < (ncol/2); col++){
                            auxcol = imagem[lin][col];
                            imagem[lin][col] = imagem[lin][ncol - col - 1];
                            imagem[lin][ncol - col - 1] = auxcol;
                        }//Fim: laco coluna
                    }//Fim: laco linha

                    fechar_imagem();
                    mensagem_final();
                    break;

            case 4: //Inversao Vertical
                    printf("\n\n\t\t***************** INVERSÃO VERTICAL *****************\n");
                    abrir_imagem();
                    //calculo para inversao vertical
                    for(lin = 0; lin < (nlin/2); lin++){
                        for(col = 0; col < ncol; col++){
                            auxlin = imagem[lin][col];
                            imagem[lin][col] = imagem[nlin - lin - 1][col];
                            imagem[nlin - lin - 1][col] = auxlin;
                        }//Fim: laco coluna
                    }//Fim: laco linha

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
                        }//Fim: Laco coluna
                    }//Fim: Laco linha
                    fechar_imagem();
                    mensagem_final();
                    break;

            case 6: //Aumento de Brilho
                    printf("\n\n\t\t***************** AUMENTAR BRILHO *****************\n");
                    printf("\n\t\tNível de brilho desejado, escolha entre 0 e 255"
                           "\n\t\tAumentar em:  ");
                    scanf("%[^\n]", opc);
                    scanf("%*c");

                    brilho = validacao_entrada(opc);

                    abrir_imagem();
                    //Aumentar intensidade do brilho
                    for(lin = 0; lin < nlin; lin++){
                        for(col = 0; col < ncol; col++){
                            imagem[lin][col] = imagem[lin][col] + brilho;
                            if(imagem[lin][col] > quant_nivel_cinza)
                                imagem[lin][col] = quant_nivel_cinza;
                        }//Fim: laco coluna
                    }//Fim: laco linha

                    fechar_imagem();
                    mensagem_final();
                    break;

            case 7: //Diminuicao de brilho
                    printf("\n\n\t\t***************** DIMINUIR BRILHO *****************\n");
                    printf("\n\t\tNível de brilho desejado, escolha entre 0 e 255"
                           "\n\t\tDiminuir em:  ");
                    scanf("%[^\n]", opc);
                    scanf("%*c");

                    brilho = validacao_entrada(opc);

                    abrir_imagem();
                    //Diminuir intensidade do Brilho
                    for(lin = 0; lin < nlin; lin++){
                        for(col = 0; col < ncol; col++){
                            imagem[lin][col] = imagem[lin][col] - brilho;
                            if(imagem[lin][col] < 0)
                                imagem[lin][col] = 0;
                        }//Fim: laco coluna
                    }//Fim: laco linha

                    fechar_imagem();
                    mensagem_final();
                    break;

            case 8: //Deteccao e correcao de ruidos
                    printf("\n\n\t\t***************** DETECÇÃO E CORREÇÃO DE RUÍDOS *****************\n");
                    printf("\n\t\tDigite o limite para ruído na imagem");
                    printf("\n\t\tLimite: ");
                    scanf("%[^\n]", opc);
                    scanf("%*c");

                    limite = validacao_entrada(opc);

                    abrir_imagem();

                    for(lin = 0; lin < nlin; lin++){
                        for(col = 0; col < ncol; col++){
                            
                            diferenca = media = quantVizinhos = 0;
                            //Condicionais para rastrear os vizinhos (linha)
                            if(lin > 0 && lin != nlin - 1){
                                auxlin = lin - 1;
                                maxlin = lin + 1;
                            }else if(lin == nlin - 1){
                                    auxlin = lin - 1;
                                    maxlin = lin;
                                }else{
                                        auxlin = 0;
                                        maxlin = lin + 1;
                                }

                            //Rastreia os vizinhos das colunas
                            if(col > 0 && col != ncol -1){
                                ajusteCol = auxcol = col - 1;
                                maxcol = col + 1;
                            }else if(col == ncol - 1){
                                    ajusteCol = auxcol = col -1;
                                    maxcol = col;
                                }else{
                                        ajusteCol = auxcol = 0;
                                        maxcol = col + 1;
                                }

                            //Fors para fazer a  media dos vizinhos
                            for(; auxlin <= maxlin; auxlin++){
                                auxcol = ajusteCol;
                                for(; auxcol <= maxcol; auxcol++){
                                    if(auxlin == lin && auxcol == col) continue;
                                    media += imagem[auxlin][auxcol];
                                    quantVizinhos++;
                                }
                            }
                            
                            quantVizinhos = (quantVizinhos == 3) ?  0.33333333333 : (quantVizinhos == 5) ?
                                            0.2 : 0.125;
                            
                            //Calcular media e verificar se há ruído
                            media*=quantVizinhos;
                            diferenca = (int) media - imagem[lin][col];
                            diferenca = (diferenca < 0) ? diferenca * (-1) : diferenca;
                            if(diferenca > limite){
                                imagem[lin][col] = (int) media;
                            }
                           
                        }//Fim: laco da coluna
                    }//Fim: laco da linha

                    fechar_imagem();
                    mensagem_final();
                    break;

            default: /*Em caso de entrada de dado errada no menu, o Usuario é direcionado ao Switch case,
                       para que possa voltar ao menu e selecionar uma nova opcao.
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

//Funcao de mensagem final
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

int validacao_entrada(char opc[10]){
    
    int auxvalid, retorno, validacao, auxopc, col;
    int quant_nivel_cinza = 255;

     do{
            auxvalid = 1;
            retorno = -1;
            validacao = 0;

            //Descobrir o tamanho da string e incrementar potencia
            for(col = 0; opc[col] != '\0'; col++){
                if(col > 0) auxvalid*=10;
            }
            //transformacao de string para int e validacao de entrada(tamanho da string/numero)
            if(col > 3){
                validacao = 1;
                retorno = -2;
            }else{
                for(int cont = 0; cont < col; cont++){
                    if(opc[cont] >= 48 && opc[cont] <= 57){
                        auxopc = opc[cont] - 48;
                        retorno += (auxopc * auxvalid);
                        auxvalid /= 10;
                        printf("\n\n\tRETORNO: %d\n\n", retorno);
                    }else{
                        validacao = 1;
                        retorno = -2;
                        break;
                    }
                }//fim: transformacao string-int
            }//fim: validacao de tamanho da string/numero

                retorno++;
                //Validacao de intervalo do limite
                if(retorno < 0 || retorno > quant_nivel_cinza){
                    printf("\n\t\tERRO - Valor inválido. Digite novamente");
                    printf("\n\t\tValor: ");
                    scanf("%[^\n]", opc);
                    scanf("%*c");
                    retorno = 0;
                    validacao = 1;
                }
            }while(validacao);

    return retorno;

}


