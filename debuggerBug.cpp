
#include <iostream>

struct BugProducer
{
	char name[64]{};
	int32_t size{};
};

struct BugFree
{
	int32_t size{};
};



BugProducer runBug()
{
	//Debugger displays object's fields as uninitialized
	BugProducer c{};
	std::cout << c.size << '\n';
	c.size = 42;
	std::cout << c.size << '\n';
	//Still uninitialized
	return c;
}

auto runNoBugWithProducer()
{
	//Fields are ok
	BugProducer c{};
	return c.size;
}

BugFree runBugFree()
{
	//Fields are ok
	BugFree c{};
	return c;
}

int main()
{

	//Everything is ok
	//c.size is 42
    const auto bug = runBug();
	const auto bugNoBugWithProducer = runNoBugWithProducer();
	const auto noBug = runBugFree();

    return 0;

}
