#include "TSSPatientAlertLevelsStrategy.h"

AlertLevel TSSPatientAlertLevelsStrategy::calculateAlertLevels(const Patient& patient, const Vitals* v) {

	if (v->RR() > 50 && patient.age() > 30) {
		return AlertLevel::Red;
	}
	else if (v->RR() > 50 && patient.age() < 12 && v->HR() > 100) {
		return AlertLevel::Red;
	}
	else if (v->RR() > 30 && patient.age() > 40) {
		return AlertLevel::Yellow;
	}
	else if (v->RR() > 30 && patient.age() < 12 && v->HR() > 100) {
		return AlertLevel::Yellow;
	}
	else {
		return AlertLevel::Green;
	}

}