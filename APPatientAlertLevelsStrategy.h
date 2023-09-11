#pragma once
#ifndef _APPPATIENTALERTLEVELSTRATEGY_H
#define _APPPATIENTALERTLEVELSTRATEGY_H
#include "IPatientAlertLevelsStrategy.h"
#include "Patient.h"

class APPatientAlertLevelsStrategy : public IPatientAlertLevelsStrategy{
public:

	AlertLevel calculateAlertLevels(const Patient& patient, const Vitals* v) const;

};

#endif
