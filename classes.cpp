#include<iostream>
#include<string.h>
using namespace std;
class cricket
{
  string PlayerName;
  float MatchesPlayed;
  float TotalRuns;
  int Tons;
  int HalfTons;
  float StrikeRate;
public:
  void GetNewPlayerInfo()
  {
    cout<<"\nPlayer Name - ";
    cin>>PlayerName;
    cout<<"Matches Played - ";
    cin>>MatchesPlayed;
    cout<<"Total Runs - ";
    cin>>TotalRuns;
    cout<<"Hundreds - ";
    cin>>Tons;
    cout<<"Fifties - ";
    cin>>HalfTons;
    CalculateStrikeRate();

  }

  void PrintPlayerInfo()
  {
    cout<<"\nPlayer Name - "<<PlayerName<<endl;
    cout<<"Matches Played - "<<MatchesPlayed<<endl;
    cout<<"Total Runs - "<<TotalRuns<<endl;
    cout<<"Strike Rate - "<<StrikeRate<<endl;
    cout<<"Hundreds - "<<Tons<<endl;
    cout<<"Fifties - "<<HalfTons<<endl;

  }

  void CalculateStrikeRate()
  {
    StrikeRate = float(TotalRuns/MatchesPlayed);
  }

  void UpdateNewMatch()
  {
    int Runs;
    cout<<"\nRunsScored - ";
    cin>>Runs;
    TotalRuns = TotalRuns + Runs;
    MatchesPlayed = MatchesPlayed + 1;
    if(Runs > 100)
      Tons = Tons + 1;
    else if(Runs > 50 && Runs < 100)
      HalfTons = HalfTons + 1;

    CalculateStrikeRate();

  }

};

int main()
{
  cricket player;
  char choice;
  while(choice!='q')
  {
    cout<<"\nChoose an option -\n"<<endl;
    cout<<"Create new profile\n";
    cout<<"Update new match\n";
    cout<<"Print player info\n";
    cout<<"Quit\n";
    cin>>choice;
    switch (choice)
    {
      case 'c':
      {
        player.GetNewPlayerInfo();
        break;
      }
      case 'u':
      {
        player.UpdateNewMatch();
        break;
      }
      case 'p':
      {
        player.PrintPlayerInfo();
        break;
      }
      case 'q':break;
      default:cout<<"Not sure\n";
    }
  }
}
