#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {

	std::cout << "/////////////////// CLAP TRAP PART /////////////////////" << std::endl << std:: endl;
	{
	ClapTrap	a( "Christian");

	a.attack( "log of wood with spikes" );
	a.takeDamage( 5 );

	std::cout << a.getName() << " has now  " << a.getHP() << " Hit Points! " << std::endl; 

	a.beRepaired( 3 );

	std::cout << a.getName() << " has now  " << a.getHP() << " Hit Points! " << std::endl; 

	std::cout << std::endl;

	std::cout << "Now we copy " << a.getName() << " into a new ClapTrap and name it different:" << std::endl;

	ClapTrap	b( a );

	b.setName( "Some other Christian" ); 
	b.attack( "log of wood with spikes" );
	b.takeDamage( 5 );

	std::cout << b.getName() << " has now  " << b.getHP() << " Hit Points! " << std::endl; 

	b.beRepaired( 3 );

	std::cout << b.getName() << " has now  " << b.getHP() << " Hit Points! " << std::endl;

	std::cout << std::endl;

	std::cout << "Now we assign (=) " << a.getName() <<  " to " << b.getName() << std::endl;

	a = b;

	a.attack( "log of wood with spikes" );
	a.takeDamage( 5 );

	std::cout << a.getName() << " has now  " << a.getHP() << " Hit Points! " << std::endl; 

	a.beRepaired( 3 );

	std::cout << a.getName() << " has now  " << a.getHP() << " Hit Points! " << std::endl; 
	}
	std::cout << std::endl << std::endl;
	std::cout << "/////////////////// SCAV TRAP PART /////////////////////" << std::endl << std:: endl;
	///////////////////////////////SCAV TRAP PART////////////////////////////////////
	{
	ScavTrap	a( "Christian");

	a.attack( "log of wood with spikes" );
	a.takeDamage( 5 );

	std::cout << a.getName() << " has now  " << a.getHP() << " Hit Points! " << std::endl; 

	a.beRepaired( 3 );

	std::cout << a.getName() << " has now  " << a.getHP() << " Hit Points! " << std::endl; 

	std::cout << std::endl;

	std::cout << " Now we copy " << a.getName() << " into a new ScavTrap and name it different:" << std::endl;

	ScavTrap	b( a );

	b.setName( "Some other Christian" ); 
	b.attack( "log of wood with spikes" );
	b.takeDamage( 5 );

	std::cout << b.getName() << " has now  " << b.getHP() << " Hit Points! " << std::endl; 

	b.beRepaired( 3 );

	std::cout << b.getName() << " has now  " << b.getHP() << " Hit Points! " << std::endl;

	std::cout << std::endl;

	a.guardGate();
	b.guardGate();

	std::cout << std::endl;

	std::cout << "Now we assign (=) " << a.getName() <<  " to " << b.getName() << std::endl;

	a = b;

	a.attack( "log of wood with spikes" );
	a.takeDamage( 5 );

	std::cout << a.getName() << " has now  " << a.getHP() << " Hit Points! " << std::endl;

	a.beRepaired( 3 );

	std::cout << a.getName() << " has now  " << a.getHP() << " Hit Points! " << std::endl;

	std::cout << std::endl;
	
	}
	{
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "/////////////////// FRAG TRAP PART /////////////////////" << std::endl << std:: endl;
	///////////////////////////// FRAG TRAP PART ////////////////////////////////////
	FragTrap	a( "Christian");

	a.attack( "log of wood with spikes" );
	a.takeDamage( 5 );

	std::cout << a.getName() << " has now  " << a.getHP() << " Hit Points! " << std::endl; 

	a.beRepaired( 3 );

	std::cout << a.getName() << " has now  " << a.getHP() << " Hit Points! " << std::endl; 

	std::cout << std::endl;

	std::cout << " Now we copy " << a.getName() << " into a new FragTrap and name it different:" << std::endl;

	FragTrap	b( a );

	b.setName( "Some other Christian" ); 
	b.attack( "log of wood with spikes" );
	b.takeDamage( 5 );

	std::cout << b.getName() << " has now  " << b.getHP() << " Hit Points! " << std::endl; 

	b.beRepaired( 3 );

	std::cout << b.getName() << " has now  " << b.getHP() << " Hit Points! " << std::endl;

	std::cout << std::endl;
	a.highFivesGuys();
	b.highFivesGuys();
	std::cout << std::endl;

	a = b;

	a.attack( "log of wood with spikes" );
	a.takeDamage( 5 );

	std::cout << a.getName() << " has now  " << a.getHP() << " Hit Points! " << std::endl;

	a.beRepaired( 3 );

	std::cout << a.getName() << " has now  " << a.getHP() << " Hit Points! " << std::endl;

	std::cout << std::endl;	
	}
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "/////////////////// DIAMOND TRAP PART /////////////////////" << std::endl << std:: endl;
	DiamondTrap	a( "Christian");

	
	a.attack( "log of wood with spikes" );
	a.takeDamage( 5 );

	std::cout << a.getName() << " has now  " << a.getHP() << " Hit Points! " << std::endl; 

	a.beRepaired( 3 );

	std::cout << a.getName() << " has now  " << a.getHP() << " Hit Points! " << std::endl; 

	std::cout << std::endl;

	std::cout << " Now we copy " << a.getName() << " into a new DiamondTrap and name it different:" << std::endl;

	DiamondTrap	b( a );

	b.setName( "Some other Christian" ); 
	b.attack( "log of wood with spikes" );
	b.takeDamage( 5 );

	std::cout << b.getName() << " has now  " << b.getHP() << " Hit Points! " << std::endl; 

	b.beRepaired( 3 );

	std::cout << b.getName() << " has now  " << b.getHP() << " Hit Points! " << std::endl;

	std::cout << std::endl;
	a.guardGate();
	a.highFivesGuys();
	a.whoAmI();
	std::cout << std::endl;
	b.guardGate();
	b.highFivesGuys();
	b.whoAmI();
	std::cout << std::endl;

	a = b;

	a.attack( "log of wood with spikes" );
	a.takeDamage( 5 );

	std::cout << a.getName() << " has now  " << a.getHP() << " Hit Points! " << std::endl;

	a.beRepaired( 3 );

	std::cout << a.getName() << " has now  " << a.getHP() << " Hit Points! " << std::endl;

	std::cout << std::endl;
	return 0;
}
