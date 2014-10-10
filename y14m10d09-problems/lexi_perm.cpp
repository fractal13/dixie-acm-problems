#include <iostream>
#include <algorithm>
#include <cstring>

void find_lexi_perm(char *str, int N)
{
  N--;
  while(N > 0)
    {
      int k=-1;
      int i;
      // step 1
      for(i = 0; str[i] && str[i+1]; i++)
	{
	  if(str[i] < str[i+1]) { k = i; }
	}
      if(k < 0)
	{
	  std::sort(str, str+std::strlen(str));
	}
      else
	{
	  // step 2
	  int l,j;
	  for(j = k+1; str[j]; j++)
	    {
	      if(str[k] < str[j]) { l = j; }
	    }
	  // step 3
	  char tmp = str[k];
	  str[k] = str[l];
	  str[l] = tmp;
	  // step 4
	  std::reverse(str+k+1, str+std::strlen(str));
	}
      N--;
    }  
}

int main()
{
  int N;
  std::cin >> N;
  char str[6] = "12345";

  find_lexi_perm(str, N);

  std::cout << str << std::endl;
  
  return 0;
}
