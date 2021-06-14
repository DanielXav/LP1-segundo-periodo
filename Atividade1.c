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
            printf("DIGITE O NÚMERO CONFORME SUA ESCOLHA:\n");
            printf("1 - Informar a quantidade de números a tratar;\n");
            printf("2 - Digitar os números;\n");
            printf("3 - Informar o menor número;\n");
            printf("4 - Informar o maior número;\n");
            printf("5 - Retornar o n-ésimo número da lista;\n");
            printf("6 - Calcular a soma dos números;\n");
            printf("7 - Calcular o produto dos números;\n");
            printf("8 - Multiplicar todos os números por um valor;\n");
            printf("9 - Calcular a média aritmética dos números;\n");
            printf("10 - Informar quantos números estão acima da média aritmética;\n");
            printf("11 - Calcular a média ponderada dos números;\n");
            printf("12 - Ordenar os números em ordem crescente;\n");
            printf("13 - Ordenar os números em ordem decrescente;\n");
            printf("14 - Terminar a execução;\n");

            printf("Digite sua opção: ");
            scanf("%d", &entrada);

            while (entrada < 1 || entrada > 14)
                {
                    printf("OPÇÃO INVÁLIDA!\n");
                    printf("Digite sua opção: ");
                    scanf("%d", &entrada);
                }

            if (entrada == 1)
                {
                    printf("Digite a quantidade de números: ");
                    scanf("%d", &quantNum);

                    while (quantNum < 5 || quantNum > 15)
                        {
                            printf("Digite um total entre 5 e 15.\n");
                            printf("Digite a quantidade de números: ");
                            scanf("%d", &quantNum);
                        }
                }

            if (entrada == 2)
                {
                    i = 0;
                    if (quantNum == 0)
                        {
                            printf("Vá na alternativa >1< PRIMEIRO.\n");
                        }
                            doisOk = 1;
                            while (i != quantNum)
                            {
                                printf("Digite o número: ");
                                scanf("%d", &num);

                                while (num < -100 || num > 500 || num % 8 == 0 || num == 0)
                                {
                                    printf("Digite um número maior que -100 e menor que 500.\n");
                                    printf("É proibido números múltiplos de 8 ou 0.\n");
                                    printf("Digite o número: ");
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
                        printf("Vá na alternativa >1< e >2< PRIMEIRO.\n");
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
                        printf("O menor número é: %d\n", menor);
                    }
                }

            if (entrada == 4)
                {
                    if (quantNum == 0 || doisOk == 0)
                    {
                        printf("Vá na alternativa >1< e >2< PRIMEIRO.\n");
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
                        printf("O maior número é: %d\n", maior);
                    }
                }

            if (entrada == 5)
                {
                    if (quantNum == 0 || doisOk == 0)
                    {
                        printf("Vá na alternativa >1< e >2< PRIMEIRO.\n");
                    }
                    else
                    {
                        printf("Digite o n-ésimo número da lista que você deseja: ");
                        scanf("%d", &n);
                        while (n > quantNum) {
                            printf("Digite até o número %d. \n", quantNum);
                            scanf("%d", &n);
                        }
                        printf("O n-ésimo número da lista é: %d\n", array[n-1]);
                    }
                }

            if (entrada == 6)
                {
                    if (quantNum == 0 || doisOk == 0)
                    {
                        printf("Vá na alternativa >1< e >2< PRIMEIRO.\n");
                    }
                    else
                    {
                        soma = 0;
                        for (int i = 0; i < quantNum; i++)
                        {
                            soma += array[i];
                        }
                        printf("A soma dos números é: %d\n", soma);
                    }
                }

            if (entrada == 7)
                {
                    if (quantNum == 0 || doisOk == 0)
                    {
                        printf("Vá na alternativa >1< e >2< PRIMEIRO.\n");
                    }
                    else
                    {
                        produto = 1;
                        for (int i = 0; i < quantNum; i++)
                        {
                            produto *= array[i];
                        }
                        printf("O produto dos números é: %d\n", produto);
                    }
                }

            if (entrada == 8)
                {
                    if (quantNum == 0 || doisOk == 0)
                    {
                        printf("Vá na alternativa >1< e >2< PRIMEIRO.\n");
                    }
                    else
                    {
                        scanf("%d", &numProduto);
                        while (numProduto == 0)
                        {
                            printf("Digite um número diferente de 0.\n");
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
                        printf("Vá na alternativa >1< e >2< PRIMEIRO.\n");
                    }
                    else
                    {
                        soma = 0;
                        for (int i = 0; i < quantNum; i++)
                        {
                            soma += array[i];
                        }
                        media = soma/(float)quantNum;
                        printf("A média aritmética dos valores é: %.1f\n", media);
                    }
                }

            if (entrada == 10)
                {
                    if (quantNum == 0 || doisOk == 0)
                    {
                        printf("Vá na alternativa >1< e >2< PRIMEIRO.\n");
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
                        printf("Existe %d números acima da média aritmética\n", contador);
                    }
                }

            if (entrada == 11)
                {
                    if (quantNum == 0 || doisOk == 0)
                    {
                        printf("Vá na alternativa >1< e >2< PRIMEIRO.\n");
                    }
                    else
                    {
                        printf("Os números são:\n");
                        for (int i = 0; i < quantNum; i++)
                        {
                            printf("%d ", array[i]);
                            ponderada[i] = array[i];
                        }
                        printf("\n");

                        printf("Digite os pesos para fazer a média ponderada na mesma ordem dos números do array:\n");
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
                        printf("A média ponderada dos valores é: %.1f\n", media);

                    }
                }

            if (entrada == 12)
                {
                    if (quantNum == 0 || doisOk == 0)
                    {
                        printf("Vá na alternativa >1< e >2< PRIMEIRO.\n");
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
                        printf("Vá na alternativa >1< e >2< PRIMEIRO.\n");
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
