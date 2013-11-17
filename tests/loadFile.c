#include<stdio.h>

int main()
{
  int n, m, count = 5;
  int x[6][6];
  FILE *inp; 
  inp = fopen("network.txt","r");
  for (n = 0; n < count; ++n) {
  for (m = 0; m < count; ++m)
    fscanf (inp, "%d", &x[n][m]);
  }
  fclose (inp); 
  
  for (n = 0; n < count; ++n) 
  {
    for (m = 0; m < count; ++m)
    {
      printf("%d  ",x[n][m]);
    }
     printf("\n");
  }
}