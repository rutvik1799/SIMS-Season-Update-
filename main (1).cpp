// 1.Keep track of the index of items to be removed, as well as whether
//   they need to be completely eliminated or just their quantity decreased.

// 2. If the input_quantity is greater than or equal to the current quantity of the item,
//    remove the item from the inventory (completely eliminate it) and shift the remaining items in the array.

// 3. If the input_quantity is less than the current quantity of the item,
//    decrease the item's quantity as you are currently doing.


// here is the modified code:


void remove_item(int item_index) {
    int input_quantity;
    Item *item = items[item_index];
    std::cout << "\nEnter number of items to sell: ";
    std::cin >> input_quantity;

    int quantity = item->get_quantity();
    if (input_quantity <= quantity) {
        float price = item->get_price();
        float money_earned = price * input_quantity;
        item->set_quantity(quantity - input_quantity);

        // Check if the item needs to be completely eliminated
        if (item->get_quantity() == 0) {
            delete items[item_index]; // Free the memory for the item
            for (int i = item_index; i < item_count - 1; i++) {
                items[i] = items[i + 1]; // Shift remaining items in the array
            }
            item_count--;
        }

        std::cout << "\nItems sold";
        std::cout << "\nMoney received: " << money_earned;
        total_money += money_earned;
    } else {
        std::cout << "\nCannot sell more items than you have.";
    }
}
