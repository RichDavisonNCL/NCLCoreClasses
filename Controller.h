/*
Part of Newcastle University's Game Engineering source code.

Use as you see fit!

Comments and queries to: richard-gordon.davison AT ncl.ac.uk
https://research.ncl.ac.uk/game/
*/
#pragma once


class Controller	{
public:
	Controller() {

	}
	virtual ~Controller() {

	}

	virtual float	GetAxis(uint32_t axis) = 0;
	virtual float	GetButtonAnalogue(uint32_t button) = 0;
	virtual bool	GetButton(uint32_t button) = 0;


	virtual float	GetAxis(const std::string& axis);
	virtual float	GetButtonAnalogue(const std::string& button);
	virtual bool	GetButton(const std::string& button);


	void MapAxis(uint32_t axis, const std::string& name);
	void MapButton(uint32_t axis, const std::string& name);
	void MapButtonAnalogue(uint32_t axis, const std::string& name);

	virtual void Update(float dt = 0.0f) {}

protected:

	std::map<std::string, uint32_t> buttonMappings;
	std::map<std::string, uint32_t> analogueMappings;
	std::map<std::string, uint32_t> axisMappings;
};