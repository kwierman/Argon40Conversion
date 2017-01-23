#ifndef Ar40NeutronGenerator_hh_
#define Ar40NeutronGenerator_hh_

class G4ParticleGun;
class G4Event;
class Protium::Math::Random;

namespace ar40
{

  class Ar40NeutronGenerator : public G4ParticleGun {
    Random fDice;
  public:
    Ar40NeutronGenerator();
    virtual ~Ar40NeutronGenerator();
    virtual void GeneratePrimaryVertex(G4Event * evt);
    void SetNewSeed();

  protected:

  };

}
#endif
