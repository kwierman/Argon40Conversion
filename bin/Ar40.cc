#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4UIterminal.hh"
#include "G4UItcsh.hh"

#include "Ar40.hh"

int main(int argc, char **argv)
{
   
   G4RunManager* runManager = new G4RunManager;

   ar40::Ar40Geometry geo;

   runManager->SetUserInitialization(&geo);




   NeuFlux::NeuRunAction* runAction = new NeuFlux::NeuRunAction();
   runManager->SetUserAction(runAction);
   NeuFlux::NeuEventAction* eventAction =
       new NeuFlux::NeuEventAction();
   runManager->SetUserAction(eventAction);
   runManager->SetUserAction( new NeuFlux::NeuPrimaryGeneratorAction());
   NeuFlux::NeuTrackingAction* trackingAction =
       new NeuFlux::NeuTrackingAction;
   runManager->SetUserAction(trackingAction);
   runManager->
       SetUserAction(new
                     NeuFlux::NeuSteppingAction() ) ;

   G4cout<<"  Initializing the G4 kernel"<<std::endl;

   runManager->Initialize();

   G4UImanager *UI = G4UImanager::GetUIpointer();

   if (argc == 1) 
   {
      G4UIsession *session = new G4UIterminal(
      #ifdef G4UI_USE_TCSH
    		  new G4UItcsh
      #endif
    		);

      session->SessionStart();
      delete session;
   } 
   else 
   {
      G4String command = "/control/execute ";
      G4String fileName = argv[1];
      UI->ApplyCommand(command + fileName);
   }
   return 0;
}
