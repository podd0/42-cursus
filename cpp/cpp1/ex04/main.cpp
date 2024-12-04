#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

std::string read_file(std::ifstream& in)
{
	std::string text;
	while (!in.eof())
	{
		std::string temp;
		std::getline(in, temp);
		if (!in.eof())
			text += temp + '\n';
	}
	in.close();
	return text;
}

void sub_and_print(std::string pattern, std::string replace, std::string text, std::ostream &out)
{
	int i = 0;
	while(i + pattern.size() <= text.size())
	{
		if (text.substr(i, pattern.size()) == pattern)
		{
			out << replace;
			i += pattern.size();
		}
		else
		{
			out << text[i];
			i++;
		}
	}
	out << text.substr(i);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage : "<<argv[0]<<" FILENAME PATTERN REPLACE\n";
		return 1;
	}
	std::string filename = argv[1];
	std::string pattern = argv[2];
	std::string replace = argv[3];

	std::ifstream in(filename.c_str());
	if (!in.good())
	{
		std::cerr << filename << ": " << strerror(errno) << "\n";
		return 1;
	}

	std::string text = read_file(in);
	std::ofstream out((filename + ".replace").c_str());
	sub_and_print(pattern, replace, text, out);
	out.close();
}
