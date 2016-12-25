#include <mutex>

class someData
{
    int a;
    str::string b;
public:
    void doSomething(){}
}

class shearData
{
private:
    someData data;
    std::mutex m;
public:
    template<typename Function>
    void process_data(Function func)
    {
        std::lock_guard<std::mutex> g(m);
        func(data);
    }
}

someData* unprotected;

void malicious_function(someData& protected_data)
{
    unprotected = &protected_data;
}

shearData x;

void foo()
{
    x.process_data(malicious_function);
    unprotected->doSomething();
}

int main()
{
    foo();
}
