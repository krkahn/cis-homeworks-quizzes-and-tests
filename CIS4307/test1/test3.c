#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char* doubleup(char* string){
        //static char string2[40] = {0};           // zero initialized
        char *string2 = malloc(strlen(string)*2);
	for(unsigned i=0, j=0, len = strlen(string); i<len; i++) {
            string2[j++] = string[i];
            string2[j++] = string[i];
        }
	return string2;
	free(string2);
}

int main(){
	char *str = "hello";
	printf("%s\n",doubleup(str));
	char *str2 = "fuck";
        printf("%s\n",doubleup(str2));
}
