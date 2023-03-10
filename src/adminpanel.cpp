#include "adminpanel.h"
void AdminPanel::initcrow() {
  crow::mustache::set_global_base("adminsite/");
  CROW_ROUTE(adminpanel, "/")
  ([]() { return crow::mustache::load("index.html").render(); });
  CROW_ROUTE(adminpanel, "/public/<path>")
  ([](const crow::request&, crow::response& res,std::string path) {
        //replace cat.jpg with your file path
        std::cout<<"PATH: "<<path<<"\n";
        res.set_static_file_info("adminsite/public/"+path);
        res.end();
    });
}
AdminPanel::AdminPanel() {
  initcrow();
  workcrow = false;
}
AdminPanel::AdminPanel(int port) : AdminPanel() {
  startcrow(port);
}

void AdminPanel::setport(int port) {
  stopcrow();
  this->port = port;
}
void AdminPanel::startcrow() {
  workcrow = true;
  adminpanel.port(port).run();
}
void AdminPanel::startcrow(int port) {
  setport(port);
  workcrow = true;
  adminpanel.port(port).run();
}
void AdminPanel::stopcrow() {
  if (workcrow == true) {
    workcrow = false;
    adminpanel.stop();
  }
}
