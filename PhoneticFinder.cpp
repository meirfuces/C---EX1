
#include <string>
#include <iostream>
using namespace std;

int count = 0;

char toLowerCase(char c) // convert to lowercase
{
    if(c>=65 && c<= 90) //asci aruthmtic
        return c+32;
    return c;
}

namespace phonetic
{
string find(string text, string word)
{
	string swaps[8] = {"vw", "bfp", "gj", "ckq", "sz", "dt", "ou", "iy"};

	while (text.length() > 0)
	{
		while(text[0]== ' ' || text[0] == '\t')
			text = text.substr(1);
		string temp = "";
		while (text.length()>0 && text[0] != ' ' && text[0]!='\t')
		{
			temp += text[0];
			text = text.substr(1);
		}
		if(temp.length()==word.length())
		{
			string temp_word = word;
			string ans = temp;
			bool equal = true;
			
			while(temp.length()>0 && equal)
			{
				char t = temp[0];
				char w = temp_word[0];
				temp = temp.substr(1);
				temp_word = temp_word.substr(1);
				t = toLowerCase(t);
				w = toLowerCase(w);
				if(t!=w)
				{
					equal = false;
					for(int i=0; i<8; i++)
					{
						if(swaps[i].find(t)!=string::npos && swaps[i].find(w)!=string::npos)
							equal = true;
					}

				}
			}

			if(equal)
			{
				return ans;
			}
		}
	}
	throw runtime_error("Did not find the word in the text");
}
} // namespace phonetic






