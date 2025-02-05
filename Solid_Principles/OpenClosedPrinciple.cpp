#include <bits/stdc++.h>
using namespace std;

class paymentProcessor
{
public:
    virtual void processPayment(double amount) = 0;
};

class creditCardPayment : public paymentProcessor
{
public:
    void processPayment(double amount) override{
        std::cout<<"payment done through creditcard"<<std::endl;
    }
};

class paypalPayment : public paymentProcessor
{
public:
    void processPayment(double amount) override
    {
        std::cout<<"payment done through paypal"<<std::endl;
    }
};

int main()
{
    paymentProcessor* pay;
    pay = new creditCardPayment();
    pay->processPayment(456);

    pay = new paypalPayment();
    pay->processPayment(234);
}