#include "/home/onyuksel/courses/340/common/340.h"

using namespace std;

int main()
{

return 0;
}

template<class T> void get_list(vector<T> &v, const char* path)
{

T temp;
ifstream in;
in.open(path);
if(in.fail())

	{

	cerr << "Cannot open file.  Check file permissions.";
	exit(-1);

	}

in.read((char*)&temp, sizeof(T));

while(in)

	{

	v.push_back(temp);

	in.read((char*)&temp, sizeof(T));

	}	

in.close();

}

template<class T, class P> void construct_heap(vector<T> &v, P pred)
{

make_heap(v.begin(), v.end(), pred);
sort_heap(v.begin(), v.end(), pred);

}

template<class T> bool abs_less<T>::operator()(const T&x, const T&y) const
{


}
