#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void receber_valores();
void somar_valores(int p, int q, int r, int s);
void subtrair_valores(int p, int q, int r, int s);
void multiplicar_valores(int p, int q, int r, int s);
void dividir_valores(int p, int q, int r, int s);
int calcular_mdc(int p, int q);
void reduzir_valor(int p, int q, int *num, int *den);

int n1, d1, n2, d2;

//Inicio do código, parte principal

int main() {
    char escolha;


    //Está parte irá mostrar opções e você escolhe em qual operação matemática quer realizar o resultado
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

        // n1 significa primeiro numerador, d1 significa primeiro denominador
        // n2 significa segundo numerador d2 significa segundo denominador
        switch (escolha) {
            case '1': somar_valores(n1, d1, n2, d2); break;
            case '2': subtrair_valores(n1, d1, n2, d2); break;
            case '3': multiplicar_valores(n1, d1, n2, d2); break;
            case '4': dividir_valores(n1, d1, n2, d2); break;
            default: printf("\nOpcao invalida!\n"); // Caso escolha uma opção que não existi, ao pedir o resultador dará como Opção Invalida no resultado
        }
        printf("Pressione qualquer tecla para continuar...\n");
        getch();
    }
    return 0;
}

//Aqui começará os cálculos para execução do resultado

int calcular_mdc(int p, int q) {
    if (q == 0) return p;
    return calcular_mdc(q, p % q);
}

void reduzir_valor(int p, int q, int *num, int *den) {
    int mdc = calcular_mdc(p, q);
    *num = p / mdc;
    *den = q / mdc;
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
    int mdc = calcular_mdc(num, den);
    num /= mdc;
    den /= mdc;
    printf("Resultado: %d / %d\n", num, den);
}

void subtrair_valores(int p, int q, int r, int s) {
    int num = p * s - r * q;
    int den = q * s;
    int mdc = calcular_mdc(num, den);
    num /= mdc;
    den /= mdc;
    printf("Resultado: %d / %d\n", num, den);
}

void multiplicar_valores(int p, int q, int r, int s) {
    int num = p * r;
    int den = q * s;
    int mdc = calcular_mdc(num, den);
    num /= mdc;
    den /= mdc;
    printf("Resultado: %d / %d\n", num, den);
}

void dividir_valores(int p, int q, int r, int s) {
    int num = p * s;
    int den = q * r;
    int mdc = calcular_mdc(num, den);
    num /= mdc;
    den /= mdc;
    printf("Resultado: %d / %d\n", num, den);
}
