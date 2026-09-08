
#include "VetSystem.h"
#include "Patient.h"
#include "FullIterator.h"
#include "EmergencyPriorityIterator.h"
#include "Unit.h"
#include "Isolation.h"
#include "EmergencyPriority.h"
#include "ContinuousMonitoring.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

    std::cout<<"-----------TESTING VET SYSTEM-------------"<<std::endl;
    Unit* vetHospital = new Unit("Veterinary Hospital");
    Unit* emergencyDep = new Unit("Emergency Department");
    Unit* treatment1 = new Unit("Treatment Room 1");
    Unit* treatment2 = new Unit("Treatment Room 2");
    Unit* surgeryDep = new Unit("Surgery Department");
    Unit* theatre1 = new Unit("Theatre 1");
    Unit* generalCare = new Unit("General Care");
    Unit* wardA = new Unit("Ward A");
    Patient* oreo = new Patient("010", "Oreo", "Canis lupus familiaris -> Dog", 4);
    Patient* max = new Patient("011", "Max", "Felis catus -> Cat", 2);
    Patient* buddy = new Patient("012", "Buddy", "Psittacus -> Parrot", 5);
    Patient* milo = new Patient("013", "Milo", "Canis lupus familiaris -> Dog", 1);
    Patient* lucky = new Patient("014", "Lucky", "Felis catus -> Cat", 3);
    VetSystem vs(vetHospital);

    Vet* isolationLucky = new Isolation(lucky, "Terminally ill and possibly contagious. Rabies as well.");
    cout << "\nLucky in isolation: \n\t"; isolationLucky->print(); cout << endl;

    Vet* decorateBuddy = new Isolation(buddy, "Bird Flu spread being contained.");
    decorateBuddy = new ContinuousMonitoring(decorateBuddy, 4);
    decorateBuddy = new EmergencyPriority(decorateBuddy, 3);
    cout << "\nBuddy in Emergency, Under continuous monitoring & in Isolation: \n\t"; decorateBuddy->print(); cout << endl;

    Vet* emergencyOreo = new EmergencyPriority(oreo, 6);
    cout << "\nOreo in emergency: \n\t"; emergencyOreo->print(); cout << endl;

    treatment1->add(emergencyOreo);
    treatment1->add(max);
    treatment2->add(decorateBuddy);
    emergencyDep->add(treatment1);
    emergencyDep->add(treatment2);
    
    theatre1->add(milo);
    surgeryDep->add(theatre1);

    wardA->add(isolationLucky);
    generalCare->add(wardA);

    vetHospital->add(emergencyDep);
    vetHospital->add(surgeryDep);
    vetHospital->add(generalCare);

    

    cout << "--- Print All (Whole Tree Structure) ---" << endl;
    vs.printAll(); cout << endl;

    cout << "--- Show All Patients ---" << endl;
    vs.showAllPatients(); cout << endl;

    cout << "--- Show Emergency Priority Patients ---" << endl;
    vs.showEmergencyPriorityPatients(); cout << endl;
    
    std::cout<<"--------------------RUNTIME SCENARIO 1-----------------------"<<std::endl;
    // Build a fresh hierarchy
    Unit* clinic = new Unit("City Clinic");
    Unit* consultRoom = new Unit("Consultation Room");
    Unit* treatmentArea = new Unit("Treatment Area");

    // Create some patients
    Patient* rocky = new Patient("R001", "Rocky", "Dog", 3);
    Patient* whiskers = new Patient("R002", "Whiskers", "Cat", 2);
    Patient* polly = new Patient("R003", "Polly", "Parrot", 1);

    // Decorate Rocky with EmergencyPriority (level 4)
    Vet* rockyPriority = new EmergencyPriority(rocky, 4);

    // Add to the structure
    consultRoom->add(rockyPriority);
    consultRoom->add(whiskers);
    treatmentArea->add(polly);

    clinic->add(consultRoom);
    clinic->add(treatmentArea);

    // ---- Phase 1: Traversal and state change ----
    std::cout << "\n--- Phase 1: Initial state and traversal ---\n";
    FullIterator* it1 = new FullIterator(clinic);
    std::cout << "All patients initially:\n";
    while (it1->hasNext()) {
        Vet* v = it1->next();
        v->print();  // Rocky will show priority level
    }
    delete it1;

    // Change Rocky's state: Admitted to UnderExamination to InTreatment
    std::cout << "\n--- Changing Rocky's state (advance twice) ---\n";
    rocky->advance();  // Admitted to UnderExamination
    rocky->advance();  // UnderExamination to InTreatment
    rocky->print();    // shows new state

    // ---- Phase 2: Traversal after state change, but before structure change ----
    std::cout << "\n--- Phase 2: Traversal after state change (state is now InTreatment) ---\n";
    FullIterator* it2 = new FullIterator(clinic);
    while (it2->hasNext()) {
        Vet* v = it2->next();
        v->print();  // Rocky's print will show InTreatment state
    }
    delete it2;

    // ---- Phase 3: Structure change during an ongoing snapshot iteration ----
    std::cout << "\n--- Phase 3: Structure change during snapshot traversal ---\n";
    // Create a new iterator (snapshot taken now)
    FullIterator* it3 = new FullIterator(clinic);
    std::cout << "First two patients from snapshot:\n";
    if (it3->hasNext()) { it3->next()->print(); }
    if (it3->hasNext()) { it3->next()->print(); }

    // Now change structure: add a new patient to the clinic
    Patient* newbie = new Patient("R004", "Newbie", "Hamster", 1);
    clinic->add(newbie);
    std::cout << "\nAdded new patient 'Newbie' to the clinic during traversal.\n";

    // Continue the same iterator
    std::cout << "Remaining patients from the snapshot (Newbie will NOT appear):\n";
    while (it3->hasNext()) {
        Vet* v = it3->next();
        v->print();
    }
    delete it3;

    // Show that a new iterator will see Newbie
    std::cout << "\nNow a fresh iterator (sees Newbie because it's a new snapshot):\n";
    FullIterator* it4 = new FullIterator(clinic);
    while (it4->hasNext()) {
        Vet* v = it4->next();
        v->print();
    }
    delete it4;
    delete clinic; 

    std::cout<<"\n\n\n"<<std::endl;


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

    std::cout << "\n\n--- INTERACTIVE PORTION | PATIENT CHECK-IN ---\n";
    std::string name;
    std::string type;
    int age;

    std::cout << "Receptionist: Welcome to the Veterinary Hospital!\n";
    std::cout << "Enter patient name: ";
    std::cin >> name;

    std::cout << "Enter animal type: ";
    std::cin >> type;

    std::cout << "Enter patient age: ";
    std::cin >> age;

    Patient* newPatient = new Patient("I001", name, type, age);

    std::cout << "\nPatient has been admitted:\n";
    newPatient->print();

    std::cout << "\nAdvancing patient into treatment...\n";
    newPatient->advance();
    newPatient->print();

    std::cout << "\nDischarging patient...\n";
    newPatient->advance();
    newPatient->print();

    delete newPatient;

    return 0;
}