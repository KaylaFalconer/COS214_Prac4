#include <string>
using namespace std;

#ifndef ADMITTED_H
#define ADMITTED_H

#include "State.h"

class Admitted: public State
{
	public:
		Admitted();
		void handle(Patient* patient) override;
		string getStateName() const override;
		~Admitted();

		

};

#endif
