#include <Leezel.h>

class Sandbox : public Leezel::Application
{
public:
	Sandbox()
	{
		
	}
	~Sandbox()
	{
		
	}
};

Leezel::Application* Leezel::CreateApplication()
{
	return new Sandbox();
}

