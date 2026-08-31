#include <stdio.h>
#include <stdlib.h>

char *change(char input[50]) {
    char *output;
    int begin, end, count = 0;

    //Calculating string length
    while (input[count] != '\0') {
        count++;
    }

    output= (char*)malloc((count + 3) * sizeof(char));

    end = count - 1;

    output[0] = 'A';

    for (begin = 1; begin <= count; begin++) {
        output[begin] = input[end];
        end--;
    }

    output[begin] = 'a';
    output[begin+1] = '\0';

    return output;
}

int main() {
    FILE *fptr, *fw;
    char str[50];
    // Replace these with paths on your own machine.
    fptr = fopen("/home/elahe/Desktop/letter.txt", "r");
    fw   = fopen("/home/elahe/Desktop/new.txt", "w");

    if (fptr == NULL || fw == NULL) {
        perror("fopen");
        return 1;
    }

    while (fscanf(fptr, "%49s", str) == 1) {
        fprintf(fw,"%s ", change(str));
    }

    fclose(fptr);
    fclose(fw);
    return 0;
}
