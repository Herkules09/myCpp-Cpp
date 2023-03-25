#include "Header.h"
#include "Search.h"

Search::Search(){}
Search::~Search(){}

void Search::display_search() {
	while (Search::option != 1) {
		system("CLS");
		cout << "-----JAKA CZYNNOSC CHCESZ WYKONAC-----" << endl;
		cout << endl << "1 - WYSZUKIWANIE BUDYNKOW Z BAZY DANYCH " << endl;
		cout << "2 - DODAWANIE BUDYNKOW DO BAZY DANYCH" << endl;
		cout << "3-WYJSCIE" << endl;


		cin >> Search::option;

		switch (option) {
		case 1:
			
			 search_building();
			break;
		case 2:
			 add_building();
		case 3:
			display_end();
		default:
			cout << "Zla opcja"<<endl;
			display_end();
		}
	}
}
	
void Search::add_building() {
	char x;
	cout << "CHCESZ DODAC MIESZKANIE CZY DOM?" << endl;
	cout << "1-MIESZKANIE" << endl;
	cout << "2-DOM" << endl;
	cin >> Search::option;
	switch (option) {
	case 1:
		do {
			ApartmentsBase ab;
			Apartment a ;
			a.setBuilding(a);
			ab.addApartment(a);
			cout <<endl<< "Budynek zostal pomyslnie dodany" << endl;
			cout << "Chcesz dodac jeszcze?(y/n)";
			cin >> x;
		} while (x == 'y');
		
		system("pause");
		display_search();


	case 2:
		do {
			HousesBase hb;
			House h;
			h.setBuilding(h);
			hb.addHouse(h);
			cout << "Budynek zostal pomyslnie dodany" << endl;
			cout <<endl<< "Chcesz dodac jeszcze?(y/n)";
			cin >> x;
		} while (x == 'y');
		
		system("pause");
		display_search();

	
	}
}
void Search::search_building() {
	cout << "JAKIEGO RODZAJU BUDYNKI CHCESZ WYSZUKAC " << endl;
	cout << "1-MIESZKANIA" << endl;
	cout << "2-DOMY " << endl;
	cout << "3-WSZYSTKO" << endl;
	cin >> Search::option;
	cout << endl;


	int x,z;
	string inputString;
	ApartmentsBase ap;
	InfrastructuresList infrastructureL;
	InfrastructuresList infrastructureS;
	Advantages adv;
	HousesBase ho;
	Filters f;

	cout << "CHCESZ ZASTOSOWAC FILTRY?" << endl;
	cout << "1-Tak||2-Nie" << endl;
	cin >> x;
	system("cls");
	if (x == 1) {
		cout << "Minimalna cena : ";
		cin.ignore();
		getline(cin, inputString);
		f.set_min_price(inputString);
		system("cls");
		cout << "Maksymalna cena: ";
		getline(cin, inputString);
		f.set_max_price(inputString);
		system("cls");
		cout << "Minimalna powierzchnia: ";
		getline(cin, inputString);
		f.set_min_area(inputString);
		system("cls");
		cout << "Maksymalna powierzchnia: ";
		getline(cin, inputString);
		f.set_max_area(inputString);
		system("cls");
		cout << "Miasto: ";
		getline(cin, inputString);
		f.set_Fcity(inputString);
		system("cls");
		if (option == 1) {
			cout << "Typ budynku (blok, kamienica, apartamentowiec, loft): ";
		    getline(cin, inputString);
			f.set_Ftype_of_building(inputString);
		    system("cls");
			cout << "Pietro: ";
			getline(cin, inputString);
			f.set_Ffloor(inputString);
			system("cls");
		}if (option == 2) {
			cout << "Typ budynku (wolnostojacy, blizniak, szeregowiec, gospodarstwo, dworek): ";
		    getline(cin, inputString);
			f.set_Ftype_of_building(inputString);
			system("cls");
			cout << "Ogrod (1-tak||2-nie): ";
			getline(cin, inputString);
			f.set_Fgarden(inputString);
			system("cls");
		}
		
		system("cls");
	}
	if (option == 1 || option == 3) {
		vector<Apartment>d = ap.getApartments(f);
		if (ap.getApartments(f).size() == 0) {
			cout << "Brak mieszkan z takimi parametrami " << endl;
			
		}
		for (Apartment s : d) {
			s.showBuilding();
			infrastructureL.add(adv.find_nearest(&s));
			cout << "Najblizszy szpital:" << endl;
		    adv.find_nearest(&s).show_Infrastructure();
			cout << endl << "*****************************************" << endl;
		}
	}
	if (option == 2 || option == 3) {
		vector<House>h = ho.getHouses(f);
		if (ho.getHouses(f).size() == 0) {
			cout << "Brak domow z takimi parametrami " << endl;
			
		}
		for (House g : h) {
			g.showBuilding();
			infrastructureL.add(adv.find_nearest(&g));
			cout << "Najblizszy szpital:" << endl;
			adv.find_nearest(&g).show_Infrastructure();
			cout << endl << "*****************************************" << endl;
		}
		system("pause");
    }
	
}
		
	


	void Search::display_end() {
		system("pause");
		exit(0);
	}


	