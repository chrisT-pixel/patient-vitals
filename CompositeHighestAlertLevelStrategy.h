#pragma once
#ifndef _COMPOSITEHIGHESTLEVELSTRATEGY_H
#define _COMPOSITEHIGHESTLEVELSTRATEGY_H
#include "IPatientAlertLevelsStrategy.h"
#include <vector>

class CompositeHighestAlertLevelStrategy : public IPatientAlertLevelsStrategy{
public:

	void addStrategy(IPatientAlertLevelsStrategy* strategy);
	AlertLevel calculateAlertLevels(const Patient& patient, const Vitals* v) const;

protected:

	std::vector<IPatientAlertLevelsStrategy*> _alertStrategies;

};

#endif
