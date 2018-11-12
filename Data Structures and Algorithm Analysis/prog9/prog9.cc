// Doug MacClure
// z0125061
// Assignment 9
// CSCI330-3
// Due: 4/16/13




#include "/home/onyuksel/courses/340/common/340.h"
#include "/home/onyuksel/courses/340/progs/13s/p9/prog9.h"



using namespace std;

int main()
{


 vector < int >    v1;   // heap of integers
    vector < float >  v2;   // heap of floating-pt nums
    vector < string > v3;   // heap of strings

    // print header message
    cout << "\t\t\t*** CSCI 340: Program 9 - Output ***\n\n";

    // first heap

    cout << "first heap - ascending order:\n\n";
    get_list ( v1, D1 );
    construct_heap ( v1, less < int > ( ) );
    print_list < int, INT_SZ, INT_LN > print1 ( v1.size ( ) );
    for_each ( v1.begin ( ), v1.end ( ), print1 );




    cout << "first heap - descending order:\n\n";
    //get_list ( v1, D1 );
    construct_heap ( v1, greater < int > ( ) );
    for_each ( v1.begin ( ), v1.end ( ), print1 );


 

    cout << "first heap - ascending order with absolute values:\n\n";
    //get_list ( v1, D1 );
    construct_heap ( v1, abs_less < int > ( ) );
    for_each ( v1.begin ( ), v1.end ( ), print1 );
   

    // second heap

    cout << "second heap - ascending order:\n\n";
    get_list ( v2, D2 );
    construct_heap ( v2, less < float > ( ) );
    print_list < float, FLT_SZ, FLT_LN > print2 ( v2.size ( ) );
    for_each ( v2.begin ( ), v2.end ( ), print2 );



    cout << "second heap - descending order:\n\n";
    //get_list ( v2, D2 );
    construct_heap ( v2, greater < float > ( ) );
    for_each ( v2.begin ( ), v2.end ( ), print2 );



    cout << "second heap - ascending order with absolute values:\n\n";
    //get_list ( v2, D2 );
    construct_heap ( v2, abs_less < float > ( ) );
    for_each ( v2.begin ( ), v2.end ( ), print2 );


    // third heap

    cout << "third heap - ascending order:\n\n";
    get_list ( v3, D3 );
    construct_heap ( v3, less < string > ( ) );
    print_list < string, STR_SZ, STR_LN > print3 ( v3.size ( ) );
    for_each ( v3.begin ( ), v3.end ( ), print3 );



    cout << "third heap - descending order:\n\n";
    //get_list ( v3, D3 );
    construct_heap ( v3, greater < string > ( ) );
    for_each ( v3.begin ( ), v3.end ( ), print3 );

    // print termination message
    cout << "\t\t\t*** end of program execution ***\n\n";


return 0;
}

//******************************************************************************
// FUNCTION: get_list()
// RETURNS: void
// ARGUMENTS: vector<T> &v, const char *path
// NOTES: path is a path to a file that this function will open for input
// and write into v
//******************************************************************************



template<class T> void get_list(vector<T> &v, const char* path)
{

//for each read from file, we place into temp
T temp;
ifstream in;

//open file
in.open(path);
if(in.fail())

	{

	cerr << "Cannot open file.  Check file permissions.";
	exit(-1);

	}


//read from file
in >> temp;

//while we have stuff to read
while(in)

	{
	//add data to vector
	v.push_back(temp);
	//read from file
	in >> temp;

	}	


}


//******************************************************************************
// FUNCTION: construct_heap()
// RETURNS: void
// ARGUMENTS: vector<T> &v, P pred
// NOTES: pred is a predicate function which we use when we want to make v a heap data
// structure with make_heap(), and for sorting the heap as well with a sort() call
//******************************************************************************


template < class T, class P > void construct_heap ( vector < T >& v, P pred )
{

make_heap(v.begin(), v.end(), pred);
sort_heap(v.begin(), v.end(), pred);

}

//******************************************************************************
// FUNCTION: abs_less<T>::operator()()
// RETURNS:  bool
// ARGUMENTS: const T&x, const T&y
// NOTES: simply returns if the absolute value of x is less than the absolute value of y.
// Is the overloaded function operator for abs_less class
//******************************************************************************

template<class T> bool abs_less<T>::operator()(const T& x, const T& y) const
{

return abs(x) < abs(y);

}

//******************************************************************************
// FUNCTION: print_list()
// RETURNS:  void
// ARGUMENTS: const int &s, const int &c
// NOTES: The constructor for print_list class
//
//******************************************************************************


template<class T, const int W, const int L> print_list<T, W, L>::print_list(const int &s, const int &c):sz(s), cnt(c){}


//******************************************************************************
// FUNCTION: print_list::operator()
// RETURNS: void
// ARGUMENTS: const T&x
// NOTES: Is the overloaded function operator for print_list class.  Used to print 
// passed-in data.  Prints a newline after we have printed L items.
//******************************************************************************


template< class T, const int  W, const int L> void print_list<T,W,L>::operator()(const T&x)
{

cout.precision(2);
cout.setf(ios::fixed, ios::floatfield|ios::showpoint);
cout << ' ' << setw(W) << x;
cnt++;
if(cnt % L == 0|| cnt == sz) cout << endl; 
if(cnt == sz) cout << endl;
}






