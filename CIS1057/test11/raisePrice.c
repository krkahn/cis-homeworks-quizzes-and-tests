#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 100

void raisePrice(char *filename) {
    FILE *fp;
    char line[MAX_LINE_LEN];
    double price;
    char partNum[13];

    // Open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Read each line and raise the price
    while (fgets(line, MAX_LINE_LEN, fp)) {
        // Extract the part number and price from the line
        sscanf(line, "%12s %lf", partNum, &price);

        // Raise the price by 5%
        price *= 1.05;

        // Print the updated line
        printf("%s %.2lf\n", partNum, price);
    }

    // Close the file
    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    raisePrice(argv[1]);

    return 0;
}
