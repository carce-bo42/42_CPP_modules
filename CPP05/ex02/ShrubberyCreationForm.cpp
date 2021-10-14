#include "ShrubberyCreationForm.hpp"
#include <fstream>

SCF::SCF( std::string target ) : Form( "Shrubbery Creation", 145, 137 ), _target( target ) {
}

SCF::SCF( SCF const &other ) : Form( other.getName(), other.getSignGrade(), other.getExecGrade() ),
							   _target( other.getTarget() ) {
}

SCF::~SCF( void ) {
}

SCF&	SCF::operator = ( SCF const &other ) {

	this->_target = other.getTarget();
	return *this;
}

std::string	SCF::getTarget( void ) const {

	return this->_target;
}

void	SCF::execute( Bureaucrat const &executor ) const {

	Form::execute( executor );
	std::string DefinatelyNotATree = "░░░░░▄▄▄▄▀▀▀▀▀▀▀▀▄▄▄▄▄▄░░░░░░░\n░░░░░█░░░░▒▒▒▒▒▒▒▒▒▒▒▒░░▀▀▄░░░░\n░░░░█░░░▒▒▒▒▒▒░░░░░░░░▒▒▒░░█░░░\n░░░█░░░░░░▄██▀▄▄░░░░░▄▄▄░░░░█░░\n░▄▀▒▄▄▄▒░█▀▀▀▀▄▄█░░░██▄▄█░░░░█░\n█░▒█▒▄░▀▄▄▄▀░░░░░░░░█░░░▒▒▒▒▒░█\n█░▒█░█▀▄▄░░░░░█▀░░░░▀▄░░▄▀▀▀▄▒█\n░█░▀▄░█▄░█▀▄▄░▀░▀▀░▄▄▀░░░░█░░█░\n░░█░░░▀▄▀█▄▄░█▀▀▀▄▄▄▄▀▀█▀██░█░░\n░░░█░░░░██░░▀█▄▄▄█▄▄█▄████░█░░░\n░░░░█░░░░▀▀▄░█░░░█░█▀██████░█░░\n░░░░░▀▄░░░░░▀▀▄▄▄█▄█▄█▄█▄▀░░█░░\n░░░░░░░▀▄▄░▒▒▒▒░░░░░░░░░░▒░░░█░\n░░░░░░░░░░▀▀▄▄░▒▒▒▒▒▒▒▒▒▒░░░░█░\n░░░░░░░░░░░░░░▀▄▄▄▄▄░░░░░░░░█░░\n";

	std::ofstream ofs;
	std::string	filename = executor.getName();
	ofs.open(filename.append("_shrubbery"), std::ofstream::out | std::ofstream::app );

	if (ofs.fail()) {
		throw SCF::OutputFileFailException() ; 
	}
	ofs << DefinatelyNotATree << std::endl;
	ofs.close();
}
