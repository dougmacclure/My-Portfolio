#include "/home/onyuksel/courses/340/common/340.h"

#ifndef H_WDIGRAPH
#define H_WDIGRAPH

// definition of weighted digraph

#define NO_NODES   1    // default size for no of nodes in digraph
#define LINK_PROB  0.25 // prob of having direct link between nodes
#define MAX_WEIGHT 10   // max weight factor for links

class wdigraph {
public:
    wdigraph ( int = NO_NODES );            // default constructor
    ~wdigraph ( ) { };                      // destructor
    int get_size ( ) const { return size; } // returns size of digraph

    void depth_first ( int ) const;// traverses graph using depth-first search
    void print_graph ( ) const;    // prints adjacency matrix of digraph

private:
    int size;                               // size of digraph
    vector < char > label;                  // node labels
    vector < vector < int > > adj_matrix;   // adjacency matrix
};
#endif
