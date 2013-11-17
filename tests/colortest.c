#include <stdio.h>

#define MAX_NODECOUNT 100
#define Color_Red "\x1b[31;1m;" // Color Start
#define Color_Blue "\x1b[34;1m;" // Color Start
#define Color_end "\x1b[39;49m" // To flush out prev settings

#define LOG_RED(X) printf("%s %s %s",Color_Red,X,Color_end)
#define LOG_BLUE(X) printf("%s %c %s",Color_Blue,X,Color_end)


int main()
{
  LOG_RED("test red");
    LOG_BLUE('d');
    printf ("\e[5;32;40m Blink Text\e[m\n");
    
    char exit='a';
    while(exit!='\n')
    {
      exit = getc();
      LOG_BLUE(exit);
    }
}