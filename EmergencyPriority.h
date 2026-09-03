using namespace std;

#ifndef EMERGENCYPRIORITY_H
#define EMERGENCYPRIORITY_H

#include "Decorator.h"

class EmergencyPriority: public Decorator
{
	private:
		int priorityLevel;

	public:
		EmergencyPriority(Vet* patient, int level);

		bool hasEmergencyPriority() const override;
		void print() const override;
};

#endif
