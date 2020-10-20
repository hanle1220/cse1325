#include "mainwin.h"
#include <iostream> 

std::string Mainwin::get_string(std::string prompt) {
    return prompt;
}

double Mainwin::get_double(std::string prompt) {
    while(true) {
        try {
            return std::stod(get_string(prompt));
        } catch(std::exception& e) {
            Gtk::MessageDialog{"ERROR", true}.run();
        }
    }
}

int Mainwin::get_int(std::string prompt) {
    while(true) {
        try {
            return std::stoi(get_string(prompt));
        } catch(std::exception& e) {
            Gtk::MessageDialog{"ERROR", true}.run();
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

    display = Gtk::manage(new Gtk::Label());
    display->set_hexpand(true);
    vbox->pack_start(*display, Gtk::PACK_SHRINK, 0);

    vbox->show_all();


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
        products.push_back(new Tool(get_string(e_name.get_text()), get_double(e_price.get_text()), get_string(e_description.get_text())));
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
        products.push_back(new Plant(get_string(e_name.get_text()), get_double(e_price.get_text()), get_string(e_description.get_text()), get_string(e_species.get_text()), get_exposure(c_expo.get_active_row_number())));
        on_view_products_click();
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
        products.push_back(new Mulch(get_string(e_name.get_text()), get_double(e_price.get_text()), get_string(e_description.get_text()), get_double(e_volume.get_text()), get_material(c_material.get_active_row_number())));
        on_view_products_click();
    }
}

void Mainwin::on_view_products_click() {
    oss << "\nCurrent Catalog\n===============\n";
    for(auto product : products) {
        oss << std::endl << *product << std::endl;
        display->set_text(oss.str());
    }
}




