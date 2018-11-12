#include "/home/onyuksel/courses/340/progs/13s/p10/prog10.h"
#include "/home/onyuksel/courses/340/progs/13s/p10/hTable.h"

// Hashing with linear probe and indirect sorting

int main ( )
{
    char c;  // operation code
    Entry e; // holds input data
    HT h;    // hash table

    // print program header message
    cout << "\t*** Hashing with linear probe ***\n\n";

    while ( cin >> c ) {
        switch ( c ) {
            case 'A': // insert record in hash table
                read_rec1 ( e ); prnt_rec1 ( e );
                h.insert ( e ); break;

            case 'S': // search for record in hash table
                read_rec2 ( e );
                cout << "search: key " << e.key;
                h.search ( e.key ); break;

            case 'P': // print all active entries of hash table
                cin.ignore ( BUF_SZ, ':' );
                cout << "\nhTable_print:\n";
                cout << "entry  key    number    description\n";
                h.hTable_print ( ); break;

            default: // illegal command
                cout  << "error: invalid entry\n";
                break;
        }
    }

    // print hash table (in sorted order) 

    cout << "\nsort_print:\n   sorted hash table:\n";
    cout << "   key    number    description\n";
    h.pTable_print ( );

    // print program termination message
    cout << "\n\t*** end of program termination ***\n";
    return 0;
}
