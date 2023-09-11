#pragma once
#ifndef _HOSPITALALERTSYSTEMFACADE_H
#define _HOSPITALALERTSYSTEMFACADE_H
#include "Patient.h"


class HospitalAlertSystemFacade : public PatientSubscriber{
public:
	
	HospitalAlertSystemFacade();
	virtual ~HospitalAlertSystemFacade();

	void sendAlertForPatient(Patient* p);
	void alertLevelHasChanged(Patient* p);

};

#endif
