#include <iostream>
#include <cmath>

int main()
{
  int coins;
  double rate, take;
  int i;
  while(std::cin >> coins >> rate)
    {
      rate /= 100.;
      i = 0;
      while(coins > 0)
	{
	  coins = std::floor(coins * rate);
	  i++;
	}
      std::cout << i << std::endl;
    }
  return 0;
}
