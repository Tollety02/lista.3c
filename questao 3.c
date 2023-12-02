#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define PLACA_SIZE 9
#define DIA_SIZE 20

void toLowerCase(char str[])
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int main()
{
    char placa[PLACA_SIZE], dia[DIA_SIZE];
    char placaInvalida[] = "INVALIDO", diaInvalido[] = "INVALIDO";

    strcpy(placa, placaInvalida);
    strcpy(dia, diaInvalido);

    scanf("%s %s", placa, dia);

    int tamanho = strlen(placa) == 7 ? 7 : 8;

    if (tamanho == 7)
    {
        if (!(isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) && isalpha(placa[4])) || !(isdigit(placa[3]) && isdigit(placa[5]) && isdigit(placa[6])))
        {
            strcpy(placa, placaInvalida);
        }
    }
    else
    {
        if (!(isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2])) || !(isdigit(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]) && isdigit(placa[7])) || placa[3] != '-')
        {
            strcpy(placa, placaInvalida);
        }
    }

    toLowerCase(dia);

    if (strcmp(dia, "segunda-feira") == 0 || strcmp(dia, "terca-feira") == 0 ||
        strcmp(dia, "quarta-feira") == 0 || strcmp(dia, "quinta-feira") == 0 ||
        strcmp(dia, "sexta-feira") == 0 || strcmp(dia, "sabado") == 0 || strcmp(dia, "domingo") == 0)
    {
        // Valid day
    }
    else
    {
        strcpy(dia, diaInvalido);
    }

    if (strcmp(placa, placaInvalida) != 0 && strcmp(dia, diaInvalido) != 0)
    {
        if (strcmp(dia, "sabado") == 0 || strcmp(dia, "domingo") == 0)
        {
            printf("Nao ha proibicao no fim de semana\n");
        }
        else
        {
            int lastDigit = tamanho == 7 ? placa[6] - '0' : placa[7] - '0';
            int restrictedDay = lastDigit / 2;

            if (restrictedDay == 0)
            {
                printf("%s nao pode circular %s\n", placa, dia);
            }
            else
            {
                printf("pode circular %s\n", placa, dia);
            }
        }
    }
    else
    {
        if (strcmp(placa, placaInvalida) == 0)
        {
            printf("Placa invalida\n");
        }
        if (strcmp(dia, diaInvalido) == 0)
        {
            printf("%s Dia da semana invalido\n");
        }
    }

    return 0;
}