#include <bits/stdc++.h>

using namespace std;


// Complete the repeatedString function below.
long repeatedString(string s, long n) {
static long int occurence;
static int min;
long int x = s.size();
static int clay;

for(long int j=1;j<=n;j*=1024)
{
  min+=10;
  cout<<j<<endl;
}



cout<<min<<endl;

for(long int i = 0;i<min; i++)
{
  s = s + s;
  cout<<"Loop"<<endl;
}

cout<<s.size()<<endl;

for(long int i=0;i<n;i++)
{
  if(s[i]=='a')
  occurence++;
}

cout<<occurence<<endl;
return occurence;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
