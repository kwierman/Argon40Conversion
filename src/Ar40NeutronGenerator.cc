#include "Ar40CosmicGenerator.hh"
#include "Protium/Math/Random.hh"
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
	Ar40CosmicGenerator::Ar40CosmicGenerator() : G4ParticleGun() , fDice()
	{}

	Ar40CosmicGenerator::~Ar40CosmicGenerator() 
	{
	}

	Ar40CosmicGenerator::SetNewSeed(){w
	  Protium::Time::Clock::ClockPrimitive clock;
	  fDice.setSeed(clock.Get());
	}

	void Ar40CosmicGenerator::GeneratePrimaryVertex(G4Event * evt) 
	{


	  //TODO:: Replace ALL OF THIS;

	  TF2* muonE =
	      new TF2("f2",
	          ".372*((x+105.66)*.001+15)/(((x+105.66)*.001*y+80)*((x+105.66)*.001+15/y)*(5*(x+105.66)*.001+10/y)^(2.57))",
	          0.25 * CLHEP::GeV, 100 * CLHEP::GeV, 0, 1);
	  muonE->SetNpx(500);
	  muonE->SetNpy(400);


	  //generate the random variables in regard to energy and costheta
	  G4double costheta = 0;
	  G4double particle_energy;
	  G4ParticleDefinition* mu_definition = G4ParticleTable::GetParticleTable()->FindParticle("mu-");
	  G4double particle_mass = mu_definition->GetPDGMass();

	  muonE->GetRandom2(particle_energy, costheta);
	  particle_energy*=1000;
	  costheta = TMath::ACos(costheta);
	  G4double phi = NeuRandom::GetInstance()->GetRandom() * 2.0 * TMath::Pi();

	  phi = NeuRandom::GetInstance()->GetRandom() * 2.0 * TMath::Pi();

	  G4ThreeVector position(1000.0*TMath::Cos(costheta)*TMath::Sin(phi),
	              2000.0,
	              1000.0*TMath::Sin(costheta)*TMath::Sin(phi)
	              );//remember that y is the "up"

	  /*
	  G4double pos_magnitude  =1000.0*TMath::Cos(costheta)*TMath::Sin(phi)*1000.0*TMath::Cos(costheta)*TMath::Sin(phi)
	              +2000.0*2000.0
	              + 1000.0*TMath::Sin(costheta)*TMath::Cos(phi)*1000.0*TMath::Sin(costheta)*TMath::Cos(phi);
	  */

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
	  G4cout<<"Cosmic Generator Generating Particle Parameters: Mass: "<<particle_mass<<std::endl;
	  G4cout<<"                     Energy: "<<particle_energy<<std::endl;
	  G4cout<<"                     Momentum: "<<momentum_magnitude<<std::endl;
	  G4cout<<"                     CosTheta: "<<costheta<<std::endl;
	  G4cout<<"                     Phi: "<<phi<<std::endl;
	  G4cout<<"                     Position: "<<position.x()<<", "<<position.y()<<", "<<position.z()<<std::endl;
	  G4cout<<"                     Momentum: "<<momentum.x()<<", "<<momentum.y()<<", "<<momentum.z()<<std::endl;
	  G4cout<<"                     Charge: "<<mu_definition->GetPDGCharge()<<std::endl;
	}
}
