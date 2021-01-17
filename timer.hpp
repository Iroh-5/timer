#ifndef TIMER
#define TIMER

#include <chrono>

template <typename Stream>
class Timer
{
public:
	Timer() = delete; // default constructor is deleted

	Timer(Stream& _str, const char* _name)
		: prcName { _name }, str { _str }
	{
		m_StartPoint = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		auto endPoint = std::chrono::high_resolution_clock::now();

		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartPoint).time_since_epoch().count();
		auto stop = std::chrono::time_point_cast<std::chrono::microseconds>(endPoint).time_since_epoch().count();
		auto duration = stop - start;

		str << prcName << " ended:" << std::endl;
		str << std::fixed << duration << "(mcrs)\n" << duration * 1e-3 << "(ms)\n" << duration * 1e-6 << "(s)\n";
	}
private:
	Stream& str;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_StartPoint;
	const char* prcName;
};

#endif
