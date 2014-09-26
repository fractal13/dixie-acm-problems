#include <iostream>
using namespace std;

int main()
{
  int N, M;
  int cardnums[8192];
  int numcards = 1;
  int i,j,n;
  cin >> N >> M;

  while((1 << numcards) < M)
    {
      numcards++;
    }

  cout << numcards << endl;
  for(i = 0; i < numcards; i++)
    {
      n = 0;
      for(j = N; j <= M; j++)
	{
	  if((j >> i) & 0x1)
	    {
	      cardnums[n] = j;
	      n++;
	    }
	}
      for(j = 0; j < n; j++)
	{
	  cout << cardnums[j] << " ";
	}
      cout << endl;
    }
  
  return 0;
}
