
#include "/home/onyuksel/courses/340/progs/13s/p11/wdigraph.h"
#include "/home/onyuksel/courses/340/common/340.h"

using namespace std;

int nextelt(vector<int>, int);

//***************************************************************************
// FUNCTION:  depth_first const
// ARGUMENTS: int u
// RETURNS: void
// NOTES: A wdigraph const member function that is used to traverse the weighted directional
// graphs created in the driver program with the depth first search algorithm.  A
// stack is used to keep track of nodes visited.  When we have reached a node that 
// is not linked to any other nodes we haven't visited, we pop the node from the 
// stack to backtrack.
//***************************************************************************

void wdigraph::depth_first(int u) const
{

//temporary variables and subscripts
char temp;
char A = 'A';
unsigned i;
unsigned l;
unsigned count = 0;
unsigned k;
int back;

//backtracking stack
vector<char> v(0);

//holds all nodes visited
vector<char> other(0);


//begin output
cout << endl;
cout << label[u];

//designate that we have vistied the first node at position u by adding to stacks
v.push_back(label[u]);
other.push_back(label[u]);

//use to access stack
vector<char>::iterator ind;

//Search Adj.Matx for link
i = nextelt(adj_matrix[u], 0);
k = i;

//use count to keep track of how many times we have searched Adj Mat'x in a particular row
//if we have searched # of column times, we backtrack
count++;


//if(i == label.size())

//	return;

//within a while loop that terminates when we have visited all nodes

while(other.size()!=label.size())

	{

		//find if label[i] is already in adjacency matrix		
	
		ind = find_if(other.begin(), other.end(),[&](const char &x){return label[i] == x;} );
	
		//if we have a match

		while(ind != other.end())
	
			{

				//if we visited all nodes, exit program				

				if(other.size() == label.size())
	
					return;					

				//otherwise there are other nodes yet visited, look for next link
				l = nextelt(adj_matrix[k], count);
				count++;
				
				//if l = label.size(), then we couldn't find the next link in the adj matrix
                                if(l == label.size())

                                
					{

				        l = nextelt(adj_matrix[k], 0);
					
					}


				//otherwise we found a match in adj matx


				//search to see if we have already visited this node
				ind = find_if(other.begin(), other.end(),[&](const char &x){return label[l] == x;} );

				//if find_if found no matches, exit this while loop to print node info and move onto next row

				if(ind == other.end()) 

					{
					
					i = l;
					break;
					}

				//otherwise, if our counter indicates that we have visited every node already, then we need 	
				//to backtrack
			
				else if(count == label.size()-1)
			
					{


					//if our stack is empty, then we have visited all nodes, and can exit this function
					if(v.empty())

						return;

					//otherwise we can backtrack	
					
					else

						{
						//get previous node 
						ind = v.end() -2;				
						temp = *ind;
						//delete current node from stack
						v.pop_back();
										
						//get subscript of previous node		
						back = temp - A;
						//set it to our current row
						i = (unsigned)back;
						k = i;
						//reset counter
						count = 0;

						//find next link
						l = nextelt(adj_matrix[k], count);
					
						//see if we have already visited node
						ind = find_if(other.begin(), other.end(),[&](const char &x){return label[l] == x;} );
						count++;

						//if not, break out of secondary while loop to print node info, otherwise
						//continue secondary while loop to search for next link
						if(ind == other.end())

							{
							i = l;
							 break;

							}
								
						}

					

					}
	
	

			}				

		//print node data
	
		cout << "->" << label[i];

		//indicate node as visited by adding to stack and other container and reset counter          
		v.push_back(label[i]);
		count = 0;
		other.push_back(label[i]);
		k = i;
		//find next link and move on
		i = nextelt(adj_matrix[k], count);
		count++;		

	}
}



//***************************************************************************
// FUNCTION:  nextelt
// ARGUMENTS: vector<int> v1, int j
// RETURNS: int
// NOTES: Helper function that searches v1 for first nonzero element after 
// index j.
//***************************************************************************



int nextelt(vector<int> v1, int j)
{


for(unsigned i = j; i < v1.size(); i++)

	{

	//return first nonzero element after v1[j]
	if(v1[i] != 0) return  i;


	}

//otherwise return a subscript that is out of range
return v1.size();
}


//***************************************************************************
// FUNCTION:  print_graph const
// ARGUMENTS: void
// RETURNS: void
// NOTES: Prints Adjacency Matrix and other desired information.
// 
//***************************************************************************



void wdigraph::print_graph() const
{

//print desired info
cout << endl << endl;
cout << "A Weighted Digraph" << endl;
cout << "__________________" << endl << endl;

cout << "No nodes = " << label.size() << endl << endl;

cout << "Adjacency Matrix: " << endl << endl;

cout << "  |";

//header of Matrix to indicate column info
for(vector<char>::const_iterator i = label.begin(); i != label.end(); i++)

	{

	cout << "  " << *i;

	}


cout << endl << "--|";

for(vector<char>::const_iterator i = label.begin(); i != label.end(); i++)

	{

	cout << "---";

	}
cout << endl;

for(unsigned i = 0; i < label.size(); i++)

	{

	//indicates row info

	cout << label[i] << " |  ";

	//prints elements of a row.  If element in matrix is zero, print a "-"

	for(unsigned j = 0; j < label.size(); j++)

		{

		if(adj_matrix[i][j] == 0)

			cout << "-  ";

		else

			cout << left << setw(3) << adj_matrix[i][j];

		

		}

	cout << endl << "  | " << endl;

	}

}
