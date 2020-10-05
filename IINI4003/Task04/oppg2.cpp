#include <gtkmm.h>

class Window : public Gtk::Window {
public:
  Gtk::VBox vbox;
  Gtk::Entry entryFirst;
  Gtk::Entry entryLast;
  Gtk::Button button;
  Gtk::Label label;
  Gtk::Label labelFirst;
  Gtk::Label labelLast;

  void checkInput() {
    if (entryFirst.get_text() == "" || entryLast.get_text() == "") {
      button.set_sensitive(false);
      return;
    }
    button.set_sensitive(true);
  }

  Window() {
    button.set_label("Combine names");
    labelFirst.set_text("First Name:");
    labelLast.set_text("Last Name:");

    vbox.pack_start(labelFirst);
    vbox.pack_start(entryFirst); //Add the widget entry to vbox
    vbox.pack_start(labelLast);
    vbox.pack_start(entryLast);
    vbox.pack_start(button); //Add the widget button to vbox
    vbox.pack_start(label);  //Add the widget label to vbox
    button.set_sensitive(false);

    add(vbox);  //Add vbox to window
    show_all(); //Show all widgets

    entryFirst.signal_changed().connect([this]() {
      label.set_text("Entry now contains: " + entryFirst.get_text());
      checkInput();
    });

    entryLast.signal_changed().connect([this]() {
      label.set_text("Entry now contains: " + entryLast.get_text());
      checkInput();
    });

    entryFirst.signal_activate().connect([this]() {
      label.set_text("Entry activated");
    });

    entryLast.signal_activate().connect([this]() {
      label.set_text("Entry activated");
    });

    button.signal_clicked().connect([this]() {
      label.set_text(entryFirst.get_text() + " " + entryLast.get_text());
    });
  }
};

int main() {
  Gtk::Main gtk_main;
  Window window;
  window.set_title("Task 04");
  gtk_main.run(window);
}