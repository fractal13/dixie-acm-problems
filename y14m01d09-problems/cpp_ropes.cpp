#include <iostream>

int main()
{
  int N;
  int p[100];
  int i,j,total;
  int lengths[] = { 50, 60, 70 };
  while(std::cin >> N && N > 0)
    {
      total = 0;
      for(i = 0; i < N; i++)
	{
	  std::cin >> p[i];
	  total += p[i];
	}
      for(j = 0; j < 3; j++)
	{
	  if(j) { std::cout << " "; }
	  int l = lengths[j];
	  if(2*total > l)
	    {
	      std::cout << "0";
	    }
	  else
	    {
	      int m = l;
	      for(i = 0; i < N; i++)
		{
		  int n = 1 + (l/p[i]);
		  if(n < 2) { n = 0; }
		  if(n < m) { m = n; }
		}
	      std::cout << m;
	    }
	}
      std::cout << std::endl;
    }
  return 0;
}
