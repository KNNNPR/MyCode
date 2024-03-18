var itemCounter = 0;
var totalPrice = 0;
var price = 0;

function renew(total, iter) {
    document.getElementById('total').innerHTML = total;
    document.getElementById('count').innerHTML = iter;
}
function addToCartOne() {
    price = 999;
    itemCounter++;
    totalPrice += price;
    renew(totalPrice, itemCounter);
};
function clearCart() {
    totalPrice = 0;
    itemCounter = 0;
    renew(totalPrice, itemCounter);
}
function addToCartTwo() {
    price = 1789;
    itemCounter++;
    totalPrice += price;
    renew(totalPrice, itemCounter);
};
function addToCartThree() {
    price = 659;
    itemCounter++;
    totalPrice += price;
    renew(totalPrice, itemCounter);
};

let gg = document.querySelector('#total');