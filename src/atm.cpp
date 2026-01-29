#include <iostream>
using namespace std;

// ---------- Abstract Products ----------
class CashDispenser {
public:
    virtual void dispenseCash(int amount) = 0;
    virtual ~CashDispenser() {}
};

class ReceiptPrinter {
public:
    virtual void printReceipt(int amount) = 0;
    virtual ~ReceiptPrinter() {}
};

// ---------- Concrete Products : India ----------
class IndiaCashDispenser : public CashDispenser {
public:
    void dispenseCash(int amount) override {
        cout << "Dispensing ₹" << amount << endl;
    }
};

class IndiaReceiptPrinter : public ReceiptPrinter {
public:
    void printReceipt(int amount) override {
        cout << "Receipt: ₹" << amount << " withdrawn" << endl;
    }
};

// ---------- Concrete Products : USA ----------
class USCashDispenser : public CashDispenser {
public:
    void dispenseCash(int amount) override {
        cout << "Dispensing $" << amount << endl;
    }
};

class USReceiptPrinter : public ReceiptPrinter {
public:
    void printReceipt(int amount) override {
        cout << "Receipt: $" << amount << " withdrawn" << endl;
    }
};

// ---------- Abstract Factory ----------
class ATMFactory {
public:
    virtual CashDispenser* createCashDispenser() = 0;
    virtual ReceiptPrinter* createReceiptPrinter() = 0;
    virtual ~ATMFactory() {}
};

// ---------- Concrete Factories ----------
class IndiaATMFactory : public ATMFactory {
public:
    CashDispenser* createCashDispenser() override {
        return new IndiaCashDispenser();
    }

    ReceiptPrinter* createReceiptPrinter() override {
        return new IndiaReceiptPrinter();
    }
};

class USATMFactory : public ATMFactory {
public:
    CashDispenser* createCashDispenser() override {
        return new USCashDispenser();
    }

    ReceiptPrinter* createReceiptPrinter() override {
        return new USReceiptPrinter();
    }
};

// ---------- Client ----------
class ATM {
private:
    CashDispenser* dispenser;
    ReceiptPrinter* printer;

public:
    ATM(ATMFactory* factory) {
        dispenser = factory->createCashDispenser();
        printer   = factory->createReceiptPrinter();
    }

    void withdraw(int amount) {
        dispenser->dispenseCash(amount);
        printer->printReceipt(amount);
    }

    ~ATM() {
        delete dispenser;
        delete printer;
    }
};

// ---------- Main ----------
int main() {
    cout << "=== India ATM ===" << endl;
    ATMFactory* indiaFactory = new IndiaATMFactory();
    ATM* indiaATM = new ATM(indiaFactory);
    indiaATM->withdraw(2000);

    cout << endl;

    cout << "=== US ATM ===" << endl;
    ATMFactory* usFactory = new USATMFactory();
    ATM* usATM = new ATM(usFactory);
    usATM->withdraw(100);

    delete indiaATM;
    delete usATM;
    delete indiaFactory;
    delete usFactory;

    return 0;
}
