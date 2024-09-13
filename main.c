#include<stdio.h>
#include<string.h>

// Function for Leftmost Derivation (LMD)
void LMD(char str[], int size) {
    char virtual_str[size + 1];  // Ensure space for null-terminator
    strcpy(virtual_str, str);
    printf("LMD:\n");
    int counter = 0;

    // Loop for Leftmost Derivation
    Jump:
    printf("Step %d -> %s\n", ++counter, virtual_str);
    for(int i = 0; i < size; i++) {
        if(virtual_str[i] == 'A') {
            virtual_str[i] = 'b';
            goto Jump;  // Jump to print next step after substitution
        } else if(virtual_str[i] == 'B') {
            virtual_str[i] = 'c';
            goto Jump;
        }
    }
}

// Function for Rightmost Derivation (RMD)
void RMD(char str[], int size) {
    printf("RMD:\n");
    int counter = 0;

    // Loop for Rightmost Derivation
    Jump:
    printf("Step %d -> %s\n", ++counter, str);
    for(int i = size - 1; i >= 0; i--) {
        if(str[i] == 'A') {
            str[i] = 'b';
            goto Jump;  // Jump to print next step after substitution
        } else if(str[i] == 'B') {
            str[i] = 'c';
            goto Jump;
        }
    }
}

int main() {
    char str[100];  // Allocate enough space for user input

    printf("Enter the Context-Free Grammar: ");
    scanf("%s", str);  // Correct input handling

    int size = strlen(str);  // Get the size of the input string

    // Leftmost Derivation
    LMD(str, size);

    // Rightmost Derivation
    RMD(str, size);

    return 0;
}
