#include<iostream>
using namespace std;
#include <unistd.h>
#include <termios.h>

char getch() {
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
        return (buf);
}
int main()
{
  char pa[10][10];
  char choice;
  int i_co = 0;
  int j_co = 0;

  /*for(int i=0;i<10;i++)
  {
    for(int j=0;j<10;j++)
    pa[i][j]=' ';
  }*/

  while(choice!='q')
  {
    std::system("clear");
    char temp;
    temp = pa[i_co][j_co];
    pa[i_co][j_co]='*';
    for(int i=0;i<10;i++)
    {
      for(int j=0;j<10;j++)
      cout<<pa[i][j]<<"\t";
      cout<<endl;
    }
    choice = getch();
    pa[i_co][j_co] = ' ';
    switch(choice)
    {
      case 'd':
      {
        //pa[i_co][j_co] = ' ';
        if(j_co==9)
        {
          j_co=-1;
        }
        j_co=j_co+1;
        break;
      }
      case 'a':
      {
        //pa[i_co][j_co] = ' ';
        if(j_co==0)
        {
          j_co=10;
        }
        //pa[i_co][j_co-1]='*';
        j_co=j_co-1;
        break;
      }
      case 'w':
      {
        //pa[i_co][j_co] = ' ';
        if(i_co == 0)
        i_co = 10;
        i_co = i_co-1;
        break;

      }
      case 's':
      {
        //pa[i_co][j_co] = ' ';
        if(i_co == 9)
        {
          i_co=-1;
        }
        i_co=i_co+1;
        break;
      }


    }
    pa[i_co][j_co] = temp;
  }
}
