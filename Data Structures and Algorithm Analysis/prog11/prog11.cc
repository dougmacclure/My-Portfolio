#include "/home/onyuksel/courses/340/progs/13s/p11/wdigraph.h"
#include "/home/onyuksel/courses/340/common/340.h"

using namespace std;

void proc_graph(wdigraph &, int);


//***************************************************************************
// FUNCTION:  main
// ARGUMENTS: void
// RETURNS: int
// NOTES: A series of function calls to produced desired output
//
//***************************************************************************



int main()
{

wdigraph graph1(NO_NODES);
proc_graph(graph1, NO_NODES);

wdigraph graph2(5);
wdigraph graph3(20);

proc_graph(graph2, 5);
proc_graph(graph3, 20);

return 0;
}


//***************************************************************************
// FUNCTION:  proc_graph
// ARGUMENTS: wdigraph &g, int x
// RETURNS: void
// NOTES: This function prints paths of every 3rd node of passed in wdigraph 
// object.
//***************************************************************************



void proc_graph(wdigraph &g, int x)
{

//call g's print_graph member function to print g's adjacency matrix
g.print_graph();

//print every 3rd node's path by calling g's depth_first() memeber function, passing in the starting
//node, a multiple of 3
cout << endl << "Paths by Depth-First Search:" << endl << "(skip every 2nd and 3rd node to print)";
for(int i = 0; i < x ; i += 3)

	{
	cout << endl;
	g.depth_first(i);

	}
cout << endl;


}

