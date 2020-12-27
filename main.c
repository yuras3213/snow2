#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <windows.h>

#include <unistd.h>


#define h 25
#define w 80
char mas[h][w+1];

#define STDIN_FILENO 0
#define NB_DISABLE 0
#define NB_ENABLE 1

int kbhit()
{
    struct timeval tv;
    fd_set fds;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &fds);
}


void init()
{
    for (int i=0; i<w; i++)
    mas[0][i]=' ';
    mas[0][w]= '\0';
    for(int i=1; i<h; i++)
    sprintf(mas[i], mas[0]);
}
void show()
{
    mas[h-1][w-1]='\0';
    for (int i=0 ; i<h ; i++)
    printf(mas[i]);
}
void newSnow()
{
    for(int i=0; i<w; i++)
        if(rand()% 12 == 1)
        mas[0][i]='*';

}
    void moveSnow()
{
 int dx;
 for(int j=h-1;j>=0;j--)
 for(int i=0; i<w; i++)
        if(mas[j][i]== '*')
 {
  mas[j][i]=' ';
  dx=0;
  if (rand()% 10<1)dx++;
  if (rand()% 10<1)dx--;
  dx=dx+i;
  if((dx>=0)&&(dx<w)&&(j+1 <h))
        mas[j+1][dx]='*';
 }
}
   /* void setcur(int x, int y)
    {
     COORD coord;
     coord.X = x;
     coord.Y = y;
     SetConsoleCursorPosition(GetStdHandle (STD_OUTPUT_HANDLE),coord);
    }
    */

int main()
{
    init();
 //   do
  //  {
      //  setcur(0,0);

   while (1)     //for(int i = 0; i<1000 ; i++)
   {
//    setcur(0,0);
    if (kbhit() != 0)break;

    moveSnow();
    newSnow();
    show();
    sleep(1);

    }
//    while(GetKeyState(VK_ESCAPE)>=0);

    return 0;
}
