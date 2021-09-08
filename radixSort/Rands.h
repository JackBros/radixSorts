#pragma once
#include <chrono>

using std::chrono::seconds;
using std::chrono::milliseconds;
using std::chrono::microseconds;
using std::chrono::nanoseconds;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;

#define second duration_cast<seconds>(high_resolution_clock::now().time_since_epoch()).count()
#define millisecond duration_cast<milliseconds>(high_resolution_clock::now().time_since_epoch()).count()
#define microsecond duration_cast<microseconds>(high_resolution_clock::now().time_since_epoch()).count()
#define nanosecond duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count()

int m_z = second ^ nanosecond;
int m_w = millisecond ^ microsecond;

auto start = high_resolution_clock::now();

static int intRand()
{
	m_z = 36969 * (m_z & 65535) + (m_z >> 16);
	m_w = 18000 * (m_w & 65535) + (m_w >> 16);

	return (m_z << 16) + m_w;
}

static double doubleRand() { return (intRand() + 1.0) * 2.328306435454494e-10; }

static void startTimer() {
	start = high_resolution_clock::now();
}

static double stopTimer() {
	return duration_cast<microseconds>(high_resolution_clock::now() - start).count() * 0.000001;
}