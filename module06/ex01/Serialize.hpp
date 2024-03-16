#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

# include <cstdlib>
# include <iostream>
# include <stdint.h>
# include <string>
struct	Data
{
	std::string name;
	int	age;
};

class Serialize
{
  private:
	Serialize();
	Serialize(Serialize const &object);
	Serialize &operator=(Serialize const &rhs);

  public:
	~Serialize();
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif