#include "PatientFileLoader.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Patient.h"
#include "Vitals.h"
#include "IPatientAlertLevelsStrategy.h"
#include "BEPatientAlertLevelsStrategy.h";
#include "APPatientAlertLevelsStrategy.h";
#include "MZPatientAlertLevelsStrategy.h";
#include "TSSPatientAlertLevelsStrategy.h";
#include "CompositeHighestAlertLevelStrategy.h"
#include "GPNotificationSystemFacade.h"
#include "HospitalAlertSystemFacade.h"

using namespace std;


std::vector<Patient*> PatientFileLoader::loadPatientFile(const std::string& file){

    vector<Patient*> patients{};

    std::ifstream inFile(file);
    if (inFile.is_open()) {
        
        std::string line;

        while (std::getline(inFile, line)) {
            
            // Split the line into different fields using delimiter '|'
            std::istringstream issFile(line);
            std::string id, date, name, diagnosis, vitals;
            
            std::getline(issFile, id, '|');
            std::getline(issFile, date, '|');
            std::getline(issFile, name, '|');
            std::getline(issFile, diagnosis, '|');
            std::getline(issFile, vitals);

            // Process the fields 
            std::tm birthday{};
            std::istringstream dateStream(date);
            dateStream >> std::get_time(&birthday, "%d-%m-%Y");

            //split full name into first and last name
            std::istringstream issName(name);
            std::vector<std::string> firstAndLastName;
            std::string word;
                
            while (std::getline(issName, word, ',')) {
                firstAndLastName.push_back(word);
            }

            std::string firstName;
            std::string lastName;

            // Access the individual words
            if (firstAndLastName.size() == 2) {
                firstName = firstAndLastName[1];
                lastName = firstAndLastName[0];
            }

            //create patient and notification alerts 
            Patient* patient = new Patient(firstName, lastName, birthday);
            GPNotificationSystemFacade* gpNotify = new GPNotificationSystemFacade();
            HospitalAlertSystemFacade* hospitalNotify = new HospitalAlertSystemFacade();

            if (vitals == "") {
                //do nothing
            }

            //more than one vitals so break up into seperate vital enteries
            else if (vitals.find(';') != std::string::npos) {
            
                std::istringstream issVitals(vitals);
                std::vector<std::string> vitalsMultiple;
                std::string vit;

                std::string vitSin;

                //seperate vital measurments and put in a vector
                while (std::getline(issVitals, vit, ';')) {
                    vitalsMultiple.push_back(vit);
                }

                //loop through vector of all measurments and split them up
                for (const std::string& vitSin : vitalsMultiple) {
                    //put individual vitals in a vector
                    std::istringstream issSingleVitals(vitSin);
                    std::string token;
                    std::vector<std::string> vitalsSingle;
                    while (std::getline(issSingleVitals, token, ',')) {
                        vitalsSingle.push_back(token);
                    }

                    //convert to float and ints
                    float btFloat = std::stof(vitalsSingle[0]);
                    int bpInt = std::stoi(vitalsSingle[1]);
                    int hrInt = std::stoi(vitalsSingle[2]);
                    int rrInt = std::stoi(vitalsSingle[3]);

                    //create vital objects and add to patient 
                    Vitals* v = new Vitals(btFloat, bpInt, hrInt, rrInt, true);
                    patient->addVitals(v);
                }

            }

            else {

                std::istringstream issSingleVitals(vitals);
                std::vector<std::string> vitalsSingle;
                std::string vitSin;

                //put individual vitals in a vector
                while (std::getline(issSingleVitals, vitSin, ',')) {
                    vitalsSingle.push_back(vitSin);
                }
                
                //convert to float and ints
                float btFloat = std::stof(vitalsSingle[0]);
                int bpInt = std::stoi(vitalsSingle[1]);
                int hrInt = std::stoi(vitalsSingle[2]);
                int rrInt = std::stoi(vitalsSingle[3]);

                //create vital object and add to patient 
                Vitals* v = new Vitals(btFloat, bpInt, hrInt, rrInt, true);
                patient->addVitals(v);
               
            
            }

            std::string assignedDiagnosis;
            bool multipleDiagnosisFlag = false;

            // Assign the diagnosis based on the input
            if (diagnosis == Diagnosis::BONUS_ERUPTUS) {
                assignedDiagnosis = Diagnosis::BONUS_ERUPTUS;
                patient->setPatientAlertLevelsStrategy(new BEPatientAlertLevelsStrategy());
            }
            else if (diagnosis == Diagnosis::AMORIA_PHLEBITIS) {
                assignedDiagnosis = Diagnosis::AMORIA_PHLEBITIS;
                patient->setPatientAlertLevelsStrategy(new APPatientAlertLevelsStrategy());
            }
            else if (diagnosis == Diagnosis::MAD_ZOMBIE_DISEASE) {
                assignedDiagnosis = Diagnosis::MAD_ZOMBIE_DISEASE;
                patient->setPatientAlertLevelsStrategy(new MZPatientAlertLevelsStrategy());
            }
            else if (diagnosis == Diagnosis::THREE_STOOGES_SYNDROME) {
                assignedDiagnosis = Diagnosis::THREE_STOOGES_SYNDROME;
                patient->setPatientAlertLevelsStrategy(new TSSPatientAlertLevelsStrategy());
            }
            //patient has more than 1 diagnosis, need to split up the strings 
            else {
                multipleDiagnosisFlag = true;
                std::istringstream issDiagnosis(diagnosis);
                std::vector<std::string> diagnosisMultiple;
                std::string dia;

                auto highest = new CompositeHighestAlertLevelStrategy();

                //put seperate diagnosis' in a vector
                while (std::getline(issDiagnosis, dia, ',')) {
                    diagnosisMultiple.push_back(dia);
                }

                //loop through vector and add to patient
                for (const std::string& diag : diagnosisMultiple) {
                    
                    patient->addDiagnosis(diag);

                    if (diag == Diagnosis::BONUS_ERUPTUS) {
                        highest->addStrategy(new BEPatientAlertLevelsStrategy());
                    }
                    else if (diag == Diagnosis::AMORIA_PHLEBITIS) {
                        highest->addStrategy(new APPatientAlertLevelsStrategy());
                    }
                    else if (diag == Diagnosis::MAD_ZOMBIE_DISEASE) {
                        highest->addStrategy(new MZPatientAlertLevelsStrategy());
                    }
                    else if (diag == Diagnosis::THREE_STOOGES_SYNDROME) {
                        highest->addStrategy(new TSSPatientAlertLevelsStrategy());
                    }

                }

                //finalise all required patient info for patients with multiple diagnosis'
                //and add to patients vector
                patient->setPatientAlertLevelsStrategy(highest);
                patient->addPatientSubscriber(hospitalNotify);
                patient->addPatientSubscriber(gpNotify);
                patients.push_back(patient);
               
            }

            //finalise all required patient info for patients with single diagnosis
            //and add to patients vector
            if (!multipleDiagnosisFlag) {
               
                patient->addDiagnosis(assignedDiagnosis);
                patient->addPatientSubscriber(hospitalNotify);
                patient->addPatientSubscriber(gpNotify);
                patients.push_back(patient);
            }
            
        }
    }

    //close connection to the file
    inFile.close();

    return patients;

}


