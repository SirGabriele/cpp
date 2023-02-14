/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:49:18 by kbrousse          #+#    #+#             */
/*   Updated: 2023/02/14 11:32:55 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

static void	replace_strings(char *s1, char *s2, std::ifstream &infile, std::ofstream &outfile)
{
	std::string	toSearch;
	std::string	toReplace;
	std::string	finalBuffer;
	std::string	tempBuffer;
	size_t		i;

	toSearch = s1;
	toReplace = s2;
	std::getline(infile, finalBuffer);
	finalBuffer += "\n";
	while (std::getline(infile, tempBuffer))
	{
		finalBuffer += tempBuffer;
		if (infile.eof() == false)
			finalBuffer += "\n";
	}
	i = 0;
	while (((i = finalBuffer.find(toSearch)) != std::string::npos)
		&& toSearch != toReplace && toSearch.length() != 0)
	{
		finalBuffer.erase(i, toSearch.length());
		finalBuffer.insert(i, toReplace);
	}
	outfile << finalBuffer;
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
