#ifndef NeuWorldGeometry_hh
#define NeuWorldGeometry_hh


/*
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"

#include "NeuDetector.hh"
#include "NeuEarthFields.hh"
#include "NeuGeometryMessenger.hh" 
*/

class G4UserDetectorConstruction;

namespace ar40
{


	class Ar40Geometry : public G4VUserDetectorConstruction
	{
	public:
	   Ar40Geometry();
	   ~Ar40Geometry();

	 public:
	   G4VPhysicalVolume * Construct();

	   void PrintGeometry();

	private:
		G4VPhysicalVolume* ConstructWorld();
		G4VPhysicalVolume* ConstructRock();
		G4VPhysicalVolume* ConstructConcrete();
		G4VPhysicalVolume* ConstructDetector();

	private:
		NeuFlux::NeuDetector* fDetector;
		NeuFlux::NeuGeometryMessenger* fMessenger;

		G4double fWorldX;						/*!<World X-dimension Value*/
		G4double fWorldY;						/*!<World X-dimension Value*/
		G4double fWorldZ;						/*!<World X-dimension Value*/

		G4double fRockX;						/*!<Rock X Dimension Value*/
		G4double fRockY;						/*!<Rock X Dimension Value*/
		G4double fRockZ;						/*!<Rock X Dimension Value*/

		G4double fConcreteX;					/*!< Concrete X Dimension */
		G4double fConcreteY;					/*!< Concrete X Dimension */
		G4double fConcreteZ;					/*!< Concrete X Dimension */

		G4double fDetectorX;					/*!< Detector X Dimension */
		G4double fDetectorY;					/*!< Detector Y Dimension */
		G4double fDetectorZ;					/*!< Detector Z Dimension */

		G4LogicalVolume* fLogicWorld;						/*!< an integer value */
   		G4VPhysicalVolume* fPhysiWorld;						/*!< an integer value */

   		G4LogicalVolume* fLogicRock;						/*!< an integer value */
   		G4VPhysicalVolume* fPhysiRock;						/*!< an integer value */

   		G4LogicalVolume* fLogicConcrete;						/*!< an integer value */
   		G4VPhysicalVolume* fPhysiConcrete;						/*!< an integer value */

   		G4LogicalVolume* fLogicDetector;						/*!< an integer value */
   		G4VPhysicalVolume* fPhysiDetector;						/*!< an integer value */

public:
   		void SetWorldX(G4double X)
   			{fWorldX = X;}
   		void SetWorldY(G4double Y)
   			{fWorldY = Y;}
   		void SetWorldZ(G4double Z)
   			{fWorldZ = Z;}

   		void SetRockX(G4double X)
   			{fRockX = X;}
   		void SetRockY(G4double Y)
   			{fRockY = Y;}
   		void SetRockZ(G4double Z)
   			{fRockZ = Z;}

   		void SetConcreteX(G4double X)
   			{fConcreteX = X;}
   		void SetConcreteY(G4double Y)
   			{fConcreteY = Y;}
   		void SetConcreteZ(G4double Z)
   			{fWorldZ = Z;}

   		void SetDetectorX(G4double X)
   			{fDetectorX = X;}
   		void SetDetectorY(G4double Y)
   			{fDetectorY = Y;}
   		void SetDetectorZ(G4double Z)
   			{fDetectorZ = Z;}

	};

	

}
#endif     //NeuWorldGeometry_hh


