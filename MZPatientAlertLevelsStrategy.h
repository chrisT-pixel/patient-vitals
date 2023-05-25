#pragma once
#include "IPatientAlertLevelsStrategy.h"


class MZPatientAlertLevelsStrategy : public IPatientAlertLevelsStrategy{
public:

	AlertLevel calculateAlertLevels(const Patient& patient, const Vitals* v) {
		
		std::cout << "calculating alert levels for Mad Zombie \n";
		
		if (v->HR() > 130) {
			return AlertLevel::Red;
		}
		else if (v->HR() > 120) {
			return AlertLevel::Orange;
		}

		else if (v->HR() > 100) {
			return AlertLevel::Yellow;
		}
		else {
			return AlertLevel::Green;
		}

	}

};

