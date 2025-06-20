#include "../includes/food_order.h"

int process_food_order(struct OrderRequest *request)
{
    if (!request)
        return 0;

    struct OrderConfirmation *confirmation = NULL;

    if (check_restaurant_status(request))
        confirmation = create_standard_confirmation();
    else
        confirmation = create_preorder_confirmation();

    if (!confirmation)
        return 0;

    send_confirmation_notification(confirmation);
    free(confirmation);

    return 1;
}
