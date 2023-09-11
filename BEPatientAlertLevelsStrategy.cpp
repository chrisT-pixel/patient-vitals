#include "BEPatientAlertLevelsStrategy.h"

AlertLevel BEPatientAlertLevelsStrategy::calculateAlertLevels(const Patient& patient, const Vitals* v) const {

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
