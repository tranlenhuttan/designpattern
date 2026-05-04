#include <iostream>
using namespace std;

// Target interface (hệ thống mới dùng)
class Printer {
public:
    virtual void print(string text) = 0;
};

// Adaptee (class cũ)
class OldPrinter {
public:
    void printText(string text) {
        cout << "Old Printer: " << text << endl;
    }
};

// Adapter
class PrinterAdapter : public Printer {
private:
    OldPrinter oldPrinter;

public:
    void print(string text) override {
        oldPrinter.printText(text); // chuyển đổi
    }
};

// Client
int main() {
    Printer* printer = new PrinterAdapter();
    printer->print("Hello Adapter Pattern!");
    delete printer;
    return 0;
}