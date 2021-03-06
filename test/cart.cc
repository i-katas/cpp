#include "cart.h"


void Cart::add(price_t price, int qty) {
    Cart &self = *this;
    self.price += price * qty;
    self.qty += qty;
}

Cart::price_t Cart::totalPrice() const {
    return price;
}

Cart::price_t Cart::totalQuantity() const {
    return qty;
}

void reset(Cart& cart) {
    cart.price = 0;
    cart.qty = 0;
}
