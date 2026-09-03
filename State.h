#include <string>
using namespace std;

#ifndef STATE_H
#define STATE_H

class Patient;

class State
{
	public:
		virtual void examine(Patient& patient) = 0;
		virtual void treat(Patient& patient) = 0;
		virtual void discharge(Patient& patient) = 0;
		
		virtual string getStateName() const = 0;

		virtual ~State();
};

#endif
