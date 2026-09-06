#include <string>
using namespace std;

#ifndef DISCHARGED_H
#define DISCHARGED_H

#include "State.h"

class Discharged: public State
{
	public:
		Discharged();
		void handle(Patient* patient) override;
		~Discharged();
		std::string getStateName() const override;
};

#endif
