#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int t,sum;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        sum=0;
        for(int i=5;i<n;i+=5)
        {
            if(i%3!=0)
            sum = sum + i;

        }

        for(int i=3;i<n;i+=3)
        {

            sum = sum + i;

        }


        cout<<sum<<endl;
    }
    return 0;
}
