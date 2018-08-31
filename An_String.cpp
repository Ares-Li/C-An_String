#include "An_String"


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


