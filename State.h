#include <string>
using namespace std;

#ifndef STATE_H
#define STATE_H

class Patient;

class State
{
	private:
		string stateName;
	public:
		
		virtual void handle(Patient* patient) = 0;
		virtual string getStateName() const = 0;
		State(const std::string& stateName);
		virtual ~State();
};

#endif
