#include <iostream>
#include <exception>

using namespace std;

class BaseException : public exception
{
public:
    [[nodiscard]] const char* what() const noexcept override
    {
        return "Base exception";
    }
};

class Derived1Exception : public BaseException
{
public:
    [[nodiscard]] const char* what() const noexcept override
    {
        return "Derived1 exception";
    }
};

class Derived2Exception : public BaseException
{
public:
    [[nodiscard]] const char* what() const noexcept override
    {
        return "Derived2 exception";
    }
};

class Base
{
public:
    virtual void performAction()
    {
        throw BaseException();
    }
};

class Derived1 : public Base
{
public:
    void performAction() override
    {
        throw Derived1Exception();
    }
};

class Derived2 : public Base
{
public:
    void performAction() override
    {
        throw Derived2Exception();
    }
};

void handleAction(Base& obj)
{
    try
    {
        obj.performAction();
    }
    catch (const Derived1Exception& e)
    {
        cout << "Caught: " << e.what() << endl;
    }
    catch (const Derived2Exception& e)
    {
        cout << "Caught: " << e.what() << endl;
    }
    catch (const BaseException& e)
    {
        cout << "Caught: " << e.what() << endl;
    }
    catch (const std::exception& e)
    {
        cout << "Caught std::exception: " << e.what() << endl;
    }
    catch (...)
    {
        cout << "Caught unknown exception" << endl;
    }
}

int main()
{
    Derived1 d1;
    Derived2 d2;
    Base b;

    handleAction(d1);
    handleAction(d2);
    handleAction(b);

    return 0;
}
