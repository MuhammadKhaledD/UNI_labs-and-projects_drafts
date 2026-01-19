#ifndef ENGINE_H
#define ENGINE_H
class Engine
{
private:
	int horsepower;
public:
	Engine(int h);
	~Engine();

	//Class setters and getters
	void setHorsepower(int a);
	int getHorsepower() const;

	void printInfo();

};

#endif