#include "MZPatientAlertLevelsStrategy.h"

AlertLevel MZPatientAlertLevelsStrategy::calculateAlertLevels(const Patient& patient, const Vitals* v) const {

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

