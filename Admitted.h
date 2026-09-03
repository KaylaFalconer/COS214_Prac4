#include <string>
using namespace std;

#ifndef ADMITTED_H
#define ADMITTED_H

#include "State.h"

class Admitted: public State
{
	public:
		void examine(Patient& patient) override;
		void treat(Patient& patient) override;
		void discharge(Patient& patient) override;
		
		string getStateName() const override;
};

#endif
