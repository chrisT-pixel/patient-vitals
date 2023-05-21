#include "DBLoaderToFileLoaderAdapter.h"
#include "PatientFileLoader.h"

#include <iomanip>
#include <sstream>
#include <iostream>

#include "Patient.h"
#include "Vitals.h"

void DBLoaderToFileLoaderAdapter::initialiseConnection(){
    // pretend this opens a file
}

void DBLoaderToFileLoaderAdapter::loadPatients(std::vector<Patient*>& patientIn) {

    _patientFileLoader->loadPatientFile("patients.txt");

    // we simulate loading patients from a database here.

    // initialise a birthday from a string. This code can be reused to when loading a birthday from a file
    /*std::tm t{};
    std::istringstream ss("18-02-1980");
    ss >> std::get_time(&t, "%d-%m-%Y");

    // push back a new Patient
    Patient* p = new Patient("Joe", "Bloggs", t);
    p->addDiagnosis(Diagnosis::BONUS_ERUPTUS);
    p->addDiagnosis(Diagnosis::MAD_ZOMBIE_DISEASE);

    Vitals* v = new Vitals(37.5f, 80, 60, 16);
    p->addVitals(v);

    patientIn.push_back(p);*/

}

void DBLoaderToFileLoaderAdapter::closeConnection(){
    // pretend this closes the file
}
