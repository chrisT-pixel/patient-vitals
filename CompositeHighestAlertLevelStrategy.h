#pragma once
#include "IPatientAlertLevelsStrategy.h"
#include <vector>

class CompositeHighestAlertLevelStrategy : public IPatientAlertLevelsStrategy{
public:

	void addStrategy(IPatientAlertLevelsStrategy* strategy) {
		_alertStrategies.push_back(strategy);
	}

	AlertLevel calculateAlertLevels(const Patient& patient, const Vitals* v) {

		std::cout << "calculating highest alert level \n";
		AlertLevel highestAL = AlertLevel::Green;

		for (auto strat : _alertStrategies) {
			
			AlertLevel currentAL = strat->calculateAlertLevels(patient, v);

			if (currentAL > highestAL) {
				highestAL = currentAL;
			}
		}

		
		return highestAL;

	}

protected:

	std::vector<IPatientAlertLevelsStrategy*> _alertStrategies;



};

