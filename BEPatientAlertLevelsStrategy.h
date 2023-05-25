#pragma once
#include "IPatientAlertLevelsStrategy.h"

class BEPatientAlertLevelsStrategy : public IPatientAlertLevelsStrategy{
public:

	AlertLevel calculateAlertLevels(const Patient& patient, const Vitals* v) {
		
		std::cout << "calculating alert levels for Bonus Eruptus \n";
		
		if (v->RR() > 50) {
			return AlertLevel::Red;
		}
		else if (v->RR() > 30) {
			return AlertLevel::Orange;
		}
		else if (v->RR() > 20) {
			return AlertLevel::Yellow;
		}
		else {
			return AlertLevel::Green;
		}


	}


};


