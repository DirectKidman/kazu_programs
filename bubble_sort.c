#include <stdio.h>

int main(){
  int v[10];
  int i,j;
  for(i=0;i<10;i++){
    scanf("%d",&v[i]);
  }

  for(i=0;i<10;i++) for(j=0;j<9;j++){
    int a = v[j], b = v[j+1];
    if(a>b){
      v[j+1]=a; v[j]=b;
    }
  }

  for(i=0;i<10;i++){
    printf("%d ",v[i]);
  }

  return 0;
}
