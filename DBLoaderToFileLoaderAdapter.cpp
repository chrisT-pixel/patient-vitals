#include "DBLoaderToFileLoaderAdapter.h"
#include "PatientFileLoader.h"

#include <iomanip>
#include <sstream>
#include <iostream>

#include "Patient.h"
#include "Vitals.h"

void DBLoaderToFileLoaderAdapter::initialiseConnection(){
    // not used in this adapter
}

void DBLoaderToFileLoaderAdapter::loadPatients(std::vector<Patient*>& patientIn) {

    patientIn = _patientFileLoader->loadPatientFile("patients.txt");

}

void DBLoaderToFileLoaderAdapter::closeConnection(){
    // not used in this adapter
}
