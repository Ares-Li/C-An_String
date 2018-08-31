#include <iostream>
#include <cstring>
using namespace std;

class An_String
{
private:
	char* buff;
	
public:
	An_String();
	An_String(const char*);
	An_String(const An_String& str);
	~An_String();
	
	int size() const;
	bool empty() const;

	void clear();
	void append(const char* str);
	void insert(int index,const char* str);
	void replace(const char* oldstr,const char* newstr);
	void remove(const char* str);
	const char* c_str() const;
	int to_int() const;
	float to_float() const;

	An_String operator+(const An_String& str) const;
	An_String& operator=(const An_String& str);
	char operator[](int index);
	bool operator==(const An_String& str);
	bool operator!=(const An_String& str);
	bool operator>(const An_String& str);
	//operator  int();
	operator float();

	friend istream& operator>>(istream& in,const An_String& str);
	friend ostream& operator<<(ostream& out,const An_String& str);
};

An_String::An_String()
{
	//buff = NULL;
	buff = new char[1];
	buff[0] = '\0';
}

An_String::An_String(const char* str)
{
	buff = new char[strlen(str)+1];
	strcpy(buff,str);
}

An_String::An_String(const An_String& str)
{
	buff = new char[strlen(str.buff)+1];
	strcpy(buff,str.buff);
}
	
An_String::~An_String()
{
	delete []buff;
}

int An_String::size() const
{
	return strlen(buff);
}

bool An_String::empty() const
{
	return (buff[0] == '\0');
}

void An_String::clear()
{
	buff[0] = '\0';
}

An_String& An_String::operator=(const An_String& str)
{
	delete []buff;
	buff = new char[strlen(str.buff)+1];
	strcpy(buff,str.buff);
	return *this;
}

An_String An_String::operator+(const An_String& str) const
{
	An_String tmp;
	delete tmp.buff;
	tmp.buff = new char[strlen(str.buff)+1];
	strcpy(tmp.buff,this->buff);
	strcat(tmp.buff,str.buff);
	return tmp;
}

ostream& operator<<(ostream& out,const An_String& str)
{
	out<<str.buff;
	return out;
}


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
