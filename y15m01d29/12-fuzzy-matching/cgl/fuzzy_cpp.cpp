#include <iostream>
#include <string>
#include <map>
using namespace std;

double min(double d1, double d2)
{
  return  d1 < d2 ? d1 : d2;
}

double max(double d1, double d2)
{
  return  d1 > d2 ? d1 : d2;
}

void string_to_ms(const string &w, map<string, double> &ms)
{
  size_t j, len;
  string key;
  map<string, double>::iterator mit;
  for(len = 1; len <= w.size(); len *= 2)
    {
      for(j = 0; j + len <= w.size(); j++)
	{
	  key = w.substr(j, len);
	  mit = ms.find(key);
	  if(mit == ms.end())
	    {
	      ms[key] = 0.0;
	    }
	  ms[key] += (1./(double)len);
	}
    }
  /*
  for(mit = ms.begin(); mit != ms.end(); mit++)
    {
      cout << mit->first << " " << mit->second << "   :  ";
    }
  cout << endl;
  */
}

double size_of_set(const map<string, double> &ms)
{
  map<string, double>::const_iterator mit;
  double value = 0.0;
  for(mit = ms.begin(); mit != ms.end(); mit++)
    {
      value += mit->second;
    }
  //cout << value << endl;
  return value;
}

void do_intersection(const map<string, double> &ms1, const map<string, double> &ms2, map<string, double> &ms3)
{
  map<string, double>::const_iterator mit1, mit2, mit;
  for(mit1 = ms1.begin(); mit1 != ms1.end(); mit1++)
    {
      mit2 = ms2.find(mit1->first);
      if(mit2 != ms2.end())
	{
	  ms3[mit1->first] = min(mit1->second, mit2->second);
	}
    }

  /*
  cout << "intersection: ";
  for(mit = ms3.begin(); mit != ms3.end(); mit++)
    {
      cout << mit->first << " " << mit->second << "   :  ";
    }
  cout << endl;
  */
}

void do_union(const map<string, double> &ms1, const map<string, double> &ms2, map<string, double> &ms3)
{
  map<string, double>::const_iterator mit1, mit2, mit3, mit;
  for(mit1 = ms1.begin(); mit1 != ms1.end(); mit1++)
    {
      mit2 = ms2.find(mit1->first);
      if(mit2 != ms2.end())
	{
	  ms3[mit1->first] = max(mit1->second, mit2->second);
	}
      else
	{
	  ms3[mit1->first] = mit1->second;
	}
    }
  for(mit2 = ms2.begin(); mit2 != ms2.end(); mit2++)
    {
      mit3 = ms3.find(mit2->first);
      if(mit3 == ms3.end())
	{
	  ms3[mit2->first] = mit2->second;
	}
    }
  /*
  cout << "union: ";
  for(mit = ms3.begin(); mit != ms3.end(); mit++)
    {
      cout << mit->first << " " << mit->second << "   :  ";
    }
  cout << endl;
  */
}


void solve(const string &w1, const string &w2)
{
  map<string, double> ms1, ms2, inter, un;
  double v1, v2, v3;
  string_to_ms(w1, ms1);
  //v1 = size_of_set(ms1);
  string_to_ms(w2, ms2);
  //v2 = size_of_set(ms2);
  do_intersection(ms1, ms2, inter);
  do_union(ms1, ms2, un);
  v1 = size_of_set(inter);
  v2 = size_of_set(un);
  cout << v1 << " " << v2 << " : ";
  v3 = v1/v2;
  cout  << (int)(v3*100.+0.5) << endl;
}

int main()
{
  int N,i;
  string w1, w2;
  cin >> N >> ws;
  for(i = 0; i < N; i++)
    {
      getline(cin, w1);
      getline(cin, w2);
      solve(w1, w2);
      //cout << w1 << endl;
      //cout << w2 << endl;
    }
  return 0;
}
