/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:49:18 by kbrousse          #+#    #+#             */
/*   Updated: 2023/02/13 11:54:14 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

static void	replace_strings(char *s1, char *s2, std::ifstream &infile, std::ofstream &outfile)
{
	std::string	toSearch;
	std::string	toReplace;
	std::string	buffer;
	size_t		pos;

	toSearch = s1;
	toReplace = s2;
	do
	{
		std::getline(infile, buffer);
		if ((pos = buffer.find(toSearch)) && pos == std::string::npos)
			outfile << buffer;
		else
		{
			outfile << buffer.substr(0, pos);
			outfile << toReplace;
			outfile << buffer.substr(pos + toSearch.length(), buffer.length());
		}
		if (infile.peek() != EOF)
			outfile << std::endl;
	} while (infile.eof() == false);
	infile.close();
	outfile.close();
}

int	main(int argc, char **argv)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		tempFile;

	if (argc != 4)
	{
		std::cerr << "Correct usage is: ./loser <filename> <string1> <string2>" << std::endl;
		return (0);
	}
	tempFile = argv[1];
	tempFile += ".replace";
	infile.open(argv[1]);
	outfile.open(tempFile.c_str());
	if (infile.good() == false || outfile.good() == false)
	{
		std::cout << "Error while opening " << argv[1] << " or its .replace equivalent" << std::endl;
		infile.close();
		outfile.close();
		return (1);
	}
	replace_strings(argv[2], argv[3], infile, outfile);
	return (0);
}
