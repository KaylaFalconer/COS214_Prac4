#include "VetSystem.h"
#include "Patient.h"
#include "FullIterator.h"
#include "EmergencyPriorityIterator.h"
#include "Unit.h"
#include "EmergencyPriority.h"
#include <iostream>
using namespace std;

int main() {

    std::cout<<"----------PATIENT STATE CHANGES DEMO---------------"<<std::endl;
    // Create a patient
    Patient* oreo2 = new Patient("P001", "Oreo", "Dog", 3);
    oreo2->print();

    std::cout << "\n--- Advancing through treatment ---\n";
    oreo2->advance();   // Admitted to UnderExamination
    oreo2->advance();   // UnderExamination to InTreatment
    oreo2->advance();   // InTreatment to Discharged
    oreo2->advance();   // Discharged to cannot advance

    std::cout << "\n--- Re‑admitting the patient ---\n";
    oreo2->readmit();   // Discharged to Admitted
    oreo2->print();

    std::cout << "\n--- Advancing again (new visit) ---\n";
    oreo2->advance();   // Admitted to UnderExamination
    oreo2->advance();   // UnderExamination to InTreatment
    oreo2->advance();   // InTreatment to Discharged

    delete oreo2;

    std::cout<<"\n\n\n-------------------ITERATORS DEMO-------------------"<<std::endl;
    //Build a hierarchy
    Unit* hospital = new Unit("Demo Hospital");
    Unit* er = new Unit("Emergency Room");
    Unit* ward = new Unit("General Ward");

    // Create some normal patients
    Patient* fluffy = new Patient("D001", "Fluffy", "Cat", 2);
    Patient* spot   = new Patient("D002", "Spot", "Dog", 4);
    Patient* tweety = new Patient("D003", "Tweety", "Bird", 1);

    // Wrap two of them with EmergencyPriority
    Vet* fluffyPriority = new EmergencyPriority(fluffy, 5);   // level 5
    Vet* spotPriority   = new EmergencyPriority(spot, 3);     // level 3
    // Tweety remains without priority

    // Add them to the departments
    er->add(fluffyPriority);
    er->add(spotPriority);
    ward->add(tweety);

    // Build the tree
    hospital->add(er);
    hospital->add(ward);

    //Create a VetSystem for this new tree
    VetSystem demoSystem(hospital);

    std::cout << "\n--- All patients (FullIterator) ---\n";
    demoSystem.showAllPatients();

    std::cout << "\n--- Emergency priority patients ---\n";
    demoSystem.showEmergencyPriorityPatients();

    std::cout<<"-----------TESTING VET SYSTEM-------------"<<std::endl;
    Unit* vetHospital = new Unit("Veterinary Hospital");
    Unit* emergencyDep = new Unit("Emergency Department");
    Unit* treatment1 = new Unit("Treatment Room 1");
    Unit* treatment2 = new Unit("Treatment Room 2");
    Unit* surgeryDep = new Unit("Surgery Department");
    Unit* theatre1 = new Unit("Theatre 1");
    Unit* generalCare = new Unit("General Care");
    Unit* wardA = new Unit("Ward A");
    Patient* oreo = new Patient("010", "Oreo", "Canis lupus familiaris", 4);
    Patient* max = new Patient("011", "Max", "Felis catus", 2);
    Patient* buddy = new Patient("012", "Buddy", "Psittacus", 5);
    Patient* milo = new Patient("013", "Milo", "Canis lupus familiaris", 1);
    Patient* lucky = new Patient("014", "Lucky", "Felis catus", 3);

    treatment1->add(oreo);
    treatment1->add(max);
    treatment2->add(buddy);
    emergencyDep->add(treatment1);
    
    theatre1->add(milo);
    surgeryDep->add(theatre1);

    wardA->add(lucky);
    generalCare->add(wardA);

    vetHospital->add(emergencyDep);
    vetHospital->add(surgeryDep);
    vetHospital->add(generalCare);
    return 0;
}