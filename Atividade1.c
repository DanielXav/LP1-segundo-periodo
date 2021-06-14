#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    // Daniel Xavier Brito de Araujo - LP1 - Heron

    setlocale(LC_ALL,"");
    int entrada, quantNum, num, i, menor, maior, n, soma, produto, numProduto, contador, peso, somaPesos, aux, doisOk;
    float media;
    int array[100], ponderada[100];
    entrada = 0;
    doisOk = 0;

    while (entrada != 14)
        {
            printf("\n");
            printf("DIGITE O N�MERO CONFORME SUA ESCOLHA:\n");
            printf("1 - Informar a quantidade de n�meros a tratar;\n");
            printf("2 - Digitar os n�meros;\n");
            printf("3 - Informar o menor n�mero;\n");
            printf("4 - Informar o maior n�mero;\n");
            printf("5 - Retornar o n-�simo n�mero da lista;\n");
            printf("6 - Calcular a soma dos n�meros;\n");
            printf("7 - Calcular o produto dos n�meros;\n");
            printf("8 - Multiplicar todos os n�meros por um valor;\n");
            printf("9 - Calcular a m�dia aritm�tica dos n�meros;\n");
            printf("10 - Informar quantos n�meros est�o acima da m�dia aritm�tica;\n");
            printf("11 - Calcular a m�dia ponderada dos n�meros;\n");
            printf("12 - Ordenar os n�meros em ordem crescente;\n");
            printf("13 - Ordenar os n�meros em ordem decrescente;\n");
            printf("14 - Terminar a execu��o;\n");

            printf("Digite sua op��o: ");
            scanf("%d", &entrada);

            while (entrada < 1 || entrada > 14)
                {
                    printf("OP��O INV�LIDA!\n");
                    printf("Digite sua op��o: ");
                    scanf("%d", &entrada);
                }

            if (entrada == 1)
                {
                    printf("Digite a quantidade de n�meros: ");
                    scanf("%d", &quantNum);

                    while (quantNum < 5 || quantNum > 15)
                        {
                            printf("Digite um total entre 5 e 15.\n");
                            printf("Digite a quantidade de n�meros: ");
                            scanf("%d", &quantNum);
                        }
                }

            if (entrada == 2)
                {
                    i = 0;
                    if (quantNum == 0)
                        {
                            printf("V� na alternativa >1< PRIMEIRO.\n");
                        }
                            doisOk = 1;
                            while (i != quantNum)
                            {
                                printf("Digite o n�mero: ");
                                scanf("%d", &num);

                                while (num < -100 || num > 500 || num % 8 == 0 || num == 0)
                                {
                                    printf("Digite um n�mero maior que -100 e menor que 500.\n");
                                    printf("� proibido n�meros m�ltiplos de 8 ou 0.\n");
                                    printf("Digite o n�mero: ");
                                    scanf("%d", &num);
                                }

                                array[i] = num;
                                i++;
                            }
                }

            if (entrada == 3)
                {
                    if (quantNum == 0 || doisOk == 0)
                    {
                        printf("V� na alternativa >1< e >2< PRIMEIRO.\n");
                    }
                    else
                    {
                        menor = array[0];
                        for (int i = 0; i < quantNum; i++)
                        {
                            if (array[i] < menor)
                            {
                                menor = array[i];
                            }
                        }
                        printf("O menor n�mero �: %d\n", menor);
                    }
                }

            if (entrada == 4)
                {
                    if (quantNum == 0 || doisOk == 0)
                    {
                        printf("V� na alternativa >1< e >2< PRIMEIRO.\n");
                    }
                    else
                    {
                        maior = array[0];
                        for (int i = 0; i < quantNum; i++)
                        {
                            if (array[i] > maior)
                            {
                                maior = array[i];
                            }
                        }
                        printf("O maior n�mero �: %d\n", maior);
                    }
                }

            if (entrada == 5)
                {
                    if (quantNum == 0 || doisOk == 0)
                    {
                        printf("V� na alternativa >1< e >2< PRIMEIRO.\n");
                    }
                    else
                    {
                        printf("Digite o n-�simo n�mero da lista que voc� deseja: ");
                        scanf("%d", &n);
                        while (n > quantNum) {
                            printf("Digite at� o n�mero %d. \n", quantNum);
                            scanf("%d", &n);
                        }
                        printf("O n-�simo n�mero da lista �: %d\n", array[n-1]);
                    }
                }

            if (entrada == 6)
                {
                    if (quantNum == 0 || doisOk == 0)
                    {
                        printf("V� na alternativa >1< e >2< PRIMEIRO.\n");
                    }
                    else
                    {
                        soma = 0;
                        for (int i = 0; i < quantNum; i++)
                        {
                            soma += array[i];
                        }
                        printf("A soma dos n�meros �: %d\n", soma);
                    }
                }

            if (entrada == 7)
                {
                    if (quantNum == 0 || doisOk == 0)
                    {
                        printf("V� na alternativa >1< e >2< PRIMEIRO.\n");
                    }
                    else
                    {
                        produto = 1;
                        for (int i = 0; i < quantNum; i++)
                        {
                            produto *= array[i];
                        }
                        printf("O produto dos n�meros �: %d\n", produto);
                    }
                }

            if (entrada == 8)
                {
                    if (quantNum == 0 || doisOk == 0)
                    {
                        printf("V� na alternativa >1< e >2< PRIMEIRO.\n");
                    }
                    else
                    {
                        scanf("%d", &numProduto);
                        while (numProduto == 0)
                        {
                            printf("Digite um n�mero diferente de 0.\n");
                            scanf("%d", &numProduto);
                        }

                        for (int i = 0; i < quantNum; i++)
                        {
                            array[i] = array[i] * numProduto;
                        }
                        printf("Novo array:\n");

                        for (int i = 0; i < quantNum; i++)
                        {
                            printf("Array[%d] = %d\n", i, array[i]);
                        }
                    }
                }

            if (entrada == 9)
                {
                    if (quantNum == 0 || doisOk == 0)
                    {
                        printf("V� na alternativa >1< e >2< PRIMEIRO.\n");
                    }
                    else
                    {
                        soma = 0;
                        for (int i = 0; i < quantNum; i++)
                        {
                            soma += array[i];
                        }
                        media = soma/(float)quantNum;
                        printf("A m�dia aritm�tica dos valores �: %.1f\n", media);
                    }
                }

            if (entrada == 10)
                {
                    if (quantNum == 0 || doisOk == 0)
                    {
                        printf("V� na alternativa >1< e >2< PRIMEIRO.\n");
                    }
                    else
                    {
                        contador = 0;
                        for (int i = 0; i < quantNum; i++)
                            {
                            if (array[i] > media)
                                {
                                    contador++;
                                }
                            }
                        printf("Existe %d n�meros acima da m�dia aritm�tica\n", contador);
                    }
                }

            if (entrada == 11)
                {
                    if (quantNum == 0 || doisOk == 0)
                    {
                        printf("V� na alternativa >1< e >2< PRIMEIRO.\n");
                    }
                    else
                    {
                        printf("Os n�meros s�o:\n");
                        for (int i = 0; i < quantNum; i++)
                        {
                            printf("%d ", array[i]);
                            ponderada[i] = array[i];
                        }
                        printf("\n");

                        printf("Digite os pesos para fazer a m�dia ponderada na mesma ordem dos n�meros do array:\n");
                        somaPesos = 0;
                        soma = 0;

                        for (int i = 0; i < quantNum; i++)
                        {
                            scanf("%d", &peso);
                            somaPesos += peso;
                            ponderada[i] *= peso;
                            soma += ponderada[i];
                        }

                        media = soma / (float)somaPesos;
                        printf("A m�dia ponderada dos valores �: %.1f\n", media);

                    }
                }

            if (entrada == 12)
                {
                    if (quantNum == 0 || doisOk == 0)
                    {
                        printf("V� na alternativa >1< e >2< PRIMEIRO.\n");
                    }
                    else
                    {
                        for (int i = 0; i < quantNum; i++)
                        {
                            for (int j = i + 1; j < quantNum; j++)
                            {
                                if (array[i] > array[j])
                                {
                                    aux = array[i];
                                    array[i] = array[j];
                                    array[j] = aux;
                                }
                            }
                        }
                        for (int i = 0; i < quantNum; i++)
                        {
                            printf("Array[%d] = %d\n", i, array[i]);
                        }
                    }
                }

            if (entrada == 13)
                {
                    if (quantNum == 0 || doisOk == 0)
                    {
                        printf("V� na alternativa >1< e >2< PRIMEIRO.\n");
                    }
                    else
                    {
                        for (int i = 0; i < quantNum; i++)
                        {
                            for (int j = i + 1; j < quantNum; j++)
                            {
                                if (array[i] < array[j])
                                {
                                    aux = array[i];
                                    array[i] = array[j];
                                    array[j] = aux;
                                }
                            }
                        }
                        for (int i = 0; i < quantNum; i++)
                        {
                            printf("Array[%d] = %d\n", i, array[i]);
                        }
                    }
                }
        }

    return 0;
}
