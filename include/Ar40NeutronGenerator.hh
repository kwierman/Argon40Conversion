#ifndef Ar40NeutronGenerator_hh_
#define Ar40NeutronGenerator_hh_

class G4ParticleGun;
class G4Event;
class Protium::Math::Random;

namespace ar40
{

  class Ar40NeutronPDF : ::Protium::Math::PDF{
  protected:
    double eval(double& x);
  };

  class Ar40NeutronGenerator : public G4ParticleGun {
    Ar40NeutronPDF fPDF;
  public:
    Ar40NeutronGenerator();
    virtual ~Ar40NeutronGenerator();
    virtual void GeneratePrimaryVertex(G4Event * evt);
  };

}
#endif
