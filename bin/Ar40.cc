

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4UIterminal.hh"
#include "G4UItcsh.hh"


#include "Ar40.hh"

int main(int argc, char **argv)
{
    //Setup the Random number singleton
   NeuFlux::NeuRandom::GetInstance();


   G4cout<<"  Setting up Run Manager"<<std::endl;
   
   G4RunManager* runManager = new G4RunManager;
   
   NeuFlux::NeuWorldGeometry* geometry = new NeuFlux::NeuWorldGeometry;

   runManager->SetUserInitialization(geometry);
   
   //runManager->SetUserInitialization( new QGSP_BIC_HP);
   runManager->SetUserInitialization( new NeuFlux::NeuMesonProductionCut(100*CLHEP::MeV) );
   //runManager->SetUserInitialization( new QGSP_BERT_HP);
   //runManager->SetUserInitialization( new QGSP_BERT_EMV);


   G4cout<<"  Setting up User Action Classes"<<std::endl;
   NeuFlux::NeuRunAction* runAction = new NeuFlux::NeuRunAction();
   runManager->SetUserAction(runAction);
   G4cout<<"    done setting run action"<<std::endl;
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

   delete runManager;
#ifdef G4VIS_USE
   delete visManager;
#endif

   return 0;
}
