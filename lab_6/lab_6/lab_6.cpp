#include "OSControlFactory.h"
#include "LinControlFactory.h"

int main()
{
	std::cout << "Linux" << '\n' << '\n';
	std::unique_ptr<ControlFactory> controlFactory(new LinControlFactory());

	std::unique_ptr<Label> label(controlFactory->createLabel());
	std::unique_ptr<TextBox> textBox(controlFactory->createTextBox());
	std::unique_ptr<ComboBox> comboBox(controlFactory->createComboBox());
	std::unique_ptr<Button> button(controlFactory->createButton());

	LinButton* linButton = dynamic_cast<LinButton*>(button.get());
	if (linButton != nullptr) 
	{
		linButton->click();
	}
	else {
		std::cout << "Error: Button is not a LinButton object" << std::endl;
	}

	std::cout << "\nMacOS" << '\n' << '\n';


	std::unique_ptr<ControlFactory> controlFactory1(new OSControlFactory());

	std::unique_ptr<Label> label1(controlFactory1->createLabel());
	std::unique_ptr<TextBox> textBox1(controlFactory1->createTextBox());
	std::unique_ptr<ComboBox> comboBox1(controlFactory1->createComboBox());
	std::unique_ptr<Button> button1(controlFactory1->createButton());

	LinButton* linButton1 = dynamic_cast<LinButton*>(button1.get());
	if (linButton1 != nullptr)
	{
		linButton1->click();
	}
	else 
	{
		std::cout << "Error: Button is not a LinButton object" << std::endl;
	}


	return 0;
}