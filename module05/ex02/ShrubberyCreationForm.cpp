/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <avazbekrashidov6@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:44:39 by arashido          #+#    #+#             */
/*   Updated: 2024/03/14 15:05:37 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target): AForm("ShruberryCreationForm", 130, 137), _target(_target)
{
	printMessage("ShrubberyCreationForm Default Constructor called", Color::Green);
	this->write_ascii_tree();
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &object): AForm(object), _target(object.getTarget())
{
	printMessage("ShrubberyCreationForm Copy Constructor called", Color::Green);
	*this = object;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	printMessage("ShrubberyCreationForm Copy Assignment Operator called", Color::Orange);
	if (this != &rhs)
		AForm::operator=(rhs);
	return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	printMessage("ShrubberyCreationForm Destructor called", Color::Red);
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void 	ShrubberyCreationForm::write_ascii_tree() const
{
	std::ofstream file;

	try {
		file.open((this->_target + "_shrubbery").c_str());
		if (file.fail())
			throw ShrubberyCreationForm::MyAppropriateExecption();
	}
	catch (std::exception &e) {
		throw;
	}
	file << "              _{\\ _{\\{\\/}/}/}__            " << std::endl;
	file << "             {/{/\\}{/{/\\}(\\}{/\\} _         " << std::endl;
	file << "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _     " << std::endl;
	file << "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}    " << std::endl;
	file << "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}     " << std::endl;
	file << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}     " << std::endl;
	file << "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}    " << std::endl;
	file << "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}    " << std::endl;
	file << "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}   " << std::endl;
	file << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}  " << std::endl;
	file << "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)   " << std::endl;
	file << "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}   " << std::endl;
	file << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}   " << std::endl;
	file << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}   " << std::endl;
	file << "          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)    " << std::endl;
	file << "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}        " << std::endl;
	file << "             {/{\\{\\{\\/}/}{\\{\\\\}/}          " << std::endl;
	file << "              {){/ {\\/}{\\/} \\}\\}           " << std::endl;
	file << "              (_)  \\.-'.-/                 " << std::endl;
	file << "          __...--- |'-.-'| --...__         " << std::endl;
	file << "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__ " << std::endl;
	file << " -\"    ' .  . '    |.'-._| '  . .  '   jro " << std::endl;
	file << " .  '-  '    .--'  | '-.'|    .  '  . '    " << std::endl;
	file << "          ' ..     |'-_.-|                 " << std::endl;
	file << "  .  '  .       _.-|-._ -|-._  .  '  .     " << std::endl;
	file << "              .'   |'- .-|   '.            " << std::endl;
	file << "  ..-'   ' .  '.   `-._.-�   .'  '  - .   " << std::endl;
	file << "   .-' '        '-._______.-'     '  .     " << std::endl;
	file << "        .      ~,                          " << std::endl;
	file << "    .       .   |\\   .    ' '-.            " << std::endl;
	file << "    ___________/  \\____________            " << std::endl;
	file << "   /  Why is it, when you want \\           " << std::endl;
	file << "  |  something, it is so damn   |          " << std::endl;
	file << "  |    much work to get it?     |          " << std::endl;
	file << "   \\___________________________/           " << std::endl;
	file.close();
}

void	 ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (this->getSigned())
		{
			if (executor.getGrade() <= this->getExecGrade())
			{
				this->write_ascii_tree();
				std::cout << this->_target << "_shruberry tree has been created" << std::endl;
			}
			else
				throw AForm::GradeTooLowException();
		}
		else
			throw std::out_of_range("Bureaucrat Form not signed");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

const char *ShrubberyCreationForm::MyAppropriateExecption::what() const throw() {
	return ("Couldn't Create/Open File");
}
