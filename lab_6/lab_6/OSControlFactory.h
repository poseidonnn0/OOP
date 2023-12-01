#pragma once
#include "ControlFactory.h"
#include <iostream>
#include "LinLabel.h"
#include "LinTextBox.h"
#include "LinComboBox.h"
#include "LinButton.h"

class OSControlFactory : public ControlFactory 
{
private:
    std::string osName;

public:
    OSControlFactory() 
    {
        osName = std::string(std::getenv("OS")) + std::string("ControlFactory");
        std::cout << "Creating OSControlFactory" << std::endl;
    }

    Label* createLabel() override 
    {
        if (osName.find("Linux") != std::string::npos) 
        {
            return new LinLabel();
        }
        return nullptr;
    }

    TextBox* createTextBox() override 
    {
        if (osName.find("Linux") != std::string::npos) 
        {
            return new LinTextBox();
        }
        return nullptr;
    }

    ComboBox* createComboBox() override 
    {
        if (osName.find("Linux") != std::string::npos) 
        {
            return new LinComboBox();
        }
        return nullptr;
    }

    Button* createButton() override 
    {
        if (osName.find("Linux") != std::string::npos) 
        {
            return new LinButton();
        }
        return nullptr;
    }
};
