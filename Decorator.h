#ifndef DECORATOR_H
#define DECORATOR_H

using namespace std;

#include "Vet.h"

class Decorator: public Vet
{
	protected:
		Vet* patient;

	public:
		Decorator(Vet* patient);

		void print() const override = 0;
		bool hasEmergencyPriority() const override;

		virtual ~Decorator();
};

#endif
