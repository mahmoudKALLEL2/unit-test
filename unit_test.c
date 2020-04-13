#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

char *sort(char *expr){
	int length = strlen(expr);
	int tempval = 0;

	for(int cmpt =0 ; cmpt<=length; cmpt++){
		for(int k =0; k < length - 1; k++){
			if (expr[k] > expr[k+1]){
				tempval = expr[k];
				expr[k] = expr[k +1];
				expr[k +1] = tempval;
			}
		}
	}

	return expr;
}
int isPermutation(const char *s1, const char *s2){

	if (s1 == NULL || s2 == NULL){
		printf("s1 or s2 is null \n");
		return FALSE;
	}

	if (strlen(s1) != strlen(s2)) {
		return FALSE;
	}

	char *p1 = NULL, *p2 = NULL;
	p1 = malloc(sizeof(s1[0]) * strlen(s1) + 1);
	p2 = malloc(sizeof(s2[0]) * strlen(s2) + 1);

	if (!p1 || !p2){
		return FALSE;
	}

	strncpy(p1, s1, strlen(s1));
	strncpy(p2, s2, strlen(s2));

	sort(p1);
	sort(p2);

	if (strcmp(p1, p2) == 0){
		free(p1);
		free(p2);
		return TRUE;
	}

	free(p1);
	free(p2);
	return FALSE;
}

void test(int expected, int actual, char *Nameofthe_test){
	if(expected == actual)
		printf(" Passed %s\n", Nameofthe_test);
	else
		printf(" Failed %s , expected: %d actual: %d\n",Nameofthe_test, expected, actual);
}
int main(){

	test(FALSE, isPermutation("231", "2"), "test1" );
	test(TRUE, isPermutation("231", "231"), "test2");
	test(FALSE, isPermutation("231", "231"), "test3");
	test(FALSE, isPermutation("231", "261"), "test4");
	test(FALSE, isPermutation("271", "2614444"), "test5");
	test(TRUE, isPermutation("abc", "bac"), "test6");
	test(TRUE, isPermutation("abc", NULL), "test7");
}
