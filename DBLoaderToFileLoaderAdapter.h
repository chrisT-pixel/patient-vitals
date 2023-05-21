#pragma once

#include "AbstractPatientDatabaseLoader.h"
//#include "PatientFileLoader.h"

// forward declare the patientFileLoader class
class PatientFileLoader;

class DBLoaderToFileLoaderAdapter : public AbstractPatientDatabaseLoader{
public:

	// Inherited via AbstractPatientDatabaseLoader
	virtual void initialiseConnection() override;

	virtual void loadPatients(std::vector<Patient*>& patientIn) override;

	virtual void closeConnection() override;

	

private:

	PatientFileLoader* _patientFileLoader;

};

