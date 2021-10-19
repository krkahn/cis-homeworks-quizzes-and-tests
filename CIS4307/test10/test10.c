#include <stdio.h>
#include <string.h>
#define max(x,y) (((x) >= (y)) ? (x) : (y))

int lcsubstr(char* str1,char* str2)
{
      int ans = 0;

	for (int i = 0; i < strlen(str1); i++) 
	{
         for (int j = 0; j < strlen(str2); j++) {
		int k = 0;
		while ((i + k) < strlen(str1) && (j + k) < strlen(str2) && str1[i + k] == str2[j + k]) 
		{
			k = k + 1;
		}
		ans = max(ans, k);
	   }
	}
      return ans;
}

int main(){
    char *X = "rosangela";
    char *Y = "roangieka";
    printf("%d\n",lcsubstr(X, Y));
}
