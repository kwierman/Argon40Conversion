
#ifndef Ar40Detector_hh_
#define Ar40Detector_hh_ 

namespace ar40 {

	class ::G4VSensitiveDetector;
	class ::G4HCofThisEvent;
	class ::G4Step;
	class ::G4TouchableHistory;
	class Ar40HitsCollection;
	typename G4bool;

	class Ar40Detector : public G4VSensitiveDetector {
	 	Ar40HitsCollection* hitsCollection;
	public:
		Ar40Detector();
	   	~Ar40Detector();

	   void Initialize(G4HCofThisEvent *);
	   G4bool ProcessHits(G4Step *, G4TouchableHistory *);
	   void EndOfEvent(G4HCofThisEvent *);

	};
}

#endif


