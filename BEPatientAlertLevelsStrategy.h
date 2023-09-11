#pragma once
#ifndef _BEPATIENTALERTLEVELSTRATEGY_H
#define _BEPPATIENTALERTLEVELSTRATEGY_H
#include "IPatientAlertLevelsStrategy.h"

class BEPatientAlertLevelsStrategy : public IPatientAlertLevelsStrategy{
public:

	AlertLevel calculateAlertLevels(const Patient& patient, const Vitals* v) const;

};

#endif
