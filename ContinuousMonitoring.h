using namespace std;

#ifndef CONTINUOUSMONITORING_H
#define CONTINUOUSMONITORING_H

#include "Decorator.h"

class ContinuousMonitoring: public Decorator
{
	private:
		int monitoringInterval;

	public:
		ContinuousMonitoring(Vet* patient, int interval);

		void print() const override;
};

#endif
