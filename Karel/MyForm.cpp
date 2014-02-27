#include "MyForm.h"
#include "Robot.h"

using namespace Karel;

[STAThreadAttribute]

int main(array<System::String ^> ^args)
{

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	// Create the main window and run it

	Application::Run(gcnew MyForm());



	return 0;

}


