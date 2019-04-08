#include <iostream>
using std::cout;
using std::endl;

void replace_blank(char* s) {
	char *p = s;
	char* q = s;

	while (*p != '\0')
		q += (*p++ != ' ') ? 1 : 3;
	
	while (p != q)
	{
		if (*p != ' ')
			*q-- = *p--;
		else
		{
			*q-- = '0';
			*q-- = '2';
			*q-- = '%';
			p--;
		}
	}
}


int main()
{
	char str[100] = "are you okay? hello thank you, thank you very much";
	replace_blank(str);
	cout << str << endl;
	return 0;
}