#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // esta parte se encarga de que los comandos ingresados en la terminal no superen los 2
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // este evalua cada cosa ingresada en la matriz uno (donde va el numero) y se asegura de que sea
    // solo un numero
    for (int i = 0; argv[1][i] != 0; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // esto convierte la matriz de string a enteros
    int key = atoi(argv[1]);

    int c = 0;
    string text = get_string("plaintext: ");
    int in = 0;

    printf("ciphertext: ");

    // loop para revisar cada elemento de la variable de texto plano
    for (int j = 0; text[j] != 0; j++)
    {
        // añade una condicon para saber si es una letra del alfabeto o no
        // equivalente a (text > 'a'&& text < 'z')
        if (isalpha(text[j]))
        {
            // si es mayuscula, le resta el indice mayuscula (-65) y devuelve el indice numerico
            // in se encarga de calcular ese indice numerico en base a la formula para poder usar
            // numeros mayores a 26 y devolver en valor ASCII

            if (isupper(text[j]))
            {
                c = text[j] - 'A';
                in = (c + key) % 26;
                in += 'A';
            }
            // lo mismo pero en minusculas
            else if (islower(text[j]))
            {
                c = text[j] - 'a';
                in = (c + key) % 26;
                in += 'a';
            }
            // despues de eso, imprime seguido en forma de character el valor ASCII de cada letra
            // del texto plano
            printf("%c", in);
        }
        // condicion de que si el caracter a evaluar en el texto no es una letra, la imprima tal
        // cual
        else
        {
            printf("%c", text[j]);
        }
        // imprimir el newline (porque no supe implementarlo antes)
    }
    printf("\n");
}
