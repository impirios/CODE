#include <bits/stdc++.h>

using namespace std;


// Complete the repeatedString function below.
long repeatedString(string s, long n) {
static long int occurence;
long int x = s.size();
static int clay;
long int div,mod;
/*for(long int i=0,j=0;i<n&&j<x;i++,j++)
{
  if(s[j]=='a')
  occurence++;

  if(j==x-1)
  j=-1;
}*/

for(int i=0;i<x;i++)
{
  if(s[i] == 'a')
  occurence++;
}

div = n/x;
mod = n%x;

occurence = occurence*div;

for(int j=0;j<mod;j++)
{
  if(s[j] == 'a')
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
