#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

void preprocess(char *input) {
    int i, j = 0;
    for (i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            input[j++] = toupper(input[i]);
        }
    }
    input[j] = '\0';
}

void generatePlayfairMatrix(char matrix[SIZE][SIZE], char *key) {
    int i, j, k, len;
    char alphabet[26] = {0};
    len = strlen(key);

    k = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (k < len) {
                if (!alphabet[key[k] - 'A']) {
                    matrix[i][j] = key[k];
                    alphabet[key[k] - 'A'] = 1;
                    k++;
                } else {
                    j--;
                    k++;
                }
            } else {
                for (k = 0; k < 26; k++) {
                    if (!alphabet[k] && k != ('J' - 'A')) {
                        matrix[i][j] = 'A' + k;
                        alphabet[k] = 1;
                        break;
                    }
                }
            }
        }
    }
}

void findPosition(char matrix[SIZE][SIZE], char ch, int *row, int *col) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
void encryptPair(char matrix[SIZE][SIZE], char a, char b, char *result) {
    int rowA, colA, rowB, colB;
    findPosition(matrix, a, &rowA, &colA);
    findPosition(matrix, b, &rowB, &colB);

    if (rowA == rowB) {
        result[0] = matrix[rowA][(colA + 1) % SIZE];
        result[1] = matrix[rowB][(colB + 1) % SIZE];
    } else if (colA == colB) {
        result[0] = matrix[(rowA + 1) % SIZE][colA];
        result[1] = matrix[(rowB + 1) % SIZE][colB];
    } else {
        result[0] = matrix[rowA][colB];
        result[1] = matrix[rowB][colA];
    }
}

void playfairEncrypt(char matrix[SIZE][SIZE], char *input, char *output) {
    int i, j = 0;
    char a, b;
    for (i = 0; i < strlen(input); i += 2) {
        a = input[i];
        b = (input[i + 1] == '\0') ? 'X' : input[i + 1];
        encryptPair(matrix, a, b, &output[j]);
        j += 2;
    }
    output[j] = '\0';
}

int main() {
    char matrix[SIZE][SIZE];
    char key[50], input[100], output[100];

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter the plaintext: ");
    getchar();
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; 

    preprocess(input);
    generatePlayfairMatrix(matrix, key);
    playfairEncrypt(matrix, input, output);

    printf("Encrypted text: %s\n", output);
    return 0;
}
