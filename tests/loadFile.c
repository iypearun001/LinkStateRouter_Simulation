#include<stdio.h>

int main(int argc, char ** argv)
{
  int n, m, count = 5;
  char * filename ;
  int x[100][100];
  FILE *inp; 
 
  if(argc > 1)
  {
    printf("file  specified\n");
    int i = 0;
    while(i<argc)
    {
      printf("%s\n",(char *)argv[i]);
      i++;
    }
    filename = (char *)argv[1];
    inp = fopen(filename,"r");
  }
  else
  {
   printf("file not specified\n");
   return 0;
  }
  
   printf("Filename received for n x n matrix : %s",filename);
  //Read file without bounds being given
  char fchar;
  int prevIsChar = 0;
  count = 0;
  while((fchar = fgetc(inp)) != '\n')
  {
    if(fchar>='0' && fchar<='9' && !prevIsChar)
    {
      prevIsChar = 1;
      count++;
    }
    else
    {
      prevIsChar =0;
    }
  }
  
  printf("Nodecount : %d\n",count);
  
  fseek(inp, 0, SEEK_SET);
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