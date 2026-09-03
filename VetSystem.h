#ifndef VETSYSTEM_H
#define VETSYSTEM_H

using namespace std;

class Unit;
class Patient;

class VetSystem
{
	private:
		Unit* root;

	public:
		VetSystem(Unit* root);

		void printAll() const;

		void showAllPatients();
		void showEmergencyPriorityPatients();
		
		void processPatient(Patient* patient);
		
		~VetSystem();
};

#endif
