#ifndef DEF_ELEVE
#define DEF_ELEVE

#include <string>

class Eleve
{
	public:
		int m_taille_tableau;
		std::string m_nom;
		std::string m_prenom;
		std::string m_niveau;
		std::string* m_matieres;

		Eleve(int taille_tableau);

		~Eleve();
};

#endif