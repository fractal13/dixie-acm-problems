#include <iostream>
#include <vector>
using namespace std;

int main()
{
  long long int power, term;
  vector<long long int> v;
  int i,j;
  while(cin >> power >> term)
    {
      if(power >= 2 && power <= 36 && term >= 1 && term <= 36)
	{
	  v.clear();
	  for(i = 0; i < power; i++)
	    {
	      v.push_back(1);
	    }
	  for(i = power; i < term; i++)
	    {
	      v.push_back(0);
	      for(j = 1; j <= power; j++)
		{
		  v[i] += v[i-j];
		}
	    }
	  cout << power << " " << term << " " << v[term-1] << endl;
	}
      else
	{
	  cout << power << " " << term << " " << 0 << endl;
	}
    }
  return 0;
}
