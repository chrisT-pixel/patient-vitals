#pragma once

#include "Patient.h"


class GPNotificationSystemFacade : public PatientSubscriber {
public:
	GPNotificationSystemFacade();
	virtual ~GPNotificationSystemFacade();

	void sendGPNotificationForPatient(Patient* p);

	void alertLevelHasChanged(Patient* p);
};

