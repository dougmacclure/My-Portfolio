#include "/home/onyuksel/courses/340/progs/13s/p10/prog10.h"

using namespace std;

// routine to get record from stdin
void read_rec1 ( Entry& e )
{
    char buf1 [ BUF_SZ + 1 ];

    cin.ignore ( BUF_SZ, ':' );
    cin.get ( buf1, ID_SZ + 1, ':' ); cin.ignore ( BUF_SZ, ':' );
    e.key = string ( buf1 ); cin >> e.num; cin.ignore ( BUF_SZ, ':' );
    cin.get ( buf1, ITEM_SZ + 1, ':' ); cin.ignore ( BUF_SZ, ':' ); cin.ignore (BUF_SZ, '\n');
    e.desc = string ( buf1 );
}

// routine to get record from hash table
void read_rec2 ( Entry& e )
{
    char buf2 [ BUF_SZ + 1 ];

    cin.ignore ( BUF_SZ, ':' );
    cin.get ( buf2, ID_SZ + 1, ':' ); cin.ignore ( BUF_SZ, ':' );
    e.key = string ( buf2 );
}

// routine to print record from stdin on stdout
void prnt_rec1 ( const Entry& e )
{
    cout << "insert: :" << e.key << ':';
    cout.flags ( ios :: right );
    cout << setw ( ID_SZ + 1 ) << e.num << ':';
    cout.flags ( ios :: left );
    cout << setw ( ITEM_SZ ) << e.desc.c_str ( ) << ':';
    cout.flags ( ios :: right);
}
