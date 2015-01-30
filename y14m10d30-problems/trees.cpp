#include <iostream>
using namespace std;

#define MAX_VERTEX 500

class Graph
{
public:
  Graph() : nvertex(0), nedge(0), cc(1) { }
  void set_nvertex(int nv)
  {
    int i,j;
    cc = 1;
    nedge = 0;
    nvertex = nv;
    for(i = 0; i < nv; i++)
      {
	v_visited[i] = 0;
	v_cc[i] = 0;
	cc_has_unused_edge[i] = 0;
	for(j = 0; j < nv; j++)
	  {
	    edges[i*nvertex+j] = 0;
	  }
      }
  }
  void add_edge(int i, int j)
  {
    edges[(i-1)*nvertex+(j-1)] = 1;
  }
  void explore(int i)
  {
    if(v_visited[i]) { return; }
    v_visited[i] = 1;
    v_cc[i] = cc;
    int j;
    for(j = 0; j < nvertex; j++)
      {
	if(edges[i*nvertex+j])
	  {
	    if(!v_visited[j])
	      {
		explore(j);
	      }
	    else
	      {
		cc_has_unused_edge[cc] = 1;
		cout << "i:j is unused " << i << ":" << j << endl;
	      }
	  }
      }
  }
  void dfs()
  {
    int i;
    cc = 1;
    for(i = 0; i < nvertex; i++)
      {
	if(!v_visited[i])
	  {
	    explore(i);
	    cc++;
	  }
      }
  }
  
  int nvertex;
  int v_visited[MAX_VERTEX];
  int v_cc[MAX_VERTEX];

  int nedge;
  int edges[MAX_VERTEX*MAX_VERTEX];

  int cc;

  int cc_has_unused_edge[MAX_VERTEX+1];
};

bool read_problem(Graph *g)
{
  int nv, ne;
  cin >> nv >> ne;
  if(!cin || (nv == 0 && ne == 0)) { return false; }
  g->set_nvertex(nv);
  int i, x, y;
  for(i = 0; i < ne; i++)
    {
      cin >> x >> y;
      g->add_edge(x, y);
      g->add_edge(y, x);
    }
  
  return true;
}

int main()
{
  Graph g;
  int i;
  while(read_problem(&g))
    {
      g.dfs();
      cout << "Got one. " << g.cc << " " << endl;
      int treecount = 0;
      for(i = 1; i < g.cc; i++)
	{
	  cout << "i: " << i << " : " << g.cc_has_unused_edge[i] << endl;
	  if(!g.cc_has_unused_edge[i])
	    {
	      treecount ++;
	    }
	}
      cout << treecount << endl;
    }
  return 0;
}
