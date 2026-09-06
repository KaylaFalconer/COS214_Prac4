#include "VetSystem.h"
#include "Patient.h"
#include "Unit.h"
#include "Isolation.h"
#include "EmergencyPriority.h"
#include "ContinuousMonitoring.h"
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

    std::cout<<"-------------AZOLILE TESTING VET SYSTEM----------------"<<std::endl;
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

    vs.processPatient(oreo);
    vs.processPatient(buddy);
    vs.processPatient(lucky);

    Vet* isolationLucky = new Isolation(lucky, "Terminally ill and possibly contagious. Rabies as well.");
    Vet* decorateBuddy = new Isolation(buddy, "Bird Flu spread being contained.");
    decorateBuddy = new ContinuousMonitoring(decorateBuddy, 4);
    decorateBuddy = new EmergencyPriority(decorateBuddy, 3);
    Vet* oreo = new EmergencyPriority(oreo, 6);

    cout << "--- Print All (Whole Tree Structure) ---" << endl;
    vs.printAll();

    cout << "--- Show All Patients ---" << endl;
    vs.showAllPatients();

    cout << "--- Show Emergency Priority Patients ---" << endl;
    vs.showEmergencyPriorityPatients();
    
    return 0;
}