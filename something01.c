/*
 ============================================================================
 Name        : something01.c
 Author      : tokidoki_rain
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int K ,N ,sub ,ans;
int p[1001];
int main(void) {
	scanf("%d %d",&K ,&N);
	for(int j = 0; j < N; j++){
		scanf("%d", &p[j]);
	}

	for(int a = 0; a < N; a++){
		for(int b = a +1; b < N; b++){
			if (p[a] > p[b]){
			sub = p[a];
			p[a] = p[b];
			p[b] = sub;
			}
		}
	}
	for(int t = 0; t <K; t++){
		ans += p[t];
	}
	printf("%d" ,ans);

	/*for(int i = 0; i < N; i++){
		printf("%d\n", p[i]);
	}*/

	return 0;
}
