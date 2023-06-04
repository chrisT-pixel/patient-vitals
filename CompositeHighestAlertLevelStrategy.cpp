#include "CompositeHighestAlertLevelStrategy.h"

void CompositeHighestAlertLevelStrategy::addStrategy(IPatientAlertLevelsStrategy* strategy) {
	_alertStrategies.push_back(strategy);
}

AlertLevel CompositeHighestAlertLevelStrategy::calculateAlertLevels(const Patient& patient, const Vitals* v) const {

	AlertLevel highestAL = AlertLevel::Green;

	for (auto strat : _alertStrategies) {

		AlertLevel currentAL = strat->calculateAlertLevels(patient, v);

		if (currentAL > highestAL) {
			highestAL = currentAL;
		}
	}

	return highestAL;

}
