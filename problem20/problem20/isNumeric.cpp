bool isNumeric(char* str)
{
	bool sign = false, decimal = false, hasE = false;

	for (char* s = str; *s != '\0'; ++s)
	{
		if (*s == 'e' || *s == 'E')
		{
			//e只能出现一次，且e之后必须有数字
			if (hasE || *s == '\0')
				return false;
			hasE = true;
		}
		else if (*s == '+' || *s == '-')
		{
			//正负号只能在开头或者e之后出现，别无其它可能
			if (s == str)
				sign = true;
			else if (*(s - 1) != 'e' && *(s - 1) != 'E')
				return false;
		}
		else if (*s == '.')
		{
			//只能有一个小数点且e之后不能有小数点
			if (hasE || decimal)
				return false;
			decimal = true;
		}
		else if (*s <'0' || *s >'9')
			return false;
	}
	return true;
}