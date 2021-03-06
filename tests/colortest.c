#include <stdio.h>
#include <unistd.h>
#include <termios.h>

#define MAX_NODECOUNT 100
#define Color_Red "\x1b[31;1m" // Color Start
#define Color_Blue "\x1b[34;1m" // Color Start
#define Color_end "\x1b[39;49m" // To flush out prev settings

#define LOG_RED(X) printf("%s%c%s",Color_Red,X,Color_end)
#define LOG_BLUE(X) printf("%s %s %s",Color_Blue,X,Color_end)

int getch() {
    struct termios oldtc, newtc;
    int ch;
    tcgetattr(STDIN_FILENO, &oldtc);
    newtc = oldtc;
    newtc.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newtc);
    ch=getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldtc);
    return ch;
}
void cScanf(char * inputString, int maxlength )
{
  int i =0;
  while((inputString[i] = getch())!='\n' && i < maxlength-1)
  {
    LOG_RED(inputString[i]);
    i++;
  }
}

int main()
{
  LOG_RED('f');
    LOG_BLUE("asdfasdf");
    printf ("\e[5;32;40m Blink Text\e[m\n");

    /*
    char exit;

    while(exit!='\n')
    {
      exit = getch();
      LOG_RED(exit);
    }
    */
    
    char test[10];
    printf("%d",sizeof(test));
    cScanf(test, sizeof(test));
    printf("\n\n%s",test);
}