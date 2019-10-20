#include<stdio.h>
#include<iostream>
//#include"mine_sweeper_game.cpp"
using namespace std;
//void PrintPattern(char[]);
int random(int,int);
int ispresent(struct x_y,int,int);
#define intermidiate 40
#define beginner 10
#define advanced 99

struct x_y
{
  int x[10];
  int y[10];
};

struct x_y pointX_Y;



int ispresent(int x_cor,int y_cor )                                             //to check the random pairs are used before or not
{
  int found;
  //cout<<"inside ispresent f(x)n\nx="<<x_cor<<",y="<<y_cor<<endl;
  for(int i=0 ; i<10 ; i++)
  {
    //cout<<"x["<<i<<"] = "<<pointX_Y.x[i]<<"\ty["<<i<<"] = "<<pointX_Y.y[i]<<endl;
    if(pointX_Y.x[i] == x_cor && pointX_Y.y[i] == y_cor)
    {
      found = 1;
      break;
    }
    else
    found = 0;
  }
  return found;

}

int random(int min, int max) //range : [min, max)                               //generate random number
{
   static bool first = true;
   if (first)
   {
      srand( time(NULL) ); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}

int IsMine(int row,int column,char GameBoard[][8])                              //check if there is mine or not
{
  if(GameBoard[row][column] == '*')
  return 1;
  else
  return 0;
}

int CalculatingAdjacentMines(int row , int column , char GameBoard[][8])        //check adjacent mines
{
  int count = 0;
  if(row == 0)
  {
    if(column >= 0 && column !=7)
    {
      if(IsMine(row , column+1,GameBoard) == 1)                                   //check at south
      count++;

      if(IsMine(row+1 , column+1,GameBoard) == 1)                                 //check at southwest
      count++;
    }

    if(IsMine(row+1 , column ,GameBoard) == 1)                                  //check at west
    count++;


    if(column <=7 && column!=0)
    {
      if(IsMine(row , column-1 ,GameBoard) == 1)                                  //check at north
      count++;

      if(IsMine(row+1 , column-1,GameBoard) == 1)                                 //check at northwest
      count++;
    }
  }

  else if(row == 7)
  {
    if(column >= 0 && column !=7)
    {
      if(IsMine(row , column+1,GameBoard) == 1)                                   //check at south
        count++;

      if(IsMine(row-1 , column+1,GameBoard) == 1)                                 //check at southeast
        count++;
    }

    if(IsMine(row-1 , column , GameBoard) == 1)                                 //check at east
    count++;

    if(column <=7 && column!=0)
    {
      if(IsMine(row , column-1 ,GameBoard) == 1)                                  //check at north
      count++;

      if(IsMine(row-1 , column-1,GameBoard) == 1)                                 //check at northeast
      count++;
    }
  }

  else if(column == 0)
  {
    if(IsMine(row-1 , column , GameBoard) == 1)                                 //check at east
    count++;

    if(IsMine(row+1 , column ,GameBoard) == 1)                                  //check at west
    count++;

    if(IsMine(row , column+1,GameBoard) == 1)                                   //check at south
    count++;

    if(IsMine(row+1 , column+1,GameBoard) == 1)                                 //check at southwest
    count++;

    if(IsMine(row-1 , column+1,GameBoard) == 1)                                 //check at southeast
    count++;
  }

  else if(column == 7)
  {
    if(IsMine(row-1 , column , GameBoard) == 1)                                 //check at east
    count++;

    if(IsMine(row+1 , column ,GameBoard) == 1)                                  //check at west
    count++;

    if(IsMine(row , column-1 ,GameBoard) == 1)                                  //check at north
    count++;

    if(IsMine(row-1 , column-1,GameBoard) == 1)                                 //check at northeast
    count++;

    if(IsMine(row+1 , column-1,GameBoard) == 1)                                 //check at northwest
    count++;
  }
  else
  {
    if(IsMine(row-1 , column , GameBoard) == 1)                                 //check at east
    count++;

    if(IsMine(row+1 , column ,GameBoard) == 1)                                  //check at west
    count++;

    if(IsMine(row , column-1 ,GameBoard) == 1)                                  //check at north
    count++;

    if(IsMine(row , column+1,GameBoard) == 1)                                   //check at south
    count++;

    if(IsMine(row+1 , column+1,GameBoard) == 1)                                 //check at southwest
    count++;

    if(IsMine(row-1 , column-1,GameBoard) == 1)                                 //check at northeast
    count++;

    if(IsMine(row-1 , column+1,GameBoard) == 1)                                 //check at southeast
    count++;

    if(IsMine(row+1 , column-1,GameBoard) == 1)                                 //check at northwest
    count++;
  }
  return count;
}

void PrintPattern(char GameBoard[][8])
{
  cout<<">";
  for(int i=0;i<8;i++)                                                          //print the gameboard
  cout<<"  "<<i;
  cout<<endl;
  for(int i=0;i<8;i++)
  {
    cout<<i;
    for(int j=0;j<8;j++)
    {
      cout<<"  "<<GameBoard[i][j];
    }
    cout<<endl;
  }
}

void youlose(char GameBoard[][8] , char FakeBoard[][8])                         //When player looses the game
{                                                                               //it will reveal all the mines
  for(int i=0;i<8;i++)                                                          //and tell the player where he/she
  {                                                                             //FUCKED UP
    for(int j=0;j<8;j++)
    {
      if(IsMine(i,j,GameBoard) == 1)
      {
        FakeBoard[i][j] = GameBoard[i][j];
      }
    }
  }
  PrintPattern(FakeBoard);
}


void RulesOfGame()                                                              //Gives the presentation and Rules of the game
{
  system("clear");
  char x;
  cout<<"***********/\\/\\***********************\n**********/****\\**|**|\\ |**---****----\n*********/******\\*|**| \\|**|******|***\n***************************---****----\n***************************|*********|\n***************************---****----\n**************************************\n";
  cout<<"Welcome To The Game\nThis Game is a programmed version of the famous MineSweeper puzzle\nThe Rules are simple\nThere is a 8x8 puzzle with 10 mines located at random positions\nYou have to select a coordinate in the order (row,column,choice)\nChoice is to choose whether you want to flag the coordinate or reveal it i.e.\nIf choice is 1 then it will FLAG the mine\nIf it is 0 it will reveal the position\nIf the revealed position is a MINE!YOU LOOSE\nIf you manage to FLAG all mines YOU WINN!\nPRESS ANY KEY TO CONTINUE";
  cin>>x;
}

void YOUWIN()                                                                   //WINNING presentation
{
  cout<<"\nYOU WIN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
}

void PlayGame(char GameBoard[][8])                                              //The MAIN game function
{
  int row,column,choice = 0,count;
  char FakeBoard[8][8];
  RulesOfGame();
  for(int i=0;i<8;i++)
  {
    for(int j=0;j<8;j++)
    FakeBoard[i][j] = '-';
  }

while(count!==0)
{
  for(int i=0;i<8;i++)
  {
    for(int j=0;j<8;j++)
    if(FakeBoard[i][j]=='-')
    count++;
  }

  PrintPattern(FakeBoard);
  cin>>row>>column>>choice;
  if(choice == 1)
  {
    FakeBoard[row][column] = 'M';
  }
  else if(choice == 0)
  {
    if(IsMine(row,column,GameBoard)==1)
    {
      break;
    }
    else
    {
      if(CalculatingAdjacentMines(row,column,GameBoard)==0)
      {
        ClearAdjacentBlocks(row,column,GameBoard,FakeBoard);
      }
      FakeBoard[row][column] = GameBoard[row][column];
    }
  system("clear");
}

if(count == 0)
YOUWIN();
else
youlose(GameBoard,FakeBoard);

}
