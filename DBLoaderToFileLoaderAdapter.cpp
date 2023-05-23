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

    patientIn = _patientFileLoader->loadPatientFile("patients.txt");

}

void DBLoaderToFileLoaderAdapter::closeConnection(){
    // pretend this closes the file
}
