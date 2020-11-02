#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include "store.h"
#include "customer.h"

class Mainwin : public Gtk::Window   {
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_new_store_click(); 
        void on_new_tool_click(); 
        void on_new_plant_click();
        void on_new_mulch_click();
        void on_view_products_click(); 
        void on_quit_click();
        void on_save_as_click();
        void on_save_click();
        void on_open_click();
        void on_about_click();
        void on_new_customer_click();
        void on_view_customers_click();
    private:
        Store* store;
        Customer* customer;
        Gtk::Label* display;
        std::vector<Customer*> customers;
        std::ostringstream oss;
        int get_int(std::string prompt);
        double get_double(std::string prompt);
        std::string get_string(std::string prompt);
};
#endif
