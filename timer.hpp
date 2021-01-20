#ifndef TIMER
#define TIMER

#include <chrono>

template <typename Stream>
class Timer
{
public:
	using std::chrono;
	
	Timer() = delete; // default constructor is deleted

	Timer(Stream& _str, const char* _name)
		: prcName { _name }, str { _str }
	{
		m_StartPoint = high_resolution_clock::now();
	}

	~Timer()
	{
		auto endPoint = high_resolution_clock::now();

		auto start = time_point_cast<microseconds>(m_StartPoint).time_since_epoch().count();
		auto stop = time_point_cast<microseconds>(endPoint).time_since_epoch().count();
		auto duration = stop - start;

		str << prcName << " ended:" << std::endl;
		str << std::fixed << duration << "(mcrs)\n" << duration * 1e-3 << "(ms)\n" << duration * 1e-6 << "(s)\n";
	}
private:
	Stream& str;
	time_point<high_resolution_clock> m_StartPoint;
	const char* prcName;
};

#endif
