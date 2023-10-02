#include "fichier.hpp"

Fichier::Fichier()
	: m_name("empty.csv"),
	m_nb_ligne(0)
{

}

Fichier::Fichier(std::string nom_fichier)
	: m_name(nom_fichier),
	m_nb_ligne(-1)
{

}

Fichier::Fichier(std::string nom_fichier, int nb_ligne)
	: m_name(nom_fichier),
	m_nb_ligne(nb_ligne)
{

}

Fichier::~Fichier()
{

}

int Fichier::GetNbLigne() const
{
	return m_nb_ligne;
}

std::string Fichier::GetNom() const
{
	return m_name;
}

TabDynString Fichier::Split(std::string nom_fichier, char split, char end)
{
	std::ifstream myfile;
	TabDynString data;
	myfile.open(nom_fichier);
	std::string ligne;
	std::string peche = "";
	while (true)
	{
		std::getline(myfile, ligne);
		for (char character : ligne)
		{
			if (character == end)
			{
				data.Add(peche);
				std::cout << peche << std::endl;
				return data;
			}

			if (character == split)
			{
				data.Add(peche);
				std::cout << peche << std::endl;
				peche = "";
			}

			else
			{
				peche += character;
			}
		}
	}
	return data;
}

std::string Fichier::GetTexte() const
{
	std::ifstream myfile;
	if (myfile)
	{
		myfile.open(m_name);
		std::string data = "";
		std::string ligne = "";

		if (m_nb_ligne <= 0)
		{
			std::ifstream myfiletest;
			{
				myfiletest.open(m_name);
				std::string lignetest;
				std::getline(myfile, lignetest);

				while (ligne != lignetest)
				{
					std::getline(myfile, ligne);
					for (char carac : ligne)
					{
						data += carac;
					}
					data += "\n";
					std::getline(myfiletest, lignetest);
				}
			}
		}

		else
		{

			for (unsigned int i = 0; i < m_nb_ligne; i++)
			{
				std::getline(myfile, ligne);
				for (char carac : ligne)
				{
					data += carac;
				}
				data += "\n";
			}
		}

		std::cout << data;
		return(data);
	}

	else
	{
		std::cerr << "OPENERROR : impossible d'ouvrir le fichier selectionné";
		return "";
	}
}