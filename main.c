#include<stdio.h>
#include<string.h>

void LMD(char str[], int size){
    char lmdg[100];  // Defined array with a reasonable size
    strcpy(lmdg, str);
    printf("LMD :\n");
    int counter = 0;
    
    lex:
    printf("%d -> %s\n", ++counter, lmdg);
    for(int i = 0; i < size; i++){
        if(lmdg[i] == 'A'){
            lmdg[i] = 'b';
            goto lex;
        } else if(lmdg[i] == 'B'){
            lmdg[i] = 'c';
            goto lex;
        }
    }
}

void RMD(char str[], int size){
    printf("RMD :\n");
    int counter = 0;
    
    lex:
    printf("%d -> %s\n", ++counter, str);
    for(int i = size - 1; i >= 0; i--){
        if(str[i] == 'A'){
            str[i] = 'b';
            goto lex;
        } else if(str[i] == 'B'){
            str[i] = 'c';
            goto lex;
        }
    }
}

int main(){
    char str[100];  // Allocating enough space for the string

    printf("Enter The Context-Free Grammar: ");
    scanf("%s", str);  // No need for '&' with strings in scanf

    LMD(str, strlen(str));  // Call LMD
    RMD(str, strlen(str));  // Call RMD

    return 0;
}
