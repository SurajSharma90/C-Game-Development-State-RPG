#include"msg_functions.h"

const std::string gui::msg_menutitle(const std::string title)
{
	std::stringstream ss;

	ss << "\n" << std::string(10, ' ') <<" ---- [[ " << title << " ]] ---- " << "\n" << "\n";

	return ss.str();
}

const std::string gui::msg_menudivider(const unsigned amount, const char symbol)
{
	std::stringstream ss;

	ss << std::string(4, ' ') << std::string(amount, symbol) << "\n" << "\n";

	return ss.str();
}

const std::string gui::msg_menuitem(const int number, const std::string item)
{
	std::stringstream ss;

	ss << std::string(4, ' ') << " | [ " << number << " ] " << item << "\n" << "\n";

	return ss.str();
}

const std::string gui::msg_error(const std::string msg)
{
	std::stringstream ss;

	ss << std::string(4, ' ') << " [[ (!) " << msg << " ]]" << "\n" << "\n";

	return ss.str();
}
