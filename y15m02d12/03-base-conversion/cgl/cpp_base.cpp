#include <iostream>
#include <string>
using namespace std;

int main()
{
  string line;
  getline(cin, line);
  int value = 0;
  size_t i;
  for(i = 0; i < line.size()  && (line[i] == '1' || line[i] == '0'); i++)
    {
      value = (value << 1) + (line[i] == '1' ? 1 : 0);
    }
  cout << value << endl;
  return 0;
}
