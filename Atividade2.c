#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

// Daniel Xavier Brito de Araujo - LP1 - Heron

int quantNum, numero, i, j, aux, doisOk = 0, chamada, descriptografou;
int *ptr_numero;
char palavra[51];

int verificar()
{
    if (quantNum == 0 || doisOk == 0)
    {
        printf("V� nas alternativas >1< e >2< PRIMEIRO.\n");
        return 0;
    }
    return 1;
}

int quantNumeros()
{
    quantNum = 0;

    printf("Digite a quantidade de n�meros: ");
    while (scanf("%d", &quantNum) != 1 || quantNum < 5 || quantNum > 15)
    {
        static char temp[256];
        fgets(temp, sizeof(temp), stdin);
        printf("\nOp��o inv�lida. Digite a quantidade de n�meros entre 5 e 15: ");
    }
    return 1;
}

void digitarNum(int array[])
{
    int num;

    i = 0;
    if (quantNum == 0)
    {
        printf("V� na alternativa >1< PRIMEIRO.\n");
    }
    doisOk = 1;
    while (i != quantNum)
    {
        printf("Digite o n�mero: ");

        while (scanf("%d", &num) != 1 || num < -100 || num > 500 || num % 8 == 0 || num == 0)
        {
            static char temp[256];
            fgets(temp, sizeof(temp), stdin);
            printf("\nDigite um n�mero maior que -100 e menor que 500.\n");
            printf("� proibido n�meros m�ltiplos de 8 ou 0.\n");
            printf("� proibido caracteres sem ser n�meros.\n");
            printf("Digite o n�mero: ");
        }

        array[i] = num;
        i++;
    }
}

int menorNum(int array[])
{
    int menor;

    menor = array[0];
    for (int i = 0; i < quantNum; i++)
    {
        if (array[i] < menor)
        {
            menor = array[i];
        }
    }
    return menor;
}

int maiorNum(int array[])
{
    int maior;

    maior = array[0];
    for (int i = 0; i < quantNum; i++)
    {
        if (array[i] > maior)
        {
            maior = array[i];
        }
    }
    return maior;
    }


int retornareNesimo(int array[])
{
    printf("Digite o n-�simo n�mero que voc� quer: ");

    while (scanf("%d", &i) != 1 || i < 0)
    {
        static char temp[256];
        fgets(temp, sizeof(temp), stdin);
        printf("Digite um n�mero maior que 0 e apenas n�meros: ");
    }
    return array[i-1];
}

int somarNum(int array[])
{
    int soma = 0;
    for (int i = 0; i < quantNum; i++)
    {
        soma += array[i];
    }
    return soma;
}

int produtoNum(int array[])
{
    int produto;

    produto = 1;
    for (int i = 0; i < quantNum; i++)
    {
        produto *= array[i];
    }
    return produto;
}

int produtoPorUmNum(int numProduto, int array[])
{
    printf("N�meros Antigos:\n");
    for (int i = 0; i < quantNum; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    for (int i = 0; i < quantNum; i++)
    {
        array[i] = array[i] * numProduto;
    }

    printf("\n");
    printf("Novos n�meros:\n");

    for (int i = 0; i < quantNum; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

float mediaAritmetica(int soma)
{
    float media =  soma / (float) quantNum;
    return media;
}

int valoresAcimaMedia(int array[], int soma)
{
    int contador;
    float media = mediaAritmetica(soma);

    contador = 0;
    for (int i = 0; i < quantNum; i++)
    {
        if (array[i] > media)
        {
            contador++;
        }
    }
   return contador;
}

float mediaPonderada(int array[])
{
    int peso, somaPesos;

    printf("Os n�meros s�o:\n");
    for (int i = 0; i < quantNum; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("Digite os pesos para fazer a m�dia ponderada na mesma ordem dos n�meros:\n");
    somaPesos = 0;
    int soma = 0;

    for (int i = 0; i < quantNum; i++)
    {
        while (scanf("%d", &peso) != 1)
        {
            static char temp[256];
            fgets(temp, sizeof(temp), stdin);
            printf("Digite um N�MERO: ");
        }
        somaPesos += peso;
        soma += array[i] * peso;
    }

    float media = soma / (float)somaPesos;
    return media;

}

void ordemCrescente(int array[])
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
        printf("%d ", array[i]);
    }
    printf("\n");
}

void ordemDescrecente(int array[])
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
        printf("%d ", array[i]);
    }
    printf("\n");
}

void lerString()
{
    chamada = 0;
    descriptografou = 0;
    printf("Digite uma string: ");
    scanf(" %[^\n]", palavra);

    while (apenasLetras(palavra) != 1 || minhaStrlen(palavra) > 50)
    {
        printf("Digite uma string com at� 50 caracteres! E sem caracteres especiais.\n");
        printf("Digite uma string: ");
        scanf(" %[^\n]", palavra);
    }
}

void mostrarString()
{
    if (strlen(palavra) == 0) {
        printf("V� na op��o >14< primeiro!\n");
    }
    else
    {
        printf("A string lida foi: ");
        printf("%s \n", palavra);
        printf("E o seu tamanho �: ");
        printf("%d \n", strlen(palavra));
    }
}

void criptografar(char alfabeto[], char cifra[])
{
    if (strlen(palavra) == 0 || chamada == 1) {
        printf("V� na op��o >14< primeiro! E digite uma nova palavra.\n");
    }
    else
    {
        printf("Informe um n�mero entre 1 e 5: ");
        scanf("%d", &numero);
        while (numero < 1 || numero > 5)
        {
            printf("Informe um n�mero entre 1 e 5: ");
            scanf("%d", &numero);
        }

        ptr_numero = &numero;
        numero -= 1;
        for (i = 0; i < strlen(palavra); i++)
        {
            for (j = 0; j < strlen(alfabeto); j++)
            {
                if (toupper(palavra[i]) == alfabeto[j])
                {
                    if ((j + numero) >= strlen(cifra))
                    {
                        if (toupper(palavra[i]) == 'W')
                        {
                            palavra[i] = cifra[numero - 4];
                        }
                        else if (toupper(palavra[i]) == 'X')
                        {
                            palavra[i] = cifra[numero - 3];
                        }
                        else if (toupper(palavra[i]) == 'Y')
                        {
                            palavra[i] = cifra[numero - 2];
                        }
                        else
                        {
                            palavra[i] = cifra[numero - 1];
                        }
                    }
                    else
                    {
                        palavra[i] = cifra[j + numero];
                    }
                }
            }
        }
        printf("\nA palavra criptografada �: %s\n", palavra);
        chamada = 1;
    }
}

void descriptografar(char alfabeto[], char cifra[])
{
    if (chamada == 0)
    {
        printf("Criptografe antes de vim aqui. >16<\n");
    }
    else if (descriptografou == 1)
    {
        printf("Digite uma nova palavra para descriptografar!\n");
    }
    else
    {
        for (i = 0; i < strlen(palavra); i++)
        {
            for (int j = 0; j<strlen(alfabeto); j++)
            {
                if (palavra[i] == cifra[j])
                {
                    if ((j - *ptr_numero) < 0)
                    {
                        if (palavra[i] == '1')
                        {
                            palavra[i] = alfabeto[26 - *ptr_numero];
                        }
                        else if (toupper(palavra[i]) == '2')
                        {
                            palavra[i] = alfabeto[27 - *ptr_numero];
                        }
                        else if (toupper(palavra[i]) == '3')
                        {
                            palavra[i] = alfabeto[28 - *ptr_numero];
                        }
                        else if (toupper(palavra[i]) == '4')
                        {
                            palavra[i] = alfabeto[29 - *ptr_numero];
                        }
                    }
                    else
                    {
                        palavra[i] = alfabeto[j - *ptr_numero];
                    }
                }
            }

        }
        printf("\nA palavra descriptografada �: %s\n", palavra);
        descriptografou = 1;
    }
}

int apenasLetras(char *texto)
{
    int i;
    for (i = 0; texto[i] != '\0'; i++){
        if (!isalpha(texto[i]) && texto[i] != ' '){
            return 0;
        }
    }
    return 1;
}

int minhaStrlen(char *str) // Fiz essa fun��o porque por algum motivo o strlen(palavra) n�o funcionou na entrada da string (14).
{
     int cont = 0;
     for(;*str;str++) cont++;
     return cont;
}

int main()
{
    setlocale(LC_ALL,"");
    int entrada;
    entrada = 0;
    int somaFeita;
    int array[20];
    char cifra[27] = {'1','2','3','4','5','6','7','8','9','0','!','@','#','$','%',':','&','*','(',')','-','+','<','>','/',','};
    char alfabeto[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    while (entrada != 18)
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
        printf("14 - Ler String;\n");
        printf("15 - Mostrar string lida e o seu tamanho;\n");
        printf("16 - Criptografar a string;\n");
        printf("17 - Descriptografar a string;\n");
        printf("18 - Terminar a execu��o;\n");

        printf("Digite uma op��o: ");
        while (scanf("%d", &entrada) != 1 || entrada < 1 || entrada > 18)
        {
            static char temp[256];
            fgets(temp, sizeof(temp), stdin);
            printf("\nOp��o inv�lida, por favor digite uma op��o entre 1 e 18: ");
        }

        if (entrada == 1)
        {
            quantNumeros();
        }

        if (entrada == 2)
        {
            digitarNum(array);
        }

        if (entrada == 3)
        {
            if (verificar())
            {
                printf("O menor n�mero � %d\n", menorNum(array));
            }
        }

        if (entrada == 4)
        {
            if (verificar())
            {
                printf("O maior n�mero �: %d\n", maiorNum(array));
            }
        }

        if (entrada == 5)
        {
            if (verificar())
            {
                 printf("O n-�simo n�mero �: %d\n", retornareNesimo(array));
            }
        }

        if (entrada == 6)
        {
            if (verificar())
            {
                printf("A soma dos n�meros �: %d\n", somarNum(array));
            }
        }

        if (entrada == 7)
        {
            if (verificar())
            {
                printf("O produto dos n�meros �: %d\n", produtoNum(array));
            }

        }

        if (entrada == 8)
        {
            if (verificar())
            {
                int numProduto;
                printf("Digite um valor que voc� quer multiplicar os n�meros: ");

                while (scanf("%d", &numProduto) != 1 || quantNum == 0)
                {
                    static char temp[256];
                    fgets(temp, sizeof(temp), stdin);
                    printf("Digite um n�mero diferente de 0 e que n�o seja caracteres al�m de n�meros: ");
                }

                produtoPorUmNum(numProduto, array);
            }
        }

        if (entrada == 9)
        {
           if (verificar())
            {
                int somaParaMedia = somarNum(array);
                printf("A m�dia aritm�tica dos valores �: %.1f\n", mediaAritmetica(somaParaMedia));
            }
        }

        if (entrada == 10)
        {
            if (verificar())
            {
                int somaParaMedia = somarNum(array);
                printf("Existe %d n�meros acima da m�dia aritm�tica\n", valoresAcimaMedia(array, somaParaMedia));
            }
        }

        if (entrada == 11)
        {
            if (verificar())
            {
                printf("A m�dia ponderada dos valores �: %.1f\n", mediaPonderada(array));
            }
        }

        if (entrada == 12)
        {
            if (verificar())
            {
                ordemCrescente(array);
            }
        }

        if (entrada == 13)
        {
            if (verificar())
            {
                ordemDescrecente(array);
            }
        }

        if (entrada == 14)
        {
            lerString();
        }

        if (entrada == 15)
        {
            mostrarString();
        }

        if (entrada == 16)
        {
            criptografar(alfabeto, cifra);
        }

        if (entrada == 17)
        {
            descriptografar(alfabeto, cifra);
        }
    }

    return 0;
}
