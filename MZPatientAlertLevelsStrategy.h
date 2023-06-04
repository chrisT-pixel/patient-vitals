#pragma once
#ifndef _MZPATIENTALERTLEVELSSTRATEGY_H
#define _MZPATIENTALERTLEVELSSTRATEGY_H
#include "IPatientAlertLevelsStrategy.h"


class MZPatientAlertLevelsStrategy : public IPatientAlertLevelsStrategy{
public:

	AlertLevel calculateAlertLevels(const Patient& patient, const Vitals* v) const;

};

#endif