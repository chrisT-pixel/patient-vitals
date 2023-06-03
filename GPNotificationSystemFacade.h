#pragma once
#ifndef _GPNOTIFICATIONSYSTEMFACADE_H
#define _GPNOTIFICATIONSYSTEMFACADE_H
#include "Patient.h"


class GPNotificationSystemFacade : public PatientSubscriber {
public:
	
	GPNotificationSystemFacade();
	virtual ~GPNotificationSystemFacade();
	
	void sendGPNotificationForPatient(Patient* p);
	void alertLevelHasChanged(Patient* p);

};

#endif
