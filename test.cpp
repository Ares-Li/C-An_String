#include "An_String"
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	An_String str;
	str = "hello";
	str = An_String("123") + "he!"; 
	cout<<str<<endl;
	cout<<str.size()<<endl;
	cout<<str.empty()<<endl;

	const An_String cStr("hello");
	str = cStr + "he";
	cout<<str<<endl;

//	cout<<strlen(stdin)<<endl;

	return 0;
}
