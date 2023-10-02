#include "generateur_csv.hpp"

CsvGenerateur::CsvGenerateur()
{
	M_NOMBRE_ELEVE = 200;
	m_matiere_spe.SetSecurity(false);
	m_matiere_spe.Add("Francais");
	m_matiere_spe.Add("Anglais");
	m_prenom.SetSecurity(false);
	m_prenom.Add("Alice");
	m_prenom.Add("Antoine");
	m_nom.SetSecurity(false);
	m_nom.Add("Dupont");
	m_nom.Add("Ducon");
	m_id_eleve = 0;

	M_NOMBRE_NOM = m_nom.GetNbElem();
	M_NOMBRE_PRENOM = m_prenom.GetNbElem();
	M_NOMBRE_MATIERE_SPE = m_matiere_spe.GetNbElem();
}

CsvGenerateur::~CsvGenerateur()
{
}

//std::string* PRENOM_TEMP[26] = { "Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Hannah", "Ivy", "Jack",
//"Katherine", "Liam", "Mia", "Noah", "Olivia", "Peter", "Quinn", "Rachel", "Samuel", "Taylor",
//"Ursula", "Victor", "Wendy", "Xavier", "Yasmine", "Zane" };


//std::array <std::string,29> const NOM = {"Dupont", "Martin", "Dubois", "Bernard", "Thomas", "Robert", "Richard", "Petit", "Durand", "Leroy",
//"Moreau", "Simon", "Laurent", "Lefebvre", "Michel", "Garcia", "David", "Roux", "Bonnet", "Fournier",
//"Lopez", "Legrand", "Martinez", "Ferreira", "Fernandez", "Blanc", "Andr�", "Leroux", "Rousseau" };
//
//std::vector <std::string> MATIERE_SPE = { "Francais", "Histoire" "Geo", "EMC", "EPS", "SPC", "SVT", "Maths", "NSI", "Philo",
//"Anglais", "Espagnole", "Allemand", "Italien", "Russe" };


void CsvGenerateur::creerCsv()
{
	std::ofstream myfile;
	myfile.open("eleve.csv");

	// Premi�re ligne du csv avec les diff�rentes cat�gories
	myfile << "ID;" << " PRENOM;" << "NOM;" << "Annee;";
	for (int i = 1; i < 11; i++)
	{
		myfile << "MATIERE OPTIONNELLE" << i << ";";
	};
	myfile << "\n";

	// Autres lignes du csv
	for (int i = 0; i < M_NOMBRE_ELEVE; i++)
	{
		myfile << m_id_eleve << ";";
		m_id_eleve++;
		myfile << m_prenom.Get(rand() % M_NOMBRE_PRENOM) << ";";
		myfile << m_nom.Get(rand() % M_NOMBRE_NOM) << ";";
		myfile << rand() % 3 + 1 << ";";

		NOMBRE_MATIERE_SPE = rand() % m_matiere_spe.GetNbElem();
		m_matiere_restante = m_matiere_spe;
		for (int e = 0; e < NOMBRE_MATIERE_SPE; e++)

		{
			int RANDOM_MATIERE = rand() % 5;
			myfile << m_matiere_restante.Pop(e) << ";";
		};
		myfile << "\n";
	}
	myfile.close();
}
