class Str{
public:
	int length(char* str) {
		int n = 0;
		while(str[n])
			n++;
		return n;
	}

	void push_front(char* str, char* v) {
		int v_len = length(v);
		int str_len = length(str);
		char* p = new char[str_len + v_len + 1];

		for (int i = 0; i < v_len; i++)
			p[i] = v[i];
		for(int i = 0; i < str_len; i++)
			p[v_len + i] = str[i];
		p[str_len + v_len] = 0;
		str = p;
	}

	void pop_front(char* str) {
		int str_len = length(str);
		for(int i = 0; i < str_len; i++)
			str[i] = str[i+1];
	}

	void push_back(char* str, char* v) {
		int str_len = length(str);
		int v_len = length(v);
		char* p = new char[str_len + v_len + 1];

		for(int i = 0; i < str_len; i++) 
			p[i] = str[i];
		for(int i = 0; i < v_len; i++)
			p[str_len + i] = v[i];

		str = p;
	}

	void pop_back(char* str) {
		int str_len = length(str);
		str[str_len-1] = 0;
	}

	char* at(char* str, int i) {
		int str_len = length(str);
		if (i >= 0 && i < str_len)
			return &str[i];
	}

	int size(char* str) {
		return length(str);
	}

};