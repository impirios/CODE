#include"mine_sweeper.cpp"

int main()
{
  char GameBoard[8][8];
  int x=-1,y=-1;

  for(int i=0;i<8;i++)                                                          //clear the GameBoard
  {
    for(int j=0;j<8;j++)
    {
      GameBoard[i][j] = '-';
    }
  }

  for(int i=0;i<10;i++)
  {
    pointX_Y.x[i] = -1;
    pointX_Y.y[i] = -1;
  }
  for(int i=0;i<beginner;i++)                                                   //Set the mines at random positions
  {
    while(ispresent(x,y) == 1)
    {
       x = random(0,7);
       y = random(0,7);
       //cout<<"inside while loop\nx="<<x<<",y="<<y<<endl;

    }
    GameBoard[x][y] = '*';
    pointX_Y.x[i] = x;
    pointX_Y.y[i] = y;
  }

  cout<<endl;
  for(int i=0;i<8;i++)
  {
    for(int j=0;j<8;j++)
    {
      if(GameBoard[i][j] != '*')
      {
        int x = CalculatingAdjacentMines(i,j,GameBoard);
        GameBoard[i][j] = '0'+x;
      }
    }
  }
  PlayGame(GameBoard);
}
