/*
    电脑
        1. cpu
        2. gpu
        3. memory
*/
#include <iostream>

class CPU
{
public:
    // 处理数据，纯虚函数，该类为抽象类
    virtual void process() = 0;
};

class GPU
{

public:
    // 显式 纯虚函数，该类为抽象类
    virtual void display() = 0;
};

class Memory
{
public:

    // 存储
    virtual void storage() = 0;
};

class IntelCpu : public CPU
{
public:
    void process()
    {
        std::cout << "Intel CPU Working..." << std::endl;
    }
};

class InvidiaGPU : public GPU
{
public:
    void display()
    {
        std::cout << "Invida GPU Working..." << std::endl;
    }

};


class Glowy : public Memory
{
    void storage()
    {
        std::cout << "Glowy Mem Working..." << std::endl;
    }
};

// 电脑
class PersonalComputer
{

CPU* mCpu;
GPU* mGpu;
Memory* mMemory;

public:
    PersonalComputer(CPU* cpu, GPU* gpu, Memory* mem) : mCpu(cpu), mGpu(gpu), mMemory(mem){}

    void doWork()
    {
        mCpu->process();
        mGpu->display();
        mMemory->storage();
    }

    ~PersonalComputer()
    {
        std::cout << "PersonalComputer 析构函数" << std::endl;
        if(mCpu != nullptr)
        {
            delete mCpu;
            mCpu = nullptr;
        }

        if(mGpu != nullptr)
        {
            delete mGpu;
            mGpu = nullptr;
        }
        
        if(mMemory != nullptr)
        {
            delete mMemory;
            mMemory = nullptr;
        }
    }
};

void test01()
{
    PersonalComputer pc(new IntelCpu,  new InvidiaGPU, new Glowy);
    pc.doWork();
}


int main(void)
{
    test01();
    return 0;
}

/*

Intel CPU Working...
Invida GPU Working...
Glowy Mem Working...
PersonalComputer 析构函数

*/


