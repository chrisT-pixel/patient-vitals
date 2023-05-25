#pragma once
#include "IPatientAlertLevelsStrategy.h"
#include "Patient.h"

class APPatientAlertLevelsStrategy : public IPatientAlertLevelsStrategy{
public:

	AlertLevel calculateAlertLevels(const Patient& patient, const Vitals* v) {
		
		std::cout << "calculating alert levels for Amoria Phelebitis \n";
		
		if (patient.age() < 12 && v->BP() < 30) {
			return AlertLevel::Red;
		}
		else if (patient.age() >= 12 && v->BP() < 50) {
			return AlertLevel::Red;
		}
		else {
			return AlertLevel::Green;
		}

	}

};

