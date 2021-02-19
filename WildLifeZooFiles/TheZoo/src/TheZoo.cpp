//=================================================================================
// Name        : Clint Monroe
// Date        : 19 February 2021
// Program     : Wildlife Zoo RFID Tracking (WIP, Proof of Concept)
// Description : Manages animals of multiple types and subtypes, with functions to
//               add, remove, and view entries. Will save data to a comma
//               text file or load a delimited file to a vector. Uses a factory
//               design pattern to reduce repetitive code and manage object
//               creation based on user input.
//=================================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <jni.h>
#include <ctype.h>
#include <vector>
#include <algorithm>
using namespace std;

#include "Animal.h"
#include "AnimalFactory.h"
#include "AnimalType.h"
#include "AnimalTypeMap.h"
#include "Mammal.h"
#include "Oviparous.h"

void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD
{
     JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
     JNIEnv *env;                      // Pointer to native interface
                                                              //================== prepare loading of Java VM ============================
     JavaVMInitArgs vm_args;                        // Initialization arguments
     JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
     options[0].optionString = (char*) "-Djava.class.path=";   // where to find java .class
     vm_args.version = JNI_VERSION_1_6;             // minimum Java version
     vm_args.nOptions = 1;                          // number of options
     vm_args.options = options;
     vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
                                                                          //=============== load and initialize Java VM and JNI interface =============
     jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
     delete options;    // we then no longer need the initialisation options.
     if (rc != JNI_OK) {
            // TO DO: error processing...
            cin.get();
            exit(EXIT_FAILURE);
     }
     //=============== Display JVM version =======================================
     cout << "JVM load succeeded: Version ";
     jint ver = env->GetVersion();
     cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

     jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
     if (cls2 == nullptr) {
            cerr << "ERROR: class not found !";
     }
     else {                                  // if class found, continue
            cout << "Class MyTest found" << endl;
            jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V");  // find method
            if (mid == nullptr)
                   cerr << "ERROR: method void createZooFile() not found !" << endl;
            else {
                   env->CallStaticVoidMethod(cls2, mid);                      // call method
                   cout << endl;
            }
     }


     jvm->DestroyJavaVM();
     cin.get();
}

void AddAnimal(vector<Animal*> &animalList)
{
	string userTrackNum;
	string formattedTrackNum;
	string userAnimalName;
	int    userAnimalSubType;
	int    userNurse;
	int    userEggs;
	char   confirmSelection;

	while(true) {
		try {
			// Prompt user for animal track number
			cout << "Please enter the animal's track number:" << endl;
			cin  >> userTrackNum;

			// Error checking, selection must be within specified range
			if (userTrackNum.length() > 6) {
				throw runtime_error("The track number must be six characters or less.");
			}

			break;
		}
		catch(runtime_error& excpt) {
			cout << excpt.what() << endl;
			continue;
		}
	}

	// Format track number from user input to include leading zeros and a length of six characters
	formattedTrackNum = string(6 - userTrackNum.length(), '0').append(userTrackNum);

	while(true) {
		try {
			// Prompt user for animal name
			cout << "Please enter the name of the animal:" << endl;
			cin  >> userAnimalName;

			// Error checking, selection must be within specified range
			if (userAnimalName.length() > 15) {
				throw runtime_error("The animal's name must be fifteen characters or less.");
			}

			break;
		}
		catch(runtime_error& excpt) {
			cout << excpt.what() << endl;
			continue;
		}
	}

	while(true) {
		try {
			// Prompt user for animal type
			cout << "Please select the type of animal you would like to add:" << endl;
			cout << AnimalSubType::BAT << ") Bat" << endl;
			cout << AnimalSubType::CROCODILE << ") Crocodile" << endl;
			cout << AnimalSubType::GOOSE << ") Goose" << endl;
			cout << AnimalSubType::PELICAN << ") Pelican" << endl;
			cout << AnimalSubType::SEALION << ") SeaLion" << endl;
			cout << AnimalSubType::WHALE << ") Whale" << endl;
			cin  >> userAnimalSubType;

			// Error checking, selection must be within specified range
			if (userAnimalSubType < 1 || userAnimalSubType > 6) {
				throw runtime_error("Invalid selection.");
			}

			break;
		}
		catch(runtime_error& excpt) {
			cout << excpt.what() << endl;
			continue;
		}
	}

	// Create new animal object of correct type/subtype based on user input
	AnimalSubType selectedSubType = AnimalSubType(userAnimalSubType);
	Animal* animal = AnimalFactory::create(selectedSubType, formattedTrackNum, userAnimalName);

	// If animal type is a mammal, prompt user for nursing information
	if (animal->getAnimalType() == MAMMAL) {
		while(true) {
			try {
				cout << "Is the animal nursing? Enter 1 for yes or 0 for no." << endl;
				cin  >> userNurse;

				// Error checking, value outside of accepted range
				if (userNurse < 0 || userNurse > 1) {
					throw runtime_error("Selection must be 1 or 0.");
				}

				break;
			}
			catch(runtime_error& excpt) {
				cout << excpt.what() << endl;
				continue;
			}
		}

		// Cast to mammal object if animal type is mammal
		Mammal* mammal = static_cast<Mammal*>(animal);

		if (mammal != 0) {
			mammal->setNurse(userNurse);
		}

		try {
			// Error checking, identify issue with Mammal subtype
			if (mammal == 0) {
				throw runtime_error("There is an issue with the mammal class you have selected.");
			}
		}
		catch(runtime_error& excpt) {
			cout << excpt.what() << endl;
			cout << "This requires the attention of an administrator, please open a ticket. Closing program...";
		}
	}

	// If animal type is an oviparous, prompt user for number of eggs
	else if (animal->getAnimalType() == OVIPAROUS) {
		while(true) {
			try {
				cout << "Please enter the number of eggs the animal has:" << endl;
				cin  >> userEggs;

				// Error checking, value outside of accepted range
				if (userEggs < 0) {
					throw runtime_error("Cannot have a negative number of eggs.");
				}

				break;
			}
			catch(runtime_error& excpt) {
				cout << excpt.what() << endl;
				continue;
			}
		}

		// Cast to oviparous object if animal type is oviparous
		Oviparous* oviparous = static_cast<Oviparous*>(animal);

		if (oviparous != 0) {
			oviparous->setNumberOfEggs(userEggs);
		}

		try {
			// Error checking, identify issue with Oviparous subtype
			if (oviparous == 0) {
				throw runtime_error("There is an issue with the oviparous class you have selected.");
			}
		}
		catch(runtime_error& excpt) {
			cout << excpt.what() << endl;
			cout << "This requires the attention of an administrator, please open a ticket. Closing program...";
		}
	}

	cout << "Would you like to add " << userAnimalName << " to the database? Enter 'Y' to proceed." << endl;
	cin  >> confirmSelection;

	if (confirmSelection == 'Y' || confirmSelection == 'y') {
		animalList.push_back(animal); // Add animal to vector
	}
	else {
		cout << "Returning to main menu..." << endl << endl;
	}
}

void RemoveAnimal(vector<Animal*> &animalList)
{
	unsigned int i;
	int userInput;
	char userConfirm;

	while(true) {
		try {
			cout << "Animals currently tracked are listed below, please select one for removal: " << endl;

			// Generate short list of animal object in vector
			for (i = 0; i < animalList.size(); ++i) {
				cout << i << ") " << animalList.at(i)->getTrackNum() << " ";
				cout << animalList.at(i)->getName() << " " << mapSubType.at(animalList.at(i)->getAnimalSubType()) << endl;
			}

			cin  >> userInput;

			// Error checking, find user input outside of acceptable range
			if (userInput < 0 || userInput > animalList.size()) {
				throw runtime_error("Invalid selection.");
			}

			break;
		}
		catch(runtime_error& excpt) {
			cout << excpt.what() << endl;
			continue;
		}
	}

	// Message to confirm removal of object
	cout << "Would you like to remove Track Number " << animalList.at(userInput)->getTrackNum();
	cout << ", " << animalList.at(userInput)->getName() << "?" << endl;

	cin  >> userConfirm;

	if (userConfirm == 'y' || userConfirm == 'Y') {
		// Swap position of selected object with object in the last position
		swap(animalList.at(userInput), animalList.back());

		// Resize vector by one to delete object in last position
		animalList.resize(animalList.size() - 1);
	}
	else {
		cout << "Returning to main menu..." << endl << endl;
	}
}

void ListAnimals(vector<Animal*> &animalList) {
	cout << "Track # " << "Name             " << "Type             " << "Sub-Type         " << "Eggs    " << "Nurse" << endl;
	cout << "---------------------------------------------------------------------------" << endl;

	// Output details for each animal in the vector
	for (Animal* animal:animalList) {
		cout << animal->getTrackNum() << "  ";
		cout << left << setw(15) << setfill(' ') << animal->getName() << "  ";
		cout << left << setw(15) << mapType.at(animal->getAnimalType()) << "  ";
		cout << left << setw(15) << mapSubType.at(animal->getAnimalSubType()) << "  ";

		if (animal->getAnimalType() == MAMMAL) {
			// Cast to mammal object if animal type is mammal
			Mammal* mammal = static_cast<Mammal*>(animal);

			if (mammal != 0) {
				cout << "        ";
				cout << mammal->getNurse() << "  " << endl;
			}
		}
		else if (animal->getAnimalType() == OVIPAROUS) {
			// Cast to oviparous object if animal type is oviparous
			Oviparous* oviparous = static_cast<Oviparous*>(animal);

			if (oviparous != 0) {
				cout << oviparous->getNumberOfEggs() << endl;
			}
		}
	}
}

void LoadDataFromFile(vector<Animal*> &animalList)
{
	ifstream inFS; // Input file stream
	int fileNum;   // File data

	inFS.open("zoodata.txt"); // Open file

	// Error message if file cannot be opened
	if (!inFS.is_open()) {
		cout << "Could not open file myfile.txt." << endl;
	}

	// TODO - Complete function to read file and add objects to vector

	cout << "Load complete. Returning to menu..." << endl << endl;
	inFS.close(); // Close file
}

void SaveDataToFile(vector<Animal*> &animalList)
{
	ofstream outFS; // Output file stream

	outFS.open("zoodata.txt"); // Open file

	// Error message if file cannot be opened
	if (!outFS.is_open()) {
		cout << "Could not open file zoodata.txt." << endl;
	}

	// Output animal info from vector to text file, semicolon added as delimiter
	for (Animal* animal:animalList) {
		outFS << animal->getTrackNum() << ";";
		outFS << animal->getName() << ";";
		outFS << mapType.at(animal->getAnimalType()) << ";";
		outFS << mapSubType.at(animal->getAnimalSubType()) << ";";

		if (animal->getAnimalType() == MAMMAL) {
			// Cast to mammal object if animal type is mammal
			Mammal* mammal = static_cast<Mammal*>(animal);

			if (mammal != 0) {
				outFS << mammal->getNurse() << endl;
			}
		}
		else if (animal->getAnimalType() == OVIPAROUS) {
			// Cast to oviparous object if animal type is oviparous
			Oviparous* oviparous = static_cast<Oviparous*>(animal);

			if (oviparous != 0) {
				outFS << oviparous->getNumberOfEggs() << endl;
			}
		}
	}

	cout << "Save complete. Returning to menu..." << endl << endl;
	outFS.close(); // Close file
}

char GetAction(string prompt) {
	string answer;
	char   firstChar;

	cout << endl << prompt << endl;
	getline(cin, answer);
	while(answer.size() == 0) {
		getline(cin, answer);
	}
	firstChar = toupper(answer[0]);

	return firstChar;
}

int main()
{
	const char EXIT_CODE = 'X';
	const string PROMPT_ACTION = "Welcome to Wildlife Zoo's RFID tracker.\n"
			"Please select an option below or 'X' to quit.\n\n"
			"(L)oad Animal Data\n"
			"(G)enerate Data\n"
			"(D)isplay Animal Data\n"
			"(A)dd a Record\n"
			"(R)emove a Record\n"
			"(S)ave Animal Data\n";

	vector<Animal*> animalList;

	char userAction;

	userAction = '?';

	userAction = GetAction(PROMPT_ACTION);

	while (userAction != EXIT_CODE) {
		switch(userAction) {
		case 'L':
			// LoadDataFromFile();
			// TODO - Enable menu feature once function is complete
			break;
		case 'G':
			GenerateData();
			break;
		case 'D':
			ListAnimals(animalList);
			break;
		case 'A':
			AddAnimal(animalList);
			break;
		case 'R':
			RemoveAnimal(animalList);
			break;
		case 'S':
			SaveDataToFile(animalList);
			break;
		default:
			cout << "Invalid selection, please try again." << endl;
			break;
		}

		userAction = GetAction(PROMPT_ACTION);
	}

	return 1;
}
