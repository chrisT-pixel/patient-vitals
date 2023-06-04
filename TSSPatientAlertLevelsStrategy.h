#pragma once
#ifndef _TSSPATIENTALERTLEVELSSTRATEGY_H
#define _TSSPATIENTALERTLEVELSSTRATEGY_H
#include "IPatientAlertLevelsStrategy.h"
#include "Patient.h"

class TSSPatientAlertLevelsStrategy : public IPatientAlertLevelsStrategy{
public:

	AlertLevel calculateAlertLevels(const Patient& patient, const Vitals* v) const;

};

#endif