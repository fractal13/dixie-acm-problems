#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N, P;
  unsigned int i;
  vector<int> Ps;
  while(cin >> N && N > 0)
    {
      Ps.clear();
      int total_height = 0;
      int j;
      for(i = 0; i < N; i++)
	{
	  cin >> P;
	  Ps.push_back(P);
	  total_height += P;
	}
      int L[3] = { 50, 60, 70 };
      for(j = 0; j < 3; j++)
	{
	  if(j > 0)
	    {
	      cout << " ";
	    }
	  if(2*total_height > L[j])
	    {
	      cout << 0;
	    }
	  else
	    {
	      int C = L[j];
	      for(i = 0; i < Ps.size(); i++)
		{
		  int x = L[j] / Ps[i]  + 1;
		  if(x < C)
		    {
		      C = x;
		    }
		}
	      cout << C;
	    }
	}
      cout << endl;
    }
}
