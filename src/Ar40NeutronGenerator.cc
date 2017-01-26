#include "Ar40CosmicGenerator.hh"
#include "Protium/Math/Random.hh"
#include "Protium/Math/PDF.hh"
#include "Protium/Time/Clock.hh"

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4Neutron.hh"

#include "G4PrimaryParticle.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "globals.hh"
#include "G4ios.hh"
#include "G4MuonMinus.hh"

namespace ar40{

	double Ar40NeutronPDF::eval(double& energy, double& costheta){
		/**
			TODO: Fetch out the 
		**/
			return .372*((energy+105.66)*.001+15)/
									 (((energy+105.66)*.001*costheta+80)*
										((energy+105.66)*.001+15/costheta)*
										 (5*(energy+105.66)*.001+10/costheta)^(2.57));	
	}

	Ar40CosmicGenerator::Ar40CosmicGenerator() : G4ParticleGun() , fPDF()
	{
		fPDF.NXBins(500);
		fPDF.NYBins(400);

	}

	Ar40CosmicGenerator::~Ar40CosmicGenerator() 
	{
	}

	void Ar40CosmicGenerator::GeneratePrimaryVertex(G4Event * evt) 
	{
		//create discrete steps
		std::pair<double, double> pPhaseSpace = fPDF.Sample();
		double pEnergy = pPhaseSpace->first*1000;
		double pCosTheta = std::acos(pPhaseSpace->second);
	  G4ParticleDefinition* mu_definition = G4ParticleTable::GetParticleTable()->FindParticle("neutron");
	  G4double particle_mass = mu_definition->GetPDGMass();
	  G4double phi = NeuRandom::GetInstance()->GetRandom() * 2.0 * TMath::Pi();
	  phi = NeuRandom::GetInstance()->GetRandom() * 2.0 * TMath::Pi();
	  G4ThreeVector position(1000.0*TMath::Cos(costheta)*TMath::Sin(phi),
	              2000.0,
	              1000.0*TMath::Sin(costheta)*TMath::Sin(phi)
	              );

	  //From the Energy and mass, get the momentum magnitude
	  G4double momentum_magnitude = TMath::Sqrt((particle_energy*particle_energy -particle_mass*particle_mass ) );
	    //momentum
	      //from phi and costheta
	  G4ThreeVector momentum( momentum_magnitude*TMath::Cos(costheta)*TMath::Sin(phi),
	              -momentum_magnitude*TMath::Abs(TMath::Cos(phi) ) ,
	              momentum_magnitude*TMath::Sin(costheta)*TMath::Sin(phi)
	              );
	  G4PrimaryVertex *vertex = new G4PrimaryVertex(position,
	      0.0);
	  G4PrimaryParticle *particle = new G4PrimaryParticle(mu_definition,
	        momentum.x(), momentum.y(), momentum.z());
	  particle->SetMass(particle_mass);
	  particle->SetCharge(mu_definition->GetPDGCharge());
	  particle->SetTotalEnergy(particle_energy);
	  vertex->SetPrimary(particle);
	  evt->AddPrimaryVertex(vertex);
	}
}
