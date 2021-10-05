#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <sys/errno.h>

static int	compare_strings(std::string& s1, std::string& filestr, std::string::iterator &it) {

	size_t	start = std::distance(filestr.begin(), it);
	size_t	end = s1.length();

	if (!filestr.compare(start, end, s1, 0, end))
		return 0;
	else
		return 1;

}

int main(int ac, char **av)
{

	// Error control at start:
	// I accept s2 to be empty (""), but not s1. It wouldn't make any sense to search
	// for a null string inside a file. But it does make sense to replace a string
	// with nothing (delete any occurrence of s1 in filename).
	if (ac != 4) {
		std::cerr << "Wrong number of arguments. The order is filename, s1, s2." << std::endl;
		exit (1);
	}
	if (!*av[1] || !*av[2]) {
		std::cerr << "filename or s1 cannot be empty." << std::endl;
		exit(1);
	}

	std::string	s1 = av[2];
	std::string	s2 = av[3];
	std::string	filename = av[1];

	// open the filename to input stream.
	std::ifstream ifs;

	ifs.open(filename, std::ifstream::in);
	if (ifs.fail()) {
		std::cerr << "Error: " << filename.append(": ") << strerror(errno) << std::endl;
		exit(1);
	}

	// putting all of the text inside a stringstream buffer.
	std::stringstream buffer;
	buffer << ifs.rdbuf();

	// declaring a std string as what the buffer contains (to be extracted
	// with the getter .str() from stringstream).
	std::string	filestr = buffer.str();

	//Now witth the main purpose of the exercise: 

	//open the filename.result to output stream.
	std::ofstream ofs;

	ofs.open(filename.append(".replace"), std::ofstream::out);
	if (ofs.fail()) {
		std::cerr << "Error: " << filename.append(": ") << strerror(errno) << std::endl;
		exit(1);
	}

	// Explanation from a human will be carried out in this part. Hopefully this human is me.
	std::string::iterator it = filestr.begin();
	int	do_increment = 1;

	while (it != filestr.end()) {
		do_increment = 1;
		if (*it == s1[0]) {	
			if (!compare_strings(s1, filestr, it)) {
				ofs << s2;
				it += s1.length();
				do_increment = 0;
			}
		}	
		if (do_increment)
		{
			ofs << *it;
			it++;
		}
		do_increment = 1;
	}
	return 0;
}
