#include "mainwin.h"
#include <iostream> 
#include <fstream>

std::string Mainwin::get_string(std::string prompt) {
    return prompt;
}

double Mainwin::get_double(std::string prompt) {
    while(true) {
        try {
            return std::stod(prompt);
        } catch(std::exception& e) {
            Gtk::MessageDialog{*this, "ERROR"}.run();
        }
    }
}

int Mainwin::get_int(std::string prompt) {
    while(true) {
        try {
            return std::stoi(prompt);
        } catch(std::exception& e) {
            Gtk::MessageDialog{*this, "ERROR"}.run();
        }
    }
}

Material get_material(int m) {
    while(true) {
        switch (m) {
            case 0: return Material::RUBBER;
            case 1: return Material::PINE;
            case 2: return Material::CEDAR;
            case 3: return Material::HARDWOOD;
            default: Gtk::MessageDialog{"ERROR: INVALID SELECTION", true}.run();
        }
    }
} 

Exposure get_exposure(int e) {
    while(true) {
        switch (e){
            case 0: return Exposure::SHADE;
            case 1: return Exposure::PARTSUN;
            case 2: return Exposure::SUN;
            default: Gtk::MessageDialog{"ERROR: INVALID SELECTION", true}.run();
        }
    }
}

Mainwin::Mainwin(){

    set_default_size(400, 300);
    set_title("MANGA");

    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    //M E N U
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
    //vbox->add(*menubar);

    //F I L E
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //New store
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_store_click();});
    filemenu->append(*menuitem_new);
    
    //Save as
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect([this] {this->on_save_click();});
    filemenu->append(*menuitem_save);

    //Save as
    Gtk::MenuItem *menuitem_save_as = Gtk::manage(new Gtk::MenuItem("_Save as", true));
    menuitem_save_as->signal_activate().connect([this] {this->on_save_as_click();});
    filemenu->append(*menuitem_save_as);
    
    //Open
    Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
    menuitem_open->signal_activate().connect([this] {this->on_open_click();});
    filemenu->append(*menuitem_open);

    //Q U I T
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

    //Insert
    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    menubar->append(*menuitem_insert);
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*insertmenu);

    //Tool
    Gtk::MenuItem *menuitem_tool = Gtk::manage(new Gtk::MenuItem("_Tool", true));
    menuitem_tool->signal_activate().connect([this] {this->on_new_tool_click();});
    insertmenu->append(*menuitem_tool);

    //Plant
    Gtk::MenuItem *menuitem_plant = Gtk::manage(new Gtk::MenuItem("_Plant", true));
    menuitem_plant->signal_activate().connect([this] {this->on_new_plant_click();});
    insertmenu->append(*menuitem_plant);
     
    //Mulch
    Gtk::MenuItem *menuitem_mulch = Gtk::manage(new Gtk::MenuItem("_Mulch", true));
    menuitem_mulch->signal_activate().connect([this] {this->on_new_mulch_click();});
    insertmenu->append(*menuitem_mulch);

    //Customer
    Gtk::MenuItem *menuitem_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
    menuitem_customer->signal_activate().connect([this] {this->on_new_customer_click();});
    insertmenu->append(*menuitem_customer);

    //View
    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
    menubar->append(*menuitem_view);
    Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
    menuitem_view->set_submenu(*viewmenu);

    //Products
    Gtk::MenuItem *menuitem_products = Gtk::manage(new Gtk::MenuItem("_Products", true));
    menuitem_products->signal_activate().connect([this] {this->on_view_products_click();});
    viewmenu->append(*menuitem_products);    
    
    //Customer
    Gtk::MenuItem *menuitem_customers = Gtk::manage(new Gtk::MenuItem("_Customers", true));
    menuitem_customers->signal_activate().connect([this] {this->on_view_customers_click();});
    viewmenu->append(*menuitem_customers);

      //H E L P
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

       //A B O U T
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*menuitem_about);

    display = Gtk::manage(new Gtk::Label());
    display->set_hexpand(true);
    vbox->pack_start(*display, Gtk::PACK_SHRINK, 0);

    vbox->show_all();

    on_new_store_click();


}

Mainwin::~Mainwin() { }

void Mainwin::on_quit_click() {
    close();
}

void Mainwin::on_new_tool_click() {
    Gtk::Dialog dialog{"TOOL", *this};
    Gtk::Grid grid;

    Gtk::Label l_name{"Name"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);

    Gtk::Label l_price{"Price"};
    Gtk::Entry e_price;
    grid.attach(l_price, 0, 1, 1, 1);
    grid.attach(e_price, 1, 1, 2, 1);

    Gtk::Label l_description{"Description"};
    Gtk::Entry e_description;
    grid.attach(l_description, 0, 2, 1, 1);
    grid.attach(e_description, 1, 2, 2, 1);

    dialog.get_content_area()->add(grid);

    dialog.add_button("OK", Gtk::RESPONSE_OK);
    dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
    
    dialog.show_all(); 
    int response = dialog.run();
    if (response == Gtk::RESPONSE_OK) {
        store->add_product(*(new Tool{e_name.get_text(), get_double(e_price.get_text()), e_description.get_text()}));        
        on_view_products_click();
    }
}

void Mainwin::on_new_plant_click() {
    Gtk::Dialog dialog{"PLANT", *this};
    Gtk::Grid grid;

    Gtk::Label l_name{"Name"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);

    Gtk::Label l_price{"Price"};
    Gtk::Entry e_price;
    grid.attach(l_price, 0, 1, 1, 1);
    grid.attach(e_price, 1, 1, 2, 1);

    Gtk::Label l_description{"Description"};
    Gtk::Entry e_description;
    grid.attach(l_description, 0, 2, 1, 1);
    grid.attach(e_description, 1, 2, 2, 1);

    Gtk::Label l_species{"Species"};
    Gtk::Entry e_species;
    grid.attach(l_species, 0, 3, 1, 1);
    grid.attach(e_species, 1, 3, 2, 1);

    Gtk::Label l_expo{"Exposure"};
    Gtk::ComboBoxText c_expo;     
    c_expo.append("Shade");     
    c_expo.append("Part Sun");         
    c_expo.append("Sun");       
    c_expo.set_active(0);
    grid.attach(l_expo, 0, 4, 1, 1);
    grid.attach(c_expo, 1, 4, 2, 1);

    dialog.get_content_area()->add(grid);
    dialog.add_button("OK", Gtk::RESPONSE_OK);
    dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);

    dialog.show_all();
    int response = dialog.run();
    if (response == Gtk::RESPONSE_OK) {
        store->add_product(*(new Plant{get_string(e_name.get_text()), get_double(e_price.get_text()), get_string(e_description.get_text()), get_string(e_species.get_text()), get_exposure(c_expo.get_active_row_number())}));        
        //on_view_products_click();
    }
}

void Mainwin::on_new_mulch_click() {
    Gtk::Dialog dialog{"MULCH", *this};
    Gtk::Grid grid;

    Gtk::Label l_name{"Name"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);

    Gtk::Label l_price{"Price"};
    Gtk::Entry e_price;
    grid.attach(l_price, 0, 1, 1, 1);
    grid.attach(e_price, 1, 1, 2, 1);

    Gtk::Label l_description{"Description"};
    Gtk::Entry e_description;
    grid.attach(l_description, 0, 2, 1, 1);
    grid.attach(e_description, 1, 2, 2, 1);

    Gtk::Label l_volume{"Volume (ft³)"};
    Gtk::Entry e_volume;
    grid.attach(l_volume, 0, 3, 1, 1);
    grid.attach(e_volume, 1, 3, 2, 1);

    Gtk::Label l_material{"Material"};
    Gtk::ComboBoxText c_material;     
    c_material.append("Rubber");     
    c_material.append("Pine");         
    c_material.append("Cedar");    
    c_material.append("Hardwood");    
    c_material.set_active(0);
    grid.attach(l_material, 0, 4, 1, 1);
    grid.attach(c_material, 1, 4, 2, 1);

    dialog.get_content_area()->add(grid);
    dialog.add_button("OK", Gtk::RESPONSE_OK);
    dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);

    dialog.show_all();
    int response = dialog.run();
    if (response == Gtk::RESPONSE_OK) {  
        store->add_product(*(new Mulch{e_name.get_text(), get_double(e_price.get_text()), get_string(e_description.get_text()), get_int(e_volume.get_text()), get_material(c_material.get_active_row_number())}));
        //on_view_products_click();
    }
}

void Mainwin::on_new_customer_click(){
      
    Gtk::Dialog dialog{"Insert Customer", *this};
    Gtk::Grid grid;

    Gtk::Label l_name{"Name"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);

    Gtk::Label l_phone{"Phone"};
    Gtk::Entry e_phone;
    grid.attach(l_phone, 0, 1, 1, 1);
    grid.attach(e_phone, 1, 1, 2, 1);

    Gtk::Label l_email{"Email"};
    Gtk::Entry e_email;
    grid.attach(l_email, 0, 2, 1, 1);
    grid.attach(e_email, 1, 2, 2, 1);

    dialog.get_content_area()->add(grid);
    dialog.add_button("Insert", Gtk::RESPONSE_OK);
    dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
    dialog.show_all();
 
    int response = dialog.run();
    if (response == Gtk::RESPONSE_OK) {  
        store->add_customer(*(new Customer{e_name.get_text(), e_phone.get_text(), e_email.get_text()}));
    }
    //on_view_products_click();
}

void Mainwin::on_view_products_click() {
    std::string s = "\nCurrent Catalog\n===============\n";
    for(int i=0; i<store->products(); ++i) {
        std::ostringstream oss;
        oss << store->product(i) << '\n';
        s += oss.str();
    }
    display->set_text(s);
}

void Mainwin::on_view_customers_click() {
    std::string s = "\nCurrent Catalog\n===============\n";
    for(int i=0; i<store->customers(); ++i) {
        std::ostringstream oss;
        oss << store->customer(i) << '\n';
        s += oss.str();
    }
    display->set_text(s);
}

void Mainwin::on_new_store_click(){
    delete store;   
    Gtk::Dialog dialog{"New Store", *this};
    Gtk::Grid grid;

    Gtk::Label l_name{"Store's Name?"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(e_name, 0, 1, 2, 1);

    dialog.get_content_area()->add(grid);
    dialog.add_button("OK", Gtk::RESPONSE_OK);
    dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
    dialog.show_all();
    dialog.run();
 
    store = new Store{e_name.get_text()};
    //on_view_products_click();
}


void Mainwin::on_save_as_click() {
    Gtk::FileChooserDialog dialog("Please choose a file",
    Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);

    auto filter_manga = Gtk::FileFilter::create();
    filter_manga->set_name("Manga files");
    filter_manga->add_pattern("*.manga");
    dialog.add_filter(filter_manga);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename("untitled.manga");

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Save As", 1);

    int result = dialog.run();

    if (result == 1) {
        try {
            std::ofstream ofs{dialog.get_filename()};
            store->save(ofs);
            if(!ofs) throw std::runtime_error{"Error writing file"};
        } catch(std::exception& e) {
            Gtk::MessageDialog{*this, "Unable to save"}.run();
        }
    }
}

void Mainwin::on_save_click() {
    std::ofstream ofs{"untitled.manga"};
    store->save(ofs);
    Gtk::MessageDialog{*this, "Saved to 'untitled.manga'"}.run();
}

void Mainwin::on_open_click() {
    Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

    auto filter_store = Gtk::FileFilter::create();
    filter_store->set_name("MANGA files");
    filter_store->add_pattern("*.manga");
    dialog.add_filter(filter_store);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename("untitled.manga");

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Open", 1);

    int result = dialog.run();

    if (result == 1) {   
            delete store;
            std::ifstream ifs{dialog.get_filename()};
            store = new Store{ifs};
            on_view_products_click();
    }
}

void Mainwin::on_about_click(){
    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this); 
    dialog.set_program_name("MANGA\nMavs Arboreta, Nursery, and Garden Association");
    auto logo = Gdk::Pixbuf::create_from_file("tree.jpg");
    dialog.set_logo(logo);
    std::vector< Glib::ustring > authors = {"Han Le"};
    dialog.set_authors(authors);
    dialog.run();
}

