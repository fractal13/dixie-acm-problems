#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

std::map<std::string, char> code;
std::vector<std::string> words;

void find_answers(std::string line, std::string word)
{
  int i,j;
  if(line.size() == 0)
    {
      words.push_back(word);
      return;
    }
  for(i = 1; i <= 4; i++)
    {
      if(line.size() >= i)
	{
	  std::string c;
	  for(j = 0; j < i; j++)
	    {
	      c += line[j];
	    }
	  char x;
	  x = code[c];
	  if(x >= 'A' && x <= 'Z')
	    {
	      std::string new_word(word);
	      std::string new_line = line.substr(i, std::string::npos);
	      new_word += x;
	      find_answers(new_line, new_word);
	    }
	}
    }
}

int main()
{
  code[".-"] = 'A';
  code["-..."] = 'B';
  code["-.-."] = 'C';
  code["-.."] = 'D';
  code["."] = 'E';
  code["..-."] = 'F';
  code["--."] = 'G';
  code["...."] = 'H';
  code[".."] = 'I';
  code[".---"] = 'J';
  code["-.-"] = 'K';
  code[".-.."] = 'L';
  code["--"] = 'M';
  code["-."] = 'N';
  code["---"] = 'O';
  code[".--."] = 'P';
  code["--.-"] = 'Q';
  code[".-."] = 'R';
  code["..."] = 'S';
  code["-"] = 'T';
  code["..-"] = 'U';
  code["...-"] = 'V';
  code[".--"] = 'W';
  code["-..-"] = 'X';
  code["-.--"] = 'Y';
  code["--.."] = 'Z';
  std::string line;
  std::cin >> line;
  std::string word;
  find_answers(line, word);
  std::sort(words.begin(), words.end());
  int i;
  for(i = 0; i < words.size(); i++)
    {
      std::cout << words[i] << std::endl;
    }
  return 0;
}
