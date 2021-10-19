#include<stdio.h>
#include<string.h>

int main(){
	char string1[20] = "nabucco";
	char string2[40] = "";
	//char *string3 = "tobacco";
        int j=0;
	for(int i=0; i<strlen(string1);i++){
		string2[j]   = string1[i];
		j++;
		string2[j] = string1[i];
		j++;
	}
	printf("string1=\t%s\n",string1);
	printf("string2=\t%s\n",string2);
	//printf("%c\n", string3[2]);
}
