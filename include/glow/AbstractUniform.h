#pragma once

#include <string>
#include <set>

#include <GL/glew.h>

#include <glm/glm.hpp>

#include <glow/glow.h>
#include <glow/Referenced.h>

namespace glow 
{
class Program;

class GLOW_API AbstractUniform : public Referenced
{
	friend class Program;

public:
	AbstractUniform(const std::string & name);
	virtual ~AbstractUniform();

	const std::string & name() const;

	void registerProgram(Program * program);
	void unregisterProgram(Program * program);

protected:
	void setUniform(const GLint location);

	void changed();
	virtual void update(Program * program) = 0;

protected:
	std::string _name;
	std::set<Program *> _programs;
};

} // namespace glow
