#pragma once
#include "coneccion.h"
#include<thread>
#include<mutex>
#include<memory>
enum rol {
	PROXYSIMULADO,PROXYAUTONOMO,AUTORIDAD
};
class networkmanager
{
public:
	void start();
	//std::mutex m;
	//std::shared_ptr<thread> t;
	void nt();
	coneccion c;
};

