#include <iostream>

// ===== 1. Strategy Interface =====
class CheckoutStrategy {
public:
    virtual void executePayment(double amount) = 0;
    virtual ~CheckoutStrategy() {}
};

// ===== 2. Concrete Strategies =====
class CreditCardCheckout : public CheckoutStrategy {
public:
    void executePayment(double amount) {
        std::cout << "Thanh toan " << amount << " bang the tin dung\n";
    }
};

class MoMoCheckout : public CheckoutStrategy {
public:
    void executePayment(double amount) {
        std::cout << "Thanh toan " << amount << " bang MoMo\n";
    }
};

class CashCheckout : public CheckoutStrategy {
public:
    void executePayment(double amount) {
        std::cout << "Thanh toan " << amount << " bang tien mat\n";
    }
};

// ===== 3. Context =====
class ShoppingCart {
private:
    CheckoutStrategy* checkoutStrategy;

public:

    ShoppingCart() {
        this->checkoutStrategy = nullptr;
    }

    void switchCheckoutStrategy(CheckoutStrategy* newStrategy) {
        this->checkoutStrategy = newStrategy;
    }

    void proceedToCheckout(double totalAmount) {
        if (checkoutStrategy == nullptr) {
            std::cout << "Chua chon cach thanh toan!\n";
            return;
        }
        checkoutStrategy->executePayment(totalAmount);
    }
};

// ===== Main =====
int main() {
    CreditCardCheckout creditCard;
    MoMoCheckout momoWallet;
    CashCheckout cashOnDelivery;

    ShoppingCart cart;

    cart.switchCheckoutStrategy(&creditCard);
    cart.proceedToCheckout(150000);

    cart.switchCheckoutStrategy(&momoWallet);
    cart.proceedToCheckout(75000);

    cart.switchCheckoutStrategy(&cashOnDelivery);
    cart.proceedToCheckout(50000);

    return 0;
}