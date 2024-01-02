#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class ScavTrap : public ClapTrap
{
  public:
	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(const ScavTrap &);
	ScavTrap &operator=(const ScavTrap &rhs);

	void guardGate(void);
	void attack(const std::string &target);
};

#endif