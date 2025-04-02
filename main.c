#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void receber_valores();
void somar_valores(int p, int q, int r, int s);
void subtrair_valores(int p, int q, int r, int s);
void multiplicar_valores(int p, int q, int r, int s);
void dividir_valores(int p, int q, int r, int s);
void reduzir_valor(int *p, int *q);
int calcular_mdc(int p, int q);

int n1, d1, n2, d2;

int main() {
    char escolha;

    while (1) {
        system("CLS");
        printf("1. Somar\n");
        printf("2. Subtrair\n");
        printf("3. Multiplicar\n");
        printf("4. Dividir\n");
        printf("9. Sair\n");
        printf("Escolha uma opcao: ");
        escolha = getche();

        if (escolha == '9') break;
        receber_valores();

        switch (escolha) {
            case '1': somar_valores(n1, d1, n2, d2); break;
            case '2': subtrair_valores(n1, d1, n2, d2); break;
            case '3': multiplicar_valores(n1, d1, n2, d2); break;
            case '4': dividir_valores(n1, d1, n2, d2); break;
            default: printf("\nOpcao invalida!\n");
        }
        printf("Pressione qualquer tecla para continuar...\n");
        getch();
    }
    return 0;
}

int calcular_mdc(int p, int q) {
    if (q == 0) return p;
    return calcular_mdc(q, p % q);
}

void reduzir_valor(int *p, int *q) {
    int divisor = calcular_mdc(*p, *q);
    *p /= divisor;
    *q /= divisor;
}

void receber_valores() {
    printf("\nPrimeira fracao: ");
    scanf("%d %d", &n1, &d1);
    printf("Segunda fracao: ");
    scanf("%d %d", &n2, &d2);
}

void somar_valores(int p, int q, int r, int s) {
    int num = p * s + r * q;
    int den = q * s;
    reduzir_valor(&num, &den);
    printf("Resultado: %d / %d\n", num, den);
}

void subtrair_valores(int p, int q, int r, int s) {
    int num = p * s - r * q;
    int den = q * s;
    reduzir_valor(&num, &den);
    printf("Resultado: %d / %d\n", num, den);
}

void multiplicar_valores(int p, int q, int r, int s) {
    int num = p * r;
    int den = q * s;
    reduzir_valor(&num, &den);
    printf("Resultado: %d / %d\n", num, den);
}

void dividir_valores(int p, int q, int r, int s) {
    int num = p * s;
    int den = q * r;
    reduzir_valor(&num, &den);
    printf("Resultado: %d / %d\n", num, den);
}
