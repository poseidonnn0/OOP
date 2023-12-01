#pragma once

__interface TextBox
{
public:
	virtual void setText(std::string& text) /*= 0*/;
	virtual const std::string& getText() const /*= 0*/; // можно не писать, так как __interface делает всё обязательным к переопределению по умолчанию
	virtual void onValueChanged()/* = 0 */;
};
