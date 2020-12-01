/*
 * Filename: AsyncTimer.h
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/11/30 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-11-30
 * LastChange: 2020-11-30
 *    Version: v0.0.01
 *
 */

#ifndef _ASYNCTIMER_H
#define _ASYNCTIMER_H
#include <functional>
#include <iostream>
#include <atomic>
#include <condition_variable>
#include <thread>
#include <chrono>
using namespace std::chrono_literals;
class Timer
{
public :
	Timer() = default;

	~Timer()
	{
		delete s;
		s = nullptr;
	}

private:
	static bool _updateStatus(Timer *timer)
	{
		if (timer->status == TIMER_NOT_INIT || timer->status == TIMER_START) {
			timer->status = TIMER_START;
			std::cout << "start timer. update status:" << timer->status << std::endl;
			return false;
		} else {
			std::cout << "stop timer. status:" << timer->status << std::endl;
			return true;//stop
		}
	}

	static void _do_task_func(int64_t sec, Timer *timer, std::function<void()> callback)
	{
		std::unique_lock<std::mutex> lk(timer->cv_m);
		auto now = std::chrono::system_clock::now();
		std::cout << "start task, delay:" << sec << std::endl;
		if (timer->cv.wait_until(lk, now + sec * 1000ms, std::bind(_updateStatus, timer))) {
			std::cerr << "Thread finished waiting. \n";
		} else {
			std::cerr << "Thread timed out.\n";
			callback();
		}
	}

public:
	void start(int64_t sec, std::function<void()> callback)
	{
		s = new std::thread(_do_task_func, sec, this, callback);

	}

	void stop()
	{
		status = TIMER_STOP;
		std::cout << "Notifying...\n";
		cv.notify_one();
		s->join();
	}

	enum TimerStatus {
		TIMER_NOT_INIT = 0,
		TIMER_START = 1,
		TIMER_STOP = 2
	};
	std::mutex cv_m;
	std::condition_variable cv;
	TimerStatus status = TIMER_NOT_INIT;
	std::thread *s = nullptr;

};

#endif
