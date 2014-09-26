#include <iostream>
using namespace std;

int reverse(int P)
{
  int R = 0;
  while(P > 0)
    {
      R = R*10 + P%10;
      P /= 10;
    }

  return R;
}

void find_palindrome(int N, int &P, int &count)
{
  int R;
  count = 0;
  P = N;
  while((R = reverse(P)) != P)
    {
      count++;
      P += R;
    }
}

int main()
{
  int n,i;
  int N;
  int P, count;
  std::cin >> n;
  for(i = 0; i < n; i++)
    {
      cin >> N;
      find_palindrome(N, P, count);
      cout << count << " " << P << std::endl;
    }
  return 0;
}
