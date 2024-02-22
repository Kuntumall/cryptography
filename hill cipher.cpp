#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 3 
void hillEncrypt(int key[N][N], char *plaintext, char *ciphertext) {
    int len = strlen(plaintext);
    int i, j, k, sum;
    int padding = (len % N == 0) ? 0 : (N - len % N);
    len += padding;
    char padded_text[len + 1];
    strcpy(padded_text, plaintext);
    for (i = len - padding; i < len; i++) padded_text[i] = 'X';
    padded_text[len] = '\0';

    for (i = 0; i < len; i += N) {
        for (j = 0; j < N; j++) {
            sum = 0;
            for (k = 0; k < N; k++) sum += (key[j][k] * (padded_text[i + k] - 'A'));
            ciphertext[i + j] = (sum % 26) + 'A';
        }
    }
    ciphertext[len] = '\0';
}
int main() {
    int key[N][N] = {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}};
    char plaintext[] = "HELLO"; 
    char ciphertext[strlen(plaintext) + 1];

    hillEncrypt(key, plaintext, ciphertext);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}
