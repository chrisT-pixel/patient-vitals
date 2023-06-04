#include "APPatientAlertLevelsStrategy.h"

AlertLevel APPatientAlertLevelsStrategy::calculateAlertLevels(const Patient& patient, const Vitals* v) const {

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
